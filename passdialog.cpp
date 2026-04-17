#include "passdialog.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

PassDialog::PassDialog(QString name, QString birth, QWidget *parent)
    : QDialog(parent) {

    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* nameLabel = new QLabel(name);
    QLabel* birthLabel = new QLabel(birth);
    QLabel* img = new QLabel();

    img->setPixmap(QPixmap(":/img/default.png"));

    QPushButton* printBtn = new QPushButton("Печать");
    QPushButton* cancelBtn = new QPushButton("Отмена");

    layout->addWidget(nameLabel);
    layout->addWidget(birthLabel);
    layout->addWidget(img);
    layout->addWidget(printBtn);
    layout->addWidget(cancelBtn);

    connect(printBtn, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelBtn, &QPushButton::clicked, this, &QDialog::reject);
}
