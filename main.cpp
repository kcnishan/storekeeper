#include "storekeeper.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen * splash =new QSplashScreen;
    splash->setPixmap(QPixmap("ssss.JPG"));
    splash->show();

    StoreKeeper w;
    QTimer::singleShot(3500,splash,SLOT(close()));
    QTimer::singleShot(3500,&w,SLOT(show()));
    //w.show();


    return a.exec();
}
