#ifndef HOME_H
#define HOME_H
#include <QDialog>
#include "classes.h"


namespace Ui {
class home;
}

class home : public QDialog
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr);
    ~home();

private:
    Ui::home *ui;
    QList<mv> movies;
    void save_to_setting();
};

#endif // HOME_H
