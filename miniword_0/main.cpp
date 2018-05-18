#include "mainwindow.h"
#include "hcontrol.h"
#include <QApplication>
#include <QDebug>
#include <QList>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
