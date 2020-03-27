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
    parentWidget()->parentWidget()->showFullScreen();
    this->hide();
}

void End::on_nextPB_clicked()
{
    emit resetTimer();
    this->hide();
}
