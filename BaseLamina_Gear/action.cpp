//#include "mainwindow.h"


//void MainWindow::action()
//{
//}


///// my own axis status check function
//void MainWindow::all_axis_check_done()
//{
//    unsigned short j;
//    int x;
//    do
//    {
//        x=0;
//        for(j=0;j<7;j++)
//        {
//            x+=dmc_check_done(0,j);
//        }
//        do
//        {
////                Sleep(200);
//        }while(pause);
//    }while(x!=7);//all axis stop j=7
//}

//void MainWindow::single_axis_check_done(unsigned short axis)
//{
//    do
//    {
//        if(pause)
//        {
//            do
//            {
////                Sleep(200);
//            }while(pause);
//        }
//    }while(!(dmc_check_done(0,axis)));
//}

///// my own serials staus check function
//void MainWindow::wait_main_board_serial(unsigned short bitno)
//{
//    do
//    {
//    }while(dmc_read_inbit(0,bitno));
//}
//void MainWindow::wait_can_board_serial(unsigned short bitno)
//{
//    do
//    {
//    }while(dmc_read_can_inbit(0,1,bitno));
//}

///// my own axis action function
//void MainWindow::single_axis_action_relative(unsigned short axis,long long pulse)
//{
//    dmc_pmove(0,axis,pulse,0);
//    single_axis_check_done(axis);
//}
//void MainWindow::single_axis_action_absolute(unsigned short axis, long long pulse)
//{
//    dmc_pmove(0,axis,pulse,1);
//    single_axis_check_done(axis);
//}
