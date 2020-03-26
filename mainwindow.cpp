#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_custom(new Custom(this))
    ,m_timer(new Timer(this))
{
    this->loadStyle();
    ui->setupUi(this);

    borderLabelTextShadowEffect = new QGraphicsDropShadowEffect(this);
    borderLabelTextShadowEffect->setColor(QColor("#000000"));
    borderLabelTextShadowEffect->setBlurRadius(10);
    borderLabelTextShadowEffect->setOffset(0, 0);
    ui->label->setGraphicsEffect(borderLabelTextShadowEffect );
    borderLabelTextShadowEffect2 = new QGraphicsDropShadowEffect(this);
    borderLabelTextShadowEffect2->setColor(QColor("#000000"));
    borderLabelTextShadowEffect2->setBlurRadius(10);
    borderLabelTextShadowEffect2->setOffset(0, 0);
    ui->label_2->setGraphicsEffect(borderLabelTextShadowEffect2);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::loadStyle(QString filename, QString variablesFilename) {
    QString cssContent;
    QString cssFilename(filename);
    QString cssVariablesFilename(variablesFilename);

    // Reading CSS
    QFile cssFile(cssFilename);
    if(!cssFile.open(QIODevice::ReadOnly)) {
        return;
    } else {
        cssContent = cssFile.readAll();
    }
    cssFile.close();

    // Reading CSS Variables
    QFile variablesFile(cssVariablesFilename);
    QString line;
    QList<QString> splittedLine;
    if(variablesFile.open(QIODevice::ReadOnly)) {
        do {
            line = variablesFile.readLine();
            splittedLine = line.split("=");
            if (splittedLine.size() == 2) {
                cssContent.replace(QString("@") + splittedLine[0], splittedLine[1]);
            }
        } while(!line.isEmpty());
        variablesFile.close();
    }

    // Replacing variables and applying style
    this->setStyleSheet(cssContent);
}

void MainWindow::on_customButton_clicked()
{
    this->hide();
    m_custom->showMaximized();
}

void MainWindow::on_tirCompteButton_clicked()
{
  QVector<int> paramsTC={4,5,3};
  startTimer(0,paramsTC);
}

void MainWindow::on_duelButton_clicked()
{
    QVector<int> paramsDuel={4,5,3};
    startTimer(1,paramsDuel);
}

void MainWindow::startTimer(bool mode,QVector<int> params)
{
    this->hide();
   m_timer->timerTC(mode,params);
}


