#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    save_to_list();
    timer_1s = new QTimer(this);
    connect(timer_1s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    timer_1s->start(100);

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_signup_clicked()
{
    signup=new class signup(this,&users);
    signup->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    this->hide();
    signup->show();

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
    bool find=false;
   QString u= this->ui->username->text();
   QString p= this->ui->password->text();
   for(int i=0;i<users.size();i++)
   {
       if(users.at(i).username==u && users.at(i).password==p )
       {
               find=true;
               home=new class home(this);
               this->hide();
               home->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
               home->show();
               break;
       }
   }
   if(!find)
     {

       QMessageBox::critical(this," ","There was a problem logging in. Check your username and password or create an account.");
       this->ui->username->clear();
       this->ui->password->clear();
   }
}

void Dialog::UpdateTime()
{
  ui->time-> setText(QTime::currentTime().toString("hh:mm:ss"));
}

void Dialog::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void Dialog::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}






void Dialog::on_commandLinkButton_clicked()
{
   forget=new class forget(this,&users);
    forget->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
   this->hide();
    forget->show();
}

void Dialog::save_to_list()
{
    QSettings user("mot","prj");
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
