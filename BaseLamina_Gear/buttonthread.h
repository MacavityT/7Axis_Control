#ifndef BUTTONTHREAD_H
#define BUTTONTHREAD_H
#include "LTDMC.h"
#include <QThread>
class buttonthread:public QThread
{
    Q_OBJECT
public:
    buttonthread();
    ~buttonthread();
    void run();
signals:
    void click_start();
    void click_pause();
    void click_resume();
    void click_reset();
};

#endif // BUTTONTHREAD_H
