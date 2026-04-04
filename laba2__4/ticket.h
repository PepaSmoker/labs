#ifndef TICKET_H
#define TICKET_H

#include <QString>

class ticket{
private:
    QString number_;
    QString name_;
    QString date_;
    QString prize_;
    QString conditions_;
    QString result_;

public:
    QString get_number() {return number_;}
    QString get_name() {return name_;}
    QString get_date() {return date_;}
    QString get_prize() {return prize_;}
    QString get_conditions() {return conditions_;}
    QString get_result() {return result_;}

    ticket(QString a, QString b, QString c, QString d, QString e, QString f);
};

#endif // TICKET_H
