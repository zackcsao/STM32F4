/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	task_gather_water_level.c
*      Abstract:	��Ҫ�����ļ�������
*
*      Filename:	task_gather_water_level.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-22 17:40:56
*   Description:	�޸�˵��
*
*
*********************************************************************/

#include "task_gather_water_level.h"
#include  <os.h>

void task_gather_water_level(void)
{
	OS_ERR  err;
	
	while (1){    
		OSTimeDlyHMSM(0u, 0u, 1u, 0u,
				OS_OPT_TIME_HMSM_STRICT,
				&err);			 
	}
}

