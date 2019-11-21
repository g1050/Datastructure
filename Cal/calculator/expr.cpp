#include "expr.h"
#include <QDebug>
expr::expr(QWidget *parent) :
    QDialog(parent)
{
    ui.setupUi(this);
    this->tmp = "";
}

void expr::on_btn_1_clicked()
{
    this->tmp += this->ui.btn_1->text();
    this->ui.lb_display->setText(this->tmp);
}

void expr::on_btn_2_clicked()
{
    this->tmp += this->ui.btn_2->text();
    this->ui.lb_display->setText(this->tmp);
}

void expr::on_btn_3_clicked()
{
    this->tmp += this->ui.btn_3->text();
    this->ui.lb_display->setText(this->tmp);
}

void expr::on_btn_4_clicked()
{
    this->tmp += this->ui.btn_4->text();
    this->ui.lb_display->setText(this->tmp);
}

void expr::on_btn_5_clicked()
{
    this->tmp += this->ui.btn_5->text();
    this->ui.lb_display->setText(this->tmp);
}

void expr::on_btn_6_clicked()
{
    this->tmp += this->ui.btn_6->text();
    this->ui.lb_display->setText(this->tmp);
}

void expr::on_btn_7_clicked()
{
    this->tmp += this->ui.btn_7->text();
    this->ui.lb_display->setText(this->tmp);
}

void expr::on_btn_8_clicked()
{
    this->tmp += this->ui.btn_8->text();
    this->ui.lb_display->setText(this->tmp);
}

void expr::on_btn_9_clicked()
{
    this->tmp += this->ui.btn_9->text();
    this->ui.lb_display->setText(this->tmp);
}

void expr::on_btn_0_clicked()
{
    if(tmp != ""){
        this->tmp += this->ui.btn_0->text();
        this->ui.lb_display->setText(this->tmp);
    }

}

void expr::on_btn_p2_clicked()
{
    if(tmp != ""){
        this->tmp += this->ui.btn_p2->text();
        this->ui.lb_display->setText(this->tmp);
    }
}

void expr::on_btn_p1_clicked()
{
    if(tmp != ""){
        this->tmp = tmp.left(tmp.length()-1);
        this->ui.lb_display->setText(this->tmp);
    }
}

void expr::on_btn_div_clicked()
{
    if(tmp != ""){
        this->tmp += this->ui.btn_div->text();
        this->ui.lb_display->setText(this->tmp);
    }
}

void expr::on_btn_mul_clicked()
{
    if(tmp != ""){
        this->tmp += this->ui.btn_mul->text();
        this->ui.lb_display->setText(this->tmp);
    }
}

void expr::on_btn_sub_2_clicked()
{
    if(tmp != ""){
        this->tmp += this->ui.btn_sub_2->text();
        this->ui.lb_display->setText(this->tmp);
    }
}

void expr::on_btn_plus_clicked()
{
    if(tmp != ""){
        this->tmp += this->ui.btn_plus->text();
        this->ui.lb_display->setText(this->tmp);
    }
}

void expr::on_btn_l_clicked()
{
    this->tmp += this->ui.btn_l->text();
    this->ui.lb_display->setText(this->tmp);
}

void expr::on_btn_r_clicked()
{
    this->tmp += this->ui.btn_r->text();
    this->ui.lb_display->setText(this->tmp);
}

void expr::on_btn_ac_clicked()
{
    tmp = "";
    this->ui.lb_display->setText(this->tmp);
}

void expr::on_btn_equal_clicked()
{
    QString res;
    //std::cout << tmp.toStdString() << endl ;
    cal c = cal(tmp.toStdString());
    if(!c.ifLegal()){
        res = "Error";

    }else{
        c.toPostfix();
        //std::cout << c.getValue() << endl;
        res = res.number(c.getValue());
        //QDebug() << tmp;
        this->ui.lb_display->setText(res);
    }
    this->ui.lb_display->setText(res);
}
