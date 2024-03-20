/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ����Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		zf_vadc
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		ADS v1.2.2
 * @Target core		TC377TP
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-11-23
 ********************************************************************************************************************/
 
#ifndef _zf_vadc_h
#define _zf_vadc_h

#include "common.h"



//��ö�ٶ��岻�����û��޸�
typedef enum    // ö��ADC���
{
	ADC_0,
	ADC_1,
	ADC_2,
	ADC_3,
	ADC_8 = 8,

}VADCN_enum;

typedef enum  // ö��ADCͨ��
{
    //ADC0��ѡ����
    ADC0_CH0_A0   = 0*16 + 0,
    ADC0_CH1_A1,
    ADC0_CH2_A2,
    ADC0_CH3_A3,
    ADC0_CH4_A4,
    ADC0_CH5_A5,
    ADC0_CH6_A6,
    ADC0_CH7_A7,

    //ADC1��ѡ����
    ADC1_CH0_A8   = 1*16 + 0,
    ADC1_CH2_A10  = 1*16 + 2,
    ADC1_CH3_A11,
    ADC1_CH4_A12,
    ADC1_CH5_A13,
	
	//ADC2��ѡ����
	ADC2_CH0_A16  = 2*16 + 0,
	ADC2_CH1_A17  = 2*16 + 1,
	ADC2_CH4_A20  = 2*16 + 4,
	ADC2_CH5_A21  = 2*16 + 5,

	//ADC3��ѡ����
	ADC3_CH0_A24  = 3*16 + 0,
	ADC3_CH1_A25  = 3*16 + 1,
	
	//ADC8��ѡ����
	ADC8_CH3_A35  = 8*16 + 3,
	ADC8_CH4_A36,
	ADC8_CH5_A37,
	ADC8_CH6_A38,
	ADC8_CH7_A39,
	ADC8_CH10_A42 = 8*16 + 10,
	ADC8_CH11_A43,
	ADC8_CH12_A44,
	ADC8_CH13_A45,
	ADC8_CH14_A46,
	ADC8_CH15_A47,
}VADC_CHN_enum;

//��ö�ٶ��岻�����û��޸�
typedef enum    // ö��ADCͨ��
{
    ADC_8BIT,     //8λ�ֱ���
    ADC_10BIT,    //10λ�ֱ���
    ADC_12BIT,    //12λ�ֱ���
}VADC_RES_enum;

void adc_init(VADCN_enum vadc_n, VADC_CHN_enum vadc_chn);
uint16 adc_convert(VADCN_enum vadc_n, VADC_CHN_enum vadc_chn, VADC_RES_enum vadc_res);
uint16 adc_mean_filter(VADCN_enum vadc_n, VADC_CHN_enum vadc_chn, VADC_RES_enum vadc_res, uint8 count);
#endif
