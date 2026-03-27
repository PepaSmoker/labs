#include "ticket.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ticket w;
    w.show();
    return QCoreApplication::exec();
}
