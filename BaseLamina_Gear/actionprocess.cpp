#include "actionprocess.h"
using namespace ACTIONPROCESS;
int actionprocess::action=0;
bool actionprocess::pause=false;
bool actionprocess::resume=false;
bool actionprocess::action_start=false;
bool actionprocess::origin_start=false;
bool actionprocess::origin_finished=false;
bool actionprocess::gear_clamp_status=false;
bool actionprocess::gear_set_status=false;
bool actionprocess::base_lamina_clamp_status=false;
bool actionprocess::base_lamina_set_status=false;
bool actionprocess::shoutai1_state=false;
bool actionprocess::shoutai2_state=false;
bool actionprocess::shoutai1_rising_edge=false;
bool actionprocess::shoutai2_rising_edge=false;
bool actionprocess::paoke_rising_edge=false;
bool actionprocess::baselamina_rising_edge=false;
bool actionprocess::shoutai1_origin_back=false;
bool actionprocess::shoutai2_origin_back=false;
bool actionprocess::paoke_origin_back=false;

actionprocess::actionprocess()
{
    get_configure_parameter();
    gear_coordinate[0][0][0]=gear_coordinate_x1;
    gear_coordinate[0][1][0]=gear_coordinate_y1;
    gear_coordinate[0][0][1]=gear_coordinate_x1_2;
    gear_coordinate[0][1][1]=gear_coordinate_y1_2;
    gear_coordinate[0][0][2]=gear_coordinate_x1_3;
    gear_coordinate[0][1][2]=gear_coordinate_y1_3;

    gear_coordinate[1][0][0]=gear_coordinate_x2;
    gear_coordinate[1][1][0]=gear_coordinate_y2;
    gear_coordinate[1][0][1]=gear_coordinate_x2_2;
    gear_coordinate[1][1][1]=gear_coordinate_y2_2;
    gear_coordinate[1][0][2]=gear_coordinate_x2_3;
    gear_coordinate[1][1][2]=gear_coordinate_y2_3;

    gear_coordinate[2][0][0]=gear_coordinate_x3;
    gear_coordinate[2][1][0]=gear_coordinate_y3;
    gear_coordinate[2][0][1]=gear_coordinate_x3_2;
    gear_coordinate[2][1][1]=gear_coordinate_y3_2;
    gear_coordinate[2][0][2]=gear_coordinate_x3_3;
    gear_coordinate[2][1][2]=gear_coordinate_y3_3;

    gear_coordinate[3][0][0]=gear_coordinate_x4;
    gear_coordinate[3][1][0]=gear_coordinate_y4;
    gear_coordinate[3][0][1]=gear_coordinate_x4_2;
    gear_coordinate[3][1][1]=gear_coordinate_y4_2;
    gear_coordinate[3][0][2]=gear_coordinate_x4_3;
    gear_coordinate[3][1][2]=gear_coordinate_y4_3;

    gear_coordinate[4][0][0]=gear_coordinate_x5;
    gear_coordinate[4][1][0]=gear_coordinate_y5;
    gear_coordinate[4][0][1]=gear_coordinate_x5_2;
    gear_coordinate[4][1][1]=gear_coordinate_y5_2;
    gear_coordinate[4][0][2]=gear_coordinate_x5_3;
    gear_coordinate[4][1][2]=gear_coordinate_y5_3;

    gear_coordinate[5][0][0]=gear_coordinate_x6;
    gear_coordinate[5][1][0]=gear_coordinate_y6;
    gear_coordinate[5][0][1]=gear_coordinate_x6_2;
    gear_coordinate[5][1][1]=gear_coordinate_y6_2;
    gear_coordinate[5][0][2]=gear_coordinate_x6_3;
    gear_coordinate[5][1][2]=gear_coordinate_y6_3;

    gear_coordinate[6][0][0]=gear_coordinate_x7;
    gear_coordinate[6][1][0]=gear_coordinate_y7;
    gear_coordinate[6][0][1]=gear_coordinate_x7_2;
    gear_coordinate[6][1][1]=gear_coordinate_y7_2;
    gear_coordinate[6][0][2]=gear_coordinate_x7_3;
    gear_coordinate[6][1][2]=gear_coordinate_y7_3;

    gear_coordinate[7][0][0]=gear_coordinate_x8;
    gear_coordinate[7][1][0]=gear_coordinate_y8;
    gear_coordinate[7][0][1]=gear_coordinate_x8_2;
    gear_coordinate[7][1][1]=gear_coordinate_y8_2;
    gear_coordinate[7][0][2]=gear_coordinate_x8_3;
    gear_coordinate[7][1][2]=gear_coordinate_y8_3;

    gear_coordinate[8][0][0]=gear_coordinate_x9;
    gear_coordinate[8][1][0]=gear_coordinate_y9;
    gear_coordinate[8][0][1]=gear_coordinate_x9_2;
    gear_coordinate[8][1][1]=gear_coordinate_y9_2;
    gear_coordinate[8][0][2]=gear_coordinate_x9_3;
    gear_coordinate[8][1][2]=gear_coordinate_y9_3;

    gear_coordinate[9][0][0]=gear_coordinate_x10;
    gear_coordinate[9][1][0]=gear_coordinate_y10;
    gear_coordinate[9][0][1]=gear_coordinate_x10_2;
    gear_coordinate[9][1][1]=gear_coordinate_y10_2;
    gear_coordinate[9][0][2]=gear_coordinate_x10_3;
    gear_coordinate[9][1][2]=gear_coordinate_y10_3;

    gear_coordinate[10][0][0]=gear_coordinate_x11;
    gear_coordinate[10][1][0]=gear_coordinate_y11;
    gear_coordinate[10][0][1]=gear_coordinate_x11_2;
    gear_coordinate[10][1][1]=gear_coordinate_y11_2;
    gear_coordinate[10][0][2]=gear_coordinate_x11_3;
    gear_coordinate[10][1][2]=gear_coordinate_y11_3;

    gear_coordinate[11][0][0]=gear_coordinate_x12;
    gear_coordinate[11][1][0]=gear_coordinate_y12;
    gear_coordinate[11][0][1]=gear_coordinate_x12_2;
    gear_coordinate[11][1][1]=gear_coordinate_y12_2;
    gear_coordinate[11][0][2]=gear_coordinate_x12_3;
    gear_coordinate[11][1][2]=gear_coordinate_y12_3;
}

