/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	task_power_management.c
*      Abstract:	��Ҫ�����ļ�������
*
*      Filename:	task_power_management.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-22 17:45:33
*   Description:	�޸�˵��
*
*
*********************************************************************/

#include "task_power_management.h"
#include  <os.h>

void task_power_management(void)
{
	OS_ERR  err;
	
	while (1){
		OSTimeDlyHMSM(0u, 0u, 1u, 0u,
				OS_OPT_TIME_HMSM_STRICT,
				&err);			 
	}
}


