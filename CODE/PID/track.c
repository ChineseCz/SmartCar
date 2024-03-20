/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 *
 * @file            track
 * @function        赛道判断以及特殊控制开关
 * @author          Cz
 * @date            2021-7-10
 * @注释            下面几个xxxx_open函数是特殊控制开关，原理是时间断点，需要场上极限调车，追求提前打角过直角或特定地方减速等。
 * @注释            环岛用的是全速打死进环出环，因为赛道自行设计一直调。T前缀的环岛函数则可适用任何大小环。
 ********************************************************************************************************************/
#include "headfile.h"










void stop_car()
{
    /*停车*/
      if (cnt._1ms>=cnt.run_time_limit*1000)
      {
          servo(SERVO_MIDDLE);
          motor1(0);
          flag.str=0;
          cnt._1ms=0;
      }

}
void cross_open()
{
    for (int i=0;i<cnt.cross_num;i++)
    {
        if (cnt._1ms==cnt.cross_open_time[i]*1000)
            flag.cross_spe=1;

        if (cnt._1ms==cnt.cross_close_time[i]*1000)
            flag.cross_spe=0;

    }
}
void right_die_open()
{
    for (int i=0;i<cnt.right_die_num;i++)
    {
        if (cnt._1ms==cnt.right_die_open_time[i]*1000 )
            flag.right_die_spe=1;
        if (cnt._1ms==cnt.right_die_close_time[i]*1000 && flag.right_die_spe==1)
        {
            flag.right_die_spe=0;
            cnt.right_die_xb++;
        }
        else if(cnt._1ms==cnt.right_die_close_time[i]*1000)
            flag.right_die_spe=0;
    }


}
void left_die_open()
{
    for (int i=0;i<cnt.left_die_num;i++)
    {
        if (cnt._1ms==cnt.left_die_open_time[i]*1000)
            flag.left_die_spe=1;
        if (cnt._1ms==cnt.left_die_close_time[i]*1000 && flag.left_die_spe==1)
        {
            flag.left_die_spe=0;
            cnt.left_die_xb++;
        }
        else if(cnt._1ms==cnt.left_die_close_time[i]*1000)
            flag.left_die_spe=0;
    }
}

void island_open()
{
    flag.T_island_spe=1;
    flag.island_spe=1;
}

void spe_open()
{
    /**spe**/
    if (flag.right_die_EN) right_die_open();
    if (flag.left_die_EN) left_die_open();
    if (flag.cross_EN) cross_open();
    if (flag.island_EN) island_open();
  //island

}

void Count()
{
    /**计数**/
    if (cnt._5ms==10)
    {
        cnt._5ms=0;
    }

    if (cnt.oled==cnt.oled_rst)
        cnt.oled=0;

    if(flag.timeswitch)
    {
        cnt._5ms++;
        cnt._1ms+=5;
    }



    /*spe*/
    if (flag.all_EN) spe_open();
    /*stop*/
    stop_car();

    cnt.oled++;
}
void err_revise()
{


    if (steer.err >= 0)
        steer.err*=rate.err_p;
    else
        steer.err*=rate.err_n;

    if (steer.err >= 200 ) steer.err=200;
    if (steer.err <=-200) steer.err=-200;

    steer.errtmp[4] = steer.errtmp[3];
    steer.errtmp[3] = steer.errtmp[2];
    steer.errtmp[2] = steer.errtmp[1];
    steer.errtmp[1] = steer.errtmp[0];
    steer.errtmp[0] = steer.err;
}

