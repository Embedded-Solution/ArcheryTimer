#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_custom(new Custom(this))
{
    this->loadStyle();
    ui->setupUi(this);

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
    this->hide();
    QVector<int> paramsTC={10,90,30};
    m_timer=new Timer(0,paramsTC,this);
   m_timer->timerTC();
}




