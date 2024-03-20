#ifndef _AD_H_
#define _AD_H_


#define ADSource ADC7

void Read_AD(void);
void AD_Init(void);
void AD_Bluetooth(void);
//电感参数
extern struct AD ad;

#endif
