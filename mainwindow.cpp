#include "mainwindow.h"
#include <QGroupBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QJsonArray>
#include <QDebug>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QTabWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QHeaderView>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Лабораторная работа №6 - Пища");
    resize(900, 600);
    setupTabs();
    onLoadJson();
}

MainWindow::~MainWindow() {}

void MainWindow::setupTabs()
{
    QTabWidget *tabWidget = new QTabWidget(this);
    tabWidget->addTab(createTab1(), "Программа 1: Создание");
    tabWidget->addTab(createTab2(), "Программа 2: Проверка");
    setCentralWidget(tabWidget);
}

QWidget *MainWindow::createTab1()
{
    QWidget *tab = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout(tab);

    // Группа ввода
    QGroupBox *groupBox = new QGroupBox("Новый объект");
    QFormLayout *formLayout = new QFormLayout;
    leName = new QLineEdit;
    leDescription = new QLineEdit;
    leHunger = new QLineEdit;
    lePrice = new QLineEdit;
    leWeight = new QLineEdit;
    formLayout->addRow("Название:", leName);
    formLayout->addRow("Описание:", leDescription);
    formLayout->addRow("Ед. голода:", leHunger);
    formLayout->addRow("Цена:", lePrice);
    formLayout->addRow("Вес:", leWeight);
    groupBox->setLayout(formLayout);
    mainLayout->addWidget(groupBox);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    btnCreate = new QPushButton("Создать и сохранить");
    btnImportTxt = new QPushButton("Импорт из .txt");
    buttonLayout->addWidget(btnCreate);
    buttonLayout->addWidget(btnImportTxt);
    mainLayout->addLayout(buttonLayout);

    mainLayout->addWidget(new QLabel("Последние добавленные (из JSON):"));
    tablePreview = new QTableWidget;
    tablePreview->setColumnCount(5);
    tablePreview->setHorizontalHeaderLabels({"Название", "Описание", "Голод", "Цена", "Вес"});
    tablePreview->horizontalHeader()->setStretchLastSection(true);
    mainLayout->addWidget(tablePreview);

    connect(btnCreate, &QPushButton::clicked, this, &MainWindow::onCreateFood);
    connect(btnImportTxt, &QPushButton::clicked, this, &MainWindow::onImportFromTxt);

    return tab;
}

QWidget *MainWindow::createTab2()
{
    QWidget *tab = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout(tab);

    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLoad = new QPushButton("Загрузить JSON");
    btnSaveBroken = new QPushButton("Сохранить битые объекты в файл");
    btnRefresh = new QPushButton("Обновить таблицы");
    btnLayout->addWidget(btnLoad);
    btnLayout->addWidget(btnSaveBroken);
    btnLayout->addWidget(btnRefresh);
    mainLayout->addLayout(btnLayout);

    mainLayout->addWidget(new QLabel("Корректные объекты:"));
    tableValid = new QTableWidget;
    tableValid->setColumnCount(5);
    tableValid->setHorizontalHeaderLabels({"Название", "Описание", "Голод", "Цена", "Вес"});
    tableValid->horizontalHeader()->setStretchLastSection(true);
    mainLayout->addWidget(tableValid);

    mainLayout->addWidget(new QLabel("Битые объекты:"));
    tableBroken = new QTableWidget;
    tableBroken->setColumnCount(5);
    tableBroken->setHorizontalHeaderLabels({"Название", "Описание", "Голод", "Цена", "Вес"});
    tableBroken->horizontalHeader()->setStretchLastSection(true);
    mainLayout->addWidget(tableBroken);

    connect(btnLoad, &QPushButton::clicked, this, &MainWindow::onLoadJson);
    connect(btnSaveBroken, &QPushButton::clicked, this, &MainWindow::onSaveBrokenToFile);
    connect(btnRefresh, &QPushButton::clicked, this, &MainWindow::onRefreshTables);

    return tab;
}

void MainWindow::onCreateFood()
{
    QString name = leName->text();
    QString desc = leDescription->text();
    bool okHunger, okPrice, okWeight;
    int hunger = leHunger->text().toInt(&okHunger);
    double price = lePrice->text().toDouble(&okPrice);
    double weight = leWeight->text().toDouble(&okWeight);


    Food newFood(name, desc, hunger, price, weight);
    QFile file(dataFileName);
    QList<Food> allFoods;
    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        if (doc.isArray()) {
            QJsonArray arr = doc.array();
            for (const QJsonValue &val : arr) {
                allFoods.append(Food::fromJson(val.toObject()));
            }
        }
        file.close();
    }
    allFoods.append(newFood);
    saveFoodsToJson(dataFileName, allFoods);

    onRefreshTables();
    leName->clear();
    leDescription->clear();
    leHunger->clear();
    lePrice->clear();
    leWeight->clear();

    QMessageBox::information(this, "Успех", "Объект добавлен и сохранён в JSON.");
}

