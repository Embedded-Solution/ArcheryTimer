#include "timer.h"
#include "ui_timer.h"
#include <QPainter>
#include <QDebug>

Timer::Timer(int mode, QVector<int> params, QWidget *home, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Timer)
  ,m_home(home)
  ,m_mode(mode)
  ,m_params(params)


{
    ui->setupUi(this);
    timerLabelTextShadowEffect = new QGraphicsDropShadowEffect(this);
    timerLabelTextShadowEffect->setColor(QColor("#C56800"));
    timerLabelTextShadowEffect->setBlurRadius(10);
    timerLabelTextShadowEffect->setOffset(20, 20);
    ui->timerLabel->setGraphicsEffect(timerLabelTextShadowEffect );

    ui-> timerLabel->setStyleSheet(".timer{ font-size : 500px;color : white;font-family: 'DAGGERSQUARE';}");
    this->setStyleSheet(".timerWindow{ background-color : #EB7D00;}");
    //timer pour rafraichir le label du timer toutes les secondes
    timer = new QTimer(this);

}

Timer::~Timer()
{
    delete ui;
}

bool Timer::timerTC()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timerTC()));
    m_phase=3;
    timer->start(300);
    this->showMaximized();
    //play double bip
    QSound::play(":/sounds/doubleBip.mp3");

}

void Timer::on_timerTC()
{
    int total=0;
    switch (m_phase)
    {
    case 3:
        ui->timerLabel->setText(QString::number(m_paramsTC[0]));
        m_paramsTC[0]--;
        if (m_paramsTC[0]==-1)
            m_phase--;
        //play simple bip

        break;

    case 2:
        total=m_paramsTC[1]+m_paramsTC[2];
        if (m_paramsTC[0]==-1)
        {
            //change color green
            this->setStyleSheet(".timerWindow{ background-color : #09CB36;}");
            timerLabelTextShadowEffect->setColor(QColor("#07AA2D"));
            ui->timerLabel->setGraphicsEffect(timerLabelTextShadowEffect );
            m_paramsTC[0]--;
        }

        if (m_paramsTC[1]==0)
        {
            this->setStyleSheet(".timerWindow{ background-color : red;}");
            timerLabelTextShadowEffect->setColor(QColor("#07AA2D"));
            ui->timerLabel->setGraphicsEffect(timerLabelTextShadowEffect );
        }

        ui->timerLabel->setText(QString::number(total));
        m_paramsTC[1]--;

        if (total==0)
        {
            m_phase--;
            qDebug()<<"phase="<<m_phase;

            //play final sound
        }
        break;

    case 1:
        timer->stop();
        qDebug()<<"ouverture";
        //affichage fenêtre end


        break;

    }

}

void Timer::on_timerDuel()
{

}

void Timer::on_timerCustom()
{

}
