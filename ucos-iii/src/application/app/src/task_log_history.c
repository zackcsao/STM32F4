/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	task_log_history.c
*      Abstract:	��Ҫ�����ļ�������
*
*      Filename:	task_log_history.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-23 09:52:42
*   Description:	�޸�˵��
*
*
*********************************************************************/

#include "task_log_history.h"
#include "os.h"


void task_log_history(void)
{
	OS_ERR  err;
	
	while (1){    
		OSTimeDlyHMSM(0u, 0u, 1u, 0u,
				OS_OPT_TIME_HMSM_STRICT,
				&err);			 
	}
}

