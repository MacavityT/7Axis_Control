#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qRegisterMetaType<DWORD>("DWORD");

    all_sensor=new sensor;//get the status of sensor
    button=new buttonthread;
    rising_edge=new risedgethread;
    actprocess=new actionprocess;
    act1=new actionthread1;//the recycle run() function
    act2=new actionthread2;
    act3=new actionthread3;
///set all io widget
/// these can also use the QList like the way was used in "commidialog.cpp"
/// (QList Class is like a reload vector container)
    Main_Input_Box={ui->Main_Input_1,ui->Main_Input_2,ui->Main_Input_3,ui->Main_Input_4,\
                   ui->Main_Input_5,ui->Main_Input_6,ui->Main_Input_7,ui->Main_Input_8,\
                   ui->Main_Input_9,ui->Main_Input_10,ui->Main_Input_11,ui->Main_Input_12,\
                   ui->Main_Input_13,ui->Main_Input_14,ui->Main_Input_15,ui->Main_Input_16};
    Main_Output_Box={ui->Main_Output_1,ui->Main_Output_2,ui->Main_Output_3,ui->Main_Output_4,\
                   ui->Main_Output_5,ui->Main_Output_6,ui->Main_Output_7,ui->Main_Output_8,\
                   ui->Main_Output_9,ui->Main_Output_10,ui->Main_Output_11,ui->Main_Output_12,\
                   ui->Main_Output_13,ui->Main_Output_14,ui->Main_Output_15,ui->Main_Output_16};
    Can_Input_Box={ui->CAN_Input_1,ui->CAN_Input_2,ui->CAN_Input_3,ui->CAN_Input_4,ui->CAN_Input_5,\
                  ui->CAN_Input_6,ui->CAN_Input_7,ui->CAN_Input_8,ui->CAN_Input_9,ui->CAN_Input_10,\
                  ui->CAN_Input_11,ui->CAN_Input_12,ui->CAN_Input_13,ui->CAN_Input_14,ui->CAN_Input_15,ui->CAN_Input_16};
    Can_Output_Box={ui->CAN_Output_1,ui->CAN_Output_2,ui->CAN_Output_3,ui->CAN_Output_4,ui->CAN_Output_5,\
                  ui->CAN_Output_6,ui->CAN_Output_7,ui->CAN_Output_8,ui->CAN_Output_9,ui->CAN_Output_10,\
                  ui->CAN_Output_11,ui->CAN_Output_12,ui->CAN_Output_13,ui->CAN_Output_14,ui->CAN_Output_15,ui->CAN_Output_16};
    for(vector<QLabel*>::iterator it1=Main_Input_Box.begin();it1!=Main_Input_Box.end();++it1)
    {
        QLabel* new_button1=*it1;
        new_button1->setScaledContents(true);
        new_button1->setPixmap(QPixmap("Q1480\\yellow-circle-md.png"));
    }
    for(vector<QLabel*>::iterator it2=Main_Output_Box.begin();it2!=Main_Output_Box.end();++it2)
    {
        QLabel* new_button2=*it2;
        new_button2->setScaledContents(true);
        new_button2->setPixmap(QPixmap("Q1480\\yellow-circle-md.png"));
    }
    for(vector<QLabel*>::iterator it3=Can_Input_Box.begin();it3!=Can_Input_Box.end();++it3)
    {
        QLabel* new_button3=*it3;
        new_button3->setScaledContents(true);
        new_button3->setPixmap(QPixmap("Q1480\\yellow-circle-md.png"));
    }
    for(vector<QLabel*>::iterator it4=Can_Output_Box.begin();it4!=Can_Output_Box.end();++it4)
    {
        QLabel* new_button4=*it4;
        new_button4->setScaledContents(true);
        new_button4->setPixmap(QPixmap("Q1480\\yellow-circle-md.png"));
    }


