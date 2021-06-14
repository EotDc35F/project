#ifndef ADD_H
#define ADD_H
#include <QDialog>
#include "classes.h"


namespace Ui {
class Add;
}

class Add : public QDialog
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = nullptr,QDialog *qd=nullptr,QList<mv>*movies=nullptr);
    ~Add();

private slots:

    void on_return_2_clicked();

    void on_cancel_clicked();

    void on_close_clicked();

    void on_add_clicked();

private:
    Ui::Add *ui;
    QDialog * hm;
    QList<mv>*movies;
    QDialog* rhome;


};

#endif // ADD_H
