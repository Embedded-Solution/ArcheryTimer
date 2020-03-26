#include "timer.h"
#include "ui_timer.h"
#include <QPainter>
#include <QDebug>

Timer::Timer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Timer)
{
    ui->setupUi(this);
    timerLabelTextShadowEffect = new QGraphicsDropShadowEffect(this);
    timerLabelTextShadowEffect->setColor(QColor("#C56800"));
    timerLabelTextShadowEffect->setBlurRadius(10);
    timerLabelTextShadowEffect->setOffset(20, 20);
    ui->timerLabel->setGraphicsEffect(timerLabelTextShadowEffect );
    ui-> timerLabel->setStyleSheet(".timer{ font-size : 500px;color : white;font-family: 'DAGGERSQUARE';}");

    //timer pour rafraichir le label du timer toutes les secondes
    timer = new QTimer(this);
    //Vue à la fin du timer pour relancer ou retour menu
    m_endView=new End(this);
    //connecte le signal reset
    connect(m_endView,SIGNAL(resetTimer()),this,SLOT(on_resetTimer()));
}

Timer::~Timer()
{
    delete ui;
}

void Timer::timerTC(bool mode,QVector<int> params)
{
    m_mode=mode;
    m_params=params;
    m_previousParams=params;
    on_resetTimer();
}

void Timer::on_resetTimer()
{
    if (m_mode)
        connect(timer, SIGNAL(timeout()), this, SLOT(on_timerDuel()));
    else
        connect(timer, SIGNAL(timeout()), this, SLOT(on_timerTC()));

    //couleur orange intitiale
    timerLabelTextShadowEffect->setColor(QColor("#C56800"));
    ui->timerLabel->setGraphicsEffect(timerLabelTextShadowEffect );
    this->setStyleSheet(".timerWindow{ background-color : #EB7D00;}");
    m_params=m_previousParams;
    m_phase=3;

    ui->timerLabel->setText(QString::number(m_params[0]));
    showMaximized();
    //play double bip
    QSound::play(":/sounds/doubleBip.wav");
    timer->start(1000);

}

void Timer::on_timerTC()
{
    int total=0;
    switch (m_phase)
    {
    case 3:
        ui->timerLabel->setText(QString::number(m_params[0]));
        m_params[0]--;

        //play simple bip
        if (m_params[0]==0)
            QSound::play(":/sounds/simpleBip.wav");

        //next phase
        if (m_params[0]==-1)
            m_phase--;
        break;

    case 2:
        total=m_params[1]+m_params[2];
        if (m_params[0]==-1)
        {
            //change color green
            this->setStyleSheet(".timerWindow{ background-color : #09CB36;}");
            timerLabelTextShadowEffect->setColor(QColor("#07AA2D"));
            ui->timerLabel->setGraphicsEffect(timerLabelTextShadowEffect );
            m_params[0]--;
        }

        if (m_params[1]==0)
        {
            this->setStyleSheet(".timerWindow{ background-color : #EB0000;}");
            timerLabelTextShadowEffect->setColor(QColor("#C50000"));
            ui->timerLabel->setGraphicsEffect(timerLabelTextShadowEffect );
        }

        ui->timerLabel->setText(QString::number(total));
        m_params[1]--;

        if (total==4)
        {
            //play final sound
            QSound::play(":/sounds/finalBip.wav");
        }

        if (total==0)
            m_phase--;
        break;

    case 1:
        //disconenct timer
        timer->disconnect();
        this->hide();
        //show next/menu page
        m_endView->show();
        break;

    }

}


void Timer::on_timerDuel()
{

    switch (m_phase)
    {
    case 3:
        ui->timerLabel->setText(QString::number(m_params[0]));
        m_params[0]--;
        if (m_params[0]==-1)
        {
            m_phase--;
            //play simple bip
            QSound::play(":/sounds/simpleBip.wav");
        }
        break;

    case 2:
        if (m_params[0]==-1)
        {
            //change color green
            this->setStyleSheet(".timerWindow{ background-color : #09CB36;}");
            timerLabelTextShadowEffect->setColor(QColor("#07AA2D"));
            ui->timerLabel->setGraphicsEffect(timerLabelTextShadowEffect );
            m_params[0]--;
        }

        ui->timerLabel->setText(QString::number(m_params[1]));
        m_params[1]--;

        if (m_params[1]==1)
        {
            //play final sound
            QSound::play(":/sounds/finalBip.wav");
        }

        if (m_params[1]==-1)//quand le chrono est fini
        {

            //on redemarre le chrono
            m_params[1]=m_previousParams[1];
            //on décrémente le nombre de reps
            m_params[2]--;
        }

        if (m_params[2]==0)
            m_phase--;
        break;

    case 1:
        timer->disconnect();
        this->hide();

        m_endView->show();
        break;

    }

}
