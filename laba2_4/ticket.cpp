#include "ticket.h"
#include "Ticket1.h"
#include "ui_ticket.h"
#include <QRegularExpression>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

Ticket::Ticket(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ticket)
{
    ui->setupUi(this);

    ui->resetButton->setStyleSheet("background-color: red; color: black;");
    ui->save->setStyleSheet("background-color: green; color: black;");
}

Ticket::~Ticket()
{
    delete ui;
}

void Ticket::on_resetButton_clicked()
{
    ui->seatEdit->clear();
    ui->fromEdit->clear();
    ui->toEdit->clear();
    ui->dateEdit->clear();

    ui->no->setAutoExclusive(false);
    ui->yes->setAutoExclusive(false);
    ui->vip->setAutoExclusive(false);
    ui->taxi->setAutoExclusive(false);
    ui->food->setAutoExclusive(false);

    ui->no->setChecked(false);
    ui->yes->setChecked(false);
    ui->vip->setChecked(false);
    ui->taxi->setChecked(false);
    ui->food->setChecked(false);

    ui->no->setAutoExclusive(true);
    ui->yes->setAutoExclusive(true);
    ui->vip->setAutoExclusive(true);
    ui->taxi->setAutoExclusive(true);
    ui->food->setAutoExclusive(true);

}

void Ticket::on_save_clicked()
{
    QString from = ui->fromEdit->text();
    QString to = ui->toEdit->text();
    QString date = ui->dateEdit->text();
    QString seat = ui->seatEdit->text();
    QString extra_luggage;
    QString services;

    QRegularExpression from_to_Regex("^([A-ZА-ЯЁ][a-zа-яё]+)(\\s[A-ZА-ЯЁ][a-zа-яё]+)*$");
    QRegularExpression dateRegex("^\\d{2}\\.\\d{2}\\.\\d{4}/\\d{2}:\\d{2}$");
    QRegularExpression seatRegex("^([1-5][A-D]|([6-9]|[1-2][0-9]|30)[A-F])$");

    if(from.isEmpty() || to.isEmpty() ||  date.isEmpty() || seat.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка", "Заполните все обязательные поля");
        return;
    }
    if(!from_to_Regex.match(from).hasMatch() )
    {
        QMessageBox::warning(this,"Ошибка", "Неверный формат места вылета");
        return;
    }
    if(!from_to_Regex.match(to).hasMatch() )
    {
        QMessageBox::warning(this,"Ошибка", "Неверный формат места прилёта");
        return;
    }
    if(!dateRegex.match(date).hasMatch())
    {
        QMessageBox::warning(this,"Ошибка", "Неверный формат даты");
        return;
    }
    if(!seatRegex.match(seat).hasMatch())
    {
        QMessageBox::warning(this, "Ошибка", "Неверный формат номера кресла");
        return;
    }

    if(ui->yes->isChecked())
    {
        extra_luggage = "yes";
    }
    else
    {
        extra_luggage = "no";
    }

    if(ui->vip->isChecked())
    {
        services += "Vip зал ";
    }
    if(ui->taxi->isChecked())
    {
        services += "Такси ";
    }
    if(ui->food->isChecked())
    {
        services += "Питание ";
    }

    Ticket1 t(from, to, date, seat, extra_luggage, services);

    QFile file("result.txt");
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << "From: " << t.get_from() << "\n";
        out << "To: " << t.get_to() << "\n";
        out << "Date: " << t.get_date() << "\n";
        out << "Seat: " << t.get_seat() << "\n";
        out << "Extra luggage: " << t.get_lugg() << "\n";
        out << "Services: " << t.get_serv() << "\n";

        file.close();
    }
    QMessageBox::information(this, "Успех", "Данные сохранены!");
}