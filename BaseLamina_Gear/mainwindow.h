#ifndef MAINWINDOW_H
#define MAINWINDOW_H
typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
#include <QMainWindow>
#include "stdio.h"
#include<iostream>
#include<chrono>
#include<windows.h>
#include<thread>
#include<QMessageBox>
#include<QCloseEvent>
#include<QApplication>
#include<QTime>
#include<QSettings>
#include<QPushButton>
#include<vector>
#include<QMetaType>



//private head.h
#include "LTDMC.h"
#include "paramdialog.h"
#include "commidialog.h"
#include "sensorthread.h"
#include "buttonthread.h"
#include "risedgethread.h"
#include "actionprocess.h"
#include "actionthread1.h"
#include "actionthread2.h"
#include "actionthread3.h"

namespace Ui {
class MainWindow;
}
using namespace std;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//programme initialization function define
    void closeEvent(QCloseEvent *);
    QApplication *app;
    sensor* all_sensor;
    buttonthread* button;
    risedgethread* rising_edge;
    actionprocess * actprocess;
    actionthread1 * act1;
    actionthread2 * act2;
    actionthread3 * act3;
    unsigned short int Can_State;

//function define
    //initialization functhion
    void ControlCard_Initialization();
    void OriginBack_Initialization();
    void Mysleep(unsigned int);
    void systems_conversion(DWORD,int);
    void display_IO();

//    void get_configure_parameter();

////    my action check function
//    void all_axis_check_done();
//    void single_axis_check_done(unsigned short);
////    my serial wait function
//    void wait_main_board_serial(unsigned short);
//    void wait_can_board_serial(unsigned short);
////    action function
//    void action();
//    void single_axis_action_relative(unsigned short,long long);
//    void single_axis_action_absolute(unsigned short,long long);
//    void all_origin_back();
//    void single_origin_back(unsigned short,long long);


//variable define
    bool board_initialization=true;
    bool stop=false;
    int  Live_MainCard_Input[100];
    int  Live_CanIO_Input[100];
    int  Live_MainCard_Output[100];
    int  Live_CanIO_Output[100];
    vector<QLabel*>Main_Input_Box;
    vector<QLabel*>Main_Output_Box;
    vector<QLabel*>Can_Input_Box;
    vector<QLabel*>Can_Output_Box;
//    qRegisterMetaType<DWORD>();



signals:
    void signal_pause(bool);
    void signal_action();
    void signal_origin_back();


public slots:
    void slot_sensor_status(DWORD,DWORD,DWORD,DWORD);
    void slot_button_enable();
    void click_start();
    void click_pause();
    void click_resume();
    void click_reset();


private slots:
    void on_actionParameter_Settings_triggered();

    void on_START_clicked();

    void on_PAUSE_clicked();

    void on_RESUME_clicked();

    void on_RESET_clicked();

    void on_actionCommissioning_triggered();

    void on_coor_clean_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
