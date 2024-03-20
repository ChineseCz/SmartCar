/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 *
 * @file            Menu
 * @function        多级菜单
 * @author          Cz
 * @date            2021-7-10
 * @Tip             从暑假面试用到比赛，没改结构比较繁琐，可用class类定义优化，但可能C++库有点不兼容。
 ********************************************************************************************************************/
#include "headfile.h"

//增量参数
float key_add=1;
float add=1,gain=1,rate_gain=0.1,add_gain=0.1;
char subline=0,subcolumn=4;
char out=0;

//主菜单名称
char menu_case_num=0;
char menu_case0[20][20]={"Go!!!!","err.dis","rate.p","spe.p"};
char menu_case2[20][20]={"ad_dis","err_dis","ad1_dis","cnt.dis"};//略
char menu_case1[20][20]={"unit_para","PID_para","Special_para","Speed_para","Start_para"};//(序号+=key_add*20);

char menu_case3[20][20]={"all_spe","Left_spe","Right_spe","cro_spe","isl_spe"};//(序号+=key_add*20);//略
char menu_case4[20][20]={"isl1_con","isl2_con","slow_con","slow1_con","left_con","right_con","xie"};//(序号+=key_add*20);


/******80-99************/
char submenu80_case[20][20]={"t1","t2","t3","s1","s2","s3"};
float *submenu80_num[20]={&cnt.T_island_t1[0],&cnt.T_island_t2[0],&cnt.T_island_t3[0],&cnt.T_island_s1[0],&cnt.T_island_s2[0],&cnt.T_island_s3[0]};

char submenu81_case[20][20]={"t1","t2","t3","s1","s2","s3"};
float *submenu81_num[20]={&cnt.T_island_t1[1],&cnt.T_island_t2[1],&cnt.T_island_t3[1],&cnt.T_island_s1[1],&cnt.T_island_s2[1],&cnt.T_island_s3[1]};

char submenu82_case[20][20]={"o1","c1","r1","o2","c2","r2","o3","c3","r3"};
float *submenu82_num[20]={&cnt.man_slow_open_time[0],&cnt.man_slow_close_time[0],&cnt.man_slow_ra[0],
                          &cnt.man_slow_open_time[1],&cnt.man_slow_close_time[1],&cnt.man_slow_ra[1],
                          &cnt.man_slow_open_time[2],&cnt.man_slow_close_time[2],&cnt.man_slow_ra[2],
};

char submenu83_case[20][20]={"o1","c1","r1","o2","c2","r2","o3","c3","r3"};
float *submenu83_num[20]={&cnt.man_fast_open_time[0],&cnt.man_fast_close_time[0],&cnt.man_fast_ra[0],
                          &cnt.man_fast_open_time[1],&cnt.man_fast_close_time[1],&cnt.man_fast_ra[1],
                          &cnt.man_fast_open_time[2],&cnt.man_fast_close_time[2],&cnt.man_fast_ra[2],
};

char submenu84_case[20][20]={"o1","c1","a1","o2","c2","a2","o3","c3","a3"};
float *submenu84_num[20]={&cnt.man_left_open_time[0],&cnt.man_left_close_time[0],&cnt.man_left_angle[0],
                          &cnt.man_left_open_time[1],&cnt.man_left_close_time[1],&cnt.man_left_angle[1],
                          &cnt.man_left_open_time[2],&cnt.man_left_close_time[2],&cnt.man_left_angle[2],
};

char submenu85_case[20][20]={"o1","c1","r1","o2","c2","r2","o3","c3","a3"};
float *submenu85_num[20]={&cnt.man_right_open_time[0],&cnt.man_right_close_time[0],&cnt.man_right_angle[0],
                          &cnt.man_right_open_time[1],&cnt.man_right_close_time[1],&cnt.man_right_angle[1],
                          &cnt.man_right_open_time[2],&cnt.man_right_close_time[2],&cnt.man_right_angle[2],
};
char submenu86_case[20][20]={"o1","c1","o2","c2","o3","c3"};
float *submenu86_num[20]={&cnt.man_xie_open_time[0],&cnt.man_xie_close_time[0],
                          &cnt.man_xie_open_time[1],&cnt.man_xie_close_time[1],
                          &cnt.man_xie_open_time[2],&cnt.man_xie_close_time[2],
};

//TEST
/*****************************************************/
char submenu87_case[20][20]={"T.mot","T.ste","T.ste1","T.mot1"};
float *submenu87_num[20]={&test.mot_du,&test.ste_du,&test.ste_du1,&test.mot_du1};
/*****************************************************/


//各列序号
/********0-19**********/
//GO
/*****************************************************/
char submenu0_case[20][20]={"sw.str","sw.ste","sw.mot","sw.isl_fx","sw.save","sw.read","sw.f_Xb","sw.man","sw.DD","sw.ST","sw.pro"};
int *submenu0_num[20]={&flag.str,&flag.ste_con,&flag.mot_con,&flag.island_fx,&cnt.save,&cnt.read,&cnt.flash_xb,&flag.man_swi,&flag.DD_EN,&flag.start_EN,&flag.pro_EN};
/*****************************************************/

//err
char submenu1_case[20][20]={"ste.err","mot.err","ste.out","mot.out","mot.pulse","mot.filsp","err_h","err_x"};
float *submenu1_num[20]={&steer.err,&motor.err,&steer.duty,&enc.speed_control_out,&enc.pulse,&enc.filter_speed,&steer.err_h,&steer.err_x};


//Uint
/*****************************************************/
char submenu5_case[20][20]={"U.add","U.gain","U.ra_g","U.ad_g"};
float *submenu5_num[20]={&add,&gain,&rate_gain,&add_gain};
/*****************************************************/

//PID
/***********************************************************************/
char submenu4_case[20][20]={"ste.p","ste.d","mot.p","mot.i","mot.d","ra.pid","ra.ai"};
float *submenu4_num[20]={&steer.Kp,&steer.Kd,&motor.Kp,&motor.Ki,&motor.Kd,&steer.rate_pid,&steer.rate_ai};
/**********************************************************************/

//RATE
/************************************************************************************************/
char submenu2_case[20][20]={"0.err","1.err1","2.kp1","3.ste","4.lef","5.rig","6.err+","7.err-",
            "8.stop","9.out","10.bas","11.rush","12.mote"};
float *submenu2_num[20]={&rate.err,&rate.err_tg,&rate.dynamic_kp,&rate.ste,&rate.ste_lef,
        &rate.ste_rig,&rate.err_p,&rate.err_n,&rate.sharptrun_stop,
        &rate.outof_sharpturn_str,&rate.basic,&rate.rush,&rate.encoder};
/************************************************************************************************/

//Speed
/************************************************************************************************/
char submenu3_case[20][20]={"Exc_Spe","Spe_Max","all_time","r.cur_s","r.isl_s","st_ms"};
float *submenu3_num[20]={&enc.expect_speed,&enc.speed_control_out_max,&cnt.run_time_limit,&rate.curve_stop,&rate.island_stop,&cnt.str_rush};
/************************************************************************************************/

//GYRO
char submenu6_case[20][20]={"g_x","g_y","g_z","a_x","a_y","a_z"};
int16 *submenu6_num[20]={&icm_gyro_x,&icm_gyro_y,&icm_gyro_z,&icm_acc_x,&icm_acc_y,&icm_acc_z};
/************************************************************************************************/

/************************************************************************************************/

//
////FLAG
///************************************************************************************************/
//char submenu2_case[20][20]={"f.str","f.tra"};
//int *submenu2_num[20]={&flag.str,&flag.track};
///************************************************************************************************/
//
//
////TEST
///*****************************************************/
//char submenu3_case[20][20]={"T.ste","T.mot"};
//float *submenu3_num[20]={&test.ste_du,&test.mot_du};
///*****************************************************/



