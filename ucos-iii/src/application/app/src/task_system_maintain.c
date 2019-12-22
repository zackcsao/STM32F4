/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	task_system_maintain.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	task_system_maintain.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-22 16:54:02
*   Description:	修改说明
*
*
*********************************************************************/

#include "task_system_maintain.h"
#include  <os.h>
#include "bsp.h"
#include <stdio.h>

#include "driver.h"


extern const SYS_FUNC sys_func;
//static struct tm _can_soft;
extern gpio_dev_t gpio_run;
extern rtc_dev_t rtc_8025t;
void  task_system_maintain(void)
{
	OS_ERR  err;
	static uint32_t _sec_maintian = 0;
	struct tm _can_soft;
	
	while (1){    
		rtc_get_time(&rtc_8025t,&_can_soft);
		sys_func.feed_wdg();
		_sec_maintian++;
		
		if(_sec_maintian%2){
			gpio_output_high(&gpio_run);
		}else{
			gpio_output_low(&gpio_run);
		}
			
		printf("%02u\t%02u\t%02u\t%02u:%02u:%02u\t%u\r\n",
			1900 + _can_soft.tm_year,_can_soft.tm_mon+1,_can_soft.tm_mday,_can_soft.tm_hour,_can_soft.tm_min,_can_soft.tm_sec,sys_func.sys_get_sec());
//		
//		printf("_FUNC_TION=%s\r\n",__FUNCTION__);
		OSTimeDlyHMSM(0u, 0u, 1u, 0u,
				OS_OPT_TIME_HMSM_STRICT,
				&err);			 
	}
}