///connect the signals and slots
    connect(all_sensor,SIGNAL(signal_sensor_status(DWORD,DWORD,DWORD,DWORD)),\
            this,SLOT(slot_sensor_status(DWORD,DWORD,DWORD,DWORD)));

    connect(button,SIGNAL(click_start()),this,SLOT(click_start()));
    connect(button,SIGNAL(click_pause()),this,SLOT(click_pause()));
    connect(button,SIGNAL(click_resume()),this,SLOT(click_resume()));
    connect(button,SIGNAL(click_reset()),this,SLOT(click_reset()));

    connect(rising_edge,SIGNAL(shoutai1_rising_edge()),actprocess,SLOT(shoutai1_rising_edge_check()));
    connect(rising_edge,SIGNAL(shoutai2_rising_edge()),actprocess,SLOT(shoutai2_rising_edge_check()));
    connect(rising_edge,SIGNAL(paoke_rising_edge()),actprocess,SLOT(paoke_rising_edge_check()));
    connect(rising_edge,SIGNAL(baselamina_rising_edge()),actprocess,SLOT(baselamina_rising_edge_check()));

    connect(act3,SIGNAL(signal_button_enable()),this,SLOT(slot_button_enable()));
    connect(this,SIGNAL(signal_action()),actprocess,SLOT(slot_action()));
    connect(this,SIGNAL(signal_pause(bool)),actprocess,SLOT(slot_pause(bool)));
    connect(this,SIGNAL(signal_origin_back()),actprocess,SLOT(slot_origin_back()));

    //initialization the card parameter
    ControlCard_Initialization();
    OriginBack_Initialization();
    if(board_initialization)
    {
        button->start();
        rising_edge->start();
        act1->start();
        act2->start();
        act3->start();
    }
    if(Can_State==1)
    {
        qDebug()<<"start all_sensor";
        all_sensor->start();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete actprocess;
//    delete all_sensor;
    all_sensor->terminate();
    all_sensor->wait(1);
    all_sensor->deleteLater();
//    delete button thread
    button->terminate();
    button->wait(1);
    button->deleteLater();
//    delete rising edge thread
    rising_edge->terminate();
    rising_edge->wait(1);
    rising_edge->deleteLater();
//    delete act
    act1->terminate();
    act1->wait(1);
    act1->deleteLater();
    act2->terminate();
    act2->wait(1);
    act2->deleteLater();
    act3->terminate();
    act3->wait(1);
    act3->deleteLater();
    //close the control card
    dmc_board_close();
}

void MainWindow::on_actionParameter_Settings_triggered()
{
    auto NewDialog = new ParamDialog();
    NewDialog->setAttribute(Qt::WA_DeleteOnClose);//let the dialog auto delete when click the X.
    NewDialog->setAttribute(Qt::WA_QuitOnClose,false);//let the dialog close with mianwindow exit.
    NewDialog->show();
}
void MainWindow::on_actionCommissioning_triggered()
{
    auto NewDialog = new commissioning();
    NewDialog->setAttribute(Qt::WA_DeleteOnClose);//let the dialog auto delete when click the X.
    NewDialog->setAttribute(Qt::WA_QuitOnClose,false);//let the dialog close with mianwindow exit.
    NewDialog->show();
}



void MainWindow::closeEvent( QCloseEvent * event )
{
  switch( QMessageBox::information( this, tr("Control System"),tr("Really Exit?"),\
          tr("Yes"), tr("No"),0, 1 ) ) //  the symbol "\" is a sign to shift the index and line feed
{
  case 0:
      event->accept();
      break;
  case 1:
      event->ignore();
      break;
  default:
      event->ignore();
      break;
}
}


void MainWindow::on_START_clicked()
{
    if(*(Live_MainCard_Input+4)&&*(Live_MainCard_Input+5))//judge the complete signal
    {
        ui->START->setEnabled(false);
        ui->PAUSE->setEnabled(true);
        ui->RESET->setEnabled(false);
        ui->RESUME->setEnabled(false);
        emit signal_action();
        act1->start();
        act2->start();
    }
}
void MainWindow::on_PAUSE_clicked()
{
    ui->START->setEnabled(false);
    ui->RESET->setEnabled(true);
    ui->PAUSE->setEnabled(false);
    ui->RESUME->setEnabled(true);
    emit signal_pause(true);
    int i=0;
    for(i;i<7;i++)
    {
        dmc_stop(0,i,0);//mode of emergency stop
                        //0 for reduce speed and stop
                        //1 for urgent stop
    }
}
void MainWindow::on_RESUME_clicked()
{
    ui->START->setEnabled(false);
    ui->PAUSE->setEnabled(true);
    ui->RESET->setEnabled(false);
    ui->RESUME->setEnabled(false);
    emit signal_pause(false);
}

void MainWindow::on_RESET_clicked()
{
    ui->START->setEnabled(false);
    ui->RESET->setEnabled(false);
    ui->PAUSE->setEnabled(false);
    ui->RESUME->setEnabled(false);
    act1->terminate();
    act1->wait(1);
    act2->terminate();
    act2->wait(1);
    emit signal_origin_back();
//    act3->start();
}

void MainWindow::slot_button_enable()
{
//    act3->terminate();
//    act3->wait(1);
    ui->START->setEnabled(true);
    ui->RESET->setEnabled(true);
    ui->PAUSE->setEnabled(false);
    ui->RESUME->setEnabled(false);
}

void MainWindow::click_start()
{
    ui->START->click();
}

void MainWindow::click_pause()
{
    ui->PAUSE->click();
}

void MainWindow::click_resume()
{
    ui->RESUME->click();
}

void MainWindow::click_reset()
{
    ui->RESET->click();
}

void MainWindow::on_coor_clean_clicked()
{
    QSettings *configFile=new QSettings(".\\Q1480\\Temporary_File.ini",QSettings::IniFormat);
    configFile->setValue("Gear_Coordinate_Index",0);
    delete configFile;
}
