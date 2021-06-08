#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
//    usr admin;
//    admin.username="admin";
//   admin.password="admin";
//    users.append(admin);
    QSettings user("mot","idk");
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
   home=new class home(this);
   this->hide();
   home->show();

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
   QString u= this->ui->username->text();
   QString p= this->ui->password->text();
   for(int i=0;i<users.size();i++)
   {
       if(users.at(i).username==u && users.at(i).password==p )
       {
               home=new class home(this);
               this->hide();
               home->show();
               break;
       }
      QMessageBox::warning(this,"LOG IN","WRONG");


   }
}

void Dialog::save_to_setting()
{
    QSettings user("mot","idk");
    user.beginWriteArray("logins");
    for(int i=0;i<users.size();i++)
    {
        user.setArrayIndex(i);
        user.setValue("username",users.at(i).username);
        user.setValue("password",users.at(i).password);
    }
    user.endArray();

}




