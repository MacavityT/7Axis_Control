#include "buttonthread.h"

buttonthread::buttonthread()
{

}

buttonthread::~buttonthread()
{}

void buttonthread::run()
{
    while(true)
    {
        //start
        while(!dmc_read_inbit(0,0))
        {
            msleep(50);
            if(dmc_read_inbit(0,0))
            {
                emit click_start();
            }
        }
        //pause
        if(dmc_read_inbit(0,1))
        {
            msleep(50);
            if(!dmc_read_inbit(0,1))
            {
                emit click_pause();
            }
        }
        //resume
        if(!dmc_read_inbit(0,1))
        {
            msleep(50);
            if(dmc_read_inbit(0,1))
            {
                emit click_resume();
            }
        }
        //reset
        while(!dmc_read_inbit(0,2))
        {
            msleep(50);
            if(dmc_read_inbit(0,2))
            {
                emit click_reset();
            }
        }
    }
}
