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

private:
    Ui::End *ui;
};

#endif // END_H
