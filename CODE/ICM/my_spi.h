#ifndef MY_SPI_H
#define MY_SPI_H


#include "stdio.h"
#include "zf_gpio.h"
#include "zf_stm_systick.h"




#define SCLK_PORT P02_3
#define MOSI_PORT P02_2
#define MISO_PORT P02_4
#define CS_PORT   P02_5


#define SPI_SCK_CLR     gpio_set(SCLK_PORT,0)//时钟线拉低
#define SPI_MOSI_SET    gpio_set(MOSI_PORT,1)//数据线拉高
#define SPI_MOSI_CLR    gpio_set(MOSI_PORT,0)//数据线拉低
#define SPI_SCK_SET     gpio_set(SCLK_PORT,1)//时钟线拉高
#define SPI_MISO_READ   gpio_get(MISO_PORT)//读数据


void MY_SPIInit(void);
unsigned char MY_SPISendData(unsigned char dat);
static void MY_Delay(void);

#endif
