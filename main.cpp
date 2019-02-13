#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    void keyPressEvent(QKeyEvent *ev);
    //w.show();



    return a.exec();
}
