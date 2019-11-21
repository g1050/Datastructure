#ifndef DIALOG_H
#define DIALOG_H

#include <QString>
#include "ui_dialog.h"
#include "lang.h"
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);

private slots:
    void on_ok_clicked();

    void on_ok_2_clicked();

private:
    Ui::Dialog ui;
    QString s;
    QString res;
};

#endif // DIALOG_H
