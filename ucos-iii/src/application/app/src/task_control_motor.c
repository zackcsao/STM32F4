/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	task_control_motor.c
*      Abstract:	��Ҫ�����ļ�������
*
*      Filename:	task_control_motor.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-22 17:43:29
*   Description:	�޸�˵��
*
*
*********************************************************************/

#include "task_control_motor.h"
#include  <os.h>

void task_control_motor(void)
{
	OS_ERR  err;
	
	while (1){    
		OSTimeDlyHMSM(0u, 0u, 1u, 0u,
				OS_OPT_TIME_HMSM_STRICT,
				&err);			 
	}
}

