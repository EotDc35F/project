#ifndef FORGET_H
#define FORGET_H

#include <QDialog>
#include "home.h"

namespace Ui {
class forget;
}

class forget : public QDialog
{
    Q_OBJECT

public:
    explicit forget(QWidget *parent = nullptr,QList<usr>*users=nullptr);
    ~forget();

private slots:

    void on_back_clicked();

    void on_reset_clicked();

    void on_close_clicked();
    void UpdateTime();

private:
    Ui::forget *ui;
    QList<usr>*users;
    QTimer *timer_1s;
};

#endif // FORGET_H
