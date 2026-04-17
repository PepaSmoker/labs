#ifndef AMP_H
#define AMP_H
#include "R.h"

class AmP : public R {
    QString secondName;

public:
    AmP(QString f, QString s, QString l, int d, int mo, int y);
    QString getFullName() const override;
    bool Craft(QWidget* parent) override;
};
#endif // AMP_H
