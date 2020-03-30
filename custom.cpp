/****************************************
 *                                      *
 * Author : Erwan BARBIER               *
 * Project : ArcheryTimer               *
 * Date :26/03/2020                     *
 *                                      *
 * www.maomaker.wordpress.com           *
 *                                      *
 * **************************************/

#include "custom.h"
#include "ui_custom.h"
#include "mainwindow.h"

Custom::Custom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Custom)

{
    ui->setupUi(this);
    ui->time1TC->setValue(valTC[0]);
    ui->time2TC->setValue(valTC[1]);
    ui->time3TC->setValue(valTC[2]);
    ui->time1Duel->setValue(valDuel[0]);
    ui->time2Duel->setValue(valDuel[1]);
    ui->repsDuel->setValue(valDuel[2]);
}

Custom::~Custom()
{
    delete ui;
}

void Custom::on_homePB_clicked()
{
    parentWidget()->showFullScreen();
    this->hide();
}

void Custom::on_time1TC_valueChanged(int arg1)
{
    valTC[0]=arg1;
}

void Custom::on_time2TC_valueChanged(int arg1)
{
    valTC[1]=arg1;
}

void Custom::on_time3TC_valueChanged(int arg1)
{
    valTC[2]=arg1;
}

void Custom::on_time1Duel_valueChanged(int arg1)
{
    valDuel[0]=arg1;
}

void Custom::on_time2Duel_valueChanged(int arg1)
{
    valDuel[1]=arg1;
}

void Custom::on_repsDuel_valueChanged(int arg1)
{
    valDuel[2]=arg1;
}

void Custom::on_resetPB_clicked()
{
    ui->time1TC->setValue(defValTC[0]);
    ui->time2TC->setValue(defValTC[1]);
    ui->time3TC->setValue(defValTC[2]);
    ui->time1Duel->setValue(defValDuel[0]);
    ui->time2Duel->setValue(defValDuel[1]);
    ui->repsDuel->setValue(defValDuel[2]);
}

void Custom::on_startTC_clicked()
{
    MainWindow *parent_ptr = static_cast<MainWindow*>(this->parent());
    parent_ptr->startTimer(0,valTC);
    this->hide();
}

void Custom::on_startDuel_clicked()
{
    MainWindow *parent_ptr = static_cast<MainWindow*>(this->parent());
    parent_ptr->startTimer(1,valDuel);
    this->hide();
}
