#include "risedgethread.h"

risedgethread::risedgethread()
{
    shoutai1_sensor=!dmc_read_inbit(0,4);
    shoutai2_sensor=!dmc_read_inbit(0,5);
    paoke_sensor=!dmc_read_inbit(0,6);
    baselamina_sensor=!dmc_read_inbit(0,7);
}

risedgethread::~risedgethread()
{}

void risedgethread::run()
{
    int tem_shoutai1,tem_shoutai2,\
            tem_paoke,tem_baselamina;
    while(true)
    {
        //shoutai1 rising edge
        tem_shoutai1=!dmc_read_inbit(0,4);
        tem_shoutai2=!dmc_read_inbit(0,5);
        tem_paoke=!dmc_read_inbit(0,6);
        tem_baselamina=!dmc_read_inbit(0,7);


        if((tem_shoutai1-shoutai1_sensor)==1)
        {
            emit shoutai1_rising_edge();
        }
        shoutai1_sensor=tem_shoutai1;
        msleep(50);


        if((tem_shoutai2-shoutai2_sensor)==1)
        {
            emit shoutai2_rising_edge();
        }
        shoutai2_sensor=tem_shoutai2;
        msleep(50);


        if((tem_paoke-paoke_sensor)==1)
        {
            emit paoke_rising_edge();
        }
        paoke_sensor=tem_paoke;
        msleep(50);


        if((tem_baselamina-baselamina_sensor)==1)
        {
            emit baselamina_rising_edge();
        }
        baselamina_sensor=tem_baselamina;
        msleep(50);
    }
}
