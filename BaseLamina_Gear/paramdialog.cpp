#include "paramdialog.h"
#include "ui_paramdialog.h"

//    //Test of delay time.
//    std::this_thread::sleep_for(std::chrono::milliseconds(1000));//delay for 1000ms(so as 1s)
//    std::cout<<"Hello World"<<std::endl;

ParamDialog::ParamDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParamDialog)
{
    ui->setupUi(this);
//    connect(this,SIGNAL(signal_parameters_changed()),
    disp_configure_parameter();
    lock_ui(true);
}

ParamDialog::~ParamDialog()
{
    delete ui;
}

void ParamDialog::set_configure_parameter()
{
    QSettings *configFile=new QSettings(".\\Q1480\\Parameter_Configure.ini",QSettings::IniFormat);
    ///Parameters of GearClamp.
    configFile->setValue("Gear_Clamp_Coordinate/X1",ui->GearClamp1_X->text());
    configFile->setValue("Gear_Clamp_Coordinate/X1_2",ui->GearClamp1_X_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/X1_3",ui->GearClamp1_X_3->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y1",ui->GearClamp1_Y->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y1_2",ui->GearClamp1_Y_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y1_3",ui->GearClamp1_Y_3->text());

    configFile->setValue("Gear_Clamp_Coordinate/X2",ui->GearClamp2_X->text());
    configFile->setValue("Gear_Clamp_Coordinate/X2_2",ui->GearClamp2_X_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/X2_3",ui->GearClamp2_X_3->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y2",ui->GearClamp2_Y->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y2_2",ui->GearClamp2_Y_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y2_3",ui->GearClamp2_Y_3->text());

    configFile->setValue("Gear_Clamp_Coordinate/X3",ui->GearClamp3_X->text());
    configFile->setValue("Gear_Clamp_Coordinate/X3_2",ui->GearClamp3_X_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/X3_3",ui->GearClamp3_X_3->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y3",ui->GearClamp3_Y->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y3_2",ui->GearClamp3_Y_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y3_3",ui->GearClamp3_Y_3->text());

    configFile->setValue("Gear_Clamp_Coordinate/X4",ui->GearClamp4_X->text());
    configFile->setValue("Gear_Clamp_Coordinate/X4_2",ui->GearClamp4_X_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/X4_3",ui->GearClamp4_X_3->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y4",ui->GearClamp4_Y->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y4_2",ui->GearClamp4_Y_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y4_3",ui->GearClamp4_Y_3->text());

    configFile->setValue("Gear_Clamp_Coordinate/X5",ui->GearClamp5_X->text());
    configFile->setValue("Gear_Clamp_Coordinate/X5_2",ui->GearClamp5_X_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/X5_3",ui->GearClamp5_X_3->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y5",ui->GearClamp5_Y->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y5_2",ui->GearClamp5_Y_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y5_3",ui->GearClamp5_Y_3->text());

    configFile->setValue("Gear_Clamp_Coordinate/X6",ui->GearClamp6_X->text());
    configFile->setValue("Gear_Clamp_Coordinate/X6_2",ui->GearClamp6_X_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/X6_3",ui->GearClamp6_X_3->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y6",ui->GearClamp6_Y->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y6_2",ui->GearClamp6_Y_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y6_3",ui->GearClamp6_Y_3->text());

    configFile->setValue("Gear_Clamp_Coordinate/X7",ui->GearClamp7_X->text());
    configFile->setValue("Gear_Clamp_Coordinate/X7_2",ui->GearClamp7_X_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/X7_3",ui->GearClamp7_X_3->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y7",ui->GearClamp7_Y->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y7_2",ui->GearClamp7_Y_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y7_3",ui->GearClamp7_Y_3->text());

    configFile->setValue("Gear_Clamp_Coordinate/X8",ui->GearClamp8_X->text());
    configFile->setValue("Gear_Clamp_Coordinate/X8_2",ui->GearClamp8_X_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/X8_3",ui->GearClamp8_X_3->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y8",ui->GearClamp8_Y->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y8_2",ui->GearClamp8_Y_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y8_3",ui->GearClamp8_Y_3->text());

    configFile->setValue("Gear_Clamp_Coordinate/X9",ui->GearClamp9_X->text());
    configFile->setValue("Gear_Clamp_Coordinate/X9_2",ui->GearClamp9_X_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/X9_3",ui->GearClamp9_X_3->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y9",ui->GearClamp9_Y->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y9_2",ui->GearClamp9_Y_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y9_3",ui->GearClamp9_Y_3->text());

    configFile->setValue("Gear_Clamp_Coordinate/X10",ui->GearClamp10_X->text());
    configFile->setValue("Gear_Clamp_Coordinate/X10_2",ui->GearClamp10_X_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/X10_3",ui->GearClamp10_X_3->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y10",ui->GearClamp10_Y->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y10_2",ui->GearClamp10_Y_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y10_3",ui->GearClamp10_Y_3->text());

    configFile->setValue("Gear_Clamp_Coordinate/X11",ui->GearClamp11_X->text());
    configFile->setValue("Gear_Clamp_Coordinate/X11_2",ui->GearClamp11_X_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/X11_3",ui->GearClamp11_X_3->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y11",ui->GearClamp11_Y->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y11_2",ui->GearClamp11_Y_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y11_3",ui->GearClamp11_Y_3->text());

    configFile->setValue("Gear_Clamp_Coordinate/X12",ui->GearClamp12_X->text());
    configFile->setValue("Gear_Clamp_Coordinate/X12_2",ui->GearClamp12_X_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/X12_3",ui->GearClamp12_X_3->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y12",ui->GearClamp12_Y->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y12_2",ui->GearClamp12_Y_2->text());
    configFile->setValue("Gear_Clamp_Coordinate/Y12_3",ui->GearClamp12_Y_3->text());
    ///Parameters of GearSetting.
    //shoutai1
    configFile->setValue("Gear_Setting_Coordinate/ShouTai1_X1",ui->GearSet1_1_X->text());
    configFile->setValue("Gear_Setting_Coordinate/ShouTai1_Y1",ui->GearSet1_1_Y->text());
    configFile->setValue("Gear_Setting_Coordinate/ShouTai1_X2",ui->GearSet1_2_X->text());
    configFile->setValue("Gear_Setting_Coordinate/ShouTai1_Y2",ui->GearSet1_2_Y->text());
    configFile->setValue("Gear_Setting_Coordinate/ShouTai1_X3",ui->GearSet1_3_X->text());
    configFile->setValue("Gear_Setting_Coordinate/ShouTai1_Y3",ui->GearSet1_3_Y->text());
    //shoutai2
    configFile->setValue("Gear_Setting_Coordinate/ShouTai2_X1",ui->GearSet2_1_X->text());
    configFile->setValue("Gear_Setting_Coordinate/ShouTai2_Y1",ui->GearSet2_1_Y->text());
    configFile->setValue("Gear_Setting_Coordinate/ShouTai2_X2",ui->GearSet2_2_X->text());
    configFile->setValue("Gear_Setting_Coordinate/ShouTai2_Y2",ui->GearSet2_2_Y->text());
    configFile->setValue("Gear_Setting_Coordinate/ShouTai2_X3",ui->GearSet2_3_X->text());
    configFile->setValue("Gear_Setting_Coordinate/ShouTai2_Y3",ui->GearSet2_3_Y->text());
    ///Parameter of BaseLaminaClamp.
    configFile->setValue("BaseLamina_Clamp_Coordinate/BaseLaminaClamp",ui->BaseLaminaClamp->text());
    ///Parameters of BaseLaminaSetting.
    //shoutai1
    configFile->setValue("BaseLamina_Setting_Coordinate/ShouTai1_X1",ui->BaseLaminaSet1_1_X->text());
    configFile->setValue("BaseLamina_Setting_Coordinate/ShouTai1_Y1",ui->BaseLaminaSet1_1_Y->text());
    configFile->setValue("BaseLamina_Setting_Coordinate/ShouTai1_X2",ui->BaseLaminaSet1_2_X->text());
    configFile->setValue("BaseLamina_Setting_Coordinate/ShouTai1_Y2",ui->BaseLaminaSet1_2_Y->text());
    configFile->setValue("BaseLamina_Setting_Coordinate/ShouTai1_X3",ui->BaseLaminaSet1_3_X->text());
    configFile->setValue("BaseLamina_Setting_Coordinate/ShouTai1_Y3",ui->BaseLaminaSet1_3_Y->text());
    //shoutai2
    configFile->setValue("BaseLamina_Setting_Coordinate/ShouTai2_X1",ui->BaseLaminaSet2_1_X->text());
    configFile->setValue("BaseLamina_Setting_Coordinate/ShouTai2_Y1",ui->BaseLaminaSet2_1_Y->text());
    configFile->setValue("BaseLamina_Setting_Coordinate/ShouTai2_X2",ui->BaseLaminaSet2_2_X->text());
    configFile->setValue("BaseLamina_Setting_Coordinate/ShouTai2_Y2",ui->BaseLaminaSet2_2_Y->text());
    configFile->setValue("BaseLamina_Setting_Coordinate/ShouTai2_X3",ui->BaseLaminaSet2_3_X->text());
    configFile->setValue("BaseLamina_Setting_Coordinate/ShouTai2_Y3",ui->BaseLaminaSet2_3_Y->text());
    ///Parameters of Z0 axis position.
    configFile->setValue("Z0_Position/HighPosition",ui->Z0_High->text());
    configFile->setValue("Z0_Position/LowPosition",ui->Z0_Low->text());
    configFile->setValue("Z0_Position/ClampPosition",ui->Z0_Clamp->text());
    ///Parameters of Z1 axis position.
    configFile->setValue("Z1_Position/HighPosition",ui->Z1_High->text());
    configFile->setValue("Z1_Position/LowPosition",ui->Z1_Low->text());
    configFile->setValue("Z1_Position/ClampPosition",ui->Z1_Clamp->text());
    ///Parameters of Running Speed.
    configFile->setValue("Running_Speed/HighSpeed",ui->HighSpeed->text());
    configFile->setValue("Running_Speed/LowSpeed",ui->LowSpeed->text());
    configFile->setValue("Running_Speed/AccelerationTime",ui->AccelerationTime->text());
    configFile->setValue("Running_Speed/DecelerationTime",ui->DecelerationTime->text());
    ///Parameter of DelayTime.
    configFile->setValue("DelayTime/seconds",ui->DelayTime->text());

    delete configFile;
}

void ParamDialog::disp_configure_parameter()
{
    QSettings *configFile=new QSettings(".\\Q1480\\Parameter_Configure.ini",QSettings::IniFormat);
    ///Parameters of GearClamp.
    ui->GearClamp1_X->setText(configFile->value("Gear_Clamp_Coordinate/X1").toString());
    ui->GearClamp1_X_2->setText(configFile->value("Gear_Clamp_Coordinate/X1_2").toString());
    ui->GearClamp1_X_3->setText(configFile->value("Gear_Clamp_Coordinate/X1_3").toString());
    ui->GearClamp1_Y->setText(configFile->value("Gear_Clamp_Coordinate/Y1").toString());
    ui->GearClamp1_Y_2->setText(configFile->value("Gear_Clamp_Coordinate/Y1_2").toString());
    ui->GearClamp1_Y_3->setText(configFile->value("Gear_Clamp_Coordinate/Y1_3").toString());

    ui->GearClamp2_X->setText(configFile->value("Gear_Clamp_Coordinate/X2").toString());
    ui->GearClamp2_X_2->setText(configFile->value("Gear_Clamp_Coordinate/X2_2").toString());
    ui->GearClamp2_X_3->setText(configFile->value("Gear_Clamp_Coordinate/X2_3").toString());
    ui->GearClamp2_Y->setText(configFile->value("Gear_Clamp_Coordinate/Y2").toString());
    ui->GearClamp2_Y_2->setText(configFile->value("Gear_Clamp_Coordinate/Y2_2").toString());
    ui->GearClamp2_Y_3->setText(configFile->value("Gear_Clamp_Coordinate/Y2_3").toString());

    ui->GearClamp3_X->setText(configFile->value("Gear_Clamp_Coordinate/X3").toString());
    ui->GearClamp3_X_2->setText(configFile->value("Gear_Clamp_Coordinate/X3_2").toString());
    ui->GearClamp3_X_3->setText(configFile->value("Gear_Clamp_Coordinate/X3_3").toString());
    ui->GearClamp3_Y->setText(configFile->value("Gear_Clamp_Coordinate/Y3").toString());
    ui->GearClamp3_Y_2->setText(configFile->value("Gear_Clamp_Coordinate/Y3_2").toString());
    ui->GearClamp3_Y_3->setText(configFile->value("Gear_Clamp_Coordinate/Y3_3").toString());

    ui->GearClamp4_X->setText(configFile->value("Gear_Clamp_Coordinate/X4").toString());
    ui->GearClamp4_X_2->setText(configFile->value("Gear_Clamp_Coordinate/X4_2").toString());
    ui->GearClamp4_X_3->setText(configFile->value("Gear_Clamp_Coordinate/X4_3").toString());
    ui->GearClamp4_Y->setText(configFile->value("Gear_Clamp_Coordinate/Y4").toString());
    ui->GearClamp4_Y_2->setText(configFile->value("Gear_Clamp_Coordinate/Y4_2").toString());
    ui->GearClamp4_Y_3->setText(configFile->value("Gear_Clamp_Coordinate/Y4_3").toString());

    ui->GearClamp5_X->setText(configFile->value("Gear_Clamp_Coordinate/X5").toString());
    ui->GearClamp5_X_2->setText(configFile->value("Gear_Clamp_Coordinate/X5_2").toString());
    ui->GearClamp5_X_3->setText(configFile->value("Gear_Clamp_Coordinate/X5_3").toString());
    ui->GearClamp5_Y->setText(configFile->value("Gear_Clamp_Coordinate/Y5").toString());
    ui->GearClamp5_Y_2->setText(configFile->value("Gear_Clamp_Coordinate/Y5_2").toString());
    ui->GearClamp5_Y_3->setText(configFile->value("Gear_Clamp_Coordinate/Y5_3").toString());

    ui->GearClamp6_X->setText(configFile->value("Gear_Clamp_Coordinate/X6").toString());
    ui->GearClamp6_X_2->setText(configFile->value("Gear_Clamp_Coordinate/X6_2").toString());
    ui->GearClamp6_X_3->setText(configFile->value("Gear_Clamp_Coordinate/X6_3").toString());
    ui->GearClamp6_Y->setText(configFile->value("Gear_Clamp_Coordinate/Y6").toString());
    ui->GearClamp6_Y_2->setText(configFile->value("Gear_Clamp_Coordinate/Y6_2").toString());
    ui->GearClamp6_Y_3->setText(configFile->value("Gear_Clamp_Coordinate/Y6_3").toString());

    ui->GearClamp7_X->setText(configFile->value("Gear_Clamp_Coordinate/X7").toString());
    ui->GearClamp7_X_2->setText(configFile->value("Gear_Clamp_Coordinate/X7_2").toString());
    ui->GearClamp7_X_3->setText(configFile->value("Gear_Clamp_Coordinate/X7_3").toString());
    ui->GearClamp7_Y->setText(configFile->value("Gear_Clamp_Coordinate/Y7").toString());
    ui->GearClamp7_Y_2->setText(configFile->value("Gear_Clamp_Coordinate/Y7_2").toString());
    ui->GearClamp7_Y_3->setText(configFile->value("Gear_Clamp_Coordinate/Y7_3").toString());

    ui->GearClamp8_X->setText(configFile->value("Gear_Clamp_Coordinate/X8").toString());
    ui->GearClamp8_X_2->setText(configFile->value("Gear_Clamp_Coordinate/X8_2").toString());
    ui->GearClamp8_X_3->setText(configFile->value("Gear_Clamp_Coordinate/X8_3").toString());
    ui->GearClamp8_Y->setText(configFile->value("Gear_Clamp_Coordinate/Y8").toString());
    ui->GearClamp8_Y_2->setText(configFile->value("Gear_Clamp_Coordinate/Y8_2").toString());
    ui->GearClamp8_Y_3->setText(configFile->value("Gear_Clamp_Coordinate/Y8_3").toString());

    ui->GearClamp9_X->setText(configFile->value("Gear_Clamp_Coordinate/X9").toString());
    ui->GearClamp9_X_2->setText(configFile->value("Gear_Clamp_Coordinate/X9_2").toString());
    ui->GearClamp9_X_3->setText(configFile->value("Gear_Clamp_Coordinate/X9_3").toString());
    ui->GearClamp9_Y->setText(configFile->value("Gear_Clamp_Coordinate/Y9").toString());
    ui->GearClamp9_Y_2->setText(configFile->value("Gear_Clamp_Coordinate/Y9_2").toString());
    ui->GearClamp9_Y_3->setText(configFile->value("Gear_Clamp_Coordinate/Y9_3").toString());

    ui->GearClamp10_X->setText(configFile->value("Gear_Clamp_Coordinate/X10").toString());
    ui->GearClamp10_X_2->setText(configFile->value("Gear_Clamp_Coordinate/X10_2").toString());
    ui->GearClamp10_X_3->setText(configFile->value("Gear_Clamp_Coordinate/X10_3").toString());
    ui->GearClamp10_Y->setText(configFile->value("Gear_Clamp_Coordinate/Y10").toString());
    ui->GearClamp10_Y_2->setText(configFile->value("Gear_Clamp_Coordinate/Y10_2").toString());
    ui->GearClamp10_Y_3->setText(configFile->value("Gear_Clamp_Coordinate/Y10_3").toString());

    ui->GearClamp11_X->setText(configFile->value("Gear_Clamp_Coordinate/X11").toString());
    ui->GearClamp11_X_2->setText(configFile->value("Gear_Clamp_Coordinate/X11_2").toString());
    ui->GearClamp11_X_3->setText(configFile->value("Gear_Clamp_Coordinate/X11_3").toString());
    ui->GearClamp11_Y->setText(configFile->value("Gear_Clamp_Coordinate/Y11").toString());
    ui->GearClamp11_Y_2->setText(configFile->value("Gear_Clamp_Coordinate/Y11_2").toString());
    ui->GearClamp11_Y_3->setText(configFile->value("Gear_Clamp_Coordinate/Y11_3").toString());

    ui->GearClamp12_X->setText(configFile->value("Gear_Clamp_Coordinate/X12").toString());
    ui->GearClamp12_X_2->setText(configFile->value("Gear_Clamp_Coordinate/X12_2").toString());
    ui->GearClamp12_X_3->setText(configFile->value("Gear_Clamp_Coordinate/X12_3").toString());
    ui->GearClamp12_Y->setText(configFile->value("Gear_Clamp_Coordinate/Y12").toString());
    ui->GearClamp12_Y_2->setText(configFile->value("Gear_Clamp_Coordinate/Y12_2").toString());
    ui->GearClamp12_Y_3->setText(configFile->value("Gear_Clamp_Coordinate/Y12_3").toString());
    ///Parameters of GearSetting.
    //shoutai1
    ui->GearSet1_1_X->setText(configFile->value("Gear_Setting_Coordinate/ShouTai1_X1").toString());
    ui->GearSet1_1_Y->setText(configFile->value("Gear_Setting_Coordinate/ShouTai1_Y1").toString());
    ui->GearSet1_2_X->setText(configFile->value("Gear_Setting_Coordinate/ShouTai1_X2").toString());
    ui->GearSet1_2_Y->setText(configFile->value("Gear_Setting_Coordinate/ShouTai1_Y2").toString());
    ui->GearSet1_3_X->setText(configFile->value("Gear_Setting_Coordinate/ShouTai1_X3").toString());
    ui->GearSet1_3_Y->setText(configFile->value("Gear_Setting_Coordinate/ShouTai1_Y3").toString());
    //shoutai2
    ui->GearSet2_1_X->setText(configFile->value("Gear_Setting_Coordinate/ShouTai2_X1").toString());
    ui->GearSet2_1_Y->setText(configFile->value("Gear_Setting_Coordinate/ShouTai2_Y1").toString());
    ui->GearSet2_2_X->setText(configFile->value("Gear_Setting_Coordinate/ShouTai2_X2").toString());
    ui->GearSet2_2_Y->setText(configFile->value("Gear_Setting_Coordinate/ShouTai2_Y2").toString());
    ui->GearSet2_3_X->setText(configFile->value("Gear_Setting_Coordinate/ShouTai2_X3").toString());
    ui->GearSet2_3_Y->setText(configFile->value("Gear_Setting_Coordinate/ShouTai2_Y3").toString());
    ///Parameter of BaseLaminaClamp.
    ui->BaseLaminaClamp->setText(configFile->value("BaseLamina_Clamp_Coordinate/BaseLaminaClamp").toString());
    ///Parameters of BaseLaminaSetting.
    //shoutai1
    ui->BaseLaminaSet1_1_X->setText(configFile->value("BaseLamina_Setting_Coordinate/ShouTai1_X1").toString());
    ui->BaseLaminaSet1_1_Y->setText(configFile->value("BaseLamina_Setting_Coordinate/ShouTai1_Y1").toString());
    ui->BaseLaminaSet1_2_X->setText(configFile->value("BaseLamina_Setting_Coordinate/ShouTai1_X2").toString());
    ui->BaseLaminaSet1_2_Y->setText(configFile->value("BaseLamina_Setting_Coordinate/ShouTai1_Y2").toString());
    ui->BaseLaminaSet1_3_X->setText(configFile->value("BaseLamina_Setting_Coordinate/ShouTai1_X3").toString());
    ui->BaseLaminaSet1_3_Y->setText(configFile->value("BaseLamina_Setting_Coordinate/ShouTai1_Y3").toString());
    //shoutai2
    ui->BaseLaminaSet2_1_X->setText(configFile->value("BaseLamina_Setting_Coordinate/ShouTai2_X1").toString());
    ui->BaseLaminaSet2_1_Y->setText(configFile->value("BaseLamina_Setting_Coordinate/ShouTai2_Y1").toString());
    ui->BaseLaminaSet2_2_X->setText(configFile->value("BaseLamina_Setting_Coordinate/ShouTai2_X2").toString());
    ui->BaseLaminaSet2_2_Y->setText(configFile->value("BaseLamina_Setting_Coordinate/ShouTai2_Y2").toString());
    ui->BaseLaminaSet2_3_X->setText(configFile->value("BaseLamina_Setting_Coordinate/ShouTai2_X3").toString());
    ui->BaseLaminaSet2_3_Y->setText(configFile->value("BaseLamina_Setting_Coordinate/ShouTai2_Y3").toString());
    ///Parameters of Z0 axis position.
    ui->Z0_High->setText(configFile->value("Z0_Position/HighPosition").toString());
    ui->Z0_Low->setText(configFile->value("Z0_Position/LowPosition").toString());
    ui->Z0_Clamp->setText(configFile->value("Z0_Position/ClampPosition").toString());
    ///Parameters of Z1 axis position.
    ui->Z1_High->setText(configFile->value("Z1_Position/HighPosition").toString());
    ui->Z1_Low->setText(configFile->value("Z1_Position/LowPosition").toString());
    ui->Z1_Clamp->setText(configFile->value("Z1_Position/ClampPosition").toString());
    ///Parameters of Running Speed.
    ui->HighSpeed->setText(configFile->value("Running_Speed/HighSpeed").toString());
    ui->LowSpeed->setText(configFile->value("Running_Speed/LowSpeed").toString());
    ui->AccelerationTime->setText(configFile->value("Running_Speed/AccelerationTime").toString());
    ui->DecelerationTime->setText(configFile->value("Running_Speed/DecelerationTime").toString());
    ///Parameter of DelayTime.
    ui->DelayTime->setText(configFile->value("DelayTime/seconds").toString());

    delete configFile;
}

void ParamDialog::on_CHANGE_clicked()
{
    lock_ui(false);
    ui->CHANGE->setEnabled(false);
}

void ParamDialog::on_ALL_CONFIRM_clicked()
{
    switch( QMessageBox::information( this, tr("Parameters Setting"),tr("Really Change?"),\
            tr("Yes"), tr("No"),0, 1 ) ) //  the symbol "\" is a sign to shift the index and line feed
  {
    case 0:
        set_configure_parameter();
        lock_ui(true);
        ui->CHANGE->setEnabled(true);
//        emit signal_parameters_changed(); for real-time change the parameter
        break;
    case 1:
        break;
    default:
        break;
  }
}

void ParamDialog::on_CLOSE_clicked()
{
    close();
}

void ParamDialog::lock_ui(bool YN)
{
    auto all_QObject=this->children();
    QObjectList::iterator i;
    for(i=all_QObject.begin();i!=all_QObject.end();++i)
    {
        QObject *wid=*i;
        if(wid->isWidgetType()&&wid->objectName()!="CHANGE"&&wid->objectName()!="CLOSE")
        {
            static_cast<QWidget*>(wid)->setEnabled(!YN);
        }
    }
}