actionprocess::~actionprocess()
{
}

// this function can be in the constructor.
void actionprocess::get_configure_parameter()
{
    QSettings *configFile=new QSettings(".\\Q1480\\Parameter_Configure.ini",QSettings::IniFormat);
    ///Parameters of GearClamp.
    gear_coordinate_x1=configFile->value("Gear_Clamp_Coordinate/X1").toDouble();
    gear_coordinate_x1_2=configFile->value("Gear_Clamp_Coordinate/X1_2").toDouble();
    gear_coordinate_x1_3=configFile->value("Gear_Clamp_Coordinate/X1_3").toDouble();
    gear_coordinate_y1=configFile->value("Gear_Clamp_Coordinate/Y1").toDouble();
    gear_coordinate_y1_2=configFile->value("Gear_Clamp_Coordinate/Y1_2").toDouble();
    gear_coordinate_y1_3=configFile->value("Gear_Clamp_Coordinate/Y1_3").toDouble();

    gear_coordinate_x2=configFile->value("Gear_Clamp_Coordinate/X2").toDouble();
    gear_coordinate_x2_2=configFile->value("Gear_Clamp_Coordinate/X2_2").toDouble();
    gear_coordinate_x2_3=configFile->value("Gear_Clamp_Coordinate/X2_3").toDouble();
    gear_coordinate_y2=configFile->value("Gear_Clamp_Coordinate/Y2").toDouble();
    gear_coordinate_y2_2=configFile->value("Gear_Clamp_Coordinate/Y2_2").toDouble();
    gear_coordinate_y2_3=configFile->value("Gear_Clamp_Coordinate/Y2_3").toDouble();

    gear_coordinate_x3=configFile->value("Gear_Clamp_Coordinate/X3").toDouble();
    gear_coordinate_x3_2=configFile->value("Gear_Clamp_Coordinate/X3_2").toDouble();
    gear_coordinate_x3_3=configFile->value("Gear_Clamp_Coordinate/X3_3").toDouble();
    gear_coordinate_y3=configFile->value("Gear_Clamp_Coordinate/Y3").toDouble();
    gear_coordinate_y3_2=configFile->value("Gear_Clamp_Coordinate/Y3_2").toDouble();
    gear_coordinate_y3_3=configFile->value("Gear_Clamp_Coordinate/Y3_3").toDouble();

    gear_coordinate_x4=configFile->value("Gear_Clamp_Coordinate/X4").toDouble();
    gear_coordinate_x4_2=configFile->value("Gear_Clamp_Coordinate/X4_2").toDouble();
    gear_coordinate_x4_3=configFile->value("Gear_Clamp_Coordinate/X4_3").toDouble();
    gear_coordinate_y4=configFile->value("Gear_Clamp_Coordinate/Y4").toDouble();
    gear_coordinate_y4_2=configFile->value("Gear_Clamp_Coordinate/Y4_2").toDouble();
    gear_coordinate_y4_3=configFile->value("Gear_Clamp_Coordinate/Y4_3").toDouble();

    gear_coordinate_x5=configFile->value("Gear_Clamp_Coordinate/X5").toDouble();
    gear_coordinate_x5_2=configFile->value("Gear_Clamp_Coordinate/X5_2").toDouble();
    gear_coordinate_x5_3=configFile->value("Gear_Clamp_Coordinate/X5_3").toDouble();
    gear_coordinate_y5=configFile->value("Gear_Clamp_Coordinate/Y5").toDouble();
    gear_coordinate_y5_2=configFile->value("Gear_Clamp_Coordinate/Y5_2").toDouble();
    gear_coordinate_y5_3=configFile->value("Gear_Clamp_Coordinate/Y5_3").toDouble();

    gear_coordinate_x6=configFile->value("Gear_Clamp_Coordinate/X6").toDouble();
    gear_coordinate_x6_2=configFile->value("Gear_Clamp_Coordinate/X6_2").toDouble();
    gear_coordinate_x6_3=configFile->value("Gear_Clamp_Coordinate/X6_3").toDouble();
    gear_coordinate_y6=configFile->value("Gear_Clamp_Coordinate/Y6").toDouble();
    gear_coordinate_y6_2=configFile->value("Gear_Clamp_Coordinate/Y6_2").toDouble();
    gear_coordinate_y6_3=configFile->value("Gear_Clamp_Coordinate/Y6_3").toDouble();

    gear_coordinate_x7=configFile->value("Gear_Clamp_Coordinate/X7").toDouble();
    gear_coordinate_x7_2=configFile->value("Gear_Clamp_Coordinate/X7_2").toDouble();
    gear_coordinate_x7_3=configFile->value("Gear_Clamp_Coordinate/X7_3").toDouble();
    gear_coordinate_y7=configFile->value("Gear_Clamp_Coordinate/Y7").toDouble();
    gear_coordinate_y7_2=configFile->value("Gear_Clamp_Coordinate/Y7_2").toDouble();
    gear_coordinate_y7_3=configFile->value("Gear_Clamp_Coordinate/Y7_3").toDouble();

    gear_coordinate_x8=configFile->value("Gear_Clamp_Coordinate/X8").toDouble();
    gear_coordinate_x8_2=configFile->value("Gear_Clamp_Coordinate/X8_2").toDouble();
    gear_coordinate_x8_3=configFile->value("Gear_Clamp_Coordinate/X8_3").toDouble();
    gear_coordinate_y8=configFile->value("Gear_Clamp_Coordinate/Y8").toDouble();
    gear_coordinate_y8_2=configFile->value("Gear_Clamp_Coordinate/Y8_2").toDouble();
    gear_coordinate_y8_3=configFile->value("Gear_Clamp_Coordinate/Y8_3").toDouble();

    gear_coordinate_x9=configFile->value("Gear_Clamp_Coordinate/X9").toDouble();
    gear_coordinate_x9_2=configFile->value("Gear_Clamp_Coordinate/X9_2").toDouble();
    gear_coordinate_x9_3=configFile->value("Gear_Clamp_Coordinate/X9_3").toDouble();
    gear_coordinate_y9=configFile->value("Gear_Clamp_Coordinate/Y9").toDouble();
    gear_coordinate_y9_2=configFile->value("Gear_Clamp_Coordinate/Y9_2").toDouble();
    gear_coordinate_y9_3=configFile->value("Gear_Clamp_Coordinate/Y9_3").toDouble();

    gear_coordinate_x10=configFile->value("Gear_Clamp_Coordinate/X10").toDouble();
    gear_coordinate_x10_2=configFile->value("Gear_Clamp_Coordinate/X10_2").toDouble();
    gear_coordinate_x10_3=configFile->value("Gear_Clamp_Coordinate/X10_3").toDouble();
    gear_coordinate_y10=configFile->value("Gear_Clamp_Coordinate/Y10").toDouble();
    gear_coordinate_y10_2=configFile->value("Gear_Clamp_Coordinate/Y10_2").toDouble();
    gear_coordinate_y10_3=configFile->value("Gear_Clamp_Coordinate/Y10_3").toDouble();

    gear_coordinate_x11=configFile->value("Gear_Clamp_Coordinate/X11").toDouble();
    gear_coordinate_x11_2=configFile->value("Gear_Clamp_Coordinate/X11_2").toDouble();
    gear_coordinate_x11_3=configFile->value("Gear_Clamp_Coordinate/X11_3").toDouble();
    gear_coordinate_y11=configFile->value("Gear_Clamp_Coordinate/Y11").toDouble();
    gear_coordinate_y11_2=configFile->value("Gear_Clamp_Coordinate/Y11_2").toDouble();
    gear_coordinate_y11_3=configFile->value("Gear_Clamp_Coordinate/Y11_3").toDouble();

    gear_coordinate_x12=configFile->value("Gear_Clamp_Coordinate/X12").toDouble();
    gear_coordinate_x12_2=configFile->value("Gear_Clamp_Coordinate/X12_2").toDouble();
    gear_coordinate_x12_3=configFile->value("Gear_Clamp_Coordinate/X12_3").toDouble();
    gear_coordinate_y12=configFile->value("Gear_Clamp_Coordinate/Y12").toDouble();
    gear_coordinate_y12_2=configFile->value("Gear_Clamp_Coordinate/Y12_2").toDouble();
    gear_coordinate_y12_3=configFile->value("Gear_Clamp_Coordinate/Y12_3").toDouble();
    ///Parameters of GearSetting.
    //shoutai1
    gear_set_shoutai1_x1=configFile->value("Gear_Setting_Coordinate/ShouTai1_X1").toDouble();
    gear_set_shoutai1_y1=configFile->value("Gear_Setting_Coordinate/ShouTai1_Y1").toDouble();
    gear_set_shoutai1_x2=configFile->value("Gear_Setting_Coordinate/ShouTai1_X2").toDouble();
    gear_set_shoutai1_y2=configFile->value("Gear_Setting_Coordinate/ShouTai1_Y2").toDouble();
    gear_set_shoutai1_x3=configFile->value("Gear_Setting_Coordinate/ShouTai1_X3").toDouble();
    gear_set_shoutai1_y3=configFile->value("Gear_Setting_Coordinate/ShouTai1_Y3").toDouble();
    //shoutai2
    gear_set_shoutai2_x1=configFile->value("Gear_Setting_Coordinate/ShouTai2_X1").toDouble();
    gear_set_shoutai2_y1=configFile->value("Gear_Setting_Coordinate/ShouTai2_Y1").toDouble();
    gear_set_shoutai2_x2=configFile->value("Gear_Setting_Coordinate/ShouTai2_X2").toDouble();
    gear_set_shoutai2_y2=configFile->value("Gear_Setting_Coordinate/ShouTai2_Y2").toDouble();
    gear_set_shoutai2_x3=configFile->value("Gear_Setting_Coordinate/ShouTai2_X3").toDouble();
    gear_set_shoutai2_y3=configFile->value("Gear_Setting_Coordinate/ShouTai2_Y3").toDouble();
    ///Parameter of BaseLaminaClamp.
    base_lamina=configFile->value("BaseLamina_Clamp_Coordinate/BaseLaminaClamp").toDouble();
    ///Parameters of BaseLaminaSetting.
    //shoutai1
    baselamina_set_shoutai1_x1=configFile->value("BaseLamina_Setting_Coordinate/ShouTai1_X1").toDouble();
    baselamina_set_shoutai1_y1=configFile->value("BaseLamina_Setting_Coordinate/ShouTai1_Y1").toDouble();
    baselamina_set_shoutai1_x2=configFile->value("BaseLamina_Setting_Coordinate/ShouTai1_X2").toDouble();
    baselamina_set_shoutai1_y2=configFile->value("BaseLamina_Setting_Coordinate/ShouTai1_Y2").toDouble();
    baselamina_set_shoutai1_x3=configFile->value("BaseLamina_Setting_Coordinate/ShouTai1_X3").toDouble();
    baselamina_set_shoutai1_y3=configFile->value("BaseLamina_Setting_Coordinate/ShouTai1_Y3").toDouble();
    //shoutai2
    baselamina_set_shoutai2_x1=configFile->value("BaseLamina_Setting_Coordinate/ShouTai2_X1").toDouble();
    baselamina_set_shoutai2_y1=configFile->value("BaseLamina_Setting_Coordinate/ShouTai2_Y1").toDouble();
    baselamina_set_shoutai2_x2=configFile->value("BaseLamina_Setting_Coordinate/ShouTai2_X2").toDouble();
    baselamina_set_shoutai2_y2=configFile->value("BaseLamina_Setting_Coordinate/ShouTai2_Y2").toDouble();
    baselamina_set_shoutai2_x3=configFile->value("BaseLamina_Setting_Coordinate/ShouTai2_X3").toDouble();
    baselamina_set_shoutai2_y3=configFile->value("BaseLamina_Setting_Coordinate/ShouTai2_Y3").toDouble();
    ///Parameters of Z0 axis position.
    z0_high=configFile->value("Z0_Position/HighPosition").toDouble();
    z0_low=configFile->value("Z0_Position/LowPosition").toDouble();
    z0_clamp=configFile->value("Z0_Position/ClampPosition").toDouble();
    ///Parameters of Z1 axis position.
    z1_high=configFile->value("Z1_Position/HighPosition").toDouble();
    z1_low=configFile->value("Z1_Position/LowPosition").toDouble();
    z1_clamp=configFile->value("Z1_Position/ClampPosition").toDouble();
    ///Parameters of Running Speed.
    high_speed=configFile->value("Running_Speed/HighSpeed").toDouble();
    low_speed=configFile->value("Running_Speed/LowSpeed").toDouble();
    acceleration_time=configFile->value("Running_Speed/AccelerationTime").toDouble();
    deceleration_time=configFile->value("Running_Speed/DecelerationTime").toDouble();
    ///Parameter of DelayTime.
    delay_time=configFile->value("DelayTime/seconds").toDouble();

    delete configFile;
}

