#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "food.h"

QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
class QLabel;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSaveToJson();
    void onImportFromTxt();

private:
    void loadJsonFile();          // выбрать JSON файл
    void appendFoodToJson(const Food &food);
    bool readJsonArray(const QString &filename, QList<Food> &outList);
    bool writeJsonArray(const QString &filename, const QList<Food> &list);

    QLineEdit *leName, *leDesc, *leHunger, *lePrice, *leWeight;
    QPushButton *btnSave, *btnImport;
    QLabel *lblStatus;

    QString currentJsonPath;
};

#endif // MAINWINDOW_H