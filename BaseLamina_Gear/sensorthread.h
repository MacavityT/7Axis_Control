#ifndef SENSOR_H
#define SENSOR_H
typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
#include<QThread>
#include<QDebug>
#include<windows.h>
#include"LTDMC.h"

class sensor:public QThread
{
    Q_OBJECT
public:

    sensor();
//    ~sensor();
    void run();
signals:
    void signal_sensor_status(DWORD,DWORD,DWORD,DWORD);
};

#endif // SENSOR_H
