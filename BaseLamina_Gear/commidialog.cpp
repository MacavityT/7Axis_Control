#include "commidialog.h"
#include "ui_commissioning.h"
#include <QDebug>


//////////
/// \brief commissioning::commissioning
/// \param parent
commissioning::commissioning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::commissioning)
{
    ui->setupUi(this);
//set all the pushbutton auto-repeate
    //get a list of button group and give it to a QList
    //declare a QList iterator
    QList<QAbstractButton*> list=ui->commi_button_group->buttons();
    QList<QAbstractButton*>::iterator i;
    for(i=list.begin();i!=list.end();++i)
    {
        QAbstractButton *temporary_button=*i;
        temporary_button->setAutoRepeat(true);
        temporary_button->setAutoRepeatDelay(0);
        temporary_button->setAutoRepeatInterval(10);
    }
    //display the parameter
    QSettings *configFile=new QSettings(".\\Q1480\\Temporary_File.ini",QSettings::IniFormat);
    double high_speed=configFile->value("Speed_Set/High_Speed").toDouble();
    double low_speed=configFile->value("Speed_Set/Low_Speed").toDouble();
    QString high_text=QString::number(high_speed);
    QString low_text=QString::number(low_speed);
    ui->HIGH_SPEED_SET->setText(high_text);
    ui->LOW_SPEED_SET->setText(low_text);
    delete configFile;
}

commissioning::~commissioning()
{
    delete ui;
}


void commissioning::on_HIGH_SPEED_clicked()
{
    QSettings *configFile=new QSettings(".\\Q1480\\Temporary_File.ini",QSettings::IniFormat);
    double high_speed=configFile->value("Speed_Set/High_Speed").toDouble();
    int i=0;
    ui->HIGH_SPEED->setEnabled(false);
    ui->LOW_SPEED->setEnabled(true);
    for(i;i<7;i++)
    {
        dmc_set_profile(0,i,high_speed,high_speed,0,0,high_speed);
    }
    delete configFile;
}

void commissioning::on_LOW_SPEED_clicked()
{
    QSettings *configFile=new QSettings(".\\Q1480\\Temporary_File.ini",QSettings::IniFormat);
    double low_speed=configFile->value("Speed_Set/Low_Speed").toDouble();
    int i=0;
    ui->HIGH_SPEED->setEnabled(true);
    ui->LOW_SPEED->setEnabled(false);
    for(i;i<7;i++)
    {
        dmc_set_profile(0,i,low_speed,low_speed,0,0,low_speed);
    }
    delete configFile;
}

void commissioning::on_X0_LEFT_pressed()
{
    QString text=QString::number(dmc_get_position(0,1)-50);
    dmc_pmove(0,1,-50,0);
    ui->X0_Position->setText(text);
}

void commissioning::on_X0_RIGHT_pressed()
{
    QString text=QString::number(dmc_get_position(0,1)+50);
    dmc_pmove(0,1,50,0);
    ui->X0_Position->setText(text);
}

void commissioning::on_X1_LEFT_pressed()
{
    QString text=QString::number(dmc_get_position(0,6)+50);
    dmc_pmove(0,6,50,0);
    ui->X1_Position->setText(text);
}

void commissioning::on_X1_RIGHT_pressed()
{
    QString text=QString::number(dmc_get_position(0,6)-50);
    dmc_pmove(0,6,-50,0);
    ui->X1_Position->setText(text);
}

void commissioning::on_Y0_AHEAD_pressed()
{
    QString text=QString::number(dmc_get_position(0,2)+50);
    dmc_pmove(0,2,50,0);
    ui->Y0_Position->setText(text);
}

void commissioning::on_YO_BACK_pressed()
{
    QString text=QString::number(dmc_get_position(0,2)-50);
    dmc_pmove(0,2,-50,0);;
    ui->Y0_Position->setText(text);
}

void commissioning::on_Y1_AHEAD_pressed()
{
    QString text=QString::number(dmc_get_position(0,3)+50);
    dmc_pmove(0,3,50,0);
    ui->Y1_Position->setText(text);
}

void commissioning::on_Y1_BACK_pressed()
{
    QString text=QString::number(dmc_get_position(0,3)-50);
    dmc_pmove(0,3,-50,0);
    ui->Y1_Position->setText(text);
}

void commissioning::on_Y2_AHEAD_pressed()
{
    QString text=QString::number(dmc_get_position(0,4)+50);
    if(dmc_check_done(0,4))
    {
        dmc_pmove(0,4,50,0);
    }
    else
    {
        dmc_reset_target_position(0,4,dmc_get_position(0,4)+50,0);
    }
    ui->Y2_Position->setText(text);
}

void commissioning::on_Y2_BACK_pressed()
{
    QString text=QString::number(dmc_get_position(0,4)-50);
    dmc_pmove(0,4,-50,0);
    ui->Y2_Position->setText(text);
}

void commissioning::on_Z0_UP_pressed()
{
    QString text=QString::number(dmc_get_position(0,0)-50);
    dmc_pmove(0,0,-50,0);
    ui->Z0_Position->setText(text);
}

void commissioning::on_Z0_DOWN_pressed()
{
    QString text=QString::number(dmc_get_position(0,0)+50);
    dmc_pmove(0,0,50,0);
    ui->Z0_Position->setText(text);
}

