#include "reserve.h"
#include "ui_reserve.h"

reserve::reserve(QWidget *parent,QList<mv>*mv, class home*hm) :
    QDialog(parent),
    ui(new Ui::reserve)
{
    ui->setupUi(this);
    this->movies=mv;
    load_table();
    this->home=hm;
}

reserve::~reserve()
{
    delete ui;
}

void reserve::on_close_clicked()
{
    this->close();
}

void reserve::on_back_clicked()
{
    this->hide();
    parentWidget()->show();
}

void reserve::load_table()
{
    destroy_items();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(movies->size());
    for(int i=0;i<movies->size();i++)
    {
        QTableWidgetItem* name = new QTableWidgetItem;
        QTableWidgetItem*valence =new QTableWidgetItem;

        name->setText(movies->at(i).name);
         name->setTextAlignment(Qt::AlignCenter);
        valence->setText(movies->at(i).valence);
         valence->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i,0,name);
        ui->tableWidget->setItem(i,1,valence);
        names.append(name);
        valences.append(valence);
    }
}

void reserve::destroy_items()
{
    for(int i=0;i<names.size();i++)
    {
        delete names[i];
        delete valences[i];

    }
     names.clear();
     valences.clear();

}


void reserve::on_cancel_clicked()
{
    this->ui->lname->clear();
   this->ui->number->setValue(0);
}


void reserve::on_reserve_2_clicked()
{
    QString name=this->ui->lname->text();
        bool find=false;
        int index=0;
        for(int i=0;i<movies->size();i++)
        {
            if(movies->at(i).name==name)
            {
              find=true;
               index=i;
               break;
            }
        }
        if(!find)
           {
            QMessageBox::warning(this,"Edit","There is no movie with this name!\nPlease try again");
            this->ui->lname->clear();
            return;
        }
       int a= movies->at(index).valence.toInt()-ui->number->value();
        if(a>0)
        {
            (*movies)[index].valence=QString::number(a);
            QMessageBox::information(this,"Reserve","Successfully reserved");

            this->ui->lname->clear();
           this->ui->number->setValue(0);
             load_table();
            home->load_table(movies);

        }
        else

            QMessageBox::critical(this,"Reserve","You can not book this movie with this amount.\nCheck the valence of the movie and try again");


}
