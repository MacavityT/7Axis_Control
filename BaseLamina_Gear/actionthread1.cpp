#include "actionthread1.h"

using namespace ACTIONPROCESS;

actionthread1::actionthread1()
{
   process1=new actionprocess;
}
actionthread1::~actionthread1()
{
    delete process1;
}

void actionthread1::run()
{
    while (true) {
        if(actionprocess::action_start&&actionprocess::origin_finished)
        {
            gear_clamp();
            gear_set();
        }
    }
}
////////////
/// \brief actionthread1::gear_clamp
///
void actionthread1::gear_clamp()
{
    if(process1->paoke_origin_back)
    {
        return;
    }
    if(process1->gear_clamp_status)
    {
        return;
    }
    if(process1->shoutai1_state&&process1->shoutai2_state)
    {
        return;
    }
    //all gas claw sensors are not in induction state.
    if(!(dmc_read_inbit(0,8)&&dmc_read_inbit(0,9)&&dmc_read_inbit(0,10)\
         &&dmc_read_inbit(0,11)&&dmc_read_inbit(0,12)&&dmc_read_inbit(0,13)))
    {
        process1->gear_clamp_status=false;
        return;
    }
    qDebug()<<"gear_clamp start";
    //when paoke sensor is triggered,next step.
//    process1->wait_main_board_sensor(6);  wait for paoke sensor
    //when any shoutai sensor is triggerre,action start.
    do
    {
        while(process1->pause)
        {
        }
    }while(dmc_read_inbit(0,4)&&dmc_read_inbit(0,5));
    //move to clamp the gear.
    QSettings *configFile=new QSettings(".\\Q1480\\Temporary_File.ini",QSettings::IniFormat);
    int index=configFile->value("Gear_Coordinate_Index").toInt();
    dmc_write_can_outbit(0,1,0,1);
    process1->wait_can_board_sensor(0);
    //check paoke rising edge
    if(index==0)
    {
        do
        {}while(!process1->paoke_rising_edge);
        process1->paoke_rising_edge=false;
        msleep(1500);
    }
    //go to the clamp coordinate
    dmc_pmove(0,1,process1->gear_coordinate[index][0][0],1);
    dmc_pmove(0,4,process1->gear_coordinate[index][1][0],1);
    process1->single_axis_check_done(1,process1->gear_coordinate[index][0][0]);
    process1->single_axis_check_done(4,process1->gear_coordinate[index][1][0]);
    msleep(process1->delay_time);
    //desend the z0 axis
    process1->single_axis_action_absolute(0,process1->z0_clamp);
    msleep(process1->delay_time);
    //clamp
    //first two
    dmc_write_can_outbit(0,1,1,0);
    dmc_write_can_outbit(0,1,2,0);
    process1->wait_can_board_sensor(3);
    process1->wait_can_board_sensor(5);
    msleep(process1->delay_time);
    dmc_write_can_outbit(0,1,7,0);
    dmc_write_can_outbit(0,1,8,0);
    process1->wait_main_board_sensor(8);
    process1->wait_main_board_sensor(9);
    msleep(process1->delay_time);
    msleep(100);// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Clamp delay time
    dmc_write_can_outbit(0,1,1,1);
    dmc_write_can_outbit(0,1,2,1);
    process1->wait_can_board_sensor(2);
    process1->wait_can_board_sensor(4);
    //second two
    dmc_pmove(0,1,process1->gear_coordinate[index][0][1],1);
    dmc_pmove(0,4,process1->gear_coordinate[index][1][1],1);
    process1->single_axis_check_done(1,process1->gear_coordinate[index][0][1]);
    process1->single_axis_check_done(4,process1->gear_coordinate[index][1][1]);
    dmc_write_can_outbit(0,1,3,0);
    dmc_write_can_outbit(0,1,4,0);
    process1->wait_can_board_sensor(7);
    process1->wait_can_board_sensor(9);
    msleep(process1->delay_time);
    dmc_write_can_outbit(0,1,9,0);
    dmc_write_can_outbit(0,1,10,0);
    process1->wait_main_board_sensor(10);
    process1->wait_main_board_sensor(11);
    msleep(process1->delay_time);
    msleep(100);// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Clamp delay time
    dmc_write_can_outbit(0,1,3,1);
    dmc_write_can_outbit(0,1,4,1);
    process1->wait_can_board_sensor(6);
    process1->wait_can_board_sensor(8);
    //last two
    dmc_pmove(0,1,process1->gear_coordinate[index][0][2],1);
    dmc_pmove(0,4,process1->gear_coordinate[index][1][2],1);
    process1->single_axis_check_done(1,process1->gear_coordinate[index][0][2]);
    process1->single_axis_check_done(4,process1->gear_coordinate[index][1][2]);
    dmc_write_can_outbit(0,1,5,0);
    dmc_write_can_outbit(0,1,6,0);
    process1->wait_can_board_sensor(11);
    process1->wait_can_board_sensor(13);
    msleep(process1->delay_time);
    dmc_write_can_outbit(0,1,11,0);
    dmc_write_can_outbit(0,1,12,0);
    process1->wait_main_board_sensor(12);
    process1->wait_main_board_sensor(13);
    msleep(process1->delay_time);
    msleep(100);// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Clamp delay time
    dmc_write_can_outbit(0,1,5,1);
    dmc_write_can_outbit(0,1,6,1);
    process1->wait_can_board_sensor(10);
    process1->wait_can_board_sensor(12);
    //rise the z0 axis
    process1->single_axis_action_absolute(0,process1->z0_high);
    msleep(process1->delay_time);
    if(index<11)
    {
        index++;
    }
    else
    {
        index=0;
        process1->paoke_origin_back=true;
    }
    configFile->setValue("Gear_Coordinate_Index",index);
    delete configFile;
    process1->gear_clamp_status=true;
    process1->gear_set_status=false;
}
















