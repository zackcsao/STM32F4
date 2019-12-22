/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	main.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	main.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-20 15:38:17
*   Description:	修改说明
*
*
*********************************************************************/
/*****************************os*************************************/
#include "os.h"
/*****************************os*************************************/


/***************************project init head************************************/
#include "app_init.h"
#include "bsp.h"
/***************************project init head************************************/

/***************************task head *************************************/
#include "task_system_maintain.h"
#include "task_deal_data.h"
#include "task_display.h"
#include "task_gsm.h"
#include "task_gather_dev_status.h"
#include "task_control_motor.h"
#include "task_power_management.h"
#include "task_gather_water_level.h"
#include "task_log_history.h"

/***************************task head *************************************/
/********************硬件测试，正式版删除*************************/

//#include "netconf.h"
//#include "uart.h"
//#include "platform_gpio.h"
//#include "drv_8025t.h"
//#include "system_clock.h"
//#include "drv_w25q64fv.h"
//#include "drv_fm25v05.h"
//#include <stdio.h>
/*********************************************/

//extern void FlashDebugTask(void);
//extern void LEDTask(void);
static  void  AppTaskStart  (void *p_arg);					//任务函数声明

static  OS_TCB   AppTaskStartTCB;						//任务控制块
//static  OS_TCB   FlashDebugTaskTCB;
//static  OS_TCB   LEDTaskTCB;

static OS_TCB TCB_system_maintain;
static OS_TCB TCB_deal_data;
static OS_TCB TCB_display;
static OS_TCB TCB_gsm;
static OS_TCB TCB_gather_dev_status;
static OS_TCB TCB_gather_water_level;
static OS_TCB TCB_control_motor;
static OS_TCB TCB_power_management;
static OS_TCB TCB_log_history;


static  CPU_STK  AppTaskStartStk[APP_TASK_START_STK_SIZE];			//任务堆栈
//static  CPU_STK  FlashDebugTaskStk[FLASH_DEBUG_TASK_STK_SIZE];
//static  CPU_STK  LEDTaskStk[LED_TASK_STK_SIZE];

static CPU_STK STK_system_maintain[STK_SYSTEM_MAINTAIN_SIZE];
static CPU_STK STK_deal_data[STK_DEAL_DATA_SIZE];
static CPU_STK STK_display[STK_DISPLAY_SIZE];
static CPU_STK STK_gsm[STK_GSM_SIZE];
static CPU_STK STK_gather_dev_status[STK_GATHER_DEV_STATUS_SIZE];
static CPU_STK STK_control_motor[STK_CONTROL_MOTOR_SIZE];
static CPU_STK STK_power_management[STK_POWER_MANAGEMENT_SIZE];
static CPU_STK STK_gather_water_level[STK_GATHER_WATER_LEVEL_SIZE];
static CPU_STK STK_log_history[STK_LOG_HISTORY_SIZE];



#define CREATE_APP_TASK(name,NAME)	OSTaskCreate((OS_TCB     *)&TCB_##name,			\
				(CPU_CHAR   *)"task_##name",					\
				(OS_TASK_PTR ) task_##name,					\
				(void       *) 0,						\
				(OS_PRIO     ) PRIO_##NAME,					\
				(CPU_STK    *)STK_##name,					\
				(CPU_STK_SIZE) STK_##NAME##_SIZE / 10,				\
				(CPU_STK_SIZE) STK_##NAME##_SIZE,				\
				(OS_MSG_QTY  ) 5u,						\
				(OS_TICK     ) 0u,						\
				(void       *) 0,						\
				(OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),	\
				(OS_ERR     *)&err);



int  main (void)
{
	OS_ERR  err;


	BSP_IntDisAll();
	OSInit(&err);								//初始化 uC/OS-III

	  /* 创建起始任务 */
	OSTaskCreate((OS_TCB     *)&AppTaskStartTCB,				//任务控制块地址
                 (CPU_CHAR   *)"App Task Start",				//任务名称
                 (OS_TASK_PTR ) AppTaskStart,					//任务函数
                 (void       *) 0,						//传递给任务函数（形参p_arg）的实参
                 (OS_PRIO     ) APP_TASK_START_PRIO,				//任务的优先级
                 (CPU_STK    *)&AppTaskStartStk[0],				//任务堆栈的基地址
                 (CPU_STK_SIZE) APP_TASK_START_STK_SIZE / 10,			//任务堆栈空间剩下1/10时限制其增长
                 (CPU_STK_SIZE) APP_TASK_START_STK_SIZE,			//任务堆栈空间（单位：sizeof(CPU_STK)）
                 (OS_MSG_QTY  ) 5u,						//任务可接收的最大消息数
                 (OS_TICK     ) 0u,						//任务的时间片节拍数（0表默认值OSCfg_TickRate_Hz/10）
                 (void       *) 0,						//任务扩展（0表不扩展）
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),	//任务选项
                 (OS_ERR     *)&err);						//返回错误类型

	OSStart(&err);
	
	while (DEF_ON) {                                            /* Should Never Get Here.                               */
	;
	}								//启动多任务管理（交由uC/OS-III控制）
}


