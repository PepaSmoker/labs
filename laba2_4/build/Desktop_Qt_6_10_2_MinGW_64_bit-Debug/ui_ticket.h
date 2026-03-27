/********************************************************************************
** Form generated from reading UI file 'ticket.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKET_H
#define UI_TICKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ticket
{
public:
    QWidget *centralwidget;
    QPushButton *resetButton;
    QPushButton *save;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *food;
    QCheckBox *taxi;
    QCheckBox *vip;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *fromEdit;
    QLineEdit *toEdit;
    QLineEdit *dateEdit;
    QLineEdit *seatEdit;
    QRadioButton *yes;
    QRadioButton *no;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Ticket)
    {
        if (Ticket->objectName().isEmpty())
            Ticket->setObjectName("Ticket");
        Ticket->resize(553, 600);
        centralwidget = new QWidget(Ticket);
        centralwidget->setObjectName("centralwidget");
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(60, 400, 151, 51));
        save = new QPushButton(centralwidget);
        save->setObjectName("save");
        save->setGeometry(QRect(340, 400, 151, 51));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(220, 260, 101, 88));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        food = new QCheckBox(verticalLayoutWidget);
        food->setObjectName("food");

        verticalLayout->addWidget(food);

        taxi = new QCheckBox(verticalLayoutWidget);
        taxi->setObjectName("taxi");

        verticalLayout->addWidget(taxi);

        vip = new QCheckBox(verticalLayoutWidget);
        vip->setObjectName("vip");

        verticalLayout->addWidget(vip);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 260, 71, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 230, 81, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 200, 63, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 170, 101, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(160, 140, 63, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(160, 110, 63, 20));
        fromEdit = new QLineEdit(centralwidget);
        fromEdit->setObjectName("fromEdit");
        fromEdit->setGeometry(QRect(220, 110, 113, 26));
        toEdit = new QLineEdit(centralwidget);
        toEdit->setObjectName("toEdit");
        toEdit->setGeometry(QRect(220, 140, 113, 26));
        dateEdit = new QLineEdit(centralwidget);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(260, 170, 113, 26));
        seatEdit = new QLineEdit(centralwidget);
        seatEdit->setObjectName("seatEdit");
        seatEdit->setGeometry(QRect(210, 200, 51, 26));
        yes = new QRadioButton(centralwidget);
        yes->setObjectName("yes");
        yes->setGeometry(QRect(240, 230, 110, 24));
        no = new QRadioButton(centralwidget);
        no->setObjectName("no");
        no->setGeometry(QRect(290, 230, 110, 24));
        Ticket->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Ticket);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 553, 26));
        Ticket->setMenuBar(menubar);
        statusbar = new QStatusBar(Ticket);
        statusbar->setObjectName("statusbar");
        Ticket->setStatusBar(statusbar);

        retranslateUi(Ticket);

        QMetaObject::connectSlotsByName(Ticket);
    } // setupUi

    void retranslateUi(QMainWindow *Ticket)
    {
        Ticket->setWindowTitle(QCoreApplication::translate("Ticket", "Ticket", nullptr));
        resetButton->setText(QCoreApplication::translate("Ticket", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        save->setText(QCoreApplication::translate("Ticket", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        food->setText(QCoreApplication::translate("Ticket", "\320\237\320\270\321\202\320\260\320\275\320\270\320\265", nullptr));
        taxi->setText(QCoreApplication::translate("Ticket", "\320\242\320\260\320\272\321\201\320\270", nullptr));
        vip->setText(QCoreApplication::translate("Ticket", "VIP \320\267\320\260\320\273", nullptr));
        label->setText(QCoreApplication::translate("Ticket", "\320\243\321\201\320\273\321\203\320\263\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("Ticket", "\320\224\320\276\320\277. \321\203\321\201\320\273\321\203\320\263\320\270", nullptr));
        label_3->setText(QCoreApplication::translate("Ticket", "\320\234\320\265\321\201\321\202\320\276", nullptr));
        label_4->setText(QCoreApplication::translate("Ticket", "\320\224\320\260\321\202\320\260 \320\270 \320\262\321\200\320\265\320\274\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("Ticket", "\320\232\321\203\320\264\320\260", nullptr));
        label_6->setText(QCoreApplication::translate("Ticket", "\320\236\321\202\320\272\321\203\320\264\320\260", nullptr));
        yes->setText(QCoreApplication::translate("Ticket", "\320\224\320\260", nullptr));
        no->setText(QCoreApplication::translate("Ticket", "\320\235\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ticket: public Ui_Ticket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKET_H
