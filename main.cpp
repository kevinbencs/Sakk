#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //QSplashScreen* splash=new QSplashScreen;
    //splash->setPixmap(QPixmap("Gui/Chess1.jpg"));
    //splash->show();

    MainWindow w;

    //QTimer::singleShot(2600,splash,SLOT(close()));
    //QTimer::singleShot(2600,&w,SLOT(show()));
    w.show();
    return a.exec();
}