void MainWindow::onImportFromTxt()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите текстовый файл", "", "Текстовые файлы (*.txt)");
    if (filePath.isEmpty()) return;

    QStringList errors;
    QList<Food> imported = parseTxtFile(filePath, errors);
    if (imported.isEmpty()) {
        QMessageBox::warning(this, "Импорт", "Не удалось импортировать ни одного объекта.");
        return;
    }

    QFile file(dataFileName);
    QList<Food> allFoods;
    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        if (doc.isArray()) {
            QJsonArray arr = doc.array();
            for (const QJsonValue &val : arr) {
                allFoods.append(Food::fromJson(val.toObject()));
            }
        }
        file.close();
    }
    allFoods.append(imported);
    saveFoodsToJson(dataFileName, allFoods);
    onRefreshTables();

    QString msg = QString("Импортировано %1 объектов.").arg(imported.size());

    QMessageBox::information(this, "Результат импорта", msg);
}

void MainWindow::onSaveToJson()
{
    saveFoodsToJson(dataFileName, m_allFoods);
    QMessageBox::information(this, "Сохранение", "Данные сохранены в foods.json");
}

void MainWindow::onLoadJson()
{
    QFile file(dataFileName);
    if (!file.exists()) {
        m_allFoods.clear();
        m_validFoods.clear();
        m_brokenFoods.clear();
        displayTables(m_validFoods, m_brokenFoods);
        return;
    }
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл JSON");
        return;
    }
    QByteArray data = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isArray()) {
        QMessageBox::critical(this, "Ошибка", "Файл JSON не содержит массив");
        return;
    }
    m_allFoods.clear();
    QJsonArray arr = doc.array();
    for (const QJsonValue &val : arr) {
        m_allFoods.append(Food::fromJson(val.toObject()));
    }

    onRefreshTables();
}

void MainWindow::onSaveBrokenToFile()
{
    if (m_brokenFoods.isEmpty()) {
        QMessageBox::information(this, "Сохранение", "Нет битых объектов для сохранения.");
        return;
    }
    saveFoodsToJson(brokenFileName, m_brokenFoods);
    QMessageBox::information(this, "Сохранение",
                             QString("Битые объекты сохранены в файл %1").arg(brokenFileName));
}

void MainWindow::onRefreshTables()
{
    m_validFoods.clear();
    m_brokenFoods.clear();
    for (const Food &f : m_allFoods) {
        if (f.isValid())
            m_validFoods.append(f);
        else
            m_brokenFoods.append(f);
    }
    displayTables(m_validFoods, m_brokenFoods);

    if (tablePreview) {
        tablePreview->setRowCount(0);
        int start = qMax(0, m_allFoods.size() - 10);
        for (int i = start; i < m_allFoods.size(); ++i) {
            const Food &f = m_allFoods[i];
            int row = tablePreview->rowCount();
            tablePreview->insertRow(row);
            tablePreview->setItem(row, 0, new QTableWidgetItem(f.name()));
            tablePreview->setItem(row, 1, new QTableWidgetItem(f.description()));
            tablePreview->setItem(row, 2, new QTableWidgetItem(QString::number(f.hungerValue())));
            tablePreview->setItem(row, 3, new QTableWidgetItem(QString::number(f.price())));
            tablePreview->setItem(row, 4, new QTableWidgetItem(QString::number(f.weight())));
        }
    }
}

void MainWindow::displayTables(const QList<Food> &valid, const QList<Food> &broken)
{
    if (!tableValid || !tableBroken) return;  // защита

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

QString MainWindow::escapeJson(const QString &s)
{
    QString res = s;
    res.replace("\\", "\\\\");
    res.replace("\"", "\\\"");
    return res;
}

void MainWindow::saveFoodsToJson(const QString &filename, const QList<Food> &foods)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить файл " + filename);
        return;
    }

    QTextStream out(&file);
    out.setCodec("UTF-8");
    out.setGenerateByteOrderMark(true);

    out << "[\n";

    for (int i = 0; i < foods.size(); ++i) {
        const Food &f = foods[i];

        QString name = f.name();
        QString desc = f.description();
        name.replace("\\", "\\\\").replace("\"", "\\\"");
        desc.replace("\\", "\\\\").replace("\"", "\\\"");

        out << "  {\n";
        out << "    \"name\": \"" << name << "\",\n";
        out << "    \"description\": \"" << desc << "\",\n";
        out << "    \"hunger\": " << f.hungerValue() << ",\n";
        out << "    \"price\": " << f.price() << ",\n";
        out << "    \"weight\": " << f.weight() << "\n";
        out << "  }";
        if (i != foods.size() - 1) out << ",";
        out << "\n";
    }

    out << "]\n";
    file.close();
}

QList<Food> MainWindow::parseTxtFile(const QString &filePath, QStringList &errors)
{
    QList<Food> result;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        errors << "Не удалось открыть файл";
        return result;
    }
    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    int lineNum = 0;
    while (!stream.atEnd()) {
        QString line = stream.readLine().trimmed();
        lineNum++;
        if (line.isEmpty()) continue;
        QStringList parts = line.split(';');
        if (parts.size() != 5) {
            errors << QString("Строка %1: неверное количество полей (требуется 5)").arg(lineNum);
            continue;
        }
        QString name = parts[0].trimmed();
        QString desc = parts[1].trimmed();
        bool okHunger, okPrice, okWeight;
        int hunger = parts[2].trimmed().toInt(&okHunger);
        double price = parts[3].trimmed().toDouble(&okPrice);
        double weight = parts[4].trimmed().toDouble(&okWeight);

        result.append(Food(name, desc, hunger, price, weight));
    }
    file.close();
    return result;
}
