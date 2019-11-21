/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *ok;
    QPushButton *ok_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *line_1;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *line_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(791, 551);
        Dialog->setStyleSheet(QString::fromUtf8("image: url(:/\345\233\276\347\211\207/\350\247\206\351\242\221/devil.jpeg);"));
        ok = new QPushButton(Dialog);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(250, 350, 101, 31));
        ok->setSizeIncrement(QSize(0, 0));
        ok_2 = new QPushButton(Dialog);
        ok_2->setObjectName(QStringLiteral("ok_2"));
        ok_2->setGeometry(QRect(440, 350, 101, 31));
        ok_2->setSizeIncrement(QSize(0, 0));
        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(220, 200, 341, 100));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(85, 87, 83);"));

        horizontalLayout->addWidget(label);

        line_1 = new QLineEdit(widget);
        line_1->setObjectName(QStringLiteral("line_1"));

        horizontalLayout->addWidget(line_1);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: rgb(85, 87, 83);"));

        horizontalLayout_2->addWidget(label_3);

        line_2 = new QLineEdit(widget);
        line_2->setObjectName(QStringLiteral("line_2"));

        horizontalLayout_2->addWidget(line_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        ok->setText(QApplication::translate("Dialog", "\350\247\243\351\207\212", Q_NULLPTR));
        ok_2->setText(QApplication::translate("Dialog", "\350\247\204\345\210\231\350\257\264\346\230\216", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "\351\255\224\347\216\213\350\257\264:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "\346\204\217\346\200\235\346\230\257:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