//SAVE
//READ

/********20-39**********/

//Uint
/*****************************************************/
char submenu20_case[20][20]={"U.add","U.gain","U.ra_g","U.ad_g"};
float *submenu20_num[20]={&add,&gain,&rate_gain,&add_gain};
/*****************************************************/

//PID
/***********************************************************************/
char submenu21_case[20][20]={"ste.p","ste.d","mot.p","mot.i","mot.d","ra.pid","ra.ai"};
float *submenu21_num[20]={&steer.Kp,&steer.Kd,&motor.Kp,&motor.Ki,&motor.Kd,&steer.rate_pid,&steer.rate_ai};
/**********************************************************************/

//RATE
/************************************************************************************************/
char submenu22_case[20][20]={"0.err","1.err1","2.kp1","3.ste","4.lef","5.rig","6.err+","7.err-",
            "8.stop","9.out","10.bas","11.rush","12.mote"};
float *submenu22_num[20]={&rate.err,&rate.err_tg,&rate.dynamic_kp,&rate.ste,&rate.ste_lef,
        &rate.ste_rig,&rate.err_p,&rate.err_n,&rate.sharptrun_stop,
        &rate.outof_sharpturn_str,&rate.basic,&rate.rush,&rate.encoder};
/************************************************************************************************/

//Speed
/************************************************************************************************/
char submenu23_case[20][20]={"Exc_Spe","Spe_Max","all_time","r.cur_stop","r.isl_stop"};
float *submenu23_num[20]={&enc.expect_speed,&enc.speed_control_out_max,&cnt.run_time_limit,&rate.curve_stop,&rate.island_stop};
/************************************************************************************************/

//start
/************************************************************************************************/

/************************************************************************************************/




/********40-59***********/
//AD
/************************************************************************************************/
char submenu40_case[50][20]={"ad0","ad1","ad2","ad3","ad4","ad5","ad6","ad7","ad8",
        "ad10","ad11","ad12","ad13","ad16","ad17","ad20","ad21","ad24","ad25"};
uint16 *submenu40_num[50]={&ad._0,&ad._1,&ad._2,&ad._3,&ad._4,&ad._5,&ad._6,&ad._7,
        &ad._8,&ad._10,&ad._11,&ad._12,&ad._13,&ad._16,&ad._17,&ad._20,&ad._21,&ad._24,&ad._25};
/************************************************************************************************/

//ERR_DIS
/************************************************************************************************/

char submenu41_case[20][20]={"ste.err","mot.err","ste.out","mot.out","mot.pulse","mot.filsp","err_h","err_x"};
float *submenu41_num[20]={&steer.err,&motor.err,&steer.duty,&enc.speed_control_out,&enc.pulse,&enc.filter_speed,&steer.err_h,&steer.err_x};
/************************************************************************************************/

//AD1
char submenu42_case[50][20]={"ad35","ad36","ad37","ad38","ad39","ad42","ad43","ad44"
        ,"ad45","ad46","ad47"};
uint16 *submenu42_num[50]={&ad._35,&ad._36,&ad._37,&ad._38,&ad._39,
        &ad._42,&ad._43,&ad._44,&ad._45,&ad._46,&ad._47};

//CNT
/************************************************************************************************/
char submenu43_case[20][20]={"c_1ms","c._5ms","c._20ms","c.oled","c.indu"};
int *submenu43_num[20]={&cnt._1ms,&cnt._5ms,&cnt._20ms,&cnt.oled,&cnt.inductance_same};
/************************************************************************************************/

//GYRO
/*******************************/
char submenu44_case[20][20]={"g_x","g_y","g_z","a_x","a_y","a_z"};
int16 *submenu44_num[20]={&icm_gyro_x,&icm_gyro_y,&icm_gyro_z,&icm_acc_x,&icm_acc_y,&icm_acc_z};
/************************************************************************************************/









/************60-79****************/
char submenu60_case[20][20]={"left_num","right_num","cro_num","is_num","lef_en","righ_en","isl_en","cro_en","all_en"};
int *submenu60_num[20]={&cnt.left_die_num,&cnt.right_die_num,&cnt.cross_num,&cnt.island_num,
        &flag.left_die_EN,&flag.right_die_EN,&flag.island_EN,&flag.cross_EN,&flag.all_EN};



float lt_xh,lt_open,lt_close,lt_die,lt_dieto,lt_angle,lt_save;
//left
char submenu61_case[20][20]={"xh","open","close","die","die_to","angle","save"};
float *submenu61_num[20]={&lt_xh,&lt_open,&lt_close,&lt_die,&lt_dieto,&lt_angle,&lt_save};

float rt_xh,rt_open,rt_close,rt_die,rt_dieto,rt_angle,rt_save;
//right
char submenu62_case[20][20]={"xh","open","close","die","die_to","angle","save"};
float *submenu62_num[20]={&rt_xh,&rt_open,&rt_close,&rt_die,&rt_dieto,&rt_angle,&rt_save};


float ct_xh,ct_open,ct_close,ct_save;
//cross
char submenu63_case[20][20]={"xh","open","close","save"};
float *submenu63_num[20]={&ct_xh,&ct_open,&ct_close,&ct_save};





float it_xh,it_t1,it_t2,it_t3,it_s1,it_s2,it_s3,it_save;
//island
char submenu64_case[20][20]={"xh","t1","t2","t3","s1","s2","s3","save"};
float *submenu64_num[20]={&it_xh,&it_t1,&it_t2,&it_t3,&it_s1,&it_s2,&it_s3,&it_save};

int menu_first=0;
int submenu_first=0;

unsigned char line=0;
unsigned char column=4;



void cursor()
{
    oled_clearcursor();
	oled_p6x8str(column,line,"->");
}
void subcursor()
{
    oled_clearcursor();
    oled_p6x8str(subcolumn,subline,"->");
}
void menu()
{    
    int i;
    if (menu_case_num==0)
        for (i=menu_first;i<8+menu_first;i++)
        {
            oled_p6x8str(18,i-menu_first,menu_case0[i]);
            if (i==0)
            {
                OLED_Print_Num1(76,0,(float) ad._0);
            }
            if (i==1)
            {
                OLED_Print_Num1(76,1,(float)flag.ramp);
            }
            if (i==2)
            {
                OLED_Print_Num1(76,2,(float)cnt.ramp);
            }
            if (i==3)
            {
                OLED_Print_Num1(76,3,(float)flag.track);
            }
            if (i==4)
            {
                OLED_Print_Num1(18,4,(float)ad.left);
                OLED_Print_Num1(76,4,(float)ad.right);
            }
            if (i==5)
            {
                OLED_Print_Num1(18,5,ad.shu_left);
                OLED_Print_Num1(76,5,ad.shu_right);
            }
            if (i==6)
            {
                OLED_Print_Num1(18,6,ad.xie_left);
                OLED_Print_Num1(76,6,ad.xie_right);
            }
            if (i==7)
            {
                OLED_Print_Num1(18,7,ad.mid_left);
                OLED_Print_Num1(76,7,ad.mid_right);
            }
        }
    else if  (menu_case_num==1)
        for (i=menu_first;i<8+menu_first;i++)
            oled_p6x8str(18,i-menu_first,menu_case1[i]);
    else if (menu_case_num==2)
        for (i=menu_first;i<8+menu_first;i++)
            oled_p6x8str(18,i-menu_first,menu_case2[i]);
    else if (menu_case_num==3)
        for (i=menu_first;i<8+menu_first;i++)
            oled_p6x8str(18,i-menu_first,menu_case3[i]);
    else if (menu_case_num==4)
        for (i=menu_first;i<8+menu_first;i++)
            oled_p6x8str(18,i-menu_first,menu_case4[i]);
        
    	
}

