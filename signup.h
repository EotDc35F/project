#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include"home.h"

namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr,QList<usr>*users=nullptr);
    ~signup();

private slots:
    void on_close_clicked();

    void on_back_clicked();

    void on_signup_2_clicked();
    void UpdateTime();



private:
    Ui::signup *ui;
    QList<usr>*users;
    void save_to_setting();
    QTimer *timer_1s;
};

#endif // SIGNUP_H
