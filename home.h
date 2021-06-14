#ifndef HOME_H
#define HOME_H
#include <QDialog>
#include "add.h"


namespace Ui {
class home;
}

class home : public QDialog
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr);
    ~home();
    void load_table(QList<mv>*movies);

private slots:

    void on_close_clicked();

    void on_add_clicked();

private:
    Ui::home *ui;
  class Add * add;
    QList<mv> movies;
    QList<QTableWidgetItem*> directors;
    QList<QTableWidgetItem*> qstars;
    QList<QTableWidgetItem*> release_years;
    QList<QTableWidgetItem*> languages;
    QList<QTableWidgetItem*> genres;
    QList<QTableWidgetItem*> names;
    QList<QTableWidgetItem*> valences;
    QList<QTableWidgetItem*> imdbs;
    void save_to_setting();
    void save_to_list();
    void destroy_items();
};

#endif // HOME_H
