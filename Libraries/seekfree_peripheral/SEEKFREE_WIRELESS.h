/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ����Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		����ת����ģ��
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		ADS v1.2.2
 * @Target core		TC377TP
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-11-23
 * @note		
					���߶��壺
					------------------------------------ 
					    ����ת����       ��Ƭ��                        
    					RX              �鿴SEEKFREE_WIRELESS.h�ļ��е�WIRELESS_UART_TX�궨��
    					TX              �鿴SEEKFREE_WIRELESS.h�ļ��е�WIRELESS_UART_RX�궨��
    					RTS             �鿴SEEKFREE_WIRELESS.h�ļ��е�RTS_PIN�궨��
    					CMD             ���ջ�������
					------------------------------------ 
 ********************************************************************************************************************/

#ifndef _SEEKFREE_WIRELESS
#define _SEEKFREE_WIRELESS


#include "common.h"


#define WIRELESS_UART        UART_1         //����ת����ģ�� ��ʹ�õ��Ĵ���
#define WIRELESS_UART_TX     UART1_TX_P11_12
#define WIRELESS_UART_RX     UART1_RX_P11_10
#define WIRELESS_UART_BAUD   115200

#define RTS_PIN P10_2 //��������λ����  ָʾ��ǰģ���Ƿ���Խ�������  0���Լ�������  1�����Լ�������


void 	wireless_uart_callback(void);
void    seekfree_wireless_init(void);
uint32  seekfree_wireless_send_buff(uint8 *buff, uint32 len);

#endif 
