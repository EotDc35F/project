#include "reserve.h"
#include "ui_reserve.h"

reserve::reserve(QWidget *parent,QList<mv>*mv) :
    QDialog(parent),
    ui(new Ui::reserve)
{
    ui->setupUi(this);
    this->movies=mv;
}

reserve::~reserve()
{
    delete ui;
}
