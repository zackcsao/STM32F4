/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	task_test.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	task_test.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-06 13:10:55
*   Description:	修改说明
*
*
*********************************************************************/

#include "task_test.h"
#include  <os.h>
#include "bsp.h"
#include <stdio.h>
#include <string.h>

#include "driver.h"

#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_bus.h"
#include "lwip.h"

extern const SYS_FUNC sys_func;

gpio_dev_t led_b_run = {.port = GPIO_B_RUN_LED,
			.config = OUTPUT_PUSH_PULL,
			.priv = NULL};

gpio_dev_t led_alarm = {.port = GPIO_ALARM_LED,
			.config = OUTPUT_PUSH_PULL,
			.priv = NULL};

gpio_dev_t led_wifi = {.port = GPIO_WIFI_LED,
			.config = OUTPUT_PUSH_PULL,
			.priv = NULL};

gpio_dev_t gpio_4g_power = {.port = GPIO_4G_PWR_EN,
			.config = OUTPUT_PUSH_PULL,
			.priv = NULL};

gpio_dev_t gpio_4g_sw = {.port = GPIO_4G_PWR,
			.config = OUTPUT_PUSH_PULL,
			.priv = NULL};

gpio_dev_t gpio_do1 = {.port = GPIO_DO_1,
			.config = OUTPUT_PUSH_PULL,
			.priv = NULL};

gpio_dev_t gpio_do2 = {.port = GPIO_DO_2,
			.config = OUTPUT_PUSH_PULL,
			.priv = NULL};

gpio_dev_t gpio_do3 = {.port = GPIO_DO_3,
			.config = OUTPUT_PUSH_PULL,
			.priv = NULL};

gpio_dev_t gpio_do4 = {.port = GPIO_DO_4,
			.config = OUTPUT_PUSH_PULL,
			.priv = NULL};

gpio_dev_t gpio_do5 = {.port = GPIO_DO_5,
			.config = OUTPUT_PUSH_PULL,
			.priv = NULL};

gpio_dev_t gpio_do6 = {.port = GPIO_DO_6,
			.config = OUTPUT_PUSH_PULL,
			.priv = NULL};

gpio_dev_t gpio_do7 = {.port = GPIO_DO_7,
			.config = OUTPUT_PUSH_PULL,
			.priv = NULL};

			
			
extern uart_dev_t uart_4g;
			
void gsm_power_on_off(uint32_t sec);
void do_test(uint32_t sec);

static void MX_GPIO_Init(void)
{
  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOH);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOI);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOG);

  /**/
  LL_GPIO_SetOutputPin(GPIOI, LL_GPIO_PIN_1);

  /**/
  GPIO_InitStruct.Pin = LL_GPIO_PIN_1;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  LL_GPIO_Init(GPIOI, &GPIO_InitStruct);

}			
			
void task_test(void)
{
//	OS_ERR  err;
	static uint32_t _sec_maintian = 0;
//	struct tm _can_soft;
	uint8_t buf[128];
	uint32_t len = 0;
	uint32_t i = 0;
//以下三行初始化的LED灯的引脚
//	gpio_init(&led_b_run);
//	gpio_init(&led_alarm);
//	gpio_init(&led_wifi);
////以下两行初始化4G模块的电源开关和开机引脚	
//	gpio_init(&gpio_4g_power);
//	gpio_init(&gpio_4g_sw);
////以下7行初始化继电器的引脚输出
//	gpio_init(&gpio_do1);
//	gpio_init(&gpio_do2);
//	gpio_init(&gpio_do3);
//	gpio_init(&gpio_do4);
//	gpio_init(&gpio_do5);
//	gpio_init(&gpio_do6);
//	gpio_init(&gpio_do7);
//	
	MX_GPIO_Init();
	MX_LWIP_Init();
	tcp_echoserver_init();
	
	while (1){    
		sys_func.feed_wdg();
		MX_LWIP_Process();
		if(_sec_maintian != sys_func.sys_get_sec()){
			_sec_maintian = sys_func.sys_get_sec();
			//周期性显示LED的开关
			if(_sec_maintian%2){
				gpio_output_low(&led_alarm);
				gpio_output_low(&led_b_run);
				gpio_output_low(&led_wifi);
				gpio_output_high(&gpio_4g_power);
			}else{
				gpio_output_high(&led_alarm);
				gpio_output_high(&led_b_run);
				gpio_output_high(&led_wifi);
			}
			//4G模块开机
			gsm_power_on_off(_sec_maintian);
			//继电器依次打开，然后依次关闭
			do_test(_sec_maintian);
		
		}
		//打印4G模块的开机信息
		len = get_recv_size(&uart_4g);
		if(len > 0 ){
			memset(buf,0,128);
			uart_recv(&uart_4g,buf,len);
			printf("len=%d\r\n",len);
			for(i = 0;i < len;i++){
				printf("%c",buf[i]);
			}
			
		}
			

//		printf("_FUNC_TION=%s\r\n",__FUNCTION__);
//		OSTimeDlyHMSM(0u, 0u, 1u, 0u,
//				OS_OPT_TIME_HMSM_STRICT,
//				&err);			 
	}
}

void gsm_power_on_off(uint32_t sec)
{
	static uint32_t _sec_tmp = 0;
	static uint32_t _status = 0;
//	uint16_t tmp = 0;

//	tmp = sec;
	if(_sec_tmp != sec){
		if(((sec - _sec_tmp) >= 2) && (_status != 3)){
			_status++;
			_sec_tmp = sec;
		}
		//printf("%d,%d....................\r\n",sec,_power_status);
		switch(_status) {
		case 0:
			gpio_output_low(&gpio_4g_sw);
			break;

		case 1:
			gpio_output_high(&gpio_4g_sw);
			break;

		case 2:
			gpio_output_low(&gpio_4g_sw);
			printf("poweron  end \r\n");
			_status++;
			break;

		case 3:
	//		printf("AT\r\n");
	//		uart_send(&uart_4g,(uint8_t *)"ATE0\r",3);
			break;

		default:
			break;

		}
	}
}


void do_test(uint32_t sec)
{
	static uint32_t _sec_tmp = 0;
	static uint32_t _status = 0;
//	uint16_t tmp = 0;

//	tmp = sec;
	if(_sec_tmp != sec){
		if((sec - _sec_tmp) >= (5)){
			_status++;
			_sec_tmp = sec;
		}
		//printf("%d,%d....................\r\n",sec,_power_status);
		switch(_status) {
		case 0:
			gpio_output_high(&gpio_do1);
			break;

		case 1:
			gpio_output_high(&gpio_do2);
			break;

		case 2:
			gpio_output_high(&gpio_do3);
			break;

		case 3:
			gpio_output_high(&gpio_do4);
			break;

		case 4:
			gpio_output_high(&gpio_do5);
			break;

		case 5:
			gpio_output_high(&gpio_do6);
			break;

		case 6:
			gpio_output_high(&gpio_do7);
			break;

		case 7:
			
			gpio_output_low(&gpio_do1);
			break;

		case 8:
			gpio_output_low(&gpio_do2);
			break;

		case 9:
			gpio_output_low(&gpio_do3);
			break;

		case 10:
			gpio_output_low(&gpio_do4);
			break;

		case 11:
			gpio_output_low(&gpio_do5);
			break;

		case 12:
			gpio_output_low(&gpio_do6);
			break;

		case 13:
			gpio_output_low(&gpio_do7);
			break;

		default:
			break;

		}
	}
}