///the process function.

void actionprocess::all_origin_back()
{
    origin_start=false;
    //set the speed of origin back
    int axis;
    for(axis=0;axis<7;axis++)
    {
        dmc_set_profile(0,axis,2000,10000,0.3,0.3,2000);
    }
    //reset all output
    dmc_write_outport(0,0,0xFFFF);//card-nm,axis-nm,pin logic
    dmc_write_can_outport(0,1,0,0xFFFF);//card,can,fixed value,output pin-logic
    ///wait for the status of all air cylinder reset
    /// the "wait" step will be carry out by function: slot_button_enable()
    /// !!!!!!!It couldn't be carried out by mainwindow.cpp,or the programmer will be in thanatosis.
    for(int x=0;x<=12;x+=2)
    {
        wait_can_board_sensor(x);
    }
    //    //Test of delay time.
    //    std::this_thread::sleep_for(std::chrono::milliseconds(1000));//delay for 1000ms(so as 1s)
    //    std::cout<<"Hello World"<<std::endl;
    dmc_home_move(0,0);
    dmc_home_move(0,5);
    Sleep(50);
    all_axis_check_done();
    //define variable
    int i,k,j;
   // go front first.
   for(i=0;i<7;i++)
   {
       if(i!=0&&i!=5)
       {
           dmc_pmove(0,i,1500,0);
       }
   }
   all_axis_check_done();
   // go to the origin position
   for(j=0;j<7;j++)
   {
       if(j!=0&&j!=5)
       {
           dmc_home_move(0,j);
       }
   }
   all_axis_check_done();
   //zero cleaning
   for(k=0;k<7;k++)
   {
       dmc_set_position(0,k,0);
   }
   //reset the speed of all axis
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

   //set the flag
   origin_finished=true;
}


