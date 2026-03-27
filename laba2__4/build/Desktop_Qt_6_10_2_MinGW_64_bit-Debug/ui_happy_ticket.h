/********************************************************************************
** Form generated from reading UI file 'happy_ticket.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HAPPY_TICKET_H
#define UI_HAPPY_TICKET_H

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

class Ui_happy_ticket
{
public:
    QWidget *centralwidget;
    QLineEdit *numberEdit;
    QLabel *label_4;
    QLabel *label_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *offline;
    QCheckBox *legal_entity;
    QCheckBox *gift;
    QLineEdit *nameEdit;
    QLineEdit *dateEdit;
    QPushButton *reset;
    QPushButton *save;
    QRadioButton *win;
    QLabel *label_2;
    QLabel *label;
    QRadioButton *lose;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *prizeEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *happy_ticket)
    {
        if (happy_ticket->objectName().isEmpty())
            happy_ticket->setObjectName("happy_ticket");
        happy_ticket->resize(511, 600);
        centralwidget = new QWidget(happy_ticket);
        centralwidget->setObjectName("centralwidget");
        numberEdit = new QLineEdit(centralwidget);
        numberEdit->setObjectName("numberEdit");
        numberEdit->setGeometry(QRect(140, 120, 113, 26));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 180, 101, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 210, 121, 20));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(120, 270, 171, 88));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        offline = new QCheckBox(verticalLayoutWidget);
        offline->setObjectName("offline");

        verticalLayout->addWidget(offline);

        legal_entity = new QCheckBox(verticalLayoutWidget);
        legal_entity->setObjectName("legal_entity");

        verticalLayout->addWidget(legal_entity);

        gift = new QCheckBox(verticalLayoutWidget);
        gift->setObjectName("gift");

        verticalLayout->addWidget(gift);

        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setGeometry(QRect(180, 210, 111, 26));
        dateEdit = new QLineEdit(centralwidget);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(100, 150, 113, 26));
        reset = new QPushButton(centralwidget);
        reset->setObjectName("reset");
        reset->setGeometry(QRect(40, 410, 151, 51));
        save = new QPushButton(centralwidget);
        save->setObjectName("save");
        save->setGeometry(QRect(320, 410, 151, 51));
        win = new QRadioButton(centralwidget);
        win->setObjectName("win");
        win->setGeometry(QRect(140, 240, 110, 24));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 240, 81, 20));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 270, 71, 20));
        lose = new QRadioButton(centralwidget);
        lose->setObjectName("lose");
        lose->setGeometry(QRect(220, 240, 110, 24));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 150, 63, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(60, 120, 71, 20));
        prizeEdit = new QLineEdit(centralwidget);
        prizeEdit->setObjectName("prizeEdit");
        prizeEdit->setGeometry(QRect(100, 180, 113, 26));
        happy_ticket->setCentralWidget(centralwidget);
        menubar = new QMenuBar(happy_ticket);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 511, 26));
        happy_ticket->setMenuBar(menubar);
        statusbar = new QStatusBar(happy_ticket);
        statusbar->setObjectName("statusbar");
        happy_ticket->setStatusBar(statusbar);

        retranslateUi(happy_ticket);

        QMetaObject::connectSlotsByName(happy_ticket);
    } // setupUi

    void retranslateUi(QMainWindow *happy_ticket)
    {
        happy_ticket->setWindowTitle(QCoreApplication::translate("happy_ticket", "happy_ticket", nullptr));
        label_4->setText(QCoreApplication::translate("happy_ticket", "\320\237\321\200\320\270\320\267", nullptr));
        label_3->setText(QCoreApplication::translate("happy_ticket", "\320\230\320\274\321\217 \320\277\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\217", nullptr));
        offline->setText(QCoreApplication::translate("happy_ticket", "\320\233\320\270\321\207\320\275\320\276\320\265 \320\277\321\200\320\270\321\201\321\203\321\202\321\201\321\202\320\262\320\270\320\265", nullptr));
        legal_entity->setText(QCoreApplication::translate("happy_ticket", "\320\242\320\276\320\273\321\214\320\272\320\276 \321\216\321\200. \320\273\320\270\321\206\320\260", nullptr));
        gift->setText(QCoreApplication::translate("happy_ticket", "\320\237\320\276\320\264\320\260\321\200\320\276\320\272", nullptr));
        reset->setText(QCoreApplication::translate("happy_ticket", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        save->setText(QCoreApplication::translate("happy_ticket", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        win->setText(QCoreApplication::translate("happy_ticket", "\320\237\320\276\320\261\320\265\320\264\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("happy_ticket", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        label->setText(QCoreApplication::translate("happy_ticket", "\320\243\321\201\320\273\320\276\320\262\320\270\321\217", nullptr));
        lose->setText(QCoreApplication::translate("happy_ticket", "\320\237\320\276\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        label_5->setText(QCoreApplication::translate("happy_ticket", "\320\224\320\260\321\202\320\260", nullptr));
        label_6->setText(QCoreApplication::translate("happy_ticket", "\342\204\226 \320\261\320\270\320\273\320\265\321\202\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class happy_ticket: public Ui_happy_ticket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HAPPY_TICKET_H
