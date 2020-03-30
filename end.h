/****************************************
 *                                      *
 * Author : Erwan BARBIER               *
 * Project : ArcheryTimer               *
 * Date :26/03/2020                     *
 *                                      *
 * www.maomaker.wordpress.com           *
 *                                      *
 * **************************************/

#ifndef END_H
#define END_H

#include <QMainWindow>

namespace Ui {
class End;
}

class End : public QMainWindow
{
    Q_OBJECT

public:
    explicit End(QWidget *parent = nullptr);
    ~End();

private slots:
    void on_homePB_clicked();

    void on_nextPB_clicked();
signals:
    void resetTimer();

private:
    Ui::End *ui;
};

#endif // END_H