//single anxis action
void actionprocess::single_origin_back(unsigned short axis)
{
    //go front first
//    single_axis_action_relative(axis,pulse);
    //go to origin
    dmc_home_move(0,axis);
    single_axis_check_done(axis,NULL);
    //zero cleaning
    dmc_set_position(0,axis,0);
}

///control variable define
void actionprocess::slot_action()
{
    action_start=true;
    origin_start=false;
}

void actionprocess::slot_pause(bool PR)
{
    resume=!PR;
    pause=PR;
}

void actionprocess::slot_origin_back()
{
    origin_finished=false;
    origin_start=true;
    action_start=false;
    pause=false;
}

///rising edge check
void actionprocess::shoutai1_rising_edge_check()
{
    shoutai1_rising_edge=true;
}

void actionprocess::shoutai2_rising_edge_check()
{
    shoutai2_rising_edge=true;
}

void actionprocess::paoke_rising_edge_check()
{
    paoke_rising_edge=true;
}

void actionprocess::baselamina_rising_edge_check()
{
    baselamina_rising_edge=true;
}

/// my own axis status check function
void actionprocess::all_axis_check_done()
{
    unsigned short j;
    int x;
    do
    {
        x=0;
        for(j=0;j<7;j++)
        {
            x+=dmc_check_done(0,j);
        }
        while(pause)
        {
//wait for resume
        }
    }while(x!=7);//all axis stop j=7
}

