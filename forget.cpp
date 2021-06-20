#include "forget.h"
#include "ui_forget.h"

forget::forget(QWidget *parent,QList<usr>*user) :
    QDialog(parent),
    ui(new Ui::forget)
{
    ui->setupUi(this);
    this->users=user;
}

forget::~forget()
{
    delete ui;
}


void forget::on_back_clicked()
{
    this->hide();
    parentWidget()->show();
}

void forget::on_reset_clicked()
{
    QString s=ui->luser->text();
    for(int i=0;i<users->size();i++)
    {
        if(users->at(i).username==s)
        {

            if(ui->lpass->text()==ui->lcpass->text())
            {
                 (*users)[i].password=ui->lpass->text();
                QMessageBox::information(this,"Reset","Changes applied successfully");
                this->hide();
                parentWidget()->show();

                return;
            }
            else
            {
                QMessageBox::critical(this,"Confirm password","Passwords do not match!");
                ui->lpass->clear();
                ui->lcpass->clear();
                return;
            }
        }

    }
    QMessageBox::critical(this,"Username","There is no account with this username.\nPlease try again or sign up");
    this->ui->luser->clear();
    this->ui->lpass->clear();
    this->ui->lcpass->clear();
}

void forget::on_close_clicked()
{
    this->close();
}
