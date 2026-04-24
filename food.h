#ifndef FOOD_H
#define FOOD_H

#include <QString>
#include <QJsonObject>
#include <QJsonArray>

class Food
{
public:
    Food();
    Food(const QString &name, const QString &description,
         int hungerValue, double price, double weight);

    QString name() const;
    QString description() const;
    int hungerValue() const;
    double price() const;
    double weight() const;

    void setName(const QString &name);
    void setDescription(const QString &description);
    void setHungerValue(int hunger);
    void setPrice(double price);
    void setWeight(double weight);

    bool isValid() const;

    QJsonObject toJson() const;
    static Food fromJson(const QJsonObject &json);

private:
    QString m_name;
    QString m_description;
    int m_hungerValue;
    double m_price;
    double m_weight;
};

#endif // FOOD_H
