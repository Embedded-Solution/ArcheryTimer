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

    void on_startTC_clicked();

    void on_startDuel_clicked();

private:
    Ui::Custom *ui;
    const QVector<int> defValTC={10,90,30};
    const QVector<int> defValDuel={10,20,6};
    QVector<int> valTC={10,90,30};
    QVector<int> valDuel={10,20,6};

};

#endif // CUSTOM_H
