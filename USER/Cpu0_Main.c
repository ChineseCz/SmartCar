/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 *
 * @file            main
 * @function        ������
 * @author          Cz
 * @date            2021-11-28
 * @ע��            ��ʼ������PCIĿ¼�¡�
 ********************************************************************************************************************/

#include "Cpu0_Main.h"
#include "headfile.h"
#pragma section all "cpu0_dsram"



int core0_main(void)
{
	get_clk();//��ȡʱ��Ƶ��  ��ر���
	//�û��ڴ˴����ø��ֳ�ʼ��������
	All_Init();
    //�ȴ����к��ĳ�ʼ�����
	IfxCpu_emitEvent(&g_cpuSyncEvent);
	IfxCpu_waitEvent(&g_cpuSyncEvent, 0xFFFF);
	enableInterrupts();



	while (1)
	{
	    menu();
	    menukey();

	    if (flag.str&&flag.track!=5)
	        AD_Bluetooth1( );
	}
}

#pragma section all restore
