/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 *
 * @file            control
 * @function        ¿ØÖÆ
 * @author          Cz
 * @date            2021-7-10
 ********************************************************************************************************************/
#include "headfile.h"
void Control_Init()
{
    motor_init;
    motor1_init;
    steer_init;
    steer1_init;

}

void steer_control()
{
    if(flag.island==1 && cnt.island>=cnt.man_slow_open_time[1]*1000)
        servo(test.ste_du);

    else if (!flag.man_swi)
        servo(steer.duty);
    else
        servo(test.ste_du);


}

void motor_control()
{
    if (cnt._1ms>0 &&cnt._1ms<=cnt.str_rush*1000 && flag.start_EN)
    {
        motor1(8000);
    }

    else if (flag.island==1)
    {
        motor1(test.mot_du);
    }

//
//    #ifdef CROSS_DEC
//    else if (cnt.out_cross*5>=cnt.man_xie_open_time[2]*1000 && cnt.out_cross*5<cnt.man_xie_close_time[2]*1000)
//    {
//        motor1(enc.speed_control_out*rate.basic);
//    }
//    #endif
    /*±Õ»·*/
    else if (!flag.man_swi)
    {
//        if (flag.con_sharpturn==2)
//            motor1(enc.speed_control_out*rate.basic);
//        else if (flag.con_sharpturn==1)
//            motor1(enc.speed_control_out*rate.basic*rate.sharptrun_stop);
//        else
//            motor1(enc.speed_control_out*rate.basic*rate.outof_sharpturn_str);
        motor1(enc.speed_control_out*rate.basic);
    }
    else
    {
        motor1(test.mot_du);
    }
}