/*
*********************************************************************************************************
*                                          STARTUP TASK
*
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Arguments   : p_arg   is the argument passed to 'AppTaskStart()' by 'OSTaskCreate()'.
*
* Returns     : none
*
* Notes       : 1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                  used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/

static  void  AppTaskStart (void *p_arg)
{
	CPU_INT32U  cpu_clk_freq;
	CPU_INT32U  cnts;
	OS_ERR      err;

	(void)p_arg;
	
	BSP_Init();					//板级初始化
	CPU_Init();
											//初始化 CPU 组件（时间戳、关中断时间测量和主机名）
	cpu_clk_freq = BSP_CPU_ClkFreq();					//获取 CPU 内核时钟频率（SysTick 工作时钟）
	cnts = cpu_clk_freq / (CPU_INT32U)OSCfg_TickRate_Hz;			//根据用户设定的时钟节拍频率计算 SysTick 定时器的计数值
	OS_CPU_SysTickInit(cnts);						//调用 SysTick 初始化函数，设置定时器计数值和启动定时器

	Mem_Init();								//初始化内存管理组件（堆内存池和内存池表）

#if OS_CFG_STAT_TASK_EN > 0u							//如果使能（默认使能）了统计任务
	OSStatTaskCPUUsageInit(&err);						//计算没有应用任务（只有空闲任务）运行时 CPU 的（最大）
#endif 										//容量（决定 OS_Stat_IdleCtrMax 的值，为后面计算 CPU 
										//使用率使用）。
#ifdef CPU_CFG_INT_DIS_MEAS_EN
	CPU_IntDisMeasMaxCurReset();						//复位（清零）当前最大关中断时间
#endif
                                      

//	OSTaskCreate((OS_TCB     *)&FlashDebugTaskTCB,				//任务控制块地址
//		 (CPU_CHAR   *)"Flash debug task",				//任务名称
//		 (OS_TASK_PTR ) FlashDebugTask,					//任务函数
//		 (void       *) 0,						//传递给任务函数（形参p_arg）的实参
//		 (OS_PRIO     ) FLASH_DEBUG_TASK_PRIO,				//任务的优先级
//		 (CPU_STK    *) FlashDebugTaskStk,				//任务堆栈的基地址
//		 (CPU_STK_SIZE) FLASH_DEBUG_TASK_STK_SIZE / 10,			//任务堆栈空间剩下1/10时限制其增长
//		 (CPU_STK_SIZE) FLASH_DEBUG_TASK_STK_SIZE,			//任务堆栈空间（单位：sizeof(CPU_STK)）
//		 (OS_MSG_QTY  ) 5u,						//任务可接收的最大消息数
//		 (OS_TICK     ) 0u,						//任务的时间片节拍数（0表默认值OSCfg_TickRate_Hz/10）
//		 (void       *) 0,						//任务扩展（0表不扩展）
//		 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),	//任务选项
//		 (OS_ERR     *)&err);						//返回错误类型
//		 
//	 OSTaskCreate((OS_TCB     *)&LEDTaskTCB,				//任务控制块地址
//		 (CPU_CHAR   *)"LED task",					//任务名称
//		 (OS_TASK_PTR ) LEDTask,					//任务函数
//		 (void       *) 0,						//传递给任务函数（形参p_arg）的实参
//		 (OS_PRIO     ) LED_TASK_PRIO,					//任务的优先级
//		 (CPU_STK    *)LEDTaskStk,					//任务堆栈的基地址
//		 (CPU_STK_SIZE) LED_TASK_STK_SIZE / 10,				//任务堆栈空间剩下1/10时限制其增长
//		 (CPU_STK_SIZE) LED_TASK_STK_SIZE,				//任务堆栈空间（单位：sizeof(CPU_STK)）
//		 (OS_MSG_QTY  ) 5u,						//任务可接收的最大消息数
//		 (OS_TICK     ) 0u,						//任务的时间片节拍数（0表默认值OSCfg_TickRate_Hz/10）
//		 (void       *) 0,						//任务扩展（0表不扩展）
//		 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),	//任务选项
//		 (OS_ERR     *)&err);						//返回错误类型	 

	CREATE_APP_TASK(system_maintain,SYSTEM_MAINTAIN)
	CREATE_APP_TASK(deal_data,DEAL_DATA)
	CREATE_APP_TASK(display,DISPLAY)
	CREATE_APP_TASK(gsm,GSM)
	CREATE_APP_TASK(gather_dev_status,GATHER_DEV_STATUS)
	CREATE_APP_TASK(control_motor,CONTROL_MOTOR)
	CREATE_APP_TASK(power_management,POWER_MANAGEMENT)
	CREATE_APP_TASK(gather_water_level,GATHER_WATER_LEVEL)
	CREATE_APP_TASK(log_history,LOG_HISTORY)
	app_init();
	
	while (1){    
		OSTimeDlyHMSM(0u, 0u, 0u, 2u,
				OS_OPT_TIME_HMSM_STRICT,
				&err);			 
	}
}

