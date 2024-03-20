/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 *
 * @file            main
 * @function        主函数
 * @author          Cz
 * @date            2021-11-28
 * @注释            初始化都在PCI目录下。
 ********************************************************************************************************************/

#include "Cpu0_Main.h"
#include "headfile.h"
#pragma section all "cpu0_dsram"



int core0_main(void)
{
	get_clk();//获取时钟频率  务必保留
	//用户在此处调用各种初始化函数等
	All_Init();
    //等待所有核心初始化完毕
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
