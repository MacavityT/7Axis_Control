#include "mainwindow.h"
#include "QDebug"
///////////
/// \brief MainWindow::ControlCard_Initialization
///
/// the "cpp" format programmer file is to describe the initialization functions for the maincard
/// and the origin back action (like profile and the mode to back zero)
void MainWindow::ControlCard_Initialization()
{
    int i=0,j=0,k=0;
//    bool error;
    unsigned short int num=0;
    unsigned short int can_state=0;
    unsigned short int link_state=0;
    //initialize the control card
    if( dmc_board_init()<=0)
    {
        app->beep();
        QMessageBox::information(this,tr("Warning"),tr("Initialization Failed!"),tr("OK"),0);
        this->setEnabled(false);
        board_initialization=false;
    }
    //Check the communication state.
    dmc_LinkState(0,&link_state);//0 for connected,1 for disconnected
    if(link_state)
    {
        app->beep();
        QMessageBox::information(this,tr("Warning"),tr("MainCard Communication Error!"),tr("OK"),0);
        if(this->isEnabled())
        {
        this->setEnabled(false);
        }
    }
    //initialize main board IO
    //initialize the CAN-IO board
    int times=0;
    do
    {
        dmc_set_can_state(0,1,1,0);//card-nm,can-code-nm(1-4),status of communication(0 for broken,1 for connected),
                                  //Baud rate(0-1000，1-800，2-500，3-250,4-125,5-100,6)
        Sleep(500);//for a little delay
        dmc_get_can_state(0,&num,&can_state);//card-nu,can-code-nm,can-state
        switch (can_state) {
        case 0:
            app->beep();
            QMessageBox::information(this,tr("Warning"),tr("CAN-IO Communication Disconnected!"),tr("OK"),0);
            times++;
            break;
        case 2:
            app->beep();
            QMessageBox::information(this,tr("Warning"),tr("CAN-IO Communication Error!"),tr("OK"),0);
            times++;
        default:
            break;
        }
    }while((can_state!=1)&&(times<3));//0 for broken ,1 for connected ,2 for abnormal
    Can_State=can_state;
    if(times>=3)
    {
        if(this->isEnabled())
        {
        this->setEnabled(false);
        }
        return;
    }
    //set the position limit
    for(i=0;i<7;i++)
    {
        dmc_set_el_mode(0,i,1,0,0);//card-nm,axis-nm,EL-enable(bothway enable),
                                  //pin logic(low),break mode(stop immediately)
    }
    //initialize the speed profile
    QSettings *configFile=new QSettings(".\\Q1480\\Parameter_Configure.ini",QSettings::IniFormat);
    double high_speed=configFile->value("Running_Speed/HighSpeed").toDouble();
    double low_speed=configFile->value("Running_Speed/LowSpeed").toDouble();
    double acceleration_time=configFile->value("Running_Speed/AccelerationTime").toDouble();
    double deceleration_time=configFile->value("Running_Speed/DecelerationTime").toDouble();
    for(j=0;j<7;j++)
    {
        dmc_set_profile(0,j,low_speed,high_speed,acceleration_time,deceleration_time,low_speed);//these parameters need synchronized with configer file
    }
    delete configFile;
    //set the pulse mode
    for(k=0;k<7;k++)
    {
       dmc_set_pulse_outmode(0,k,0);//card-nm,axis-nm,pulse mode
    }
}


////////////////
/// \brief MainWindow::OriginBack_Initialization
///
void MainWindow::OriginBack_Initialization()
{
    //define variable
    int i,j;
    //set home back electrical level triggered.
    //card-nm,axis-nm,org-logic,filter(fixed value:0)
    for(i=0;i<7;i++)
    {
        dmc_set_home_pin_logic( 0, i, 0, 0);
    }

    //zero-back mode
    //card-nm,axis-nm,zero-orientation,speed mode(0 for low,1 for high)
    //zero-mode(0 to 4),filter(fixed value:0)
    for(j=0;j<7;j++)
    {
        dmc_set_homemode(0,j,0,0,2,1);//mode-number:2 get the sensor signal trrigered twice
    }
}


/////the following function is no use ,witch can be replaced by
/// "include <windows.h>" and the function "Sleep(DWORD millisecons)"

//////////////Configure Parameter
//void MainWindow::get_configure_parameter()
//{
//}

/// function of delay times
/// the function sleep could let the thread real-sleep,
/// so we can define a private function by QTime Class
void MainWindow::Mysleep(unsigned int msec)
{
    ///get the computer system real-time,add my parameter then get the time
    /// of next step will be carride out
    QTime reachTime = QTime::currentTime().addMSecs(msec);

    while(QTime::currentTime()<reachTime)
        ///the next code line could keep the Qt thread activate
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}


