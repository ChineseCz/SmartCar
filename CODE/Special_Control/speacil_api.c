/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 *
 * @file            spe
 * @function        特殊控制封装函数API
 * @author          Cz
 * @date            2021-7-10
 * @注释            国赛赛道自行设计循环多圈，一些特殊点可刷新断点并采取特殊控制追求极限速度，适用于提前知道赛道，比如主办方杭电。
 ********************************************************************************************************************/
#include "headfile.h"


void spe_judge()
{

    /*环*/
//    if (flag.island_EN) into_island_T_out();
    if (flag.island_EN) into_island_F_out();
//    into_ramp();

    /*左与右打死*/
    if (flag.left_die_EN && flag.left_die_spe ) into_left_die();
    if (flag.right_die_EN && flag.right_die_spe ) into_right_die();

    /*十字*/
    into_cross();

}


void spe_control()
{


    /*出环右转*/
    //int last_man=2;
    if (cnt.T_out_island_continue*5>=cnt.man_right_open_time[0]*1000 && cnt.T_out_island_continue*5<cnt.man_right_close_time[0]*1000)
    {
        if (ad.mid_left + ad.mid_right >400 ) steer.duty=cnt.man_right_angle[0];
    }
//    if (cnt.out_cross*5>cnt.man_xie_close_time[2]*1000)
//    {
//        gpio_set(P00_0);
//    }
    /******坡道转弯********/
    if (cnt.ramp*5>cnt.man_left_open_time[0]*1000 && cnt.ramp*5<cnt.man_left_close_time[0]*1000)
    {
//        gpio_set(P00_0,1);
        if (ad.mid_left + ad.mid_right >400 ) steer.duty = cnt.man_left_angle[0];
        else if (ad.mid_left + ad.mid_right < 200 && flag.start_EN ) steer.duty = cnt.man_left_angle[1];
    }
    else if(cnt.ramp*5>cnt.man_left_close_time[0]*1000)
    {
//        gpio_set(P00_0,0);
        cnt.ramp=0;
        flag.ramp=0;
    }
    /****************十字定点转弯*******************/
    #ifndef CROSS_DEC
    /*进十字俩转弯*/
    for (int i=1;i<=last_man;i++)
    if (cnt.out_cross*5>=cnt.man_right_open_time[i]*1000 && cnt.out_cross*5<cnt.man_right_close_time[i]*1000)
    {
         gpio_set(P00_0,1);
//        steer.duty=cnt.man_right_angle[i];

    }
    #endif
    /*重启十字判断*/
    if (cnt.out_cross*5>cnt.man_xie_close_time[0]*1000)
    {
        cnt.out_cross=0;
        flag.cross_fx=0;
    }
    /************************************************/





    //左打死与右打死
    if (flag.right_fan&&flag.right_die_spe) steer.duty=cnt.right_die_angle[cnt.right_die_xb];
    if (flag.left_fan&&flag.left_die_spe) steer.duty=cnt.left_die_angle[cnt.left_die_xb];

   //  有出环判断的出入环(还没加数组)
    if (flag.T_island && flag.T_island_out==0 && flag.T_island_spe )  steer.duty =cnt.T_island_s1[flag.island_fx];
    else if (flag.T_island && flag.T_island_out==1)  steer.duty =cnt.T_island_s2[flag.island_fx];
//    else if (flag.T_island_out==2)  steer.duty =cnt.T_island_s3[flag.island_fx];



    // 无出环判断的出入环
//    if (flag.island && flag.island_out==0 && flag.island_spe) steer.duty=cnt.island_s1[cnt.island_xb];



}
