#include "food.h"
#include <QRegularExpression>

Food::Food()
    : m_hungerValue(0), m_price(0.0), m_weight(0.0)
{
}

Food::Food(const QString &name, const QString &description,
           int hungerValue, double price, double weight)
    : m_name(name), m_description(description),
    m_hungerValue(hungerValue), m_price(price), m_weight(weight)
{
}

QString Food::name() const { return m_name; }
QString Food::description() const { return m_description; }
int Food::hungerValue() const { return m_hungerValue; }
double Food::price() const { return m_price; }
double Food::weight() const { return m_weight; }

void Food::setName(const QString &name) { m_name = name; }
void Food::setDescription(const QString &description) { m_description = description; }
void Food::setHungerValue(int hunger) { m_hungerValue = hunger; }
void Food::setPrice(double price) { m_price = price; }
void Food::setWeight(double weight) { m_weight = weight; }

bool Food::isValid() const
{
    if (m_name.trimmed().isEmpty() || m_description.trimmed().isEmpty())
        return false;
    if (m_hungerValue <= 0 || m_price <= 0.0 || m_weight <= 0.0)
        return false;
    return true;
}

QJsonObject Food::toJson() const
{
    QJsonObject obj;
    obj["name"] = m_name;
    obj["description"] = m_description;
    obj["hunger"] = m_hungerValue;
    obj["price"] = m_price;
    obj["weight"] = m_weight;
    return obj;
}

Food Food::fromJson(const QJsonObject &json)
{
    Food f;
    f.setName(json["name"].toString());
    f.setDescription(json["description"].toString());
    f.setHungerValue(json["hunger"].toInt());
    f.setPrice(json["price"].toDouble());
    f.setWeight(json["weight"].toDouble());
    return f;
}