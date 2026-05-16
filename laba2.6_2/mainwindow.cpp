#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QFileDialog>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonArray>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Программа 2: Проверка и сортировка Food");
    resize(900, 600);

    QWidget *central = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    // Кнопки
    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLoad = new QPushButton("Загрузить JSON");
    btnSaveBroken = new QPushButton("Сохранить битые объекты в JSON");
    btnLayout->addWidget(btnLoad);
    btnLayout->addWidget(btnSaveBroken);
    mainLayout->addLayout(btnLayout);

    // Таблица корректных (сортированных)
    mainLayout->addWidget(new QLabel("Корректные объекты (обратный алфавитный порядок по названию):"));
    tableValid = new QTableWidget;
    tableValid->setColumnCount(5);
    tableValid->setHorizontalHeaderLabels({"Название", "Описание", "Голод", "Цена", "Вес"});
    tableValid->horizontalHeader()->setStretchLastSection(true);
    mainLayout->addWidget(tableValid);

    // Таблица битых
    mainLayout->addWidget(new QLabel("Битые объекты:"));
    tableBroken = new QTableWidget;
    tableBroken->setColumnCount(5);
    tableBroken->setHorizontalHeaderLabels({"Название", "Описание", "Голод", "Цена", "Вес"});
    tableBroken->horizontalHeader()->setStretchLastSection(true);
    mainLayout->addWidget(tableBroken);

    setCentralWidget(central);

    connect(btnLoad, &QPushButton::clicked, this, &MainWindow::onLoadJson);
    connect(btnSaveBroken, &QPushButton::clicked, this, &MainWindow::onSaveBroken);
}

MainWindow::~MainWindow() {}

void MainWindow::onLoadJson()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Выберите JSON файл с продуктами", "", "JSON (*.json)");
    if (filePath.isEmpty()) return;

    allFoods = loadFromJson(filePath);
    if (allFoods.isEmpty() && QFile(filePath).exists()) {
        QMessageBox::warning(this, "Предупреждение", "Файл пуст или содержит некорректный JSON.");
    }

    // Разделение на valid / broken
    validFoods.clear();
    brokenFoods.clear();
    for (const Food &f : allFoods) {
        if (f.isValid())
            validFoods.append(f);
        else
            brokenFoods.append(f);
    }

    // Сортировка корректных по названию в обратном алфавитном порядке
    std::sort(validFoods.begin(), validFoods.end(),
              [](const Food &a, const Food &b) {
                  return QString::localeAwareCompare(a.name(), b.name()) > 0;
              });

    displayTables(validFoods, brokenFoods);
    QMessageBox::information(this, "Загрузка", QString("Загружено %1 объектов.\n"
                                                               "Корректных: %2\nБитых: %3")
                                                           .arg(allFoods.size()).arg(validFoods.size()).arg(brokenFoods.size()));
}

void MainWindow::onSaveBroken()
{
    if (brokenFoods.isEmpty()) {
        QMessageBox::information(this, "Сохранение", "Нет битых объектов для сохранения.");
        return;
    }

    QString savePath = QFileDialog::getSaveFileName(this,
                                                    "Сохранить битые объекты", "broken_foods.json", "JSON (*.json)");
    if (savePath.isEmpty()) return;

    QJsonArray arr;
    for (const Food &f : brokenFoods) {
        arr.append(f.toJson());
    }
    QJsonDocument doc(arr);
    QFile file(savePath);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось создать файл.");
        return;
    }
    file.write(doc.toJson());
    file.close();

    QMessageBox::information(this, "Сохранение", QString("Сохранено %1 битых объектов в %2")
                                                               .arg(brokenFoods.size()).arg(savePath));
}

void MainWindow::displayTables(const QList<Food> &valid, const QList<Food> &broken)
{
    // Таблица корректных (уже отсортированы)
    tableValid->setRowCount(0);
    for (const Food &f : valid) {
        int row = tableValid->rowCount();
        tableValid->insertRow(row);
        tableValid->setItem(row, 0, new QTableWidgetItem(f.name()));
        tableValid->setItem(row, 1, new QTableWidgetItem(f.description()));
        tableValid->setItem(row, 2, new QTableWidgetItem(QString::number(f.hungerValue())));
        tableValid->setItem(row, 3, new QTableWidgetItem(QString::number(f.price())));
        tableValid->setItem(row, 4, new QTableWidgetItem(QString::number(f.weight())));
    }

    // Таблица битых (порядок не важен)
    tableBroken->setRowCount(0);
    for (const Food &f : broken) {
        int row = tableBroken->rowCount();
        tableBroken->insertRow(row);
        tableBroken->setItem(row, 0, new QTableWidgetItem(f.name()));
        tableBroken->setItem(row, 1, new QTableWidgetItem(f.description()));
        tableBroken->setItem(row, 2, new QTableWidgetItem(QString::number(f.hungerValue())));
        tableBroken->setItem(row, 3, new QTableWidgetItem(QString::number(f.price())));
        tableBroken->setItem(row, 4, new QTableWidgetItem(QString::number(f.weight())));
    }
}

QList<Food> MainWindow::loadFromJson(const QString &filename)
{
    QList<Food> result;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) return result;

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();
    if (!doc.isArray()) return result;

    QJsonArray arr = doc.array();
    for (const QJsonValue &val : arr) {
        result.append(Food::fromJson(val.toObject()));
    }
    return result;
}