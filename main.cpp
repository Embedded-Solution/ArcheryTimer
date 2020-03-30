/****************************************
 *                                      *
 * Author : Erwan BARBIER               *
 * Project : ArcheryTimer               *
 * Date :26/03/2020                     *
 *                                      *
 * www.maomaker.wordpress.com           *
 *                                      *
 * **************************************/

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
    w.showFullScreen();
    return a.exec();
}
