#ifndef PASSDIALOG_H
#define PASSDIALOG_H
#include <QDialog>

class QLabel;
class QPushButton;

class PassDialog : public QDialog {
    Q_OBJECT

public:
    PassDialog(QString name, QString birth, QWidget *parent = nullptr);
};
#endif // PASSDIALOG_H
