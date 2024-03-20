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
 
 
#include "Evadc/Adc/IfxEvadc_Adc.h"
#include "zf_assert.h"
#include "zf_vadc.h"
#include "stdio.h"


#define ADC_SAMPLE_FREQUENCY	1000000

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ADC��ʼ��
//  @param      adcn            ѡ��ADCģ��(ADC_0��ADC_1��ADC_2)
//  @param      ch              ѡ��ADCͨ��
//  @return     void
//  Sample usage:               adc_init(ADC_0, ADC0_CH0_A0);
//-------------------------------------------------------------------------------------------------------------------
void adc_init(VADCN_enum vadc_n, VADC_CHN_enum vadc_chn)
{
	static uint8 mudule_init_flag = 0;
    static uint8 group_init_flag[ADC_8+1];
	IfxEvadc_Adc evadc;
	IfxEvadc_Adc_Group adcGroup;
    IfxEvadc_Adc_Config adcConfig;
    IfxEvadc_Adc_GroupConfig adcGroupConfig;

    IfxEvadc_Adc_initModuleConfig(&adcConfig, &MODULE_EVADC);
	if(!mudule_init_flag)
	{
		mudule_init_flag = 1;
		IfxEvadc_Adc_initModule(&evadc, &adcConfig);
	}
	else
	{
	    evadc.evadc = adcConfig.evadc;
	}

    IfxEvadc_Adc_initGroupConfig(&adcGroupConfig, &evadc);

    adcGroupConfig.groupId = (IfxEvadc_GroupId)vadc_n;//IfxVadc_GroupId_0;
    adcGroupConfig.master  = adcGroupConfig.groupId;
    adcGroupConfig.arbiter.requestSlotQueue0Enabled  = TRUE; // enable Queue0 mode
    //adcGroupConfig.arbiter.requestSlotQueue1Enabled  = TRUE; // enable Queue1 mode
    //adcGroupConfig.arbiter.requestSlotQueue2Enabled  = TRUE; // enable Queue2 mode
    adcGroupConfig.queueRequest[0].triggerConfig.gatingMode = IfxEvadc_GatingMode_always;
    //adcGroupConfig.queueRequest[1].triggerConfig.gatingMode = IfxEvadc_GatingMode_always;
    //adcGroupConfig.queueRequest[2].triggerConfig.gatingMode = IfxEvadc_GatingMode_always;
	adcGroupConfig.inputClass[0].sampleTime = 1.0f/ADC_SAMPLE_FREQUENCY;
	adcGroupConfig.inputClass[1].sampleTime = 1.0f/ADC_SAMPLE_FREQUENCY;

    if(!group_init_flag[vadc_n])
    {
        group_init_flag[vadc_n] = 1;
        IfxEvadc_Adc_initGroup(&adcGroup, &adcGroupConfig);
    }
    else
    {
        adcGroup.groupId = adcGroupConfig.groupId;
        adcGroup.module = *adcGroupConfig.module;
        adcGroup.group = &adcGroupConfig.module->evadc->G[adcGroup.groupId];
    }

    IfxEvadc_Adc_Channel       adcChannel;
	IfxEvadc_Adc_ChannelConfig adcChannelConfig;

	IfxEvadc_Adc_initChannelConfig(&adcChannelConfig, &adcGroup);
	adcChannelConfig.channelId         = (IfxEvadc_ChannelId)(vadc_chn%16);
	adcChannelConfig.resultRegister    = (IfxEvadc_ChannelResult)(vadc_chn%16);
	IfxEvadc_Adc_initChannel(&adcChannel, &adcChannelConfig);
    IfxEvadc_Adc_addToQueue(&adcChannel, IfxEvadc_RequestSource_queue0, IFXEVADC_QUEUE_REFILL);
    IfxEvadc_Adc_startQueue(&adcGroup, IfxEvadc_RequestSource_queue0);
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      ADCת��һ��
//  @param      adcn            ѡ��ADCģ��(ADC_0��ADC_1��ADC_2)
//  @param      ch              ѡ��ADCͨ��
//  @return     void
//  Sample usage:               adc_convert(ADC_0, ADC0_CH0_A0, ADC_12BIT);
//-------------------------------------------------------------------------------------------------------------------
uint16 adc_convert(VADCN_enum vadc_n, VADC_CHN_enum vadc_chn, VADC_RES_enum vadc_res)
{
	Ifx_EVADC_G_RES result;
	uint8 temp;
	do
	{
		result = IfxEvadc_getResult(&MODULE_EVADC.G[vadc_n], vadc_chn%16);
	} while (!result.B.VF);

	temp = 4 - (vadc_res * 2);
	return((result.U&0x0fff)>>temp);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ADC��ֵ�˲�
//  @param      adcn            ѡ��ADCģ��(ADC_0��ADC_1��ADC_2)
//  @param      ch              ѡ��ADCͨ��
//  @param      count           ��ֵ�˲�����
//  @return     void
//  Sample usage:               adc_mean_filter(ADC_0, ADC0_CH0_A0, ADC_12BIT, 5);//�ɼ�5�� Ȼ�󷵻�ƽ��ֵ
//-------------------------------------------------------------------------------------------------------------------
uint16 adc_mean_filter(VADCN_enum vadc_n, VADC_CHN_enum vadc_chn, VADC_RES_enum vadc_res, uint8 count)
{
    uint8 i;
    uint32 sum;

    ZF_ASSERT(count);//���Դ�������Ϊ0

    sum = 0;
    for(i=0; i<count; i++)
    {
        sum += adc_convert(vadc_n, vadc_chn, vadc_res);
    }

    sum = sum/count;
    return (uint16)sum;
}
