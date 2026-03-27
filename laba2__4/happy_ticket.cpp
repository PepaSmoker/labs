#include "happy_ticket.h"
#include "ui_happy_ticket.h"
#include <QRegularExpression>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "ticket.h"

happy_ticket::happy_ticket(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::happy_ticket)
{
    ui->setupUi(this);
    ui->save->setStyleSheet("background-color: #34C924; color: #000000 ");
    ui->reset->setStyleSheet("background-color: #FF0000; color: #000000");
}

happy_ticket::~happy_ticket()
{
    delete ui;
}

void happy_ticket::on_reset_clicked()
{
    ui->numberEdit->clear();
    ui->dateEdit->clear();
    ui->nameEdit->clear();
    ui->prizeEdit->clear();

    ui->win->setAutoExclusive(false);
    ui->lose->setAutoExclusive(false);
    ui->gift->setAutoExclusive(false);
    ui->legal_entity->setAutoExclusive(false);
    ui->offline->setAutoExclusive(false);

    ui->win->setChecked(false);
    ui->lose->setChecked(false);
    ui->gift->setChecked(false);
    ui->legal_entity->setChecked(false);
    ui->offline->setChecked(false);

    ui->win->setAutoExclusive(true);
    ui->lose->setAutoExclusive(true);
    ui->gift->setAutoExclusive(true);
    ui->legal_entity->setAutoExclusive(true);
    ui->offline->setAutoExclusive(true);
}

void happy_ticket::on_save_clicked()
{
    QString number = ui->numberEdit->text();
    QString date = ui->dateEdit->text();
    QString name = ui->nameEdit->text();
    QString prize = ui->prizeEdit->text();
    QString conditions;
    QString result;

    QRegularExpression numberRegex("^\\d{1}\\-\\d{5}$");
    QRegularExpression dateRegex("^\\d{2}\\.\\d{2}\\.\\d{4}$");
    QRegularExpression prizeRegex("^([A-ZА-ЯЁ][a-zа-яё]+)(\\s[A-ZА-ЯЁ][a-zа-яё]+)*$");
    QRegularExpression nameRegex("^([А-ЯЁ][а-яё]+)$");

    if (number.isEmpty() || date.isEmpty() || name.isEmpty() || prize.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Заполните все обязательные поля!");
        return;
    }

    if (!nameRegex.match(name).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Ошибка в имени");
        return;
    }

    if (!dateRegex.match(date).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Ошибка в дате)");
        return;
    }

    if (!numberRegex.match(number).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Ошибка в номере билета");
        return;
    }

    if (!prizeRegex.match(prize).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Ошибка в названии приза");
        return;
    }

    if (ui->win->isChecked())
    {
        result = "win";
    }
    else
    {
        result = "lose";
    }

    if(ui->gift->isChecked())
    {
        conditions += " Подарок";
    }
    if(ui->legal_entity->isChecked())
    {
        conditions += " Юр. лицо";
    }
    if(ui->offline->isChecked())
    {
        conditions += " Личное присутствие";
    }

    ticket p(number, date, name, prize, conditions, result);
    QFile file("result.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);

        out << "№ билета: " << p.get_number() << "\n";
        out << "дата: " << p.get_date() << "\n";
        out << "приз: " << p.get_prize() << "\n";
        out << "имя покупателя: " << p.get_name() << "\n";
        out << "результат: " << p.get_result() << "\n";
        out << "условия: " << p.get_conditions() << "\n";

        file.close();
    }
}