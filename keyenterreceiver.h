#ifndef KEYENTERRECEIVER_H
#define KEYENTERRECEIVER_H

#include <QObject>
#include <QEvent>
#include <QKeyEvent>

class keyEnterReceiver : public QObject
{
    Q_OBJECT
protected:
    bool eventFilter(QObject* obj, QEvent* event);

signals:
    void keyEnterIsPressed();
    void keyEscapeIsPressed();

public slots:
};

#endif // KEYENTERRECEIVER_H
