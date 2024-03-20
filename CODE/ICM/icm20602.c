/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 *
 * @file            icm
 * @function        软件模拟SPI，硬件SPI可用逐飞官方库，当时用官方ICM的读取有BUG没解决，不太建议使用。
 * @author          柒桥
 * @date            2021-7-10
 ********************************************************************************************************************/
#include "icm20602.h"

int16 icm_gyro_x,icm_gyro_y,icm_gyro_z;
int16 icm_acc_x,icm_acc_y,icm_acc_z;
float angle,roll,Angle_Balance;
void MY_ICMInit()
{
    MY_Delay50ms();
    MY_ICMWriteOneByte(ICM20602_PWR_MGMT_1, 0x80);
    MY_Delay50ms();
    while (0x80 & MY_ICMReadOneByte(ICM20602_PWR_MGMT_1))
        ;
    MY_ICMWriteOneByte(ICM20602_PWR_MGMT_1, 0x01);
    MY_ICMWriteOneByte(ICM20602_PWR_MGMT_2, 0x00);
    MY_ICMWriteOneByte(ICM20602_CONFIG, 0x01);
    MY_ICMWriteOneByte(ICM20602_SMPLRT_DIV, 0x01); //sample rate
    // 0x10 1000
    // 0x18 2000
    MY_ICMWriteOneByte(ICM20602_GYRO_CONFIG, 0x10);    //+- 1000 dps
    MY_ICMWriteOneByte(ICM20602_ACCEL_CONFIG, 0x08);   //+-4g
    MY_ICMWriteOneByte(ICM20602_ACCEL_CONFIG_2, 0x03); //Average 4 samples   44.8HZ   //0x23 Average 16 samples
}

void MY_ICMGetValue(short *gx, short *gy, short *gz, short *ax, short *ay, short *az)
{
    unsigned char gyro_buff[6], acc_buff[6];
    MY_ICMReadMultiByte(ICM20602_GYRO_XOUT_H, gyro_buff, 6);
    MY_ICMReadMultiByte(ICM20602_ACCEL_XOUT_H, acc_buff, 6);
    *gx = (short)(((unsigned short)gyro_buff[0] << 8 | gyro_buff[1]));
    *gy = (short)(((unsigned short)gyro_buff[2] << 8 | gyro_buff[3]));
    *gz = (short)(((unsigned short)gyro_buff[4] << 8 | gyro_buff[5]));
    *ax = (short)(((unsigned short)acc_buff[0] << 8 | acc_buff[1]));
    *ay = (short)(((unsigned short)acc_buff[2] << 8 | acc_buff[3]));
    *az = (short)(((unsigned short)acc_buff[4] << 8 | acc_buff[5]));
}

static unsigned char MY_ICMWriteOneByte(unsigned char reg, unsigned char dat)
{
    unsigned char ret = 0x00;
    ICM_SET_CS_LOW();
    MY_SPISendData(reg | ICM20602_SPI_W);
    ret = MY_SPISendData(dat);
    ICM_SET_CS_HIGH();
    return ret;
}

static unsigned char MY_ICMReadOneByte(unsigned char reg)
{
    unsigned char ret;
    ICM_SET_CS_LOW();
    MY_SPISendData(reg | ICM20602_SPI_R);
    ret = MY_SPISendData(0x00);
    ICM_SET_CS_HIGH();
    return ret;
}
static void MY_ICMReadMultiByte(unsigned char reg, unsigned char *dat, unsigned char num)
{
    unsigned char i;
    ICM_SET_CS_LOW();
    MY_SPISendData(reg | ICM20602_SPI_R);
    for (i = 0; i < num; i++)
        dat[i] = MY_SPISendData(0x00);
    ICM_SET_CS_HIGH();
}

static float MY_angle(float angle_m,float gyro_m)
{
    float K1=0.01f,dt=0.005f;
    angle = K1 * angle_m+ (1-K1) * (angle + gyro_m * dt);
    return angle;
}

void My_Gyro_Init(void)
{
    MY_SPIInit();
    MY_ICMInit();
}

void My_Read_Gyro(void)
{
    MY_ICMGetValue(&icm_gyro_x,&icm_gyro_y,&icm_gyro_z,&icm_acc_x,&icm_acc_y,&icm_acc_z);
    roll=atan2(icm_acc_x,icm_acc_z)*57.29;//  180/3.1415926535
    Angle_Balance=MY_angle(roll,-icm_gyro_y*LSB);
}

