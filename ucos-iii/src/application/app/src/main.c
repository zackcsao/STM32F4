/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	main.c
*      Abstract:	��Ҫ�����ļ�������
*
*      Filename:	main.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-20 15:38:17
*   Description:	�޸�˵��
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
/********************Ӳ�����ԣ���ʽ��ɾ��*************************/

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
static  void  AppTaskStart  (void *p_arg);					//����������

static  OS_TCB   AppTaskStartTCB;						//������ƿ�
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


static  CPU_STK  AppTaskStartStk[APP_TASK_START_STK_SIZE];			//�����ջ
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
	OSInit(&err);								//��ʼ�� uC/OS-III

	  /* ������ʼ���� */
	OSTaskCreate((OS_TCB     *)&AppTaskStartTCB,				//������ƿ��ַ
                 (CPU_CHAR   *)"App Task Start",				//��������
                 (OS_TASK_PTR ) AppTaskStart,					//������
                 (void       *) 0,						//���ݸ����������β�p_arg����ʵ��
                 (OS_PRIO     ) APP_TASK_START_PRIO,				//��������ȼ�
                 (CPU_STK    *)&AppTaskStartStk[0],				//�����ջ�Ļ���ַ
                 (CPU_STK_SIZE) APP_TASK_START_STK_SIZE / 10,			//�����ջ�ռ�ʣ��1/10ʱ����������
                 (CPU_STK_SIZE) APP_TASK_START_STK_SIZE,			//�����ջ�ռ䣨��λ��sizeof(CPU_STK)��
                 (OS_MSG_QTY  ) 5u,						//����ɽ��յ������Ϣ��
                 (OS_TICK     ) 0u,						//�����ʱ��Ƭ��������0��Ĭ��ֵOSCfg_TickRate_Hz/10��
                 (void       *) 0,						//������չ��0����չ��
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),	//����ѡ��
                 (OS_ERR     *)&err);						//���ش�������

	OSStart(&err);
	
	while (DEF_ON) {                                            /* Should Never Get Here.                               */
	;
	}								//�����������������uC/OS-III���ƣ�
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
	
	BSP_Init();					//�弶��ʼ��
	CPU_Init();
											//��ʼ�� CPU �����ʱ��������ж�ʱ���������������
	cpu_clk_freq = BSP_CPU_ClkFreq();					//��ȡ CPU �ں�ʱ��Ƶ�ʣ�SysTick ����ʱ�ӣ�
	cnts = cpu_clk_freq / (CPU_INT32U)OSCfg_TickRate_Hz;			//�����û��趨��ʱ�ӽ���Ƶ�ʼ��� SysTick ��ʱ���ļ���ֵ
	OS_CPU_SysTickInit(cnts);						//���� SysTick ��ʼ�����������ö�ʱ������ֵ��������ʱ��

	Mem_Init();								//��ʼ���ڴ������������ڴ�غ��ڴ�ر�

#if OS_CFG_STAT_TASK_EN > 0u							//���ʹ�ܣ�Ĭ��ʹ�ܣ���ͳ������
	OSStatTaskCPUUsageInit(&err);						//����û��Ӧ������ֻ�п�����������ʱ CPU �ģ����
#endif 										//���������� OS_Stat_IdleCtrMax ��ֵ��Ϊ������� CPU 
										//ʹ����ʹ�ã���
#ifdef CPU_CFG_INT_DIS_MEAS_EN
	CPU_IntDisMeasMaxCurReset();						//��λ�����㣩��ǰ�����ж�ʱ��
#endif
                                      

//	OSTaskCreate((OS_TCB     *)&FlashDebugTaskTCB,				//������ƿ��ַ
//		 (CPU_CHAR   *)"Flash debug task",				//��������
//		 (OS_TASK_PTR ) FlashDebugTask,					//������
//		 (void       *) 0,						//���ݸ����������β�p_arg����ʵ��
//		 (OS_PRIO     ) FLASH_DEBUG_TASK_PRIO,				//��������ȼ�
//		 (CPU_STK    *) FlashDebugTaskStk,				//�����ջ�Ļ���ַ
//		 (CPU_STK_SIZE) FLASH_DEBUG_TASK_STK_SIZE / 10,			//�����ջ�ռ�ʣ��1/10ʱ����������
//		 (CPU_STK_SIZE) FLASH_DEBUG_TASK_STK_SIZE,			//�����ջ�ռ䣨��λ��sizeof(CPU_STK)��
//		 (OS_MSG_QTY  ) 5u,						//����ɽ��յ������Ϣ��
//		 (OS_TICK     ) 0u,						//�����ʱ��Ƭ��������0��Ĭ��ֵOSCfg_TickRate_Hz/10��
//		 (void       *) 0,						//������չ��0����չ��
//		 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),	//����ѡ��
//		 (OS_ERR     *)&err);						//���ش�������
//		 
//	 OSTaskCreate((OS_TCB     *)&LEDTaskTCB,				//������ƿ��ַ
//		 (CPU_CHAR   *)"LED task",					//��������
//		 (OS_TASK_PTR ) LEDTask,					//������
//		 (void       *) 0,						//���ݸ����������β�p_arg����ʵ��
//		 (OS_PRIO     ) LED_TASK_PRIO,					//��������ȼ�
//		 (CPU_STK    *)LEDTaskStk,					//�����ջ�Ļ���ַ
//		 (CPU_STK_SIZE) LED_TASK_STK_SIZE / 10,				//�����ջ�ռ�ʣ��1/10ʱ����������
//		 (CPU_STK_SIZE) LED_TASK_STK_SIZE,				//�����ջ�ռ䣨��λ��sizeof(CPU_STK)��
//		 (OS_MSG_QTY  ) 5u,						//����ɽ��յ������Ϣ��
//		 (OS_TICK     ) 0u,						//�����ʱ��Ƭ��������0��Ĭ��ֵOSCfg_TickRate_Hz/10��
//		 (void       *) 0,						//������չ��0����չ��
//		 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),	//����ѡ��
//		 (OS_ERR     *)&err);						//���ش�������	 

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

