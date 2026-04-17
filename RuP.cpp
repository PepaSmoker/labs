#include "RuP.h"
#include "passdialog.h"

RuP::RuP(QString l, QString f, QString m, int d, int mo, int y) {
    lastName = l;
    firstName = f;
    middleName = m;
    birth = {d, mo, y};
}

QString RuP::getFullName() const {
    return lastName + " " + firstName + " " + middleName;
}

bool RuP::Craft(QWidget* parent) {
    PassDialog dlg(getFullName(), getBirthDate(), parent);
    return dlg.exec() == QDialog::Accepted;
}