#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    w.show();
    return a.exec();
}
//https://github.com/EotDc35F/project.git//
