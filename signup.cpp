#include "signup.h"
#include "ui_signup.h"

signup::signup(QWidget *parent,QList<usr>*user) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    this->users=user;
    timer_1s = new QTimer(this);
    connect(timer_1s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    timer_1s->start(100);


}


signup::~signup()
{
    delete ui;
}

void signup::save_to_setting()
{
    QSettings user("mot","prj");
    user.beginWriteArray("logins");
    for(int i=0;i<users->size();i++)
    {
        user.setArrayIndex(i);
        user.setValue("username",users->at(i).username);
        user.setValue("password",users->at(i).password);
    }
    user.endArray();

}

void signup::on_close_clicked()
{
    this->close();
}

void signup::on_back_clicked()
{
    this->hide();
    parentWidget()->show();
}


void signup::on_signup_2_clicked()
{
    QString u= this->ui->lname->text();
        for(int i=0;i<users->size();i++)
       {
          if(users->at(i).username==u  )
              {

               QMessageBox::critical(this," ","sorry,this username is already taken.");
               this->ui->lname->clear();
               this->ui->lpass->clear();
               this->ui->lcpass->clear();
               return;
           }
        }
        if(ui->lpass->text()!=ui->lcpass->text())
        {
            QMessageBox::critical(this,"Confirm password","Passwords do not match!");
            ui->lpass->clear();
            ui->lcpass->clear();
            return;
        }
       usr tmp;
       tmp.username=this->ui->lname->text();
       tmp.password=this->ui->lpass->text();
       users->append(tmp);
       save_to_setting();
       QMessageBox::information(this,"Sign Up","Account created successfully");
       this->hide();
       parentWidget()->show();


}

void signup::UpdateTime()
{
   ui->time->setText(QTime::currentTime().toString("hh:mm:ss"));
}


