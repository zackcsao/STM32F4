/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	task_gsm.c
*      Abstract:	��Ҫ�����ļ�������
*
*      Filename:	task_gsm.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-22 17:17:08
*   Description:	�޸�˵��
*
*
*********************************************************************/

#include "task_gsm.h"
#include  <os.h>

void task_gsm(void)
{
	OS_ERR  err;
	
	while (1){    
		OSTimeDlyHMSM(0u, 0u, 1u, 0u,
				OS_OPT_TIME_HMSM_STRICT,
				&err);			 
	}
}

