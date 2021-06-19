#ifndef ADD_H
#define ADD_H
#include <QDialog>
#include"classes.h"
#include "home.h"
#include <QObjectList>




namespace Ui {
class Add;
}

class Add : public QDialog
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = nullptr,QList<mv>*movies=0,class home*hm=nullptr);
    ~Add();

private slots:

    void on_return_2_clicked();

   void on_cancel_clicked();

    void on_close_clicked();

    void on_add_clicked();

private:
    Ui::Add *ui;

    QList<mv>*movies;
    home *home;
    void mousePressEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        int m_nMouseClick_X_Coordinate;
        int m_nMouseClick_Y_Coordinate;


};

#endif // ADD_H