void commissioning::on_Z1_UP_pressed()
{
    QString text=QString::number(dmc_get_position(0,5)-50);
    dmc_pmove(0,5,-50,0);
    ui->Z1_Position->setText(text);
}

void commissioning::on_Z1_DOWN_pressed()
{
    QString text=QString::number(dmc_get_position(0,5)+50);
    dmc_pmove(0,5,50,0);
    ui->Z1_Position->setText(text);
}


//////////IO crotrol
void commissioning::on_CrossWiseAirCylinder_clicked()
{
    bool state=dmc_read_can_outbit(0,1,0);
    dmc_write_can_outbit(0,1,0,!state);
}

void commissioning::on_AirCylinder1_clicked()
{
    bool state=dmc_read_can_outbit(0,1,1);
    dmc_write_can_outbit(0,1,1,!state);
}

void commissioning::on_AirCylinder2_clicked()
{
    bool state=dmc_read_can_outbit(0,1,2);
    dmc_write_can_outbit(0,1,2,!state);
}

void commissioning::on_AirCylinder3_clicked()
{
    bool state=dmc_read_can_outbit(0,1,3);
    dmc_write_can_outbit(0,1,3,!state);
}

void commissioning::on_AirCylinder4_clicked()
{
    bool state=dmc_read_can_outbit(0,1,4);
    dmc_write_can_outbit(0,1,4,!state);
}

void commissioning::on_AirCylinder5_clicked()
{
    bool state=dmc_read_can_outbit(0,1,5);
    dmc_write_can_outbit(0,1,5,!state);
}

void commissioning::on_AirCylinder6_clicked()
{
    bool state=dmc_read_can_outbit(0,1,6);
    dmc_write_can_outbit(0,1,6,!state);
}

void commissioning::on_GasClaw1_clicked()
{
    bool state=dmc_read_can_outbit(0,1,7);
    dmc_write_can_outbit(0,1,7,!state);
}

void commissioning::on_GasClaw2_clicked()
{
    bool state=dmc_read_can_outbit(0,1,8);
    dmc_write_can_outbit(0,1,8,!state);
}

void commissioning::on_GasClaw3_clicked()
{
    bool state=dmc_read_can_outbit(0,1,9);
    dmc_write_can_outbit(0,1,9,!state);
}

void commissioning::on_GasClaw4_clicked()
{
    bool state=dmc_read_can_outbit(0,1,10);
    dmc_write_can_outbit(0,1,10,!state);
}

void commissioning::on_GasClaw5_clicked()
{
    bool state=dmc_read_can_outbit(0,1,11);
    dmc_write_can_outbit(0,1,11,!state);
}

void commissioning::on_GasClaw6_clicked()
{
    bool state=dmc_read_can_outbit(0,1,12);
    dmc_write_can_outbit(0,1,12,!state);
}

void commissioning::on_Electromagnet1_clicked()
{
    bool state=dmc_read_outbit(0,0);
    dmc_write_outbit(0,0,!state);
}

void commissioning::on_Electromagnet2_clicked()
{
    bool state=dmc_read_outbit(0,1);
    dmc_write_outbit(0,1,!state);
}

void commissioning::on_Electromagnet3_clicked()
{
    bool state=dmc_read_outbit(0,2);
    dmc_write_outbit(0,2,!state);
}

void commissioning::on_Electromagnet4_clicked()
{
    bool state=dmc_read_outbit(0,3);
    dmc_write_outbit(0,3,!state);
}

void commissioning::on_Electromagnet5_clicked()
{
    bool state=dmc_read_outbit(0,4);
    dmc_write_outbit(0,4,!state);
}

void commissioning::on_Electromagnet6_clicked()
{
    bool state=dmc_read_outbit(0,5);
    dmc_write_outbit(0,5,!state);
}

void commissioning::on_Electromagnet7_clicked()
{
    bool state=dmc_read_outbit(0,6);
    dmc_write_outbit(0,6,!state);
}

void commissioning::on_Electromagnet8_clicked()
{
    bool state=dmc_read_outbit(0,7);
    dmc_write_outbit(0,7,!state);
}

void commissioning::on_Electromagnet9_clicked()
{
    bool state=dmc_read_outbit(0,8);
    dmc_write_outbit(0,8,!state);
}

void commissioning::on_Electromagnet10_clicked()
{
    bool state=dmc_read_outbit(0,9);
    dmc_write_outbit(0,9,!state);
}

void commissioning::on_Electromagnet11_clicked()
{
    bool state=dmc_read_outbit(0,10);
    dmc_write_outbit(0,10,!state);
}

void commissioning::on_Electromagnet12_clicked()
{
    bool state=dmc_read_outbit(0,11);
    dmc_write_outbit(0,11,!state);
}

void commissioning::on_HIGH_SPEED_SET_editingFinished()
{
    QSettings *configFile=new QSettings(".\\Q1480\\Temporary_File.ini",QSettings::IniFormat);
    configFile->setValue("Speed_Set/High_Speed",ui->HIGH_SPEED_SET->text());
    delete configFile;
}

void commissioning::on_LOW_SPEED_SET_editingFinished()
{
    QSettings *configFile=new QSettings(".\\Q1480\\Temporary_File.ini",QSettings::IniFormat);
    configFile->setValue("Speed_Set/Low_Speed",ui->LOW_SPEED_SET->text());
    delete configFile;
}
