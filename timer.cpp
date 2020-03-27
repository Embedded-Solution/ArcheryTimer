#include "timer.h"
#include "ui_timer.h"
#include <QPainter>
#include <QDebug>

Timer::Timer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Timer)
{
    ui->setupUi(this);

    //3D label timer effect
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

    //Install key event filter
    m_key=new keyEnterReceiver();
    this->installEventFilter(m_key);
    //ENTER=PAUSE
    connect(m_key,SIGNAL(keyEnterIsPressed()),this,SLOT(keyEnterPressed()));
    //ESCAPE= Back to home
    connect(m_key,SIGNAL(keyEscapeIsPressed()),this,SLOT(keyEscapePressed()));
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
    //init orange color
    timerLabelTextShadowEffect->setColor(QColor("#C56800"));
    ui->timerLabel->setGraphicsEffect(timerLabelTextShadowEffect );
    this->setStyleSheet(".timerWindow{ background-color : #EB7D00;}");

    //init value timer label
    ui->timerLabel->setText(QString::number(m_params[0]));

    showFullScreen();
    parentWidget()->hide();
    m_params=m_previousParams;
    m_phase=3;

    //select timer depending on mode
    if (m_mode)
        connect(timer, SIGNAL(timeout()), this, SLOT(on_timerDuel()));
    else
        connect(timer, SIGNAL(timeout()), this, SLOT(on_timerTC()));

    //play double bip
    QSound::play(":/sounds/doubleBip.wav");

    //start timer
    timer->start(1000);

}

void Timer::on_timerTC()
{
    int total=0;

    switch (m_phase)
    {
    case 3: //preparation phase
        //print timer label value
        ui->timerLabel->setText(QString::number(m_params[0]));
        m_params[0]--;

        //play simple bip
        if (m_params[0]==0)
            QSound::play(":/sounds/simpleBip.wav");

        //next phase
        if (m_params[0]==-1)
            m_phase--;
        break;

    case 2: //orange + red phase
        total=m_params[1]+m_params[2];
        //change to green color
        if (m_params[0]==-1)
        {
            this->setStyleSheet(".timerWindow{ background-color : #09CB36;}");
            timerLabelTextShadowEffect->setColor(QColor("#07AA2D"));
            ui->timerLabel->setGraphicsEffect(timerLabelTextShadowEffect );
            m_params[0]--;
        }

        //change to red color
        if (m_params[1]==0)
        {
            this->setStyleSheet(".timerWindow{ background-color : #EB0000;}");
            timerLabelTextShadowEffect->setColor(QColor("#C50000"));
            ui->timerLabel->setGraphicsEffect(timerLabelTextShadowEffect );
        }

        //print timer value
        ui->timerLabel->setText(QString::number(total));

        //timer next value
        m_params[1]--;

        if (total==4)
        {
            //play final sound
            QSound::play(":/sounds/finalBip.wav");
        }

        if (total==0)
            m_phase--;
        break;

    case 1://disconnection phase

        //disconenct timer
        timer->disconnect();

        //show next/menu page
        m_endView->showFullScreen();

        //hide timer
        this->hide();
        break;

    }

}


void Timer::on_timerDuel()
{

    switch (m_phase)
    {
    case 3: //preparation phase
        //print timer label value
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
        //change to green color
        if (m_params[0]==-1)
        {
            this->setStyleSheet(".timerWindow{ background-color : #09CB36;}");
            timerLabelTextShadowEffect->setColor(QColor("#07AA2D"));
            ui->timerLabel->setGraphicsEffect(timerLabelTextShadowEffect );
            m_params[0]--;
        }

        //print next timer value
        ui->timerLabel->setText(QString::number(m_params[1]));
        m_params[1]--;

        //play final sound at the end of each green phase
        if (m_params[1]==3)
        {
            //play final sound
            QSound::play(":/sounds/finalBip.wav");
        }

        //while reps, reset green timer
        if (m_params[1]==-1)
        {
            //reset timer
            m_params[1]=m_previousParams[1];
            //decrease reps
            m_params[2]--;
        }

        if (m_params[2]==0)
            m_phase--;
        break;

    case 1://disconnexion phase
        timer->disconnect();
        //show next window
        m_endView->showFullScreen();
        //hide timer
        this->hide();
        break;

    }

}

//ENTER=pause
void Timer::keyEnterPressed()
{
    if (timer->isActive())
        timer->stop();
    else
        timer->start();
}

//ESCAPE= back to home
void Timer::keyEscapePressed()
{
    timer->disconnect();
    parentWidget()->showFullScreen();
    this->hide();
}

