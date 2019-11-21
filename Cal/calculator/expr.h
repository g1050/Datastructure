#ifndef EXPR_H
#define EXPR_H

#include "ui_expr.h"
#include "model.h"
#include "cal.h"

class expr : public QDialog
{
    Q_OBJECT

public:
    explicit expr(QWidget *parent = 0);

private slots:
    void on_btn_1_clicked();

    void on_btn_2_clicked();

    void on_btn_3_clicked();

    void on_btn_4_clicked();

    void on_btn_5_clicked();

    void on_btn_6_clicked();

    void on_btn_7_clicked();

    void on_btn_8_clicked();

    void on_btn_9_clicked();

    void on_btn_0_clicked();

    void on_btn_p2_clicked();

    void on_btn_p1_clicked();

    void on_btn_div_clicked();

    void on_btn_mul_clicked();

    void on_btn_sub_2_clicked();

    void on_btn_plus_clicked();

    void on_btn_l_clicked();

    void on_btn_r_clicked();

    void on_btn_ac_clicked();

    void on_btn_equal_clicked();

private:
    QString tmp;
    Ui::expr ui;
    model * mod;
};

#endif // EXPR_H