////////////
/// \brief actionthread1::gear_set
///
void actionthread1::gear_set()
{
    int shoutai_num=0;
    if(process1->shoutai1_origin_back&&process1->shoutai2_origin_back)
    {
        return;
    }
    if(process1->gear_set_status||!process1->gear_clamp_status)
    {
        return;
    }
    if(process1->shoutai1_state&&process1->shoutai2_state)
    {
        return;
    }
    //judge which shoutai to set.
    //shoutai1 and shoutai2 are sensed or shoutai1 isn't but shoutai2 is sensed
    //two sensors are triggered meanwhile , carry out the process shoutai2 first.
//    qDebug()<<"gear_set start";
    if(process1->shoutai1_rising_edge&&process1->shoutai2_rising_edge)
    {
        if(!process1->shoutai2_state)
        {
            process1->shoutai2_rising_edge=false;
            msleep(1500);
            shoutai_num=2;
            dmc_pmove(0,1,process1->gear_set_shoutai2_x1,1);
            dmc_pmove(0,3,process1->gear_set_shoutai2_y1,1);
            process1->single_axis_check_done(1,process1->gear_set_shoutai2_x1);
            process1->single_axis_check_done(3,process1->gear_set_shoutai2_y1);
            msleep(process1->delay_time);
        }
        else if(!process1->shoutai1_state&&process1->shoutai2_state)
        {
            process1->shoutai1_rising_edge=false;
            msleep(1500);
            shoutai_num=1;
            dmc_pmove(0,1,process1->gear_set_shoutai1_x1,1);
            dmc_pmove(0,2,process1->gear_set_shoutai1_y1,1);
            process1->single_axis_check_done(1,process1->gear_set_shoutai1_x1);
            process1->single_axis_check_done(2,process1->gear_set_shoutai1_y1);
            msleep(process1->delay_time);
        }
        else
        {
            return;
        }
    }
    else if(!process1->shoutai1_rising_edge&&process1->shoutai2_rising_edge)
    {
        if(!process1->shoutai2_state)
        {
            process1->shoutai2_rising_edge=false;
            msleep(1500);
            shoutai_num=2;
            dmc_pmove(0,1,process1->gear_set_shoutai2_x1,1);
            dmc_pmove(0,3,process1->gear_set_shoutai2_y1,1);
            process1->single_axis_check_done(1,process1->gear_set_shoutai2_x1);
            process1->single_axis_check_done(3,process1->gear_set_shoutai2_y1);
            msleep(process1->delay_time);
        }
        else
        {
            return;
        }
    }
    else if(process1->shoutai1_rising_edge&&!process1->shoutai2_rising_edge)
    {
        if(!process1->shoutai1_state)
        {
            process1->shoutai1_rising_edge=false;
            msleep(1500);
            shoutai_num=1;
            dmc_pmove(0,1,process1->gear_set_shoutai1_x1,1);
            dmc_pmove(0,2,process1->gear_set_shoutai1_y1,1);
            process1->single_axis_check_done(1,process1->gear_set_shoutai1_x1);
            process1->single_axis_check_done(2,process1->gear_set_shoutai1_y1);
            msleep(process1->delay_time);
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
    qDebug()<<"gear set move";
    //open the crosswise air cylinder
    dmc_write_can_outbit(0,1,0,0);
    process1->wait_can_board_sensor(1);
    msleep(process1->delay_time);
    //descend the z0 axis.
    process1->single_axis_action_absolute(0,process1->z0_low);
    msleep(process1->delay_time);
    //set
    //air cylinder ad gas claw
    //the first two
    dmc_write_can_outbit(0,1,1,0);
    dmc_write_can_outbit(0,1,2,0);
    process1->wait_can_board_sensor(3);
    process1->wait_can_board_sensor(5);
    dmc_write_can_outbit(0,1,7,1);
    dmc_write_can_outbit(0,1,8,1);
    msleep(process1->delay_time);
    dmc_write_can_outbit(0,1,1,1);
    dmc_write_can_outbit(0,1,2,1);
    process1->wait_can_board_sensor(2);
    process1->wait_can_board_sensor(4);
    //the second two
    switch (shoutai_num) {
    case 1:
        dmc_pmove(0,1,process1->gear_set_shoutai1_x2,1);
        dmc_pmove(0,2,process1->gear_set_shoutai1_y2,1);
        process1->single_axis_check_done(1,process1->gear_set_shoutai1_x2);
        process1->single_axis_check_done(2,process1->gear_set_shoutai1_y2);
        break;
    case 2:
        dmc_pmove(0,1,process1->gear_set_shoutai2_x2,1);
        dmc_pmove(0,3,process1->gear_set_shoutai2_y2,1);
        process1->single_axis_check_done(1,process1->gear_set_shoutai2_x2);
        process1->single_axis_check_done(3,process1->gear_set_shoutai2_y2);
    default:
        break;
    }
    dmc_write_can_outbit(0,1,3,0);
    dmc_write_can_outbit(0,1,4,0);
    process1->wait_can_board_sensor(7);
    process1->wait_can_board_sensor(9);
    dmc_write_can_outbit(0,1,9,1);
    dmc_write_can_outbit(0,1,10,1);
    msleep(process1->delay_time);
    dmc_write_can_outbit(0,1,3,1);
    dmc_write_can_outbit(0,1,4,1);
    process1->wait_can_board_sensor(6);
    process1->wait_can_board_sensor(8);
    //the last two
    switch (shoutai_num) {
    case 1:
        dmc_pmove(0,1,process1->gear_set_shoutai1_x3,1);
        dmc_pmove(0,2,process1->gear_set_shoutai1_y3,1);
        process1->single_axis_check_done(1,process1->gear_set_shoutai1_x3);
        process1->single_axis_check_done(2,process1->gear_set_shoutai1_y3);
        break;
    case 2:
        dmc_pmove(0,1,process1->gear_set_shoutai2_x3,1);
        dmc_pmove(0,3,process1->gear_set_shoutai2_y3,1);
        process1->single_axis_check_done(1,process1->gear_set_shoutai2_x3);
        process1->single_axis_check_done(3,process1->gear_set_shoutai2_y3);
    default:
        break;
    }
    dmc_write_can_outbit(0,1,5,0);
    dmc_write_can_outbit(0,1,6,0);
    process1->wait_can_board_sensor(11);
    process1->wait_can_board_sensor(13);
    dmc_write_can_outbit(0,1,11,1);
    dmc_write_can_outbit(0,1,12,1);
    msleep(process1->delay_time);
    dmc_write_can_outbit(0,1,5,1);
    dmc_write_can_outbit(0,1,6,1);
    process1->wait_can_board_sensor(10);
    process1->wait_can_board_sensor(12);
    //rise the z0 axis
    process1->single_axis_action_absolute(0,process1->z0_high);
    msleep(process1->delay_time);
    dmc_write_can_outbit(0,1,0,1);
    process1->wait_can_board_sensor(0);
    //set falg
    process1->gear_clamp_status=false;
    process1->gear_set_status=true;
    switch (shoutai_num) {
    case 1:
        process1->shoutai1_state=true;
        break;
    case 2:
        process1->shoutai2_state=true;
    default:
        break;
    }
}
