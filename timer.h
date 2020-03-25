#ifndef TIMER_H
#define TIMER_H

#include <QMainWindow>
#include <QVector>
#include <QLabel>
#include <QTimer>
#include <QSound>
#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include "end.h"


namespace Ui {
class Timer;
}

class Timer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Timer(int mode, QVector<int> params,QWidget *home,QWidget *parent=nullptr);
    ~Timer();
    bool timerTC();



private slots:
    void on_timerTC();
    void on_timerDuel();
    void on_timerCustom();

private:
    Ui::Timer *ui;
    QTimer *timer;
    QWidget *m_home;
    int m_mode;
    int m_phase;
    QVector<int> m_params;
    QVector<int>m_paramsTC={10,5,3};
    QVector<int>m_paramsDuel={10,90,30};
    QGraphicsDropShadowEffect *timerLabelTextShadowEffect;


};

#endif // TIMER_H
