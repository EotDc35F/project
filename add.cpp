#include "add.h"
#include "ui_add.h"


Add::Add(QWidget *parent,QDialog *qd,QList<mv> *movies) :
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
    this->movies=movies;
    this->rhome=qd;
}

Add::~Add()
{
    delete ui;
}

void Add::on_return_2_clicked()
{
    this->hide();
    rhome->show();


}

void Add::on_cancel_clicked()
{
    this->ui->ldirector->clear();
    this->ui->limdb->clear();
    this->ui->llanguage->clear();
    this->ui->lname->clear();
    this->ui->lstars->clear();
    this->ui->lreleas->clear();
}

void Add::on_close_clicked()
{
    this->close();
}

void Add::on_add_clicked()
{
    mv tmp;
    tmp.name=this->ui->lname->text();
    tmp.director=this->ui->ldirector->text();
    tmp.stars=this->ui->lstars->text();
    tmp.release_year=this->ui->lreleas->text();
    tmp.language=this->ui->llanguage->text();
    tmp.imdb=this->ui->limdb->text();
    tmp.valence="30";
    tmp.genre=this->ui->genre->currentText();
    movies->append(tmp);
//    rhome->load_table(movies);
   this->hide();
   rhome->show();


}
