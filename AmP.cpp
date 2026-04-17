#include "AmP.h"
#include "passdialog.h"

AmP::AmP(QString f, QString s, QString l, int d, int mo, int y) {
    firstName = f;
    secondName = s;
    lastName = l;
    birth = {d, mo, y};
}

QString AmP::getFullName() const {
    return firstName + " " + secondName + " " + lastName;
}

bool AmP::Craft(QWidget* parent) {
    PassDialog dlg(getFullName(), getBirthDate(), parent);
    return dlg.exec() == QDialog::Accepted;
}