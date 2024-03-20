/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 *
 * @file            spe
 * @function        特殊元素判断
 * @author          Cz
 * @date            2021-7-10
 * @注释            into_right_die与left_die是用于几字直角打死回正，但作用不大，其实调好PID用斜电感就够了。
 ********************************************************************************************************************/
#include "headfile.h"
float tmp1,tmp2;
int turn_num=1;

void into_right_die()//打死
{
    if (steer.duty>=SERVO_MAX)
        cnt.right_die++;
    else
        cnt.right_die=0;

    if (cnt.right_die>=cnt.right_die_time[cnt.right_die_xb] || flag.right_fan)
    {
        flag.right_fan=1;
        cnt.right_fan++;
        if (cnt.right_fan>=cnt.right_die_to_left_time[cnt.right_die_xb])
        {
            flag.right_fan=0;
            cnt.right_fan=0;
            flag.right_die_spe=0;//关闭检测，防止误判
            cnt.right_die_xb++;
        }
    }

}
void into_left_die()//打死
{
    if (steer.duty<=SERVO_MIN)
        cnt.left_die++;
    else
        cnt.left_die=0;

    if (cnt.left_die>=cnt.left_die_time[cnt.left_die_xb] || flag.left_fan)
    {
        flag.left_fan=1;
        cnt.left_fan++;
        if (cnt.left_fan>=cnt.left_die_to_right_time[cnt.left_die_xb])
        {
            flag.left_fan=0;
            cnt.left_fan=0;
            flag.left_die_spe=0;
            cnt.left_die_xb++;
        }
    }

}

void into_ramp()
{
    if (flag.ramp)
    {
        cnt.ramp++;
    }

}
void into_cross()
{
    if (flag.cross_fx==1)
    {
        cnt.out_cross++;
//        if (cnt.out_cross*5>=1*1000)
//            gpio_set(P00_0,0);
    }
    if (flag.track==3)
    {
        flag.cross=1;
    }
    if (flag.cross)
    {
        if (cnt.out_cross==0)
        {
            flag.cross_fx=1;
//            gpio_set(P00_0,1);
        }

        cnt.cross++;
        if ( cnt.cross>30 )
        {
            flag.cross=0;
            cnt.cross=0;
        }
    }

}



//左右环都可以
void into_island_T_out()//环岛标志位(带出环处理，通用左右环，手动置左右,改改打∠就行，还没加成数组)
{

    if (flag.island_fx==1)
    {
        cnt.T_out_island_continue++;
        if (cnt.T_out_island_continue*5>=cnt.man_xie_open_time[0]*1000)
        {
            flag.island_fx=0;
            cnt.T_out_island_continue=0;
        }
    }

    if (flag.track==6 )
    {
        flag.T_island=1;
    }

    /*意外出环*/
//    if (flag.T_island_out==1)
//    {
//        cnt.T_out_island++;
//        if (cnt.T_out_island>=800)
//        {
//            cnt.T_out_island=0;
//            flag.T_island_out=0;
//        }
//    }

    if (flag.T_island && flag.T_island_out==0)
    {

        cnt.T_island++;
        if (cnt.T_island>=cnt.T_island_t1[flag.island_fx])
        {
            flag.T_island=0;
            cnt.T_island=0;
            flag.T_island_out=1;

        }
    }
    else if(flag.T_island && flag.T_island_out==1)
    {

        cnt.T_island++;
        if (cnt.T_island>=cnt.T_island_t2[flag.island_fx])
        {
            flag.T_island_out=2;
            flag.T_island=1;
            cnt.T_island=0;


        }
    }
    else if (flag.T_island_out==2)
    {

        cnt.T_island++;
        if (cnt.T_island>=cnt.T_island_t3[flag.island_fx])
        {
            flag.island_spe=0;
            flag.T_island_out=0;
            flag.T_island=0;
            cnt.T_island=0;
            flag.island_fx++;


        }
    }




}










//左右环都可以
void into_island_F_out()//环岛标志位(通用左右环，手动置左右)
{
/*fx=0未进环，1斜电感跑，2存在人工打角的时间段*/

    if (flag.island_fx==1)
    {
        cnt.T_out_island_continue++;
        if (cnt.T_out_island_continue*5>=cnt.man_xie_open_time[0]*1000)
        {
            flag.island_fx=0;
            cnt.T_out_island_continue=0;
        }


    }
    /*flag.island 0无环，1进环(一阶段打角)，2出环(二阶段打角)*/
//    if (flag.track==6 )
//    {
//        flag.island=1;
//    }


    if (flag.island )
    {

        cnt.island+=5;
//        gpio_set(P00_0,1);
        if (cnt.island>=cnt.man_slow_open_time[0]*1000 && cnt.island<=cnt.man_slow_close_time[0]*1000)
        {
            flag.island=2;
        }
        else if (cnt.island>=cnt.man_slow_close_time[0]*1000)
        {
            flag.island=0;
            cnt.island=0;
            flag.island_fx++;

        }
//        if (flag.island_fx==2)
//        {
//
//        }
    }





}


void longstraight_into_bend()//长直道入弯判断
{
    if ( (flag.track==1 || flag.track==2 ))
    {
        cnt.inductance_same++;
        if ( cnt.inductance_same>=400 )
            rate.basic=1+rate.rush;
        else
            rate.basic=1;
    }
    else if (flag.track==4 )
    {
        if ( cnt.inductance_same>=100 )
            flag.con_sharpturn=1;
        else
            flag.con_sharpturn=2;
        cnt.inductance_same=0;
    }
}
void out_of_lonstraight_into_bend()//长直道入弯后出弯判断
{

    if (flag.con_sharpturn!=2)
    {
        cnt.inductance_curve++;  //准确的说是1态持续时间
        if (cnt.inductance_curve>=50)
        {
            flag.con_sharpturn=0;
            if (cnt.inductance_curve>=100)//0态持续时间>500ms
            {
                flag.con_sharpturn=2;//
                cnt.inductance_curve=0;
            }
        }

    }
}



void reed_stop_car()
{
    if ( gpio_get(P02_6)==0 || gpio_get(P02_5)==0)
        flag.reed=1;
    else
        flag.reed=0;

    if (flag.reed&&flag.reed_state==0)
    {
        flag.reed_state=1;
        gpio_set(P00_0,1);
    }
    else if (flag.reed==0 && flag.reed_state==1)
    {
        flag.reed_state=2; //第一次离开干簧管
        gpio_set(P00_0,1);
    }
    else if(flag.reed &&flag.reed_state==2)
    {
        //停车

        gpio_set(P00_0,1);

        servo(SERVO_MIDDLE);
        motor1(0);
        flag.str=0;
    }




}