void menukey()
{
    if (!keyright())
    {
        if (menu_case_num==4)
        {
            menu_case_num=0;
            oled_clear();
            cursor();
        }
        else if (menu_case_num==0)
        {
            menu_case_num=4;
            oled_clear();
            cursor();
        }


        #ifdef M3
        if (menu_case_num==4)
        {
            menu_case_num=0;
            oled_clear();
            cursor();
        }
        else if (menu_case_num==0)
        {
            menu_case_num=3;
            oled_clear();
            cursor();
        }
        else if(menu_case_num==3)
        {
            menu_case_num=4;
            oled_clear();
            cursor();
        }
        #endif

      
    } 
    if (!keyleft())
    {
        if (menu_case_num==0 )
        {
            menu_case_num=4;
            oled_clear();
            cursor();
        }
        else if(menu_case_num==4)
        {
            menu_case_num=0;
            oled_clear();
            cursor();
        }



        #ifdef M3
        if (menu_case_num==4)
        {
            menu_case_num=3;
            oled_clear();
            cursor();
        }
        else if (menu_case_num==3)
        {
            menu_case_num=0;
            oled_clear();
            cursor();
        }
        else if(menu_case_num==0b)
        {
            menu_case_num=4;
            oled_clear();
            cursor();
        }
        #endif

    }    
    if (!keyup())
    {
        if (line>0)
            line--;
        else line=7;
        cursor();
    }
    
    if (!keydown())
    {
        line++;
        if (line==8)
            line=0;
        cursor();
    }
    if (!keycenter())
    {
        my_delay(2000);
        oled_clear();
        submenu_first=0;//可能是错误的
        submenu();
        oled_clear();
        menu();
        cursor();
    }
    if (!key1())
    {
        
        menu_first++;
        oled_clear();
        cursor();
        
    }
       if (!key2())
    {
        if (menu_first>0)
            menu_first--;
        oled_clear();
        cursor();
    }
}

