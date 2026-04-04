#include "ticket.h"

ticket::ticket(QString a, QString b, QString c, QString d, QString e, QString f)
{
    number_ = a;
    name_ = b;
    date_ = c;
    prize_ = d;
    conditions_ = e;
    result_ = f;
}