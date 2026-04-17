#ifndef RUP_H
#define RUP_H
#include "R.h"

class RuP : public R {
    QString middleName;

public:
    RuP(QString l, QString f, QString m, int d, int mo, int y);
    QString getFullName() const override;
    bool Craft(QWidget* parent) override;
};
#endif // RUP_H
