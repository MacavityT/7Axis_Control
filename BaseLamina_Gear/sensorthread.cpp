#include "sensorthread.h"

sensor::sensor()
{
}

//sensor::~sensor()
//{
//}

void sensor::run()
{
//    qDebug()<<"sensorthread running";
    DWORD MainCard_Input=0;
    DWORD CanIO_Input=0;
    DWORD MainCard_Output=0;
    DWORD CanIO_Output=0;
    while (1)
    {
        MainCard_Input=dmc_read_inport(0,0);
        CanIO_Input=dmc_read_can_inport(0,1,0);//CardID,node,PortNO
        MainCard_Output=dmc_read_outport(0,0);
        CanIO_Output=dmc_read_can_outport(0,1,0);
        //////the following code block is to test the function of the dmc_read
//        qDebug()<<"live main card input is :"<<MainCard_Input;
        //////
//        Sleep(20);
        msleep(20);
        emit signal_sensor_status(MainCard_Input,CanIO_Input,MainCard_Output,CanIO_Output);
//        qDebug()<<"emit signal_sensor_status";
    }
}
