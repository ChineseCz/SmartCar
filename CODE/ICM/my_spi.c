/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 *
 * @file            SPI
 * @function
 * @author          柒桥
 * @date            2021-7-10
 ********************************************************************************************************************/
#include "my_spi.h"


static void MY_Delay(void)
{
    return;
    volatile unsigned long time = 50;
    while (time--)
    {
        ;
    }
}

void MY_SPIInit(void)
{
    gpio_init(SCLK_PORT, GPO, 1, PUSHPULL);//推挽上拉
    gpio_init(MOSI_PORT, GPO, 1, PUSHPULL);//推挽上拉
    gpio_init(MISO_PORT, GPI, 1, PULLUP);//输入上拉
    gpio_init(CS_PORT, GPO, 1, PUSHPULL);//推挽上拉

}
unsigned char MY_SPISendData(unsigned char dat)
{
    unsigned char ret;

    for (unsigned char i = 0; i < 8; i++)
    {
        ret <<= 1;
        SPI_SCK_CLR;
        MY_Delay();
        if (dat & 0x80)
            SPI_MOSI_SET;
        else
            SPI_MOSI_CLR;
        dat <<= 1;
        MY_Delay();
        SPI_SCK_SET;
        MY_Delay();
        if (SPI_MISO_READ)
            ret |= 0x01;
    }
    return ret;
}