void regular_revise()
{


    steer.err_last=steer.err;
    steer.err = 200 *( rate.err*(ad.left-ad.right) + rate.err_tg*(ad.xie_left-ad.xie_right) ) / pow (ad.mid_left+ad.mid_right,1.5);
    steer.err_h = 200*(ad.left-ad.right)*rate.err / pow(ad.mid_left+ad.mid_right,1.5);
    steer.err_x = 200*(ad.xie_left-ad.xie_right)*rate.err_tg / pow(ad.mid_left+ad.mid_right,1.5);
    if (flag.island_fx==1)
    {
        steer.err =200 *( rate.dynamic_kp*(ad.left-ad.right) + rate.rush*(ad.xie_left-ad.xie_right) ) / pow (ad.mid_left+ad.mid_right,1.5);
//        gpio_set(P00_0,1);
    }
    else if (cnt.ramp*5>cnt.man_left_open_time[0]*1000 && cnt.ramp*5<cnt.man_left_close_time[0]*1000)
    {
        steer.err=200 *(  cnt.man_slow_ra[0]*(ad.xie_left-ad.xie_right) ) / pow (ad.mid_left+ad.mid_right,1.5);
    }
    #ifdef CROSS_DEC
    else if (flag.island==2 )
    {
        steer.err=steer.err_h;
//        gpio_set(P00_0,1);
    }

    else if (cnt.out_cross*5>=cnt.man_xie_open_time[2]*1000 && cnt.out_cross*5<cnt.man_xie_close_time[2]*1000)
    {
        steer.err=200 *(  cnt.man_slow_ra[0]*(ad.xie_left-ad.xie_right) ) / pow (ad.mid_left+ad.mid_right,1.5);
//        gpio_set(P00_0,1);
    }
    #endif
//    else if (flag.T_island_out==2) steer.err=1*steer.err_h;
//    else if (flag.T_island_out==1) steer.err=2*steer.err_x;
    else if (flag.cross) steer.err=2*steer.err_h;
//    else if (fabs(steer.err_h)>10 && fabs(steer.err_x)>10  && (ad.shu_left >20 || ad.shu_right>20) ) steer.err=steer.err_x;
    else
    {
        switch (flag.track)
        {
            case 5:steer.err=2*steer.err_last;break;//丢线
            case 3:steer.err=1*steer.err_h;break;//十字
            case 1:steer.err = 200 *( rate.err*(ad.left-ad.right) + rate.err_tg*(ad.xie_left-ad.xie_right) ) / pow (ad.mid_left+ad.mid_right,1.5);break;//直道
            case 2:steer.err = 200 *( rate.err*(ad.left-ad.right) + rate.err_tg*(ad.xie_left-ad.xie_right) ) / pow (ad.mid_left+ad.mid_right,1.5);break;//弯道
            case 4:steer.err=steer.err_x;break;//直角
            default:break;
        }
    }


//    for (int i=0;i<10;i++)
//    {
//        if (cnt._1ms>cnt.man_xie_open_time[i]*1000 && cnt._1ms<=cnt.man_xie_close_time[i]*1000)
//        {
//            steer.err =200 *( 1.5*(ad.left-ad.right) + 20*(ad.xie_left-ad.xie_right) ) / pow (ad.mid_left+ad.mid_right,1.5);
//        }
//    }



    err_revise();
}
void track_judge()//赛道判断
{


        if (ad.mid_left + ad.mid_right<180  )//100
        {
           flag.track=5;//丢线
        }
        else if (ad.left+ad.right>2000  )
        {
            flag.island=1;
            flag.track=6;
        }
        else if ( fabs(ad.xie_left - ad.xie_right) > 300 )
        {
            if ( ad.shu_left>100 && ad.shu_right>100 && (ad.mid_left+ad.mid_right)>800)
                flag.track=3;
            else if ( fabs(ad.shu_left - ad.shu_right)>60 )
            {
                if ( fabs(ad.left-ad.right)<90 )
                    flag.track=4;
                else
                    flag.track=2;
            }
            else
                flag.track=2;
        }
        else if (fabs(ad.left-ad.right)<=70 && (fabs(ad.xie_left-ad.xie_right)<150))
        {
            flag.track=1;
        }
        else
        {
            flag.track=2;
        }

}


void protect()//出线与碰撞保护
{
//    if ( enc.pulse<=20 && flag.str && cnt._1ms>4000)
//    {
//        servo(SERVO_MIDDLE);
//        motor1(0);
//        flag.str=0;
//    }
    if (ad.left<7 && ad.right<7 && ad.mid_left<7 && ad.mid_right<8 && ad.shu_left<7 && ad.shu_right<8 &&flag.pro_EN)
    {
//        servo(SERVO_MIDDLE);
        if (flag.str) motor1(3000);
//        flag.str=0;
//        cnt._1ms=0;
    }
}
