#include "actionthread3.h"

using namespace ACTIONPROCESS;

actionthread3::actionthread3()
{
    process3=new actionprocess;
}
actionthread3::~actionthread3()
{
    delete process3;
}


void actionthread3::run()
{
    while (true) {
        //all axis origin back
        if(process3->origin_start)
        {
           process3->all_origin_back();
           if(process3->origin_finished)
           {
               emit signal_button_enable();
           }
        }
        //single axis origin back
        if(process3->shoutai1_origin_back)
        {
//            process3->single_origin_back(2);
            dmc_pmove(0,2,200,1);
            process3->single_axis_check_done(2,200);
            process3->shoutai1_origin_back=false;
            process3->shoutai1_state=false;
        }
        if(process3->shoutai2_origin_back)
        {
//            process3->single_origin_back(3);
            dmc_pmove(0,3,200,1);
            process3->single_axis_check_done(3,200);
            process3->shoutai2_origin_back=false;
            process3->shoutai2_state=false;
        }
        if(process3->paoke_origin_back)
        {
//            process3->single_origin_back(4);
            dmc_pmove(0,4,200,1);
            process3->single_axis_check_done(4,200);
            process3->paoke_origin_back=false;
        }
    }
//    if(process3->origin_start)
//    {
//       process3->all_origin_back();
//    }
}
