#ifndef HAPPY_TICKET_H
#define HAPPY_TICKET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class happy_ticket;
}
QT_END_NAMESPACE

class happy_ticket : public QMainWindow
{
    Q_OBJECT

public:
    explicit happy_ticket(QWidget *parent = nullptr);
    ~happy_ticket() override;

private slots:
    void on_reset_clicked();
    void on_save_clicked();



private:
    Ui::happy_ticket *ui;

};
#endif // HAPPY_TICKET_H
