#ifndef ACTIONTHREAD2_H
#define ACTIONTHREAD2_H
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

class actionthread2:public QThread
{
    Q_OBJECT
public:
    actionthread2();
    ~actionthread2();
    void run();
    void base_lamina_clamp();
    void base_lamina_set();
    void fangdai();
    actionprocess *process2;
};

#endif // ACTIONTHREAD2_H
