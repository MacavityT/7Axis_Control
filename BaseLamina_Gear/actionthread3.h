#ifndef ACTIONTHREAD3_H
#define ACTIONTHREAD3_H
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

class actionthread3:public QThread
{
    Q_OBJECT
public:
    actionthread3();
    ~actionthread3();
    void run();
    actionprocess *process3;
signals:
    void signal_button_enable();
};

#endif // ACTIONTHREAD3_H
