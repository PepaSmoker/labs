#include "Ticket1.h"

Ticket1::Ticket1(QString n, QString d, QString c, QString s, QString w, QString x)
{
    from_ = n;
    to_ = d;
    date_ = c;
    seat_ = s;
    ext_lugg_ = w;
    serv_ = x;
}