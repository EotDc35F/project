#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
#include"home.h"
#include "QObjectList"

namespace Ui {
class edit;
}

class edit : public QDialog
{
    Q_OBJECT

public:
    explicit edit(QWidget *parent = nullptr,QList<mv>*movies=0,class home*hm=nullptr,QString * name=nullptr,int index=0);
    ~edit();

private slots:


    void on_close_clicked();

    void load();

    void on_edit_2_clicked();

    void on_cancel_clicked();

    void on_back_clicked();

private:
    Ui::edit *ui;
    QList<mv>*movies;
    home *home;
    QString * name;
    int index;
    void mousePressEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        int m_nMouseClick_X_Coordinate;
        int m_nMouseClick_Y_Coordinate;
};

#endif // EDIT_H