void actionprocess::single_axis_check_done(unsigned short axis,long long pulse)//check the statement and judge the position
{
    do
    {
        while(pause)
        {
        }
    }while(!(dmc_check_done(0,axis)));
    //here is the programmer of compare the position
    if(resume&&pulse&&pulse!=(dmc_get_position(0,axis)))//if there are a pulse parameter and the position have not get the correct falg
    {
        resume=false;
        dmc_pmove(0,axis,pulse,1);
        single_axis_check_done(axis,pulse);
    }
}

/// my own serials staus check function
void actionprocess::wait_main_board_sensor(unsigned short bitno)
{
    do
    {
        while(pause)
        {
        }
    }while(dmc_read_inbit(0,bitno));
}
void actionprocess::wait_can_board_sensor(unsigned short bitno)
{
    do
    {
        while(pause)
        {
        }
    }while(dmc_read_can_inbit(0,1,bitno));
}

/// my own axis action function
void actionprocess::single_axis_action_relative(unsigned short axis,long long pulse)
{
    dmc_pmove(0,axis,pulse,0);
    single_axis_check_done(axis,pulse);
}
void actionprocess::single_axis_action_absolute(unsigned short axis, long long pulse)
{
    dmc_pmove(0,axis,pulse,1);
    single_axis_check_done(axis,pulse);
}
