#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include "timer.h"
#include "end.h"
#include "custom.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

     void loadStyle(QString filename = ":/style/style.css", QString variablesFilename = ":/style/styledef");

private slots:
     void on_customButton_clicked();

     void on_tirCompteButton_clicked();


private:
    Ui::MainWindow *ui;
    Custom *m_custom;
    Timer *m_timer;
    End *m_end;

};
#endif // MAINWINDOW_H
