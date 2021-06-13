#include "add.h"
#include "ui_add.h"

Add::Add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
}

Add::~Add()
{
    delete ui;
}

void Add::on_reload_clicked()
{
    this->ui->director->clear();
    this->ui->imdb->clear();
    this->ui->language->clear();
    this->ui->name->clear();
    this->ui->stars->clear();
    this->ui->releas->clear();
}
void Add::on_return_2_clicked()
{
    parentWidget()->show();
    this->close();

}
