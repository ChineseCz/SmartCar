/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 *
 * @file            Flash
 * @function        高低中速度挡速
 * @author          Cz
 * @date            2021-4-23
 ********************************************************************************************************************/
#include "headfile.h"

#define divis 1
float data[85];
uint32 data_buf;

void read_now(void);
void read_low(void);
void read_mid(void);
void read_fast(void);

void Flash_ReadData()
{
   uint8 i;
   for (i=0;i<84;i++)
   {
       data[i] = flash_read(divis, i, float);
   }

   if (cnt.flash_xb==0) read_now();
   if (cnt.flash_xb==1) read_low();
   if (cnt.flash_xb==2) read_mid();
   if (cnt.flash_xb==3) read_fast();







}

void read_low()
{
    //7.8V电池
    /*******************************/
//       慢速参(不带控制)
       steer.Kp = data[0];
       steer.Kd = data[1];
       motor.Kp = data[2];
       motor.Ki = data[3];
       rate.basic = 1.05;
       rate.dynamic_kp = data[5];
       rate.encoder = data[6];
       rate.err_p = data[7];
       rate.err_n = data[8];
       rate.err = data[9];
       rate.outof_sharpturn_str = data[10];
       rate.rush = data[11];
       rate.sharptrun_stop = data[12];
       rate.ste = data[13];
       rate.ste_lef = data[14];
       rate.ste_rig = data[15];
       rate.err_tg = data[16];
       enc.expect_speed = 3000;
       enc.speed_control_out_max = 4400;
       cnt.run_time_limit = 44;
       steer.rate_ai = data[20];
       steer.rate_pid = data[21];

}
void read_mid()
{
    /*****************************/
    //   中速参(带控制)
       steer.Kp = data[0];
       steer.Kd = data[1];
       motor.Kp = data[2];
       motor.Ki = data[3];
       rate.basic = 1.15;
       rate.dynamic_kp = data[5];
       rate.encoder = data[6];
       rate.err_p = data[7];
       rate.err_n = data[8];
       rate.err = data[9];
       rate.outof_sharpturn_str = data[10];
       rate.rush = data[11];
       rate.sharptrun_stop = data[12];
       rate.ste = data[13];
       rate.ste_lef = data[14];
       rate.ste_rig = data[15];
       rate.err_tg = data[16];
       enc.expect_speed = 3200;
       enc.speed_control_out_max = 4800;
       cnt.run_time_limit = 37;
       steer.rate_ai = data[20];
       steer.rate_pid = data[21];

       //第一个左
       cnt.left_die_open_time[0]=2.2;
       cnt.left_die_close_time[0]=4;
       cnt.left_die_time[0]=120;
       cnt.left_die_to_right_time[0]=100;
       cnt.left_die_angle[0]=630;
       //第二个左
       cnt.left_die_open_time[1]=13;
       cnt.left_die_close_time[1]=20;
       cnt.left_die_time[1]=105;
       cnt.left_die_to_right_time[1]=100;
       cnt.left_die_angle[1]=630;

       //第一个右
       cnt.right_die_open_time[0]=0.1;
       cnt.right_die_close_time[0]=2;
       cnt.right_die_time[0]=130;
       cnt.right_die_to_left_time[0]=100;
       cnt.right_die_angle[0]=370;


       //第二个右
       cnt.right_die_open_time[1]=26;
       cnt.right_die_close_time[1]=33;
       cnt.right_die_time[1]=105;
       cnt.right_die_to_left_time[1]=100;
       cnt.right_die_angle[1]=370;

       //环岛
       cnt.T_island_t1[cnt.T_island_xb]=170;
       cnt.T_island_t2[cnt.T_island_xb]=25;
       cnt.T_island_t3[cnt.T_island_xb]=45;
       cnt.T_island_s1[cnt.T_island_xb]=555;
       cnt.T_island_s2[cnt.T_island_xb]=500;
       cnt.T_island_s3[cnt.T_island_xb]=540;
}
void read_fast()
{
    /*****************************/
//       快速参(带控制)
       steer.Kp = data[0];
       steer.Kd = data[1];
       motor.Kp = data[2];
       motor.Ki = data[3];
       rate.basic = 1.25;
       rate.dynamic_kp = data[5];
       rate.encoder = data[6];
       rate.err_p = data[7];
       rate.err_n = data[8];
       rate.err = data[9];
       rate.outof_sharpturn_str = data[10];
       rate.rush = data[11];
       rate.sharptrun_stop = data[12];
       rate.ste = data[13];
       rate.ste_lef = data[14];
       rate.ste_rig = data[15];
       rate.err_tg = data[16];
       enc.expect_speed = 3300;
       enc.speed_control_out_max = 4100;
       cnt.run_time_limit = 38;
       steer.rate_ai = data[20];
       steer.rate_pid = data[21];
       //第一个左
       cnt.left_die_open_time[0]=2.1;
       cnt.left_die_close_time[0]=4;
       cnt.left_die_time[0]=115;
       cnt.left_die_to_right_time[0]=100;
       cnt.left_die_angle[0]=630;
       //第二个左
       cnt.left_die_open_time[1]=13;
       cnt.left_die_close_time[1]=20;
       cnt.left_die_time[1]=105;
       cnt.left_die_to_right_time[1]=100;
       cnt.left_die_angle[1]=630;

       //第一个右
       cnt.right_die_open_time[0]=0.1;
       cnt.right_die_close_time[0]=2;
       cnt.right_die_time[0]=115;
       cnt.right_die_to_left_time[0]=100;
       cnt.right_die_angle[0]=370;


       //第二个右
       cnt.right_die_open_time[1]=26;
       cnt.right_die_close_time[1]=33;
       cnt.right_die_time[1]=130;
       cnt.right_die_to_left_time[1]=100;
       cnt.right_die_angle[1]=370;

       //环岛
       cnt.T_island_t1[cnt.T_island_xb]=130;
       cnt.T_island_t2[cnt.T_island_xb]=20;
       cnt.T_island_t3[cnt.T_island_xb]=40;
       cnt.T_island_s1[cnt.T_island_xb]=555;
       cnt.T_island_s2[cnt.T_island_xb]=500;
       cnt.T_island_s3[cnt.T_island_xb]=530;
}

