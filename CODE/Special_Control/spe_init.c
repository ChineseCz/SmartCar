/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 *
 * @file            spe
 * @function        特殊控制变量初始化
 * @author          Cz
 * @date            2021-7-10
 ********************************************************************************************************************/
#include "headfile.h"
/**初始化一些其他文件变量**/

#define All_spe_Init 1
#define INF 999


void Spe_Init()
{
    //总开关
    flag.all_EN=All_spe_Init;
    //下标
    cnt.left_die_xb=0;
    cnt.right_die_xb=0;
    cnt.cross_xb=0;
    cnt.flash_xb=0;



    /*EN控制进入元素控制程序与spe开启时间*/

    /*环岛*/
    cnt.island_num=1;
    flag.island_EN=1;


    flag.T_island_spe=1;
    flag.island_spe=1;
    for (int i=0;i<10;i++)
    {

        cnt.T_island_t1[i]=100;
        cnt.T_island_t2[i]=30;
        cnt.T_island_t3[i]=40;
        cnt.T_island_s1[i]=440;
        cnt.T_island_s2[i]=500;
        cnt.T_island_s3[i]=440;
    }



    /*左右打死*/
    cnt.left_die_num=0;
    cnt.right_die_num=0;
    flag.left_die_EN=0;
    flag.right_die_EN=0;
    flag.left_die_spe=0;
    flag.right_die_spe=0;
    for (int i=0;i<10;i++)
    {
        cnt.left_die_open_time[i]=INF;
        cnt.left_die_close_time[i]=0;
        cnt.left_die_time[i]=0;
        cnt.left_die_to_right_time[i]=0;
        cnt.left_die_angle[i]=0;

        cnt.right_die_open_time[0]=INF;
        cnt.right_die_close_time[0]=0;
        cnt.right_die_time[0]=0;
        cnt.right_die_to_left_time[0]=0;
        cnt.right_die_angle[0]=0;
    }

    /*十字*/
    flag.cross_EN=0;
    flag.cross_spe=0;
    for (int i=0;i<10;i++)
    {
        cnt.cross_open_time[0]=INF;
        cnt.cross_close_time[0]=INF;
    }

    /***过程标志位***/

    /*无出环环岛*/
    flag.island=0;//检测环岛交叉点
    flag.island_out=0; //环岛状态
    cnt.island=0;


    /*有出环环岛*/
    flag.T_island=0;//检测环岛交叉点
    flag.T_island_out=0; //环岛状态
    cnt.T_island=0;

    /*左右打死*/
    flag.left_die_spe=0;//检测是否打开
    flag.right_die_spe=0;//检测是否打开
    flag.left_fan=0;
    flag.right_fan=0;
    cnt.left_fan=0;
    cnt.right_fan=0;
    cnt.left_die=0;
    cnt.right_die=0;


    /*停车*/
    cnt.run_time_limit=80;

}







