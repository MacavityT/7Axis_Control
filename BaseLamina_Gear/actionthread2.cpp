#include "actionthread2.h"

using namespace ACTIONPROCESS;

actionthread2::actionthread2()
{
    process2=new actionprocess;
}
actionthread2::~actionthread2()
{
    delete process2;
}


void actionthread2::run()
{
    while (true) {
        if(process2->action_start&&process2->origin_finished)
        {
            base_lamina_clamp();
            base_lamina_set();
        }
    }
}

void actionthread2::base_lamina_clamp()
{
    if(process2->base_lamina_clamp_status)
    {
        return;
    }
    if(!process2->shoutai1_state&&!process2->shoutai2_state)
    {
        return;
    }
//    qDebug()<<"BaseLamina_clamp start";
    //start to clamp
    process2->single_axis_action_absolute(6,process2->base_lamina);
    msleep(process2->delay_time);
    //check base lamina rising edge
    do
    {}while(!process2->baselamina_rising_edge);
    process2->baselamina_rising_edge=false;
    msleep(1500);
    //desend z0 axis.
    //fangdai
    fangdai();
    process2->single_axis_action_absolute(5,process2->z1_clamp);
    msleep(process2->delay_time);
    for(int i=0;i<=11;i++)
    {
        dmc_write_outbit(0,i,0);
    }
    msleep(process2->delay_time);
    process2->single_axis_action_absolute(5,process2->z1_high);
    msleep(process2->delay_time);
    process2->base_lamina_clamp_status=true;
    process2->base_lamina_set_status=false;
}


void actionthread2::fangdai()
{
    dmc_pmove(0,5,(process2->z1_clamp-1000),1);
    do
    {
        while(!dmc_read_inbit(0,14)||!dmc_read_inbit(0,15))
        {
            if(!dmc_check_done(0,5))
                dmc_stop(0,5,0);
        }
    }while(!dmc_check_done(0,5));
    if(dmc_get_position(0,5)!=(process2->z1_clamp-1000))
    {
        fangdai();
    }
}

















void actionthread2::base_lamina_set()
{
    if(process2->base_lamina_set_status\
            ||!process2->base_lamina_clamp_status)
    {
        return;
    }
//    qDebug()<<"BaseLamina set start";
   if((process2->shoutai1_state&&process2->shoutai2_state)\
            ||(!process2->shoutai1_state&&process2->shoutai2_state))
   {
       dmc_pmove(0,6,process2->baselamina_set_shoutai2_x1,1);
       dmc_pmove(0,3,process2->baselamina_set_shoutai2_y1,1);
       process2->single_axis_check_done(6,process2->gear_set_shoutai2_x1);
       process2->single_axis_check_done(3,process2->gear_set_shoutai2_y1);
       msleep(process2->delay_time);
   }
   else if(process2->shoutai1_state&&!process2->shoutai2_state)
   {
       dmc_pmove(0,6,process2->baselamina_set_shoutai1_x1,1);
       dmc_pmove(0,2,process2->baselamina_set_shoutai1_y1,1);
       process2->single_axis_check_done(6,process2->gear_set_shoutai1_x1);
       process2->single_axis_check_done(2,process2->gear_set_shoutai1_y1);
       msleep(process2->delay_time);
   }
   else
   {
        return;
   }
   process2->single_axis_action_absolute(5,process2->z1_low);
   msleep(process2->delay_time);
   for(int i=0;i<=11;i++)
   {
       dmc_write_outbit(0,i,1);
   }
   msleep(process2->delay_time);
   process2->single_axis_action_absolute(5,process2->z1_high);
   msleep(process2->delay_time);
   if((process2->shoutai1_state&&process2->shoutai2_state)\
            ||(!process2->shoutai1_state&&process2->shoutai2_state))
   {
       process2->shoutai2_origin_back=true;
   }
   else if(process2->shoutai1_state&&!process2->shoutai2_state)
   {
       process2->shoutai1_origin_back=true;
   }
   else
   {
        return;
   }
   process2->base_lamina_clamp_status=false;
   process2->base_lamina_set_status=true;
}