void read_now()
{
    //现有参--快速
    steer.Kp = data[0];
    steer.Kd = data[1];
    motor.Kp = data[2];
    motor.Ki = data[3];
    rate.basic = data[4];
    rate.dynamic_kp = data[5];
    rate.encoder = data[6];
    rate.err_p = data[7];
    rate.err_n = data[8];
    rate.err = data[9];
    rate.outof_sharpturn_str = data[10];
    rate.rush = data[11];
    rate.sharptrun_stop = data[12];
    rate.ste = data[13];
    rate.ste_lef = data[14];
    rate.ste_rig = data[15];
    rate.err_tg = data[16];
    enc.expect_speed = data[17];
    enc.speed_control_out_max = data[18];
    cnt.run_time_limit = data[19];
    steer.rate_ai = data[20];
    steer.rate_pid = data[21];

    /*环岛*/
    cnt.T_island_t1[0] = data[22];
    cnt.T_island_t2[0] = data[23];
    cnt.T_island_t3[0] = data[24];
    cnt.T_island_s1[0] = data[25];
    cnt.T_island_s2[0] = data[26];
    cnt.T_island_s3[0] = data[27];


    cnt.T_island_t1[1] = data[28];
    cnt.T_island_t2[1] = data[29];
    cnt.T_island_t3[1] = data[30];
    cnt.T_island_s1[1] = data[31];
    cnt.T_island_s2[1] = data[32];
    cnt.T_island_s3[1] = data[33];

    flag.island_fx = data[34];


    /*元素减速*/
    rate.curve_stop = data[35];
    rate.island_stop = data[36];



    /*人工控制*/
    //减速
    cnt.man_slow_open_time[0] = data[37];
    cnt.man_slow_close_time[0] = data[38];
    cnt.man_slow_ra[0] = data[39];

    cnt.man_slow_open_time[1] = data[40];
    cnt.man_slow_close_time[1] = data[41];
    cnt.man_slow_ra[1] = data[42];

    cnt.man_slow_open_time[2] = data[43];
    cnt.man_slow_close_time[2] = data[44];
    cnt.man_slow_ra[2] = data[45];

    //加速
    cnt.man_fast_open_time[0] = data[46];
    cnt.man_fast_close_time[0] = data[47];
    cnt.man_fast_ra[0] = data[48];

    cnt.man_fast_open_time[1] = data[49];
    cnt.man_fast_close_time[1] = data[50];
    cnt.man_fast_ra[1] = data[51];

    cnt.man_fast_open_time[2] = data[52];
    cnt.man_fast_close_time[2] = data[53];
    cnt.man_fast_ra[2] = data[54];


    //左转
    cnt.man_left_open_time[0] = data[55];
    cnt.man_left_close_time[0] = data[56];
    cnt.man_left_angle[0] = data[57];

    cnt.man_left_open_time[1] = data[58];
    cnt.man_left_close_time[1] = data[59];
    cnt.man_left_angle[1] = data[60];

    cnt.man_left_open_time[2] = data[61];
    cnt.man_left_close_time[2] = data[62];
    cnt.man_left_angle[2] = data[63];


    //右转
    cnt.man_right_open_time[0] = data[64];
    cnt.man_right_close_time[0] = data[65];
    cnt.man_right_angle[0] = data[66];

    cnt.man_right_open_time[1] = data[67];
    cnt.man_right_close_time[1] = data[68];
    cnt.man_right_angle[1] = data[69];

    cnt.man_right_open_time[2] = data[70];
    cnt.man_right_close_time[2] = data[71];
    cnt.man_right_angle[2] = data[72];

    //斜电感

    cnt.man_xie_open_time[0] = data[73];
    cnt.man_xie_close_time[0] = data[74];


    cnt.man_xie_open_time[1] = data[75];
    cnt.man_xie_close_time[1] = data[76];


    cnt.man_xie_open_time[2] = data[77];
    cnt.man_xie_close_time[2] = data[78];

    //起步
    cnt.str_rush = data[79];
    test.mot_du = data[80];
    test.ste_du = data[81];
    test.ste_du1 = data[82];
    test.mot_du1 = data[83];
    #ifdef xuan
    steer.Kp=8;
    steer.Kd=60;
    rate.err=16;
    rate.err_tg=16;
    rate.ste=0.178;

    #endif
}
void Flash_SaveData()
{
    uint8 i;
    if(flash_check(divis, 0) || flash_check(divis, 1) || flash_check(divis, 2) || flash_check(divis, 3))
    {
        eeprom_erase_sector(divis);
    }


    data[0] = steer.Kp;
    data[1] = steer.Kd;
    data[2] = motor.Kp;
    data[3] = motor.Ki;
    data[4] = rate.basic;
    data[5] = rate.dynamic_kp;
    data[6] = rate.encoder;
    data[7] = rate.err_p;
    data[8] = rate.err_n;
    data[9] = rate.err;
    data[10] = rate.outof_sharpturn_str;
    data[11] = rate.rush;
    data[12] = rate.sharptrun_stop;
    data[13] = rate.ste;
    data[14] = rate.ste_lef;
    data[15] = rate.ste_rig;
    data[16] = rate.err_tg;
    data[17] = enc.expect_speed;
    data[18] = enc.speed_control_out_max;
    data[19] =cnt.run_time_limit;
    data[20] = steer.rate_ai;
    data[21] = steer.rate_pid;


    /*环岛*/
    //左入
    data[22] = cnt.T_island_t1[0];
    data[23] = cnt.T_island_t2[0];
    data[24] = cnt.T_island_t3[0];
    data[25] = cnt.T_island_s1[0];
    data[26] = cnt.T_island_s2[0];
    data[27] = cnt.T_island_s3[0];
    //右入
    data[28] = cnt.T_island_t1[1];
    data[29] = cnt.T_island_t2[1];
    data[30] = cnt.T_island_t3[1];
    data[31] = cnt.T_island_s1[1];
    data[32] = cnt.T_island_s2[1];
    data[33] = cnt.T_island_s3[1];


    data[34] = (float)flag.island_fx;


    data[35] = rate.curve_stop;
    data[36] = rate.island_stop;

    /*人工控制*/
    //减速
    data[37] = cnt.man_slow_open_time[0];
    data[38] = cnt.man_slow_close_time[0];
    data[39] = cnt.man_slow_ra[0];

    data[40] = cnt.man_slow_open_time[1] ;
    data[41] = cnt.man_slow_close_time[1] ;
    data[42] = cnt.man_slow_ra[1];

    data[43] = cnt.man_slow_open_time[2];
    data[44] = cnt.man_slow_close_time[2];
    data[45] = cnt.man_slow_ra[2];

    //加速
    data[46] = cnt.man_fast_open_time[0];
    data[47] = cnt.man_fast_close_time[0];
    data[48] = cnt.man_fast_ra[0];

    data[49] = cnt.man_fast_open_time[1];
    data[50] = cnt.man_fast_close_time[1];
    data[51] = cnt.man_fast_ra[1];

    data[52] = cnt.man_fast_open_time[2];
    data[53] = cnt.man_fast_close_time[2];
    data[54] = cnt.man_fast_ra[2];


    //左转
    data[55] = cnt.man_left_open_time[0];
    data[56] = cnt.man_left_close_time[0];
    data[57] = cnt.man_left_angle[0];

    data[58] = cnt.man_left_open_time[1];
    data[59] = cnt.man_left_close_time[1];
    data[60] = cnt.man_left_angle[1] ;

    data[61] = cnt.man_left_open_time[2];
    data[62] = cnt.man_left_close_time[2] ;
    data[63] = cnt.man_left_angle[2];


    //右转
    data[64] = cnt.man_right_open_time[0];
    data[65] = cnt.man_right_close_time[0];
    data[66] = cnt.man_right_angle[0];

    data[67] = cnt.man_right_open_time[1];
    data[68] = cnt.man_right_close_time[1];
    data[69] = cnt.man_right_angle[1] ;

    data[70] = cnt.man_right_open_time[2];
    data[71] = cnt.man_right_close_time[2] ;
    data[72] = cnt.man_right_angle[2] ;

    //斜电感

    data[73] = cnt.man_xie_open_time[0];
    data[74] = cnt.man_xie_close_time[0];


    data[75] = cnt.man_xie_open_time[1];
    data[76] = cnt.man_xie_close_time[1];


    data[77] = cnt.man_xie_open_time[2];
    data[78] = cnt.man_xie_close_time[2];

    //起步
    data[79] = cnt.str_rush;

    //手动
    data[80] = test.mot_du ;
    data[81] = test.ste_du ;
    data[82] = test.ste_du1 ;
    data[83] = test.mot_du1 ;
    for (i=0;i<84;i++)
    {
        data_buf = float_conversion_uint32(data[i]);
        eeprom_page_program(divis, i, &data_buf);
    }


}