void submenu()
{
    switch(line+menu_first+menu_case_num*20)
    {
        case 0://GO!!!!
        {
             int i;
             subcursor();
             for (i=submenu_first;i<8+submenu_first;i++)
             {
                 oled_p6x8str(18,i-submenu_first,submenu0_case[i]);
                 if (submenu0_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)*submenu0_num[i]);
             }

             while(1)
             {
                 subkey();
                 for (i=submenu_first;i<8+submenu_first;i++)
                 {
                     oled_p6x8str(18,i-submenu_first,submenu0_case[i]);
                     if (submenu0_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)*submenu0_num[i]);
                 }
                 if (out)
                 {
                     out=0;
                     break;
                 }
             }
             break;
        }
        case 1://err.dis
        {
           int i;
           subcursor();
           for (i=submenu_first;i<8+submenu_first;i++)
           {
               oled_p6x8str(18,i-submenu_first,submenu1_case[i]);
               if (submenu1_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)*submenu1_num[i]);
           }

           while(1)
           {
               subkey();
               for (i=submenu_first;i<8+submenu_first;i++)
               {
                   oled_p6x8str(18,i-submenu_first,submenu1_case[i]);
                   if (submenu1_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)*submenu1_num[i]);
               }
               if (out)
               {
                   out=0;
                   break;
               }
           }
           break;
        }

        case 2://rate
        {
            int i=0;
            subcursor();
            for (i=submenu_first;i<8+submenu_first;i++)
             {
                 oled_p6x8str(18,i-submenu_first,submenu2_case[i]);
                 if (submenu2_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)(*submenu2_num[i]));
             }
            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                 {
                     oled_p6x8str(18,i-submenu_first,submenu2_case[i]);
                     if (submenu2_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)(*submenu2_num[i]));
                 }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }

        case 3://speed
        {
            int i;
            subcursor();
            for (i=submenu_first;i<8+submenu_first;i++)
            {
                oled_p6x8str(18,i-submenu_first,submenu3_case[i]);
                if (submenu3_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu3_num[i]);
            }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu3_case[i]);
                    if (submenu3_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu3_num[i]);
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }


        case 4://PID
        {
            int i;
            subcursor();
            for (i=submenu_first;i<8+submenu_first;i++)
            {
                oled_p6x8str(18,i-submenu_first,submenu4_case[i]);
                if (submenu4_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu4_num[i]);
            }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu4_case[i]);
                    if (submenu4_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu4_num[i]);
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }

        case 5://PID
        {
            int i;
            subcursor();
            for (i=submenu_first;i<8+submenu_first;i++)
            {
                oled_p6x8str(18,i-submenu_first,submenu5_case[i]);
                if (submenu5_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu5_num[i]);
            }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu5_case[i]);
                    if (submenu5_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu5_num[i]);
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }
        case 6://GYRO
        {
            int i;
            subcursor();
            for (i=submenu_first;i<8+submenu_first;i++)
            {
                oled_p6x8str(18,i-submenu_first,submenu6_case[i]);
                if (submenu6_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu6_num[i]);
            }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu6_case[i]);
                    if (submenu6_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu6_num[i]);
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }

        case 20://uint_para
        {
            int i;
            subcursor();
            for (i=submenu_first;i<8+submenu_first;i++)
            {
                oled_p6x8str(18,i-submenu_first,submenu20_case[i]);
                if (submenu20_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu20_num[i]);
            }
            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu20_case[i]);
                    if (submenu20_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu20_num[i]);
                }

                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }
        case 21://PID_para
        {
            int i;
            subcursor();
            for (i=submenu_first;i<8+submenu_first;i++)
            {
                oled_p6x8str(18,i-submenu_first,submenu21_case[i]);
                if (submenu21_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu21_num[i]);
            }
            
            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu21_case[i]);
                    if (submenu21_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu21_num[i]);
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }
        case 22://special_para
        {
            int i;
            subcursor();
            for (i=submenu_first;i<8+submenu_first;i++)
            {
                oled_p6x8str(18,i-submenu_first,submenu22_case[i]);
                if (submenu22_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu22_num[i]);
            }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu22_case[i]);
                    if (submenu22_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu22_num[i]);
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }

        case 23://Control
        {
            int i;
            subcursor();
            for (i=submenu_first;i<8+submenu_first;i++)
            {
                oled_p6x8str(18,i-submenu_first,submenu23_case[i]);
                if (submenu23_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu23_num[i]);
            }
            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu23_case[i]);
                    if (submenu23_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu23_num[i]);
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }
        case 24://start_para
        {
            break;
        }


        case 40://AD_dis
        {
            int i;
            subcursor();
            for (i=submenu_first;i<8+submenu_first;i++)
            {
                oled_p6x8str(18,i-submenu_first,submenu40_case[i]);
                if (submenu40_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu40_num[i]);
            }


            while(1)
            {
                subkey();
                if (cnt.oled==cnt.oled_rst)
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu40_case[i]);
                    if (submenu40_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu40_num[i]);
                }


                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }



        case 41://err_dis
        {
            int i;
            subcursor();
            for (i=submenu_first;i<8+submenu_first;i++)
            {
                oled_p6x8str(18,i-submenu_first,submenu41_case[i]);
                if (submenu41_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu41_num[i]);
            }
            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu41_case[i]);
                    if (submenu41_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu41_num[i]);
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }


        case 42://A1_dis
        {
            int i;
            subcursor();
            for (i=submenu_first;i<8+submenu_first;i++)
            {
                oled_p6x8str(18,i-submenu_first,submenu42_case[i]);
                if (submenu42_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu42_num[i]);
            }


            while(1)
            {
                subkey();
                if (cnt.oled==cnt.oled_rst)
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu42_case[i]);
                    if (submenu42_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, *submenu42_num[i]);
                }


                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }
        case 43://cnt.dis
        {
            int i=0;
            subcursor();

            for (i=submenu_first;i<8+submenu_first;i++)
             {
                 oled_p6x8str(18,i-submenu_first,submenu43_case[i]);
                 if (submenu43_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)(*submenu43_num[i]));
             }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu43_case[i]);
                    if (submenu43_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first,(float)(*submenu43_num[i]));
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }
        case 44://cnt.dis
        {
            int i=0;
            subcursor();

            for (i=submenu_first;i<8+submenu_first;i++)
             {
                 oled_p6x8str(18,i-submenu_first,submenu44_case[i]);
                 if (submenu44_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)(*submenu44_num[i]));
             }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu44_case[i]);
                    if (submenu44_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first,(float)(*submenu44_num[i]));
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }
        case 60:
        {
            int i=0;
            subcursor();

            for (i=submenu_first;i<8+submenu_first;i++)
             {
                 oled_p6x8str(18,i-submenu_first,submenu60_case[i]);
                 if (submenu60_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)(*submenu60_num[i]));
             }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu60_case[i]);
                    if (submenu60_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first,(float)(*submenu60_num[i]));
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;            
        }
        case 61:
        {
            int i=0;
            subcursor();

            for (i=submenu_first;i<8+submenu_first;i++)
             {
                 oled_p6x8str(18,i-submenu_first,submenu61_case[i]);
                 if (submenu61_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)(*submenu61_num[i]));
             }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu61_case[i]);
                    if (submenu61_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first,(float)(*submenu61_num[i]));
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;            
        }

        case 62:
        {
            int i=0;
            subcursor();

            for (i=submenu_first;i<8+submenu_first;i++)
             {
                 oled_p6x8str(18,i-submenu_first,submenu62_case[i]);
                 if (submenu62_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)(*submenu62_num[i]));
             }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu62_case[i]);
                    if (submenu62_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first,(float)(*submenu62_num[i]));
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;            
        }
        case 63:
        {
            int i=0;
            subcursor();

            for (i=submenu_first;i<8+submenu_first;i++)
             {
                 oled_p6x8str(18,i-submenu_first,submenu63_case[i]);
                 if (submenu63_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)(*submenu63_num[i]));
             }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu63_case[i]);
                    if (submenu63_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first,(float)(*submenu63_num[i]));
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;            
        }     
        
        
        case 64:
        {
            int i=0;
            subcursor();

            for (i=submenu_first;i<8+submenu_first;i++)
             {
                 oled_p6x8str(18,i-submenu_first,submenu64_case[i]);
                 if (submenu64_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)(*submenu64_num[i]));
             }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu64_case[i]);
                    if (submenu64_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first,(float)(*submenu64_num[i]));
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;            
        }



        case 80:
        {
            int i=0;
            subcursor();

            for (i=submenu_first;i<8+submenu_first;i++)
             {
                 oled_p6x8str(18,i-submenu_first,submenu80_case[i]);
                 if (submenu80_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)(*submenu80_num[i]));
             }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu80_case[i]);
                    if (submenu80_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first,(float)(*submenu80_num[i]));
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }
        
        case 81:
        {
            int i=0;
            subcursor();

            for (i=submenu_first;i<8+submenu_first;i++)
             {
                 oled_p6x8str(18,i-submenu_first,submenu81_case[i]);
                 if (submenu81_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)(*submenu81_num[i]));
             }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu81_case[i]);
                    if (submenu81_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first,(float)(*submenu81_num[i]));
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }



        case 82:
        {
            int i=0;
            subcursor();

            for (i=submenu_first;i<8+submenu_first;i++)
             {
                 oled_p6x8str(18,i-submenu_first,submenu82_case[i]);
                 if (submenu82_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)(*submenu82_num[i]));
             }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu82_case[i]);
                    if (submenu82_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first,(float)(*submenu82_num[i]));
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }



        case 83:
        {
            int i=0;
            subcursor();

            for (i=submenu_first;i<8+submenu_first;i++)
             {
                 oled_p6x8str(18,i-submenu_first,submenu83_case[i]);
                 if (submenu83_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)(*submenu83_num[i]));
             }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu83_case[i]);
                    if (submenu83_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first,(float)(*submenu83_num[i]));
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }


        case 84:
        {
            int i=0;
            subcursor();

            for (i=submenu_first;i<8+submenu_first;i++)
             {
                 oled_p6x8str(18,i-submenu_first,submenu84_case[i]);
                 if (submenu84_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)(*submenu84_num[i]));
             }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu84_case[i]);
                    if (submenu84_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first,(float)(*submenu84_num[i]));
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }


        case 85:
        {
            int i=0;
            subcursor();

            for (i=submenu_first;i<8+submenu_first;i++)
             {
                 oled_p6x8str(18,i-submenu_first,submenu85_case[i]);
                 if (submenu85_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)(*submenu85_num[i]));
             }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu85_case[i]);
                    if (submenu85_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first,(float)(*submenu85_num[i]));
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }

        case 86:
        {
            int i=0;
            subcursor();

            for (i=submenu_first;i<8+submenu_first;i++)
             {
                 oled_p6x8str(18,i-submenu_first,submenu86_case[i]);
                 if (submenu86_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)(*submenu86_num[i]));
             }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu86_case[i]);
                    if (submenu86_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first,(float)(*submenu86_num[i]));
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }
        case 87:
        {
            int i=0;
            subcursor();

            for (i=submenu_first;i<8+submenu_first;i++)
             {
                 oled_p6x8str(18,i-submenu_first,submenu87_case[i]);
                 if (submenu87_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first, (float)(*submenu87_num[i]));
             }

            while(1)
            {
                subkey();
                for (i=submenu_first;i<8+submenu_first;i++)
                {
                    oled_p6x8str(18,i-submenu_first,submenu87_case[i]);
                    if (submenu87_case[i][0]!='\0') OLED_Print_Num1(76,i-submenu_first,(float)(*submenu87_num[i]));
                }
                if (out)
                {
                    out=0;
                    break;
                }
            }
            break;
        }



    }
}
void subkey()
{
    if (!keydown())
    {
        subline++;
        if (subline==8)
            subline=0;
        subcursor();

    }
    if (!keyup())
    {
        subline--;
        if (subline==-1)
            subline=7;
        subcursor();
    }
    if (!keyright())
    {
        switch(line+menu_first+menu_case_num*20)
        {
            case 0:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        servo(SERVO_MIDDLE);
                        motor1(0);
                        flag.str=0;
                        cnt.speedout_err0=0;
                        break;
                    }
                    case 1:
                    {
                        flag.ste_con=0;
                        break;
                    }
                    case 2:
                    {
                        flag.mot_con=0;
                        break;
                    }
                    case 3:
                    {
                        flag.island_fx=0;
                        break;
                    }
                    case 6:
                    {
                        if (cnt.flash_xb>0)
                            cnt.flash_xb--;
                        break;
                    }
                    case 7:
                    {
                        flag.man_swi=0;
                        break;
                    }
                    case 8:
                    {
                        flag.DD_EN=0;
                        break;
                    }
                    case 9:
                    {
                        flag.start_EN=0;
                        break;
                    }
                    case 10:
                    {
                        flag.pro_EN=0;
                        break;
                    }
                }
                break;
            }



            case 5:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        add-=key_add*1;
                        break;
                    }
                    case 1:
                    {
                        gain-=key_add*1;
                        break;
                    }
                    case 2:
                    {              
                        rate_gain/=10;
                        break;
                    }
                    case 3:
                    {
                        add_gain/=10;
                        break;
                    }
                }
                break;    
            }
            case 4:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        steer.Kp-=key_add*add*add_gain;
                        steer.Kp/=gain;
                        break;
                    }
                    case 1:
                    {
                        steer.Kd-=key_add*add*add_gain;
                        steer.Kd/=gain;
                        break;
                    }
                    case 2:
                    {
                        motor.Kp-=key_add*add*add_gain;
                        motor.Kp/=gain;
                        break;
                    }
                    case 3:
                    {
                        motor.Ki-=key_add*add*add_gain;
                        motor.Ki/=gain;
                        break;
                    }
                    case 4:
                    {
                        motor.Kd-=key_add*add*add_gain;
                        motor.Kd/=gain;
                        break;
                    }
                    case 5:
                    {
                        steer.rate_pid-=key_add*add*add_gain;
                        steer.rate_pid/=gain;
                        break;
                    }
                    case 6:
                    {
                        steer.rate_ai-=key_add*add*add_gain;
                        steer.rate_ai/=gain;
                        break;
                    }
                }
                break;    
            }
            case 2:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        rate.err-=key_add*1*rate_gain;
                        break;
                    }
                    case 1:
                    {
                        rate.err_tg-=key_add*1*rate_gain;
                        break;
                    }
                    case 2:
                    {
                        rate.dynamic_kp-=key_add*rate_gain;
                        break;
                    }
                    case 3:
                    {
                        rate.ste-=key_add*rate_gain;
                        break;
                    }
                    case 4:
                    {
                        rate.ste_lef-=key_add*rate_gain;
                        break;
                    }     
 
                    case 5:
                    {
                        rate.ste_rig-=key_add*rate_gain;
                        break;
                    }  
                    case 6:
                    {
                        rate.err_p-=key_add*rate_gain;
                        break;
                    }
                    case 7:
                    {
                        rate.err_n-=key_add*rate_gain;
                        break;
                    }
                    case 8:
                    {
                       rate.sharptrun_stop-=key_add*rate_gain;
                       break;
                    } 
                    case 9:
                    {
                        rate.outof_sharpturn_str-=key_add*rate_gain;
                        break;
                    }    
                    case 10:
                    {
                        rate.basic-=key_add*rate_gain;
                        break;
                    }   
                    case 11:
                    {
                        rate.rush-=key_add*rate_gain;
                        break;
                    }  
                    case 12:
                    {
                        rate.encoder-=key_add*rate_gain;
                        break;
                    }
                }
                break;    
            }
            case 3:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        enc.expect_speed-=key_add*add*add_gain;
                        break;
                    }
                    case 1:
                    {
                        enc.speed_control_out_max-=key_add*add*add_gain;
                        break;
                    }
                    case 2:
                    {
                        cnt.run_time_limit-=key_add*add_gain;
                        break;
                    }
                    case 3:
                    {
                        rate.curve_stop-=key_add*0.01;
                        break;
                    }
                    case 4:
                    {
                        rate.island_stop-=key_add*0.01;
                        break;
                    }
                    case 5:
                    {
                        cnt.str_rush-=key_add*0.5;
                        break;
                    }

                }
                break;    
            }


            case 24:
            {
                switch(subline+submenu_first)
                {

               }
                break;    
            }


            /*******************/
            case 41:
            {
                if (cnt.oled_rst>10)
                {
                    cnt.oled=0;
                    cnt.oled_rst-=key_add*10;
                }
                else if (cnt.oled_rst<=10 && cnt.oled_rst>1)
                {
                    cnt.oled=0;
                    cnt.oled_rst--;
                }
                break;
            }  
            case 42:
            {
                if (cnt.oled_rst>10)
                {
                    cnt.oled=0;
                    cnt.oled_rst-=key_add*10;

                }
                else if (cnt.oled_rst<=10 && cnt.oled_rst>1)
                {
                    cnt.oled=0;
                    cnt.oled_rst--;
                }
                break;
            }

            /************************/

            case 60:
            {
                switch(subline-submenu_first)
                {
                    case 0:
                    {
                        cnt.left_die_num--;
                        break;
                    }
                    case 1:
                    {
                        cnt.right_die_num--;
                        break;
                    }
                    case 2:
                    {
                        cnt.cross_num--;
                        break;
                    }
                    case 3:
                    {
                        cnt.island_num--;
                        break;
                    }
                    case 4:
                    {
                        flag.left_die_EN=0;
                        break;
                    }
                    case 5:
                    {
                        flag.right_die_EN=0;
                        break;
                    }
                    case 6:
                    {
                        flag.cross_EN=0;
                        break;
                    }
                    case 7:
                    {
                        flag.island_EN=0;
                        break;
                    }
                    case 8:
                    {
                        flag.all_EN=0;
                        break;
                    }
                }
                break;
            }


            case 61:
            {
                switch(subline-submenu_first)
                {
                    case 0:
                    {
                        lt_xh--;
                        break;
                    }
                    case 1:
                    {
                        lt_open-=key_add*0.5;
                        break;
                    }
                    case 2:
                    {
                        lt_close-=key_add*0.5;
                        break;
                    }
                    case 3:
                    {
                        lt_die-=key_add*10;
                        break;
                    }
                    case 4:
                    {
                        lt_dieto-=key_add*10;
                        break;
                    }
                    case 5:
                    {
                        lt_angle-=key_add*10;
                        break;
                    }
                }
                break;    
            }
            
            case 62:
            {
                switch(subline-submenu_first)
                {
                    case 0:
                    {
                        rt_xh--;
                        break;
                    }
                    case 1:
                    {
                        rt_open-=key_add*0.5;
                        break;
                    }
                    case 2:
                    {
                        rt_close-=key_add*0.5;
                        break;
                    }
                    case 3:
                    {
                        rt_die-=key_add*10;
                        break;
                    }
                    case 4:
                    {
                        rt_dieto-=key_add*10;
                        break;
                    }
                    case 5:
                    {
                        rt_angle-=key_add*10;
                        break;
                    }
                }
                break;    
            }            
            
            case 63:
            {
                switch(subline-submenu_first)
                {
                    case 0:
                    {
                        ct_xh--;
                        break;
                    }
                    case 1:
                    {
                        ct_open-=key_add*0.5;
                        break;
                    }
                    case 2:
                    {
                        ct_close-=key_add*0.5;
                        break;
                    }

                }
                break;    
            }     
            
            case 64:
            {
                switch(subline-submenu_first)
                {
                    case 0:
                    {
                        it_xh--;
                        break;
                    }
                    case 1:
                    {
                        it_t1-=key_add*10;
                        break;
                    }
                    case 2:
                    {
                        it_t2-=key_add*10;
                        break;
                    }
                    case 3:
                    {
                        it_t3-=key_add*10;
                        break;
                    }
                    case 4:
                    {
                        it_s1-=key_add*10;
                        break;
                    }
                    case 5:
                    {
                        it_s2-=key_add*10;
                        break;
                    }
                    case 6:
                    {
                        it_s3-=key_add*10;
                        break;
                    }                    
                    
                }
                break;    
            }


            case 80:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        cnt.T_island_t1[0]-=key_add*10;
                        break;
                    }
                    case 1:
                    {
                        cnt.T_island_t2[0]-=key_add*10;
                        break;
                    }
                    case 2:
                    {
                        cnt.T_island_t3[0]-=key_add*10;
                        break;
                    }
                    case 3:
                    {
                        cnt.T_island_s1[0]-=key_add*10;
                        break;
                    }
                    case 4:
                    {
                        cnt.T_island_s2[0]-=key_add*10;
                        break;
                    }
                    case 5:
                    {
                        cnt.T_island_s3[0]-=key_add*10;
                        break;
                    }


                }
                break;
            }
            case 81:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        cnt.T_island_t1[1]-=key_add*10;
                        break;
                    }
                    case 1:
                    {
                        cnt.T_island_t2[1]-=key_add*10;
                        break;
                    }
                    case 2:
                    {
                        cnt.T_island_t3[1]-=key_add*10;
                        break;
                    }
                    case 3:
                    {
                        cnt.T_island_s1[1]-=key_add*10;
                        break;
                    }
                    case 4:
                    {
                        cnt.T_island_s2[1]-=key_add*10;
                        break;
                    }
                    case 5:
                    {
                        cnt.T_island_s3[1]-=key_add*10;
                        break;
                    }


                }
                break;
            }




            case 82:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        cnt.man_slow_open_time[0]-=key_add*0.5*add_gain;
                        break;
                    }
                    case 1:
                    {
                        cnt.man_slow_close_time[0]-=key_add*0.5*add_gain;
                        break;
                    }
                    case 2:
                    {
                        cnt.man_slow_ra[0]-=key_add*0.01;
                        break;
                    }
                    case 3:
                    {
                        cnt.man_slow_open_time[1]-=key_add*0.5*add_gain;
                        break;
                    }
                    case 4:
                    {
                        cnt.man_slow_close_time[1]-=key_add*0.5*add_gain;
                        break;
                    }
                    case 5:
                    {
                        cnt.man_slow_ra[1]-=key_add*0.01;
                        break;
                    }
                    case 6:
                    {
                        cnt.man_slow_open_time[2]-=key_add*0.5*add_gain;
                        break;
                    }
                    case 7:
                    {
                        cnt.man_slow_close_time[2]-=key_add*0.5*add_gain;
                        break;
                    }
                    case 8:
                    {
                        cnt.man_slow_ra[2]-=key_add*0.01;
                        break;
                    }


                }
                break;
            }

            case 83:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        cnt.man_fast_open_time[0]-=key_add*0.5;
                        break;
                    }
                    case 1:
                    {
                        cnt.man_fast_close_time[0]-=key_add*0.5;
                        break;
                    }
                    case 2:
                    {
                        cnt.man_fast_ra[0]-=key_add*0.01;
                        break;
                    }
                    case 3:
                    {
                        cnt.man_fast_open_time[1]-=key_add*0.5;
                        break;
                    }
                    case 4:
                    {
                        cnt.man_fast_close_time[1]-=key_add*0.5;
                        break;
                    }
                    case 5:
                    {
                        cnt.man_fast_ra[1]-=key_add*0.01;
                        break;
                    }
                    case 6:
                    {
                        cnt.man_fast_open_time[2]-=key_add*0.5;
                        break;
                    }
                    case 7:
                    {
                        cnt.man_fast_close_time[2]-=key_add*0.5;
                        break;
                    }
                    case 8:
                    {
                        cnt.man_fast_ra[2]-=key_add*0.01;
                        break;
                    }

                    
                }
                break;
            }

            case 84:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        cnt.man_left_open_time[0]-=key_add*0.5*rate_gain;
                        break;
                    }
                    case 1:
                    {
                        cnt.man_left_close_time[0]-=key_add*0.5*rate_gain;
                        break;
                    }
                    case 2:
                    {
                        cnt.man_left_angle[0]-=key_add*10;
                        break;
                    }
                    case 3:
                    {
                        cnt.man_left_open_time[1]-=key_add*0.5*rate_gain;
                        break;
                    }
                    case 4:
                    {
                        cnt.man_left_close_time[1]-=key_add*0.5*rate_gain;
                        break;
                    }
                    case 5:
                    {
                        cnt.man_left_angle[1]-=key_add*10;
                        break;
                    }
                    case 6:
                    {
                        cnt.man_left_open_time[2]-=key_add*0.5*rate_gain;
                        break;
                    }
                    case 7:
                    {
                        cnt.man_left_close_time[2]-=key_add*0.5*rate_gain;
                        break;
                    }
                    case 8:
                    {
                        cnt.man_left_angle[2]-=key_add*10;
                        break;
                    }


                }
                break;
            }

            case 85:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        cnt.man_right_open_time[0]-=key_add*0.5*rate_gain;
                        break;
                    }
                    case 1:
                    {
                        cnt.man_right_close_time[0]-=key_add*0.5*rate_gain;
                        break;
                    }
                    case 2:
                    {
                        cnt.man_right_angle[0]-=key_add*10;
                        break;
                    }
                    case 3:
                    {
                        cnt.man_right_open_time[1]-=key_add*0.5*rate_gain;
                        break;
                    }
                    case 4:
                    {
                        cnt.man_right_close_time[1]-=key_add*0.5*rate_gain;
                        break;
                    }
                    case 5:
                    {
                        cnt.man_right_angle[1]-=key_add*10;
                        break;
                    }
                    case 6:
                    {
                        cnt.man_right_open_time[2]-=key_add*0.5*rate_gain;
                        break;
                    }
                    case 7:
                    {
                        cnt.man_right_close_time[2]-=key_add*0.5*rate_gain;
                        break;
                    }
                    case 8:
                    {
                        cnt.man_right_angle[2]-=key_add*10;
                        break;
                    }


                }
                break;
            }

            case 86:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        cnt.man_xie_open_time[0]-=key_add*0.5*add_gain;
                        break;
                    }
                    case 1:
                    {
                        cnt.man_xie_close_time[0]-=key_add*0.5*add_gain;
                        break;
                    }

                    case 2:
                    {
                        cnt.man_xie_open_time[1]-=key_add*0.5*add_gain;
                        break;
                    }
                    case 3:
                    {
                        cnt.man_xie_close_time[1]-=key_add*0.5*add_gain;
                        break;
                    }

                    case 4:
                    {
                        cnt.man_xie_open_time[2]-=key_add*0.5*add_gain;
                        break;
                    }
                    case 5:
                    {
                        cnt.man_xie_close_time[2]-=key_add*0.5*add_gain;
                        break;
                    }



                }
                break;
            }

            case 87:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        test.mot_du-=key_add*10*add_gain;
                        break;
                    }
                    case 1:
                    {
                        test.ste_du-=key_add*10*add_gain;
                        break;
                    }
                    case 2:
                    {
                        test.ste_du1-=key_add*10*add_gain;
                        break;
                    }
                    case 3:
                    {
                        test.mot_du1-=key_add*10*add_gain;
                        break;
                    }

                }
                break;
            }



        }
    }
    if (!keyleft())
    {
        switch(line+menu_first+menu_case_num*20)
        {
            case 0:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        flag.str=1;
                        flag.timeswitch=1;
                        cnt.speedout_err0=0;
                        cnt._5ms=0;
                        cnt._250ms=0;
                        cnt._1ms=0;
                        cnt._1s=0;
                        cnt.inductance_same=0;
                        cnt.inductance_curve=0;
                        out=1;
                        break;
                    }
                    case 1:
                    {
                        flag.ste_con=1;
                        break;
                    }
                    case 2:
                    {
                        flag.mot_con=1;
                        break;
                    }
                    case 3:
                    {
                        flag.island_fx=1;
                        break;
                    }
                    case 6:
                    {
                        if (cnt.flash_xb<3)
                            cnt.flash_xb++;
                        break;
                    }
                    case 7:
                    {
                        flag.man_swi=1;
                        break;
                    }
                    case 8:
                    {
                        flag.DD_EN=1;
                        break;
                    }
                    case 9:
                    {
                        flag.start_EN=1;
                        break;
                    }
                    case 10:
                    {
                        flag.pro_EN=1;
                        break;
                    }


                }
                break;
            }

            case 5:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        add+=key_add*1;
                        break;
                    }
                    case 1:
                    {
                        gain+=key_add*1;
                        break;
                    }
                    case 2:
                    {              
                        rate_gain*=10;
                        break;
                    }
                    case 3:
                    {
                        add_gain*=10;
                        break;
                    }
                }
                break;    
            }
            case 4:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        steer.Kp+=key_add*add*add_gain;
                        steer.Kp*=gain;
                        break;
                    }
                    case 1:
                    {
                        steer.Kd+=key_add*add*add_gain;
                        steer.Kd*=gain;
                        break;
                    }
                    case 2:
                    {
                        motor.Kp+=key_add*add*add_gain;
                        motor.Kp*=gain;
                        break;
                    }
                    case 3:
                    {
                        motor.Ki+=key_add*add*add_gain;
                        motor.Ki*=gain;
                        break;
                    }
                    case 4:
                    {
                        motor.Kd+=key_add*add*add_gain;
                        motor.Kd*=gain;
                        break;
                    }
                    case 5:
                    {
                        steer.rate_pid+=key_add*add*add_gain;
                        steer.rate_pid*=gain;
                        break;
                    }
                    case 6:
                    {
                        steer.rate_ai+=key_add*add*add_gain;
                        steer.rate_ai*=gain;
                        break;
                    }
                }
                break;    
            }
            case 2:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        rate.err+=key_add*1*rate_gain;
                        break;
                    }
                    case 1:
                    {
                        rate.err_tg+=key_add*1*rate_gain;
                        break;
                    }
                    case 2:
                    {
                        rate.dynamic_kp+=key_add*rate_gain;
                        break;
                    }
                    case 3:
                    {
                        rate.ste+=key_add*rate_gain;
                        break;
                    }
                    case 4:
                    {
                        rate.ste_lef+=key_add*rate_gain;
                        break;
                    }

                    case 5:
                    {
                        rate.ste_rig+=key_add*rate_gain;
                        break;
                    }
                    case 6:
                    {
                        rate.err_p+=key_add*rate_gain;
                        break;
                    }
                    case 7:
                    {
                        rate.err_n+=key_add*rate_gain;
                        break;
                    }
                    case 8:
                    {
                       rate.sharptrun_stop+=key_add*rate_gain;
                       break;
                    } 
                    case 9:
                    {
                        rate.outof_sharpturn_str+=key_add*rate_gain;
                        break;
                    }    
                    case 10:
                    {
                        rate.basic+=key_add*rate_gain;
                        break;
                    }   
                    case 11:
                    {
                        rate.rush+=key_add*rate_gain;
                        break;
                    }  
                    case 12:
                    {
                        rate.encoder+=key_add*rate_gain;
                        break;
                    }
                }
                break;    
            }
            case 3:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        enc.expect_speed+=key_add*add*add_gain;
                        break;
                    }
                    case 1:
                    {
                        enc.speed_control_out_max+=key_add*add*add_gain;
                        break;
                    }
                    case 2:
                    {
                        cnt.run_time_limit+=key_add*add_gain;
                        break;
                    }
                    case 3:
                    {
                        rate.curve_stop+=key_add*0.01;
                        break;
                    }
                    case 4:
                    {
                        rate.island_stop+=key_add*0.01;
                        break;
                    }
                    case 5:
                    {
                        cnt.str_rush+=key_add*0.5;
                        break;
                    }

                }
                break;    
            }

            case 24:
            {
                switch(subline+submenu_first)
                {


               }
                break;    

            }

            case 41:
            {
                if (cnt.oled_rst>0&&cnt.oled_rst<100)
                {
                    cnt.oled=0;
                    cnt.oled_rst+=key_add*10;
                }
                break;
            }
            case 42:
            {
                if (cnt.oled_rst>0&&cnt.oled_rst<100)
                {
                    cnt.oled=0;
                    cnt.oled_rst+=key_add*10;
                }                
                break;
            }
            case 60:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        cnt.left_die_num++;
                        break;
                    }
                    case 1:
                    {
                        cnt.right_die_num++;
                        break;
                    }
                    case 2:
                    {
                        cnt.cross_num++;
                        break;
                    }
                    case 3:
                    {
                        cnt.island_num++;
                        break;
                    }
                    case 4:
                    {
                        flag.left_die_EN=0;
                        break;
                    }
                    case 5:
                    {
                        flag.right_die_EN=1;
                        break;
                    }
                    case 6:
                    {
                        flag.cross_EN=1;
                        break;
                    }
                    case 7:
                    {
                        flag.island_EN=1;
                        break;
                    }
                    case 8:
                    {
                        flag.all_EN=1;
                        break;
                    }
                }
                break;
            }
            case 61:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        lt_xh++;
                        break;
                    }
                    case 1:
                    {
                        lt_open+=key_add*0.5;
                        break;
                    }
                    case 2:
                    {
                        lt_close+=key_add*0.5;
                        break;
                    }
                    case 3:
                    {
                        lt_die+=key_add*10;
                        break;
                    }
                    case 4:
                    {
                        lt_dieto+=key_add*10;
                        break;
                    }
                    case 5:
                    {
                        lt_angle+=key_add*10;
                        break;
                    }
                }
                break;    
            }
            
            case 62:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        rt_xh++;
                        break;
                    }
                    case 1:
                    {
                        rt_open+=key_add*0.5;
                        break;
                    }
                    case 2:
                    {
                        rt_close+=key_add*0.5;
                        break;
                    }
                    case 3:
                    {
                        rt_die+=key_add*10;
                        break;
                    }
                    case 4:
                    {
                        rt_dieto+=key_add*10;
                        break;
                    }
                    case 5:
                    {
                        rt_angle+=key_add*10;
                        break;
                    }
                }
                break;    
            }            
            
            case 63:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        ct_xh++;
                        break;
                    }
                    case 1:
                    {
                        ct_open+=key_add*0.5;
                        break;
                    }
                    case 2:
                    {
                        ct_close+=key_add*0.5;
                        break;
                    }

                }
                break;    
            }     
            
            case 64:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        it_xh++;
                        break;
                    }
                    case 1:
                    {
                        it_t1+=key_add*10;
                        break;
                    }
                    case 2:
                    {
                        it_t2+=key_add*10;
                        break;
                    }
                    case 3:
                    {
                        it_t3+=key_add*10;
                        break;
                    }
                    case 4:
                    {
                        it_s1+=key_add*10;
                        break;
                    }
                    case 5:
                    {
                        it_s2+=key_add*10;
                        break;
                    }
                    case 6:
                    {
                        it_s3+=key_add*10;
                        break;
                    }                    
                    
                }
                break;    
            }

            case 80:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        cnt.T_island_t1[0]+=key_add*10;
                        break;
                    }
                    case 1:
                    {
                        cnt.T_island_t2[0]+=key_add*10;
                        break;
                    }
                    case 2:
                    {
                        cnt.T_island_t3[0]+=key_add*10;
                        break;
                    }
                    case 3:
                    {
                        cnt.T_island_s1[0]+=key_add*10;
                        break;
                    }
                    case 4:
                    {
                        cnt.T_island_s2[0]+=key_add*10;
                        break;
                    }
                    case 5:
                    {
                        cnt.T_island_s3[0]+=key_add*10;
                        break;
                    }


                }
                break;
            }
            case 81:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        cnt.T_island_t1[1]+=key_add*10;
                        break;
                    }
                    case 1:
                    {
                        cnt.T_island_t2[1]+=key_add*10;
                        break;
                    }
                    case 2:
                    {
                        cnt.T_island_t3[1]+=key_add*10;
                        break;
                    }
                    case 3:
                    {
                        cnt.T_island_s1[1]+=key_add*10;
                        break;
                    }
                    case 4:
                    {
                        cnt.T_island_s2[1]+=key_add*10;
                        break;
                    }
                    case 5:
                    {
                        cnt.T_island_s3[1]+=key_add*10;
                        break;
                    }


                }
                break;
            }
            


            case 82:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        cnt.man_slow_open_time[0]+=key_add*0.5*add_gain;
                        break;
                    }
                    case 1:
                    {
                        cnt.man_slow_close_time[0]+=key_add*0.5*add_gain;
                        break;
                    }
                    case 2:
                    {
                        cnt.man_slow_ra[0]+=key_add*0.01;
                        break;
                    }
                    case 3:
                    {
                        cnt.man_slow_open_time[1]+=key_add*0.5*add_gain;
                        break;
                    }
                    case 4:
                    {
                        cnt.man_slow_close_time[1]+=key_add*0.5*add_gain;
                        break;
                    }
                    case 5:
                    {
                        cnt.man_slow_ra[1]+=key_add*0.01;
                        break;
                    }
                    case 6:
                    {
                        cnt.man_slow_open_time[2]+=key_add*0.5*add_gain;
                        break;
                    }
                    case 7:
                    {
                        cnt.man_slow_close_time[2]+=key_add*0.5*add_gain;
                        break;
                    }
                    case 8:
                    {
                        cnt.man_slow_ra[2]+=key_add*0.01;
                        break;
                    }


                }
                break;
            }

            case 83:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        cnt.man_fast_open_time[0]+=key_add*0.5;
                        break;
                    }
                    case 1:
                    {
                        cnt.man_fast_close_time[0]+=key_add*0.5;
                        break;
                    }
                    case 2:
                    {
                        cnt.man_fast_ra[0]+=key_add*0.01;
                        break;
                    }
                    case 3:
                    {
                        cnt.man_fast_open_time[1]+=key_add*0.5;
                        break;
                    }
                    case 4:
                    {
                        cnt.man_fast_close_time[1]+=key_add*0.5;
                        break;
                    }
                    case 5:
                    {
                        cnt.man_fast_ra[1]+=key_add*0.01;
                        break;
                    }
                    case 6:
                    {
                        cnt.man_fast_open_time[2]+=key_add*0.5;
                        break;
                    }
                    case 7:
                    {
                        cnt.man_fast_close_time[2]+=key_add*0.5;
                        break;
                    }
                    case 8:
                    {
                        cnt.man_fast_ra[2]+=key_add*0.01;
                        break;
                    }


                }
                break;
            }

            case 84:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        cnt.man_left_open_time[0]+=key_add*0.5*rate_gain;
                        break;
                    }
                    case 1:
                    {
                        cnt.man_left_close_time[0]+=key_add*0.5*rate_gain;
                        break;
                    }
                    case 2:
                    {
                        cnt.man_left_angle[0]+=key_add*10;
                        break;
                    }
                    case 3:
                    {
                        cnt.man_left_open_time[1]+=key_add*0.5*rate_gain;
                        break;
                    }
                    case 4:
                    {
                        cnt.man_left_close_time[1]+=key_add*0.5*rate_gain;
                        break;
                    }
                    case 5:
                    {
                        cnt.man_left_angle[1]+=key_add*10;
                        break;
                    }
                    case 6:
                    {
                        cnt.man_left_open_time[2]+=key_add*0.5*rate_gain;
                        break;
                    }
                    case 7:
                    {
                        cnt.man_left_close_time[2]+=key_add*0.5*rate_gain;
                        break;
                    }
                    case 8:
                    {
                        cnt.man_left_angle[2]+=key_add*10;
                        break;
                    }


                }
                break;
            }

            case 85:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        cnt.man_right_open_time[0]+=key_add*0.5*rate_gain;
                        break;
                    }
                    case 1:
                    {
                        cnt.man_right_close_time[0]+=key_add*0.5*rate_gain;
                        break;
                    }
                    case 2:
                    {
                        cnt.man_right_angle[0]+=key_add*10;
                        break;
                    }
                    case 3:
                    {
                        cnt.man_right_open_time[1]+=key_add*0.5*rate_gain;
                        break;
                    }
                    case 4:
                    {
                        cnt.man_right_close_time[1]+=key_add*0.5*rate_gain;
                        break;
                    }
                    case 5:
                    {
                        cnt.man_right_angle[1]+=key_add*10;
                        break;
                    }
                    case 6:
                    {
                        cnt.man_right_open_time[2]+=key_add*0.5*rate_gain;
                        break;
                    }
                    case 7:
                    {
                        cnt.man_right_close_time[2]+=key_add*0.5*rate_gain;
                        break;
                    }
                    case 8:
                    {
                        cnt.man_right_angle[2]+=key_add*10;
                        break;
                    }


                }
                break;
            }

            case 86:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        cnt.man_xie_open_time[0]+=key_add*0.5*add_gain;
                        break;
                    }
                    case 1:
                    {
                        cnt.man_xie_close_time[0]+=key_add*0.5*add_gain;
                        break;
                    }

                    case 2:
                    {
                        cnt.man_xie_open_time[1]+=key_add*0.5;
                        break;
                    }
                    case 3:
                    {
                        cnt.man_xie_close_time[1]+=key_add*0.5;
                        break;
                    }

                    case 4:
                    {
                        cnt.man_xie_open_time[2]+=key_add*0.5;
                        break;
                    }
                    case 5:
                    {
                        cnt.man_xie_close_time[2]+=key_add*0.5;
                        break;
                    }



                }
                break;
            }

            case 87:
            {
                switch(subline+submenu_first)
                {
                    case 0:
                    {
                        test.mot_du+=key_add*10*add_gain;
                        break;
                    }
                    case 1:
                    {
                        test.ste_du+=key_add*10*add_gain;
                        break;
                    }
                    case 2:
                    {
                        test.ste_du1+=key_add*10*add_gain;
                        break;
                    }
                    case 3:
                    {
                        test.mot_du1+=key_add*10*add_gain;
                        break;
                    }

                }
                break;
            }

        }

    }  

    if (!keycenter())
    {
        switch(line+menu_first+menu_case_num*20)
        {
            case 0:
            {
                switch(subline+submenu_first)
                {
                    case 4:
                    {
                        Flash_SaveData();
                        cnt.save++;
                        break;
                    }
                    case 5:
                    {
                        Flash_ReadData();
                        cnt.read++;
                        break;
                    }
                    default:
                        break;

                }
                break;
            }
            case 60:
            {
                switch(subline+submenu_first)
                {
                    case 6:
                    {
                        cnt.left_die_open_time[(int)lt_xh]=lt_open;
                        cnt.left_die_close_time[(int)lt_xh]=lt_close;
                        cnt.left_die_time[(int)lt_xh]=lt_die;
                        cnt.left_die_to_right_time[(int)lt_xh]=lt_dieto;
                        cnt.left_die_angle[(int)lt_xh]=lt_angle;
                        lt_save++;
                        break;
                    }

                    default:
                        break;

                }
                break;
            }
            case 61:
            {
                switch(subline+submenu_first)
                {
                    case 6:
                    {
                        cnt.right_die_open_time[(int)rt_xh]=rt_open;
                        cnt.right_die_close_time[(int)rt_xh]=rt_close;
                        cnt.right_die_time[(int)rt_xh]=rt_die;
                        cnt.right_die_to_left_time[(int)rt_xh]=rt_dieto;
                        cnt.right_die_angle[(int)rt_xh]=rt_angle;
                        rt_save++;
                        break;
                    }

                    default:
                        break;

                }
                break;
            }

            case 62:
            {
                switch(subline+submenu_first)
                {
                    case 3:
                    {
                        cnt.cross_open_time[(int)ct_xh]=ct_open;
                        cnt.cross_close_time[(int)ct_xh]=ct_close;
                        ct_save++;
                        break;
                    }

                    default:
                        break;

                }
                break;
            }
            case 63:
            {
                switch(subline+submenu_first)
                {
                    case 3:
                    {

                        it_save++;
                        break;
                    }

                    default:
                        break;

                }
                break;
            }
            
            default:
                break;

        }
        my_delay(1000);
        out=1;
     
    }
    if (!key1())
    {
        if (submenu_first<12)
            submenu_first++;
        else
            submenu_first=0;

        oled_clear();
        subcursor();
    }
    if (!key2())
    {
        if (submenu_first>0)
            submenu_first--;
        oled_clear();
        subcursor();
    }   

    if (!key3())
    {
        if (key_add==1) key_add=10;
        else key_add=1;
    }
}
