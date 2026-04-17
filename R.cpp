#include "R.h"

QString R::getBirthDate() const {
    return QString("%1.%2.%3")
    .arg(birth.day, 2, 10, QChar('0'))
        .arg(birth.month, 2, 10, QChar('0'))
        .arg(birth.year);
}