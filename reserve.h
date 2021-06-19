#ifndef RESERVE_H
#define RESERVE_H

#include <QDialog>
#include"home.h"

namespace Ui {
class reserve;
}

class reserve : public QDialog
{
    Q_OBJECT

public:
    explicit reserve(QWidget *parent = nullptr,QList<mv>*movies=0);
    ~reserve();

private:
    Ui::reserve *ui;
    QList<mv>*movies;

};

#endif // RESERVE_H
