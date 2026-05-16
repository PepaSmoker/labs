#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "food.h"

QT_BEGIN_NAMESPACE
class QTableWidget;
class QPushButton;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoadJson();
    void onSaveBroken();

private:
    void displayTables(const QList<Food> &valid, const QList<Food> &broken);
    QList<Food> loadFromJson(const QString &filename);

    QTableWidget *tableValid;
    QTableWidget *tableBroken;
    QPushButton *btnLoad, *btnSaveBroken;

    QList<Food> allFoods;
    QList<Food> validFoods;
    QList<Food> brokenFoods;
};

#endif // MAINWINDOW_H