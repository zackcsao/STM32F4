/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	task_deal_data.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	task_deal_data.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-22 16:57:37
*   Description:	修改说明
*
*
*********************************************************************/

#include "task_deal_data.h"
#include  <os.h>

void task_deal_data(void)
{
	OS_ERR  err;
	
	while (1){    
		OSTimeDlyHMSM(0u, 0u, 1u, 0u,
				OS_OPT_TIME_HMSM_STRICT,
				&err);			 
	}
}

