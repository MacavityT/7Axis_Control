#ifndef ACTIONTHREAD1_H
#define ACTIONTHREAD1_H
typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
#include <QThread>
#include <windows.h>
#include "LTDMC.h"
#include "actionprocess.h"

using namespace ACTIONPROCESS;

class actionthread1:public QThread
{
    Q_OBJECT
public:
    actionthread1();
    ~actionthread1();
    void run();
    void gear_clamp();
    void gear_set();
    actionprocess *process1;
};

#endif // ACTIONTHREAD1_H
