/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 *
 * @file            control
 * @function        IO、外设、AD等初始化
 * @author          Cz
 * @date            2021-7-10
 ********************************************************************************************************************/
#include "headfile.h"
/**初始化一些其他文件变量**/
#define All_spe_Init 1
#define INF 999
void Gyro_Init()
{
    //    icm20602_init_spi(); //逐飞
        My_Gyro_Init();//柒桥
}
void Reed_init(void)
{
    //干簧管
    gpio_init(Reed1,GPI,0,PULLUP);
    gpio_init(Reed2,GPI,0,PULLUP);
}

void Beep_Init()
{
    gpio_init(P00_0, GPO, 0, NO_PULL);
}
void Pit_Init()
{
    pit_interrupt_ms(CCU6_1, PIT_CH0, 5);
}
void All_Init()
{
    /*各模块初始化*/
    seekfree_wireless_init();
    Key_Init(); //不用初始化,有意思
    Beep_Init();
    Encoder_Init();


//    Gyro_Init();


    Reed_init();

    Spe_Init();
    Variable_Init();




    oled_init();
    AD_Init();
    Control_Init();

    Pit_Init();
    cursor();
    Beep_Init();
//    Beep_Init();

}
void Variable_Init()
{
    //无初始化全局变量默认为0
    flag.slong_swi=1;


    flag.ste_con=1;
    flag.mot_con=1;

    flag.start_EN=1;
    flag.DD_EN=1;
    flag.pro_EN=1;

    cnt.oled_rst=10;

    test.mot_du=2500;
    test.ste_du=SERVO_MIDDLE;



    Flash_ReadData();


    cnt.read++;


}






