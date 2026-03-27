#ifndef TICKET1_H
#define TICKET1_H

#include <QString>

class Ticket1
{
private:
    QString from_;
    QString to_;
    QString date_;
    QString seat_;
    QString ext_lugg_;
    QString serv_;
public:
    QString get_from() {return from_;}
    QString get_to() {return to_;}
    QString get_date() {return date_;}
    QString get_seat() {return seat_;}
    QString get_lugg() {return ext_lugg_;}
    QString get_serv() {return serv_;}

    void set_from(QString from);
    void set_to(QString to);
    void set_date(QString date);
    void set_seat(QString seat);

    Ticket1(QString n, QString d, QString c, QString s, QString w, QString x);
};
#endif // TICKET1_H
