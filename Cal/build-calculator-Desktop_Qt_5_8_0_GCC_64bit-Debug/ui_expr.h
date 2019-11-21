/********************************************************************************
** Form generated from reading UI file 'expr.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPR_H
#define UI_EXPR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_expr
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *lb_display;
    QGridLayout *gridLayout;
    QPushButton *btn_l;
    QPushButton *btn_r;
    QPushButton *btn_div;
    QPushButton *btn_7;
    QPushButton *btn_8;
    QPushButton *btn_9;
    QPushButton *btn_mul;
    QPushButton *btn_4;
    QPushButton *btn_5;
    QPushButton *btn_6;
    QPushButton *btn_sub_2;
    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QPushButton *btn_plus;
    QPushButton *btn_p2;
    QPushButton *btn_0;
    QPushButton *btn_p1;
    QPushButton *btn_equal;
    QPushButton *btn_ac;

    void setupUi(QDialog *expr)
    {
        if (expr->objectName().isEmpty())
            expr->setObjectName(QStringLiteral("expr"));
        expr->setEnabled(true);
        expr->resize(419, 609);
        expr->setMinimumSize(QSize(419, 609));
        expr->setMaximumSize(QSize(419, 609));
        horizontalLayout = new QHBoxLayout(expr);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lb_display = new QLabel(expr);
        lb_display->setObjectName(QStringLiteral("lb_display"));
        QFont font;
        font.setPointSize(50);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        lb_display->setFont(font);
        lb_display->setStyleSheet(QStringLiteral("background-color: rgb(211, 215, 207);"));
        lb_display->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(lb_display);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn_l = new QPushButton(expr);
        btn_l->setObjectName(QStringLiteral("btn_l"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_l->sizePolicy().hasHeightForWidth());
        btn_l->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(25);
        btn_l->setFont(font1);

        gridLayout->addWidget(btn_l, 0, 1, 1, 1);

        btn_r = new QPushButton(expr);
        btn_r->setObjectName(QStringLiteral("btn_r"));
        sizePolicy.setHeightForWidth(btn_r->sizePolicy().hasHeightForWidth());
        btn_r->setSizePolicy(sizePolicy);
        btn_r->setFont(font1);

        gridLayout->addWidget(btn_r, 0, 3, 1, 1);

        btn_div = new QPushButton(expr);
        btn_div->setObjectName(QStringLiteral("btn_div"));
        sizePolicy.setHeightForWidth(btn_div->sizePolicy().hasHeightForWidth());
        btn_div->setSizePolicy(sizePolicy);
        btn_div->setFont(font1);

        gridLayout->addWidget(btn_div, 0, 4, 1, 1);

        btn_7 = new QPushButton(expr);
        btn_7->setObjectName(QStringLiteral("btn_7"));
        sizePolicy.setHeightForWidth(btn_7->sizePolicy().hasHeightForWidth());
        btn_7->setSizePolicy(sizePolicy);
        btn_7->setFont(font1);

        gridLayout->addWidget(btn_7, 1, 0, 1, 1);

        btn_8 = new QPushButton(expr);
        btn_8->setObjectName(QStringLiteral("btn_8"));
        sizePolicy.setHeightForWidth(btn_8->sizePolicy().hasHeightForWidth());
        btn_8->setSizePolicy(sizePolicy);
        btn_8->setFont(font1);

        gridLayout->addWidget(btn_8, 1, 1, 1, 1);

        btn_9 = new QPushButton(expr);
        btn_9->setObjectName(QStringLiteral("btn_9"));
        sizePolicy.setHeightForWidth(btn_9->sizePolicy().hasHeightForWidth());
        btn_9->setSizePolicy(sizePolicy);
        btn_9->setFont(font1);

        gridLayout->addWidget(btn_9, 1, 3, 1, 1);

        btn_mul = new QPushButton(expr);
        btn_mul->setObjectName(QStringLiteral("btn_mul"));
        sizePolicy.setHeightForWidth(btn_mul->sizePolicy().hasHeightForWidth());
        btn_mul->setSizePolicy(sizePolicy);
        btn_mul->setFont(font1);

        gridLayout->addWidget(btn_mul, 1, 4, 1, 1);

        btn_4 = new QPushButton(expr);
        btn_4->setObjectName(QStringLiteral("btn_4"));
        sizePolicy.setHeightForWidth(btn_4->sizePolicy().hasHeightForWidth());
        btn_4->setSizePolicy(sizePolicy);
        btn_4->setFont(font1);

        gridLayout->addWidget(btn_4, 2, 0, 1, 1);

        btn_5 = new QPushButton(expr);
        btn_5->setObjectName(QStringLiteral("btn_5"));
        sizePolicy.setHeightForWidth(btn_5->sizePolicy().hasHeightForWidth());
        btn_5->setSizePolicy(sizePolicy);
        btn_5->setFont(font1);

        gridLayout->addWidget(btn_5, 2, 1, 1, 1);

        btn_6 = new QPushButton(expr);
        btn_6->setObjectName(QStringLiteral("btn_6"));
        sizePolicy.setHeightForWidth(btn_6->sizePolicy().hasHeightForWidth());
        btn_6->setSizePolicy(sizePolicy);
        btn_6->setFont(font1);

        gridLayout->addWidget(btn_6, 2, 3, 1, 1);

        btn_sub_2 = new QPushButton(expr);
        btn_sub_2->setObjectName(QStringLiteral("btn_sub_2"));
        sizePolicy.setHeightForWidth(btn_sub_2->sizePolicy().hasHeightForWidth());
        btn_sub_2->setSizePolicy(sizePolicy);
        btn_sub_2->setFont(font1);

        gridLayout->addWidget(btn_sub_2, 2, 4, 1, 1);

        btn_1 = new QPushButton(expr);
        btn_1->setObjectName(QStringLiteral("btn_1"));
        sizePolicy.setHeightForWidth(btn_1->sizePolicy().hasHeightForWidth());
        btn_1->setSizePolicy(sizePolicy);
        btn_1->setFont(font1);

        gridLayout->addWidget(btn_1, 3, 0, 1, 1);

        btn_2 = new QPushButton(expr);
        btn_2->setObjectName(QStringLiteral("btn_2"));
        sizePolicy.setHeightForWidth(btn_2->sizePolicy().hasHeightForWidth());
        btn_2->setSizePolicy(sizePolicy);
        btn_2->setFont(font1);

        gridLayout->addWidget(btn_2, 3, 1, 1, 1);

        btn_3 = new QPushButton(expr);
        btn_3->setObjectName(QStringLiteral("btn_3"));
        sizePolicy.setHeightForWidth(btn_3->sizePolicy().hasHeightForWidth());
        btn_3->setSizePolicy(sizePolicy);
        btn_3->setFont(font1);

        gridLayout->addWidget(btn_3, 3, 3, 1, 1);

        btn_plus = new QPushButton(expr);
        btn_plus->setObjectName(QStringLiteral("btn_plus"));
        sizePolicy.setHeightForWidth(btn_plus->sizePolicy().hasHeightForWidth());
        btn_plus->setSizePolicy(sizePolicy);
        btn_plus->setFont(font1);

        gridLayout->addWidget(btn_plus, 3, 4, 1, 1);

        btn_p2 = new QPushButton(expr);
        btn_p2->setObjectName(QStringLiteral("btn_p2"));
        sizePolicy.setHeightForWidth(btn_p2->sizePolicy().hasHeightForWidth());
        btn_p2->setSizePolicy(sizePolicy);
        btn_p2->setFont(font1);

        gridLayout->addWidget(btn_p2, 4, 0, 1, 1);

        btn_0 = new QPushButton(expr);
        btn_0->setObjectName(QStringLiteral("btn_0"));
        sizePolicy.setHeightForWidth(btn_0->sizePolicy().hasHeightForWidth());
        btn_0->setSizePolicy(sizePolicy);
        btn_0->setFont(font1);

        gridLayout->addWidget(btn_0, 4, 1, 1, 1);

        btn_p1 = new QPushButton(expr);
        btn_p1->setObjectName(QStringLiteral("btn_p1"));
        sizePolicy.setHeightForWidth(btn_p1->sizePolicy().hasHeightForWidth());
        btn_p1->setSizePolicy(sizePolicy);
        btn_p1->setFont(font1);

        gridLayout->addWidget(btn_p1, 4, 3, 1, 1);

        btn_equal = new QPushButton(expr);
        btn_equal->setObjectName(QStringLiteral("btn_equal"));
        sizePolicy.setHeightForWidth(btn_equal->sizePolicy().hasHeightForWidth());
        btn_equal->setSizePolicy(sizePolicy);
        btn_equal->setFont(font1);

        gridLayout->addWidget(btn_equal, 4, 4, 1, 1);

        btn_ac = new QPushButton(expr);
        btn_ac->setObjectName(QStringLiteral("btn_ac"));
        sizePolicy.setHeightForWidth(btn_ac->sizePolicy().hasHeightForWidth());
        btn_ac->setSizePolicy(sizePolicy);
        btn_ac->setFont(font1);

        gridLayout->addWidget(btn_ac, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 8);

        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(expr);

        QMetaObject::connectSlotsByName(expr);
    } // setupUi

    void retranslateUi(QDialog *expr)
    {
        expr->setWindowTitle(QApplication::translate("expr", "Calculator", Q_NULLPTR));
        lb_display->setText(QApplication::translate("expr", "0", Q_NULLPTR));
        btn_l->setText(QApplication::translate("expr", "(", Q_NULLPTR));
        btn_r->setText(QApplication::translate("expr", ")", Q_NULLPTR));
        btn_div->setText(QApplication::translate("expr", "/", Q_NULLPTR));
        btn_7->setText(QApplication::translate("expr", "7", Q_NULLPTR));
        btn_8->setText(QApplication::translate("expr", "8", Q_NULLPTR));
        btn_9->setText(QApplication::translate("expr", "9", Q_NULLPTR));
        btn_mul->setText(QApplication::translate("expr", "*", Q_NULLPTR));
        btn_4->setText(QApplication::translate("expr", "4", Q_NULLPTR));
        btn_5->setText(QApplication::translate("expr", "5", Q_NULLPTR));
        btn_6->setText(QApplication::translate("expr", "6", Q_NULLPTR));
        btn_sub_2->setText(QApplication::translate("expr", "-", Q_NULLPTR));
        btn_1->setText(QApplication::translate("expr", "1", Q_NULLPTR));
        btn_2->setText(QApplication::translate("expr", "2", Q_NULLPTR));
        btn_3->setText(QApplication::translate("expr", "3", Q_NULLPTR));
        btn_plus->setText(QApplication::translate("expr", "+", Q_NULLPTR));
        btn_p2->setText(QApplication::translate("expr", ".", Q_NULLPTR));
        btn_0->setText(QApplication::translate("expr", "0", Q_NULLPTR));
        btn_p1->setText(QApplication::translate("expr", "<-", Q_NULLPTR));
        btn_equal->setText(QApplication::translate("expr", "=", Q_NULLPTR));
        btn_ac->setText(QApplication::translate("expr", "AC", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class expr: public Ui_expr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPR_H
