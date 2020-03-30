/****************************************
 *                                      *
 * Author : Erwan BARBIER               *
 * Project : ArcheryTimer               *
 * Date :26/03/2020                     *
 *                                      *
 * www.maomaker.wordpress.com           *
 *                                      *
 * **************************************/

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
#include "keyenterreceiver.h"


namespace Ui {
class Timer;
}

class Timer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Timer(QWidget *parent=nullptr);
    ~Timer();
    void timerTC(bool mode,QVector<int> params);



private slots:
    void on_timerTC();
    void on_timerDuel();
    void on_resetTimer();
    void keyEnterPressed();
    void keyEscapePressed();

private:
    Ui::Timer *ui;
    QTimer *timer;
    End *m_endView;
    bool m_mode;
    int m_phase;
    QVector<int> m_params;
    QVector<int> m_previousParams;
    QGraphicsDropShadowEffect *timerLabelTextShadowEffect;
    keyEnterReceiver *m_key;


};

#endif // TIMER_H
