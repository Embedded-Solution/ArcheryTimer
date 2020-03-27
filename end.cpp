#include "end.h"
#include "ui_end.h"

End::End(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::End)
{
    ui->setupUi(this);
}

End::~End()
{
    delete ui;
}

void End::on_homePB_clicked()
{
    this->hide();
    parentWidget()->parentWidget()->showFullScreen();
}

void End::on_nextPB_clicked()
{
    emit resetTimer();
    this->hide();



}
