#ifndef R_H
#define R_H

#include <QString>
#include <QWidget>
struct Date {
    int day;
    int month;
    int year;
};

class R {
protected:
    QString lastName;
    QString firstName;
    Date birth;

public:
    virtual ~R() {}

    virtual QString getFullName() const = 0;
    QString getBirthDate() const;
    virtual bool Craft(QWidget* parent) = 0;
};

#endif