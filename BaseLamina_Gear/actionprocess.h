#ifndef ACTIONPROCESS_H
#define ACTIONPROCESS_H
typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
#include <QObject>
#include "LTDMC.h"
#include "QSettings"
#include <QDebug>
#include <windows.h>

namespace ACTIONPROCESS {
class actionprocess:public QObject
{
    Q_OBJECT
public:
    actionprocess();
    ~actionprocess();
    //the main action progress
    //get the parameter of action
    void get_configure_parameter();
    //my action check function
    void all_axis_check_done();
    void single_axis_check_done(unsigned short,long long);
    //my serial check and wait function
    void wait_main_board_sensor(unsigned short);
    void wait_can_board_sensor(unsigned short);
    void single_axis_action_relative(unsigned short,long long);
    void single_axis_action_absolute(unsigned short,long long);
    void all_origin_back();
    void single_origin_back(unsigned short);
    //judge which thread action
    static int action;
    //variable define
    static bool pause;
    static bool resume;
    static bool action_start;
    static bool origin_start;
    static bool origin_finished;
    //status variable define
    static bool gear_clamp_status;
    static bool gear_set_status;
    static bool base_lamina_clamp_status;
    static bool base_lamina_set_status;
    static bool shoutai1_state;
    static bool shoutai2_state;
    static bool shoutai1_rising_edge;
    static bool shoutai2_rising_edge;
    static bool paoke_rising_edge;
    static bool baselamina_rising_edge;
    static bool shoutai1_origin_back;
    static bool shoutai2_origin_back;
    static bool paoke_origin_back;
    //parameters variable define.
    //gear coordinate
    double gear_coordinate[12][2][3];
    double gear_coordinate_x1;
    double gear_coordinate_x1_2;
    double gear_coordinate_x1_3;
    double gear_coordinate_y1;
    double gear_coordinate_y1_2;
    double gear_coordinate_y1_3;

    double gear_coordinate_x2;
    double gear_coordinate_x2_2;
    double gear_coordinate_x2_3;
    double gear_coordinate_y2;
    double gear_coordinate_y2_2;
    double gear_coordinate_y2_3;

    double gear_coordinate_x3;
    double gear_coordinate_x3_2;
    double gear_coordinate_x3_3;
    double gear_coordinate_y3;
    double gear_coordinate_y3_2;
    double gear_coordinate_y3_3;

    double gear_coordinate_x4;
    double gear_coordinate_x4_2;
    double gear_coordinate_x4_3;
    double gear_coordinate_y4;
    double gear_coordinate_y4_2;
    double gear_coordinate_y4_3;

    double gear_coordinate_x5;
    double gear_coordinate_x5_2;
    double gear_coordinate_x5_3;
    double gear_coordinate_y5;
    double gear_coordinate_y5_2;
    double gear_coordinate_y5_3;

    double gear_coordinate_x6;
    double gear_coordinate_x6_2;
    double gear_coordinate_x6_3;
    double gear_coordinate_y6;
    double gear_coordinate_y6_2;
    double gear_coordinate_y6_3;

    double gear_coordinate_x7;
    double gear_coordinate_x7_2;
    double gear_coordinate_x7_3;
    double gear_coordinate_y7;
    double gear_coordinate_y7_2;
    double gear_coordinate_y7_3;

    double gear_coordinate_x8;
    double gear_coordinate_x8_2;
    double gear_coordinate_x8_3;
    double gear_coordinate_y8;
    double gear_coordinate_y8_2;
    double gear_coordinate_y8_3;

    double gear_coordinate_x9;
    double gear_coordinate_x9_2;
    double gear_coordinate_x9_3;
    double gear_coordinate_y9;
    double gear_coordinate_y9_2;
    double gear_coordinate_y9_3;

    double gear_coordinate_x10;
    double gear_coordinate_x10_2;
    double gear_coordinate_x10_3;
    double gear_coordinate_y10;
    double gear_coordinate_y10_2;
    double gear_coordinate_y10_3;

    double gear_coordinate_x11;
    double gear_coordinate_x11_2;
    double gear_coordinate_x11_3;
    double gear_coordinate_y11;
    double gear_coordinate_y11_2;
    double gear_coordinate_y11_3;

    double gear_coordinate_x12;
    double gear_coordinate_x12_2;
    double gear_coordinate_x12_3;
    double gear_coordinate_y12;
    double gear_coordinate_y12_2;
    double gear_coordinate_y12_3;
    //gear set coordinate.
    double gear_set_shoutai1_x1;
    double gear_set_shoutai1_y1;
    double gear_set_shoutai1_x2;
    double gear_set_shoutai1_y2;
    double gear_set_shoutai1_x3;
    double gear_set_shoutai1_y3;

    double gear_set_shoutai2_x1;
    double gear_set_shoutai2_y1;
    double gear_set_shoutai2_x2;
    double gear_set_shoutai2_y2;
    double gear_set_shoutai2_x3;
    double gear_set_shoutai2_y3;
    //base lamina clamp
    double base_lamina;
    //base lamina set
    double baselamina_set_shoutai1_x1;
    double baselamina_set_shoutai1_y1;
    double baselamina_set_shoutai1_x2;
    double baselamina_set_shoutai1_y2;
    double baselamina_set_shoutai1_x3;
    double baselamina_set_shoutai1_y3;

    double baselamina_set_shoutai2_x1;
    double baselamina_set_shoutai2_y1;
    double baselamina_set_shoutai2_x2;
    double baselamina_set_shoutai2_y2;
    double baselamina_set_shoutai2_x3;
    double baselamina_set_shoutai2_y3;
    //z0 axis position
    double z0_high;
    double z0_low;
    double z0_clamp;
    //z1 axis position
    double z1_high;
    double z1_low;
    double z1_clamp;
    //running speed
    double high_speed;
    double low_speed;
    double acceleration_time;
    double deceleration_time;
    //delay time
    double delay_time;

public slots:
    void slot_action();
    void slot_pause(bool);
    void slot_origin_back();
    void shoutai1_rising_edge_check();
    void shoutai2_rising_edge_check();
    void paoke_rising_edge_check();
    void baselamina_rising_edge_check();
};
}


#endif // ACTIONPROCESS_H
