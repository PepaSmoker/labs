#include "happy_ticket.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    happy_ticket w;
    w.show();
    return QCoreApplication::exec();
}
