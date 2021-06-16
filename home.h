#ifndef HOME_H
#define HOME_H
#include <QDialog>
#include "add.h"
#include"edit.h"


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

    void on_edit_clicked();

    void on_back_clicked();

    void on_remove_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::home *ui;
   class Add * add;
     class edit * edit;
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
