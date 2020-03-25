#include "custom.h"
#include "ui_custom.h"

Custom::Custom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Custom)
{
    ui->setupUi(this);
    ui->time1TC->setValue(m_ValTime1TC);
    ui->time2TC->setValue(m_ValTime2TC);
    ui->time3TC->setValue(m_ValTime3TC);
    ui->time1Duel->setValue(m_ValTime1TC);
    ui->time2Duel->setValue(m_ValTime2TC);
    ui->repsDuel->setValue(m_ValRepsDuel);
}

Custom::~Custom()
{
    delete ui;
}

void Custom::on_homePB_clicked()
{
    //MainWindow *parent_ptr = static_cast<MainWindow*>(this->parent());
    this->hide();
    parentWidget()->show();
}

void Custom::on_time1TC_valueChanged(int arg1)
{
    m_ValTime1TC=arg1;
}

void Custom::on_time2TC_valueChanged(int arg1)
{
    m_ValTime2TC=arg1;
}

void Custom::on_time3TC_valueChanged(int arg1)
{
    m_ValTime3TC=arg1;
}

void Custom::on_time1Duel_valueChanged(int arg1)
{
    m_ValTime1Duel=arg1;
}

void Custom::on_time2Duel_valueChanged(int arg1)
{
    m_ValTime2Duel=arg1;
}

void Custom::on_repsDuel_valueChanged(int arg1)
{
    m_ValRepsDuel=arg1;
}

void Custom::on_resetPB_clicked()
{
    ui->time1TC->setValue(m_defValTime1TC);
    ui->time2TC->setValue(m_defValTime2TC);
    ui->time3TC->setValue(m_defValTime3TC);
    ui->time1Duel->setValue(m_defValTime1TC);
    ui->time2Duel->setValue(m_defValTime2TC);
    ui->repsDuel->setValue(m_defValRepsDuel);
}
