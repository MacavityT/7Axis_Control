#ifndef RISEDGETHREAD_H
#define RISEDGETHREAD_H
#include "LTDMC.h"
#include <QThread>

class risedgethread:public QThread
{
    Q_OBJECT
public:
    risedgethread();
    ~risedgethread();
    void run();

    int shoutai1_sensor;
    int shoutai2_sensor;
    int paoke_sensor;
    int baselamina_sensor;

signals:
    void shoutai1_rising_edge();
    void shoutai2_rising_edge();
    void paoke_rising_edge();
    void baselamina_rising_edge();
};
#endif // RISEDGETHREAD_H

