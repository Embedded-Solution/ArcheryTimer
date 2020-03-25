#ifndef CUSTOM_H
#define CUSTOM_H

#include <QMainWindow>

namespace Ui {
class Custom;
}

class Custom : public QMainWindow
{
    Q_OBJECT

public:
    explicit Custom(QWidget *parent = nullptr);
    ~Custom();

private slots:
    void on_homePB_clicked();

    void on_time1TC_valueChanged(int arg1);

    void on_time2TC_valueChanged(int arg1);

    void on_time3TC_valueChanged(int arg1);

    void on_time1Duel_valueChanged(int arg1);

    void on_time2Duel_valueChanged(int arg1);

    void on_repsDuel_valueChanged(int arg1);

    void on_resetPB_clicked();

private:
    Ui::Custom *ui;
    const int m_defValTime1TC=10;
    const int m_defValTime2TC=90;
    const int m_defValTime3TC=30;
    const int m_defValTime1Duel=10;
    const int m_defValTime2Duel=20;
    const  int m_defValRepsDuel=6;
    int m_ValTime1TC=10;
    int m_ValTime2TC=90;
    int m_ValTime3TC=30;
    int m_ValTime1Duel=10;
    int m_ValTime2Duel=20;
    int m_ValRepsDuel=6;
};

#endif // CUSTOM_H
