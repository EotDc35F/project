#include "dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QSettings user;
    int size=user.beginReadArray("logins");
    for(int i=0;i<size;i++)
    {
        usr tp;
        user.setArrayIndex(i);
        tp.username=user.value("username").toString();
        tp.password=user.value("password").toString();
        users.append(tp);
    }
    user.endArray();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_signup_clicked()
{
   usr tmp;
   tmp.username=this->ui->username->text();
   tmp.password=this->ui->password->text();
   users.append(tmp);
   save_to_setting();

}

void Dialog::on_close_clicked()
{
    this->close();
}

void Dialog::on_reload_clicked()
{
    this->ui->username->clear();
    this->ui->password->clear();
}

void Dialog::on_login_clicked()
{

}

void Dialog::save_to_setting()
{
    QSettings user;
    user.beginWriteArray("logins");
    for(int i=0;i<users.size();i++)
    {
        user.setArrayIndex(i);
        user.setValue("username",users.at(i).username);
        user.setValue("password",users.at(i).password);
    }
    user.endArray();

}
