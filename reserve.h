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
    explicit reserve(QWidget *parent = nullptr,QList<mv>*movies=0,home * home=nullptr);
    ~reserve();

private slots:
    void on_close_clicked();

    void on_back_clicked();

    void on_cancel_clicked();
    void on_reserve_2_clicked();

private:
    Ui::reserve *ui;
    QList<mv>*movies;
    home * home;
    void load_table();
    void destroy_items();
    QList<QTableWidgetItem*> names;
    QList<QTableWidgetItem*> valences;

};

#endif // RESERVE_H
