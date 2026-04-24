#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "food.h"

QT_BEGIN_NAMESPACE
class QTableWidget;
class QLineEdit;
class QTextEdit;
class QComboBox;
class QPushButton;
class QTabWidget;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCreateFood();
    void onImportFromTxt();
    void onSaveToJson();

    void onLoadJson();
    void onSaveBrokenToFile();
    void onRefreshTables();

private:
    QString escapeJson(const QString &s);
    void setupTabs();
    void loadFoodsFromJson(const QString &filename);
    void saveFoodsToJson(const QString &filename, const QList<Food> &foods);
    void displayTables(const QList<Food> &valid, const QList<Food> &broken);
    QList<Food> parseTxtFile(const QString &filePath, QStringList &errors);

    QWidget *createTab1();
    QLineEdit *leName, *leDescription, *leHunger, *lePrice, *leWeight;
    QTableWidget *tablePreview;
    QPushButton *btnCreate, *btnImportTxt;

    QWidget *createTab2();
    QTableWidget *tableValid;
    QTableWidget *tableBroken;
    QPushButton *btnLoad, *btnSaveBroken, *btnRefresh;

    QList<Food> m_allFoods;
    QList<Food> m_validFoods;
    QList<Food> m_brokenFoods;

    const QString dataFileName = "foods.json";
    const QString brokenFileName = "broken_foods.json";
};

#endif // MAINWINDOW_H
