#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "RuP.h"
#include "AmP.h"

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->loadBtn, &QPushButton::clicked, this, &MainWindow::loadFile);
    connect(ui->tableWidget, &QTableWidget::cellDoubleClicked,
            this, &MainWindow::onDoubleClick);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::loadFile() {
    QString path = QFileDialog::getOpenFileName(this);

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) return;

    QTextStream in(&file);

    while (!in.atEnd()) {
        int code;
        in >> code;

        if (code == 1) {
            QString f, i, o;
            int d, m, y;
            in >> f >> i >> o >> d >> m >> y;
            people.push_back(new RuP(f, i, o, d, m, y));
        } else {
            QString i1, i2, f;
            int m, d, y;
            in >> i1 >> i2 >> f >> m >> d >> y;
            people.push_back(new AmP(i1, i2, f, d, m, y));
        }
    }

    fillTable();
}

void MainWindow::fillTable() {
    ui->tableWidget->setRowCount(people.size());

    for (int i = 0; i < people.size(); i++) {
        ui->tableWidget->setItem(i, 0,
                                 new QTableWidgetItem(people[i]->getFullName()));
        ui->tableWidget->setItem(i, 1,
                                 new QTableWidgetItem(people[i]->getBirthDate()));
    }
}

void MainWindow::onDoubleClick(int row, int) {
    if (people[row]->Craft(this)) {
        delete people[row];              // освобождаем память
        people.removeAt(row);            // удаляем из списка
        ui->tableWidget->removeRow(row); // удаляем из таблицы
    }
}