#include "mainwindow.h"

#include <QApplication>
#include <QFontDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFontDatabase::addApplicationFont(":/fonts/Daggersquare.ttf");
   //Vérification du chargement de la police
    /*QFontDatabase db;
      for(int i=0; i<db.families().size(); i++)
      {
        qDebug() << db.families().at(i);
      }*/
    MainWindow w;
    w.showMaximized();
    return a.exec();
}
