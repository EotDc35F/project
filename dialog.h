#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include "classes.h"
#include <QList>
#include <QSettings>
#include "home.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT
QList<usr> users;
public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_signup_clicked();

    void on_close_clicked();

    void on_reload_clicked();

    void on_login_clicked();






private:
    Ui::Dialog *ui;
    home *home;
    void save_to_setting();
    void mousePressEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        int m_nMouseClick_X_Coordinate;
        int m_nMouseClick_Y_Coordinate;
};
#endif // DIALOG_H
