#ifndef COMMISSIONING_H
#define COMMISSIONING_H
typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
#include <QDialog>
#include <QString>
#include <QSettings>
#include "LTDMC.h"

namespace Ui {
class commissioning;
}

class commissioning : public QDialog
{
    Q_OBJECT

public:
    explicit commissioning(QWidget *parent = 0);
    ~commissioning();

private slots:
    void on_HIGH_SPEED_clicked();

    void on_LOW_SPEED_clicked();

    void on_Y0_AHEAD_pressed();

    void on_YO_BACK_pressed();

    void on_Y1_AHEAD_pressed();

    void on_Y1_BACK_pressed();

    void on_Y2_AHEAD_pressed();

    void on_Y2_BACK_pressed();

    void on_X0_LEFT_pressed();

    void on_X0_RIGHT_pressed();

    void on_X1_LEFT_pressed();

    void on_X1_RIGHT_pressed();

    void on_Z0_UP_pressed();

    void on_Z0_DOWN_pressed();

    void on_Z1_UP_pressed();

    void on_Z1_DOWN_pressed();

    void on_CrossWiseAirCylinder_clicked();

    void on_AirCylinder1_clicked();

    void on_AirCylinder2_clicked();

    void on_AirCylinder3_clicked();

    void on_AirCylinder4_clicked();

    void on_AirCylinder5_clicked();

    void on_AirCylinder6_clicked();

    void on_GasClaw1_clicked();

    void on_GasClaw2_clicked();

    void on_GasClaw3_clicked();

    void on_GasClaw4_clicked();

    void on_GasClaw5_clicked();

    void on_GasClaw6_clicked();

    void on_Electromagnet1_clicked();

    void on_Electromagnet2_clicked();

    void on_Electromagnet3_clicked();

    void on_Electromagnet4_clicked();

    void on_Electromagnet5_clicked();

    void on_Electromagnet6_clicked();

    void on_Electromagnet7_clicked();

    void on_Electromagnet8_clicked();

    void on_Electromagnet9_clicked();

    void on_Electromagnet10_clicked();

    void on_Electromagnet11_clicked();

    void on_Electromagnet12_clicked();

    void on_HIGH_SPEED_SET_editingFinished();

    void on_LOW_SPEED_SET_editingFinished();

private:
    Ui::commissioning *ui;
};

#endif // COMMISSIONING_H
