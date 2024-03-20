/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		headfile
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		ADS v1.2.2
 * @Target core		TC364DP
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-11-23
 ********************************************************************************************************************/
 
#ifndef _headfile_h
#define _headfile_h




#include "SEEKFREE_PRINTF.h"

#include "zf_assert.h"
#include "stdio.h"
#include "math.h"

//#include "../../CODE/Special_Control/speacil_element.h"
#include "ifxAsclin_reg.h"
#include "SysSe/Bsp/Bsp.h"
#include "IfxCcu6_Timer.h"
#include "IfxScuEru.h"

//------逐飞科技单片机外设驱动头文件
#include "zf_gpio.h"
#include "zf_gtm_pwm.h"
#include "zf_uart.h"
#include "zf_ccu6_pit.h"
#include "zf_stm_systick.h"
#include "zf_spi.h"
#include "zf_eru.h"
#include "zf_eru_dma.h"
#include "zf_vadc.h"
#include "zf_gpt12.h"
#include "zf_eeprom.h"

//------逐飞科技产品驱动头文件
#include "SEEKFREE_18TFT.h"
#include "SEEKFREE_FONT.h"
#include "SEEKFREE_FUN.h"
#include "SEEKFREE_IIC.h"
#include "SEEKFREE_IPS114_SPI.h"
#include "SEEKFREE_OLED.h"
#include "SEEKFREE_VIRSCO.h"
#include "SEEKFREE_MT9V03X.h"
#include "SEEKFREE_ICM20602.h"
#include "SEEKFREE_MPU6050.h"
#include "SEEKFREE_MMA8451.h"
#include "SEEKFREE_L3G4200D.h"
#include "SEEKFREE_WIRELESS.h"
#include "SEEKFREE_IPS200_PARALLEL8.h"
#include "SEEKFREE_7725.h"
#include "SEEKFREE_RDA5807.h"
#include "SEEKFREE_7725_UART.h"






/*********************************************************************************************************************
*@Cz库汇总
*********************************************************************************************************************/
#include "openmv.h"
#include "encoder.h"
#include "AD.h"
#include "control.h"
#include "key.h"
#include "menu.h"
#include "pid.h"
#include "spe_init.h"
#include "PCI_init.h"
#include "flashsave.h"
#include "test.h"
#include "Cpu0_Main.h"
#include "model_linear.h"
#include "speacil_api.h"
#include "track.h"
#include "UART.h"
#include "speacil_element_judge.h"
#include "stdlib.h"
//浩奇陀螺仪
#include "icm20602.h"

//调用的话会报错：一个致命的外部错误
//void all_init(void);


/**是否开启测试**/
#define TESTON
#ifdef TESTON
#define mytest 1
#else
#define mytest 0
#endif







/****************结构变量声明以及类定义******************/
struct PID
{
    float err;
    float err_last;
    float angle;

    float err_h;
    float err_x;

    float duty;//占空比输出
    float duty_last;
    float Kp,Kd,Ki;
    float errtmp[5];
    float integ;


    float rate_ai;
    float rate_pid;
};
//steer.err作为电感err.
struct RATE
{
    float err;
    float err_tg;
    float dynamic_kp;
    float ste;
    float ste_lef;
    float ste_rig;
    float err_p;
    float err_n;
    float encoder;


    float sharptrun_stop;
    float outof_sharpturn_str;


    float basic;
    float rush;
    float tg_limit;

    float island_stop;
    float curve_stop;


};
struct FLAG
{
    int str;
    int timeswitch;
    int ste_con;
    int mot_con;
    int test;
    int ai;//ai_swi
    int man_swi;
    int slong_swi;
    int island_fx;



    //赛道状态变化
    int track;
    int con_sharpturn;




    /*特殊控制**/


    /*干簧管停车*/

    int reed;
    int reed_state;
    int reed_stop;


    /*各元素总开关*/

    int start_EN;
    int pro_EN;
    int DD_EN;
    int all_EN;
    int island_EN;
    int right_die_EN;
    int left_die_EN;
    int cross_EN;



    /*过程标志位*/
    int cross_spe;
    int island_spe;
    int T_island_spe;
    int right_fan;
    int right_die_spe;
    int left_fan;
    int left_die_spe;


