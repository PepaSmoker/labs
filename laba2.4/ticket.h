#ifndef TICKET_H
#define TICKET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Ticket;
}
QT_END_NAMESPACE

class Ticket : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ticket(QWidget *parent = nullptr);
    ~Ticket() override;


private:
    Ui::Ticket *ui;

private slots:
    void on_resetButton_clicked();
    void on_save_clicked();

};

#endif // TICKET_H
