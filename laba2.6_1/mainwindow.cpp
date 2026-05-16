#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonArray>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Программа 1: Создание объектов Food");
    resize(500, 350);

    QWidget *central = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    QGroupBox *group = new QGroupBox("Новый продукт");
    QFormLayout *form = new QFormLayout;
    leName = new QLineEdit;
    leDesc = new QLineEdit;
    leHunger = new QLineEdit;
    lePrice = new QLineEdit;
    leWeight = new QLineEdit;
    form->addRow("Название:", leName);
    form->addRow("Описание:", leDesc);
    form->addRow("Ед. голода (целое, можно 0):", leHunger);
    form->addRow("Цена (вещественное, можно 0):", lePrice);
    form->addRow("Вес (вещественное, можно 0):", leWeight);
    group->setLayout(form);
    mainLayout->addWidget(group);

    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnSave = new QPushButton("Сохранить в JSON (добавить)");
    btnImport = new QPushButton("Импорт из .txt (заполнить форму)");
    btnLayout->addWidget(btnSave);
    btnLayout->addWidget(btnImport);
    mainLayout->addLayout(btnLayout);

    lblStatus = new QLabel("Готов");
    mainLayout->addWidget(lblStatus);

    setCentralWidget(central);

    connect(btnSave, &QPushButton::clicked, this, &MainWindow::onSaveToJson);
    connect(btnImport, &QPushButton::clicked, this, &MainWindow::onImportFromTxt);
}

MainWindow::~MainWindow() {}

void MainWindow::onSaveToJson()
{
    // Позволяем сохранить любые данные (даже пустые или нулевые)
    QString name = leName->text();          // может быть пустой
    QString desc = leDesc->text();          // может быть пустой
    bool okHunger, okPrice, okWeight;
    int hunger = leHunger->text().toInt(&okHunger);
    double price = lePrice->text().toDouble(&okPrice);
    double weight = leWeight->text().toDouble(&okWeight);

    // Если преобразование не удалось, используем 0 (битый объект)
    if (!okHunger) hunger = 0;
    if (!okPrice) price = 0.0;
    if (!okWeight) weight = 0.0;

    Food newFood(name, desc, hunger, price, weight);

    if (currentJsonPath.isEmpty()) {
        currentJsonPath = QFileDialog::getSaveFileName(this,
                                                       "Выберите или создайте JSON файл", "", "JSON (*.json)");
        if (currentJsonPath.isEmpty()) return;
    }

    appendFoodToJson(newFood);
    lblStatus->setText(QString("Объект добавлен в %1 (может быть битым)").arg(currentJsonPath));

    // Очистка формы
    leName->clear();
    leDesc->clear();
    leHunger->clear();
    lePrice->clear();
    leWeight->clear();
}

void MainWindow::onImportFromTxt()
{
    QString txtPath = QFileDialog::getOpenFileName(this,
                                                   "Выберите текстовый файл (один объект)", "", "Текстовые файлы (*.txt)");
    if (txtPath.isEmpty()) return;

    QFile file(txtPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл.");
        return;
    }

    QTextStream stream(&file);
    QString line = stream.readLine();
    while (line.trimmed().isEmpty() && !stream.atEnd())
        line = stream.readLine();
    file.close();

    if (line.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Файл пуст или не содержит данных.");
        return;
    }

    QStringList parts = line.split(';');
    // Если частей меньше 5, то недостающие поля оставляем пустыми
    while (parts.size() < 5) parts.append("");

    leName->setText(parts[0].trimmed());
    leDesc->setText(parts[1].trimmed());
    leHunger->setText(parts[2].trimmed());
    lePrice->setText(parts[3].trimmed());
    leWeight->setText(parts[4].trimmed());

    lblStatus->setText("Данные из TXT загружены. При необходимости отредактируйте и сохраните.");
}

void MainWindow::appendFoodToJson(const Food &food)
{
    QList<Food> existing;
    readJsonArray(currentJsonPath, existing);
    existing.append(food);
    writeJsonArray(currentJsonPath, existing);
}

bool MainWindow::readJsonArray(const QString &filename, QList<Food> &outList)
{
    outList.clear();
    QFile file(filename);
    if (!file.exists()) return true;
    if (!file.open(QIODevice::ReadOnly)) return false;

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();
    if (!doc.isArray()) return false;

    QJsonArray arr = doc.array();
    for (const QJsonValue &val : arr) {
        outList.append(Food::fromJson(val.toObject()));
    }
    return true;
}

bool MainWindow::writeJsonArray(const QString &filename, const QList<Food> &list)
{
    QJsonArray arr;
    for (const Food &f : list) {
        arr.append(f.toJson());
    }
    QJsonDocument doc(arr);
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) return false;
    file.write(doc.toJson());
    file.close();
    return true;
}