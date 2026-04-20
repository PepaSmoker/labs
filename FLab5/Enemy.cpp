#include "Enemy.h"
#include "InfoDialog.h"
#include <QRandomGenerator>
#include <QDir>
#include <QCoreApplication>
#include <QDebug>

bool Enemy::s_useDefaultImages = false;

void Enemy::setUseDefaultImages(bool useDefault) {
    s_useDefaultImages = useDefault;
}

Enemy::Enemy() : NPC(), m_rarity("Unknown"), m_damage(0) {}

Enemy::Enemy(const QString& name, const QString& rarity, int damage, int health, const Armor& armor)
    : NPC(name, health, armor), m_rarity(rarity), m_damage(damage) {}

Enemy::~Enemy() {}

QString Enemy::getRarity() const { return m_rarity; }
int Enemy::getDamage() const { return m_damage; }

void Enemy::setRarity(const QString& rarity) { m_rarity = rarity; }
void Enemy::setDamage(int damage) { m_damage = damage; }

void Enemy::craft(QWidget* parent) const
{
    InfoDialog dialog(this, parent);
    dialog.exec();
}

QString Enemy::getType() const {
    return "Враг";
}

QStringList Enemy::getTableRow() const {
    return QStringList() << getType() << m_name << m_rarity
                         << QString::number(m_damage)
                         << QString::number(m_health)
                         << m_armor.toString();
}

QString Enemy::getDetails() const {
    return QString("Тип: Враг\n"
                   "Имя: %1\n"
                   "Редкость: %2\n"
                   "Урон: %3\n"
                   "Здоровье: %4\n"
                   "Броня (Шлем/Кираса/Сапоги): %5")
        .arg(m_name, m_rarity, QString::number(m_damage),
             QString::number(m_health), m_armor.toString());
}

QString Enemy::getHealthColor() const {
    return "red";
}

QString Enemy::getRarityColor() const {
    QString rar = m_rarity.toLower();
    if (rar == "редкий") return "purple";
    if (rar == "обычный") return "green";
    if (rar == "легенда") return "orange";
    return "black";
}

QString Enemy::getImagePath() const {
    if (s_useDefaultImages) {
        return QCoreApplication::applicationDirPath() + "/images/enm_default.png";
    }

    static QStringList cachedFiles;
    static bool cacheValid = false;

    QDir dir(QCoreApplication::applicationDirPath() + "/images/enm_res");
    if (!dir.exists()) {
        return QCoreApplication::applicationDirPath() + "/images/enm_default.png";
    }

    if (!cacheValid) {
        QStringList filters;
        filters << "*.png" << "*.jpg" << "*.jpeg";
        cachedFiles = dir.entryList(filters);
        cacheValid = true;
    }

    QStringList validFiles;
    for (const QString& file : cachedFiles) {
        QString fullPath = dir.absoluteFilePath(file);
        if (QFile::exists(fullPath)) {
            validFiles.append(file);
        }
    }

    if (validFiles.isEmpty()) {
        QStringList filters;
        filters << "*.png" << "*.jpg" << "*.jpeg";
        validFiles = dir.entryList(filters);
        cachedFiles = validFiles;
    }

    if (validFiles.isEmpty()) {
        return QCoreApplication::applicationDirPath() + "/images/enm_default.png";
    }

    int randomIndex = QRandomGenerator::global()->bounded(validFiles.size());
    QString chosenFile = validFiles[randomIndex];
    return dir.absoluteFilePath(chosenFile);
}
