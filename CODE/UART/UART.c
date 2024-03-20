/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 *
 * @file            Uart
 * @function        串口通信获取电感再用Python制图。
 * @author          Cz
 * @date            2021-7-10
 ********************************************************************************************************************/
#include "headfile.h"


void AD_Bluetooth(void)
{
        uint8 temp;
        char zt=0x03;
        int16 AD_data[9];

        AD_data[0]=ad.left;
        AD_data[1]=ad.shu_left;
        AD_data[2]=ad.xie_left;
        AD_data[3]=ad.mid_left;
//        AD_data[4]=ad.mid;
        AD_data[4]=ad.mid_right;
        AD_data[5]=ad.xie_right;
        AD_data[6]=ad.shu_right;
        AD_data[7]=ad.right;
        AD_data[8] = steer.duty;



        uart_putchar(UART_1,zt);
        uart_putchar(UART_1,~zt);
        for (int i=0;i<9;i++)
        {

            temp = (AD_data[i]& 0xFF);
            uart_putchar(UART_1,temp);
            temp = (AD_data[i] >>8)&0xFF;
            uart_putchar(UART_1,temp);

        }

        uart_putchar(UART_1,~zt);
        uart_putchar(UART_1,zt);


}
void AD_Bluetooth1(void)
{

    int16 AD_data[9];
    char num[10];
    AD_data[0]=ad.s_left;
    AD_data[1]=ad.s_shu_left;
    AD_data[2]=ad.s_xie_Left;
    AD_data[3]=ad.s_mid_left;

//        AD_data[4]=ad.mid;
    AD_data[4]=ad.s_mid_right;
    AD_data[5]=ad.s_xie_right;
    AD_data[6]=ad.s_shu_right;
    AD_data[7]=ad.s_right;
    AD_data[8] = steer.duty;




    for (int i=0;i<9;i++)
    {
        sprintf(num,"%d",AD_data[i]);
        uart_putstr(UART_1,num);
        if (i!=8) uart_putchar(UART_1,' ');
        else uart_putchar(UART_1,'\n');
    }




}