    int T_island;
    int T_island_out;

    int island;
    int island_out;

    int cross;
    int cross_fx;

    int ramp;



    /*电设*/
    int drug,turn_memory[10],turn_direc;


};
struct CNT
{
    int enc;
    int _1ms,_5ms,_20ms,_250ms,_1s;
    int oled,oled_rst;
//    int cross;

    int inductance_same,inductance_curve;



    int speedout_err0;
    float run_time_limit;

    int save,read;

    /**特殊控制**/





    int flash_xb;

    /*十字参数*/

    int cross_num;
    int cross;
    float cross_open_time[10],cross_close_time[10];

    int cross_xb;

    int out_cross;
    /*坡道参数*/
    int ramp;


    /*旧环岛参数*/
    int T_out_island_continue;
    int island_num;

    float T_island_t1[10],T_island_t2[10],T_island_t3[10];
    float T_island_s1[10],T_island_s2[10],T_island_s3[10];
    int T_island;
    int T_out_island;
    int T_island_xb;



    /*新环岛参数*/
    int island_xb;
    int island;//计时用

    float island_s1[10];
    int island_t1[10];

    /*左打死与右打死控制*/

    int left_die_num;
    int right_die_num;
    int left_die,right_die;
    int left_fan,right_fan;

    int right_die_xb,left_die_xb;
    float right_die_angle[10],left_die_angle[10];

    float left_die_time[10],left_die_to_right_time[10];
    float right_die_time[10],right_die_to_left_time[10];
    float left_die_open_time[10],right_die_open_time[10];
    float left_die_close_time[10],right_die_close_time[10];

    /*人为左右转*/
    int man_left_num;
    int man_right_num;

    int man_left_xb;
    int man_right_xb;

    float man_left_angle[10],man_right_angle[10];
    float man_left_open_time[10],man_right_open_time[10];
    float man_left_close_time[10],man_right_close_time[10];


    /*人为减速*/
    float man_slow_open_time[10],man_slow_close_time[10],man_slow_ra[10];
    /*人为加速*/
    float man_fast_open_time[10],man_fast_close_time[10],man_fast_ra[10];

    /*人为斜电感*/
    int xie_spe;
    float man_xie_open_time[10],man_xie_close_time[10];

    /*超级起步*/
    float str_rush;



    /*电设用的变量*/
    int left,right,turn_num;


};
struct ENCODER
{

    float pulse;
    float expect_speed;//
    float filter_speed;
    float real_speed;
    float speed_control_out;
    float speed_control_out_max;//
    float speed_old,speed_new;
    float all_speedout;
    float distance;

};

struct AD
{
    uint16 left;
    uint16 mid_left;
    uint16 right;
    uint16 mid_right;
    uint16 mid;
    uint16 xie_left,xie_right;
    uint16 shu_left,shu_right;
    uint16 _0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_35,_36,_37,_38,_39,_42,_43,_44,_45,_46,_47,_48,_49; //对应+1是 AN

    uint16 s_left,s_mid_left,s_shu_left,s_xie_Left,s_mid,
           s_right,s_mid_right,s_shu_right,s_xie_right;

    uint16 l_left,l_mid_left,l_shu_left,l_xie_Left,l_mid,
           l_right,l_mid_right,l_shu_right,l_xie_right;



    uint16 s_cha_xie;
    uint16 s_cha_heng;
    uint16 s_sum_mid_heng;
    uint16 s_sum_shu;

    uint16 l_cha_xie;
    uint16 l_cha_heng;
    uint16 l_sum_mid_heng;



};

struct TRY
{
    float ste_du;
    float mot_du;
    float ste_du1;
    float mot_du1;
};

struct AI
{

   uint16 angle;

};
/*电设*/
//Openmv摄像头
struct OPENMV
{
    /**误差类**/
    uint8 data;
    char str[15];
    float err;

    /**控制类**/

    char num_judge;//mv1(art)
    char con_left;//art
    char con_right;//art


    int track;//mv 0:丢线,1:直线,2:十字







    /**发送接受标志**/
};
#endif

