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
    //MainWindow *parent_ptr = static_cast<MainWindow*>(this->parent());
    this->hide();
    parentWidget()->parentWidget()->show();
}

void End::on_nextPB_clicked()
{
    emit resetTimer();
     this->hide();



}
