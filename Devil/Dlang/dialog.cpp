#include "dialog.h"
#include <QDebug>
#include <QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    ui.setupUi(this);
}

void Dialog::on_ok_clicked()
{
    Lang l;
    s = this->ui.line_1->text();
    //qDebug() << "s = " << s ;
    //qDebug() << s;
    std::string tmp = s.toStdString();
    //std::cout << "tmp = " << tmp ;
    l.setString(tmp);

    if(!l.ifLegal()){
        res = "输入有误";
        //qDebug() << "error";
    }else{
        res = QString::fromStdString(l.toNormal());
        //qDebug() << res;
    }
    //qDebug() << "res = " << res ;
    this->ui.line_2->setText(res);
    s.clear();
    res.clear();

}

void Dialog::on_ok_2_clicked()
{
    QMessageBox::about(NULL, "规则说明", "输入规则:\n    用户可输入A、B、a-z以及任意嵌套()。\n"
                                     "转化规则:\n    ①A->tAdA\n    ②A->sae\n    "
                                     "③()内逆序输出并且除e外每个前面加e。") ;
}
