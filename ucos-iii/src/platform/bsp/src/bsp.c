/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	bsp.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	bsp.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-06 09:57:52
*   Description:	修改说明
*
*
*********************************************************************/

#define   BSP_MODULE
#include "bsp.h"
#include "errno-base.h"
#include "driver.h"
#include "system_clock.h"
//#if defined(DEBUG_PRINTF)
#include <stdio.h>
//#endif
#include <string.h>
#include  <os.h>	
#include "os_type.h"
#include "os_cfg_app.h"
#include  <os_app_hooks.h>
#include "stm32f4xx_hal.h"



uint8_t buf_com7[128];
uint8_t buf_com3[128];

#define FRAM_SPI_PORT		E_SPI4

uart_dev_t print_uart = {.port = E_COM7,
		.config = {
			.baud_rate= 115200,
			.data_width = DATA_WIDTH_8BIT,
			.parity = NO_PARITY,
			.stop_bits = STOP_BITS_1,
			.flow_control = FLOW_CONTROL_DISABLED,
			.mode = MODE_TX_RX,
			.buf = buf_com7,
			.buf_size = 128},
			.priv = NULL};

uart_dev_t uart_4g = {.port = E_COM3,
		.config = {
			.baud_rate= 115200,
			.data_width = DATA_WIDTH_8BIT,
			.parity = NO_PARITY,
			.stop_bits = STOP_BITS_1,
			.flow_control = FLOW_CONTROL_DISABLED,
			.mode = MODE_TX_RX,
			.buf = buf_com3,
			.buf_size = 128},
			.priv = NULL};	
		
wdg_dev_t wdg = {
		.port = 0,
		.config = {.timeout = 3000},
		.priv = NULL};

		
		
 rtc_dev_t rtc_8025t = {
		.port = 0,
		.config = {1900},
		.priv = NULL};
		
i2c_dev_t rtc_i2c = {
		.port = 0,
		.config = {
			.dev_addr = 0x32,
			.mode = SIMULATION_I2C},
		.priv = NULL};
		
i2c_gpio_t i2c_gpio = {
		.scl = {
			.port = GPIO_I2C1_SCL,
			.config = OUTPUT_OPEN_DRAIN_NO_PULL,
			.priv = NULL},
		.sda = {
			.port = GPIO_I2C1_SDA,
			.config = OUTPUT_OPEN_DRAIN_NO_PULL,
			.priv = NULL}};



spi_dev_t fram_spi = {
		.port = FRAM_SPI_PORT,
		.config = {.type = E_SPI_MODE_MASTER,
			.freq = E_SPI_BAUD_1_256_FPCLK,
			.mode = MODE3,
			.bit_order = E_SPI_MSB_FIRST,
			.cs_type = E_SPI_NSS_SOFT,
			.transfer_mode = E_SPI_FULL_DUPLEX,
			.data_length = E_SPI_DATAWIDTH_8BIT},
		.priv = NULL};
		
gpio_dev_t gpio_fram_cs = {
		.port = GPIO_FRAM_CS,
		.config = OUTPUT_OPEN_DRAIN_NO_PULL,
		.priv = NULL};

gpio_dev_t gpio_fram_wp = {
		.port = GPIO_FRAM_WP,
		.config = OUTPUT_PUSH_PULL,
		.priv = NULL};	

gpio_dev_t gpio_flash_cs = {
		.port = GPIO_FLASH_CS,
		.config = OUTPUT_OPEN_DRAIN_NO_PULL,
		.priv = NULL};
gpio_dev_t gpio_flash_wp = {
		.port = GPIO_FLASH_WP,
		.config = OUTPUT_OPEN_DRAIN_NO_PULL,
		.priv = NULL};
spi_dev_t flash_spi = {
		.port = E_SPI5,
		.config = {.type = E_SPI_MODE_MASTER,
			.freq = E_SPI_BAUD_1_256_FPCLK,
			.mode = MODE3,
			.bit_order = E_SPI_MSB_FIRST,
			.cs_type = E_SPI_NSS_SOFT,
			.transfer_mode = E_SPI_FULL_DUPLEX,
			.data_length = E_SPI_DATAWIDTH_8BIT},
		.priv = NULL};
			
static void irq_sec(void);	
timer_dev_t tim2 = {
	.port = E_TIMER2,
	.config = {.period = 1000},
	.priv = irq_sec
	};
gpio_dev_t gpio_run = {.port = GPIO_RUN_LED,
			.config = OUTPUT_OPEN_DRAIN_NO_PULL,
			.priv = NULL};

int32_t uart_gpio_init(uint32_t num);
int32_t spi_gpio_init(uint8_t port);

//static struct tm _can_soft;
static uint32_t _sec = 0;
	
static uint32_t get_sec(void);
static uint32_t get_msec(void);
static void feed_wdg(void);
			
static int32_t fram_gpio_init(void);
void eth_gpio_init(void);
	
const SYS_FUNC sys_func = {
	get_sec,
	get_msec,
	NULL,
	NULL,
	feed_wdg,
	NULL
	};

int32_t rtc_i2c_init(void);		
void rtc_int_func(void)
{
	_sec++;
//	printf("hello int!\r\n");
}
static uint32_t get_sec(void)
{
	return _sec;
}	
	
static void irq_sec(void)
{
	_sec++;
}

void bsp_init(void)
{	
	system_clock_init();
	system_tick_init();
	
	uart_gpio_init(print_uart.port);
	uart_init(&print_uart);
	uart_gpio_init(uart_4g.port);
	uart_init(&uart_4g);
	
	gpio_init(&gpio_run);


//	timer_init(&tim2);
	
	rtc_i2c_init();
	eth_gpio_init();
}

static void feed_wdg(void)
{
	wdg_reload(&wdg);
}
int32_t rtc_i2c_init(void)
{
	int32_t ret = -EPERM;
	uint8_t tmp = IRQ_TRIGGER_FALLING_EDGE;
//	uint8_t buf_temp;
	uint8_t tmp8 = 0;
	gpio_dev_t gpio_rtc_int;
	
//	struct tm time = {.tm_year = 119,.tm_mon = 7,.tm_mday = 31,.tm_hour = 22,.tm_min=15};


	rtc_8025t.priv = &rtc_i2c;
	rtc_i2c.priv = &i2c_gpio;

	i2c_init(&rtc_i2c);
	rtc_init(&rtc_8025t);
//	rtc_set_time(&rtc_8025t,&time);

	//利用rtc中断产生秒时钟
	gpio_rtc_int.port = GPIO_RTC_INT;
	gpio_rtc_int.config = IRQ_MODE;
	gpio_rtc_int.priv = &tmp;

	gpio_enable_irq(&gpio_rtc_int, IRQ_TRIGGER_FALLING_EDGE, rtc_int_func);
	
	gpio_init(&gpio_rtc_int);
	spi_gpio_init(flash_spi.port);
	spi_init(&flash_spi);
	tmp8 = 1;
	gpio_flash_wp.priv = &tmp8;
	gpio_init(&gpio_flash_wp);
	
	spi_gpio_init(fram_spi.port);
	spi_init(&fram_spi);
	fram_gpio_init();
	ret = 0;
	
	return ret;
}

int32_t uart_gpio_init(uint32_t num)
{	
	int32_t ret = -EPERM;
	gpio_dev_t gpio_uart;
	uint8_t alternate = APP_AF_0;
	
	switch(num){
	
	case E_COM1:
		gpio_uart.port = GPIO_UART1_TX;
		gpio_uart.config = ALTERNATE_MODE;
		alternate = GPIO_UART1_TX_AF;
		gpio_uart.priv = &alternate;
		gpio_init(&gpio_uart);
		
		gpio_uart.port = GPIO_UART1_RX;
		gpio_uart.config = ALTERNATE_MODE;
		alternate = GPIO_UART1_RX_AF;
		gpio_uart.priv = &alternate;
		gpio_init(&gpio_uart);
		break;

	case E_COM2:
		gpio_uart.port = GPIO_UART2_TX;
		gpio_uart.config = ALTERNATE_MODE;
		alternate = GPIO_UART2_TX_AF;
		gpio_uart.priv = &alternate;
		gpio_init(&gpio_uart);
		
		gpio_uart.port = GPIO_UART2_RX;
		gpio_uart.config = ALTERNATE_MODE;
		alternate = GPIO_UART2_RX_AF;
		gpio_uart.priv = &alternate;
		gpio_init(&gpio_uart);
		break;
		
	case E_COM3:
		gpio_uart.port = GPIO_UART3_TX;
		gpio_uart.config = ALTERNATE_MODE;
		alternate = GPIO_UART3_TX_AF;
		gpio_uart.priv = &alternate;
		gpio_init(&gpio_uart);
		
		gpio_uart.port = GPIO_UART3_RX;
		gpio_uart.config = ALTERNATE_MODE;
		alternate = GPIO_UART3_RX_AF;
		gpio_uart.priv = &alternate;
		gpio_init(&gpio_uart);
		break;
		
	case E_COM4:
		gpio_uart.port = GPIO_UART4_TX;
		gpio_uart.config = ALTERNATE_MODE;
		alternate = GPIO_UART4_TX_AF;
		gpio_uart.priv = &alternate;
		gpio_init(&gpio_uart);
		
		gpio_uart.port = GPIO_UART4_RX;
		gpio_uart.config = ALTERNATE_MODE;
		alternate = GPIO_UART4_RX_AF;
		gpio_uart.priv = &alternate;
		gpio_init(&gpio_uart);
		break;
		
	case E_COM5:
		gpio_uart.port = GPIO_UART5_TX;
		gpio_uart.config = ALTERNATE_MODE;
		alternate = GPIO_UART5_TX_AF;
		gpio_uart.priv = &alternate;
		gpio_init(&gpio_uart);
		
		gpio_uart.port = GPIO_UART5_RX;
		gpio_uart.config = ALTERNATE_MODE;
		alternate = GPIO_UART5_RX_AF;
		gpio_uart.priv = &alternate;
		gpio_init(&gpio_uart);
		break;
		
	case E_COM6:
		gpio_uart.port = GPIO_UART6_TX;
		gpio_uart.config = ALTERNATE_MODE;
		alternate = GPIO_UART6_TX_AF;
		gpio_uart.priv = &alternate;
		gpio_init(&gpio_uart);
		
		gpio_uart.port = GPIO_UART6_RX;
		gpio_uart.config = ALTERNATE_MODE;
		alternate = GPIO_UART6_RX_AF;
		gpio_uart.priv = &alternate;
		gpio_init(&gpio_uart);
		break;
		
	case E_COM7:
		gpio_uart.port = GPIO_UART7_TX;
		gpio_uart.config = ALTERNATE_MODE;
		alternate = GPIO_UART7_TX_AF;
		gpio_uart.priv = &alternate;
		gpio_init(&gpio_uart);
		
		gpio_uart.port = GPIO_UART7_RX;
		gpio_uart.config = ALTERNATE_MODE;
		alternate = GPIO_UART7_RX_AF;
		gpio_uart.priv = &alternate;
		gpio_init(&gpio_uart);
		break;
	
	default:
		return ret;
	}
	
	ret = 0;
	
	return ret;
}


int32_t spi_gpio_init(uint8_t port)
{
	
	int32_t ret = -EPERM;
	gpio_dev_t gpio_spi;
	uint8_t alternate = APP_AF_0;

	switch(port){
	case E_SPI1:
		gpio_spi.port = GPIO_SPI1_SCK;
		gpio_spi.config = ALTERNATE_MODE;
		alternate = GPIO_SPI1_SCK_AF;
		gpio_spi.priv = &alternate;
		gpio_init(&gpio_spi);

		gpio_spi.port = GPIO_SPI1_MISO;
		gpio_spi.config = ALTERNATE_MODE;
		alternate = GPIO_SPI1_MISO_AF;
		gpio_spi.priv = &alternate;
		gpio_init(&gpio_spi);
		
		gpio_spi.port = GPIO_SPI1_MOSI;
		gpio_spi.config = ALTERNATE_MODE;
		alternate = GPIO_SPI1_MOSI_AF;
		gpio_spi.priv = &alternate;
		gpio_init(&gpio_spi);
		break;
		
	case E_SPI2:
		gpio_spi.port = GPIO_SPI2_SCK;
		gpio_spi.config = ALTERNATE_MODE;
		alternate = GPIO_SPI2_SCK_AF;
		gpio_spi.priv = &alternate;
		gpio_init(&gpio_spi);
		
		gpio_spi.port = GPIO_SPI2_MISO;
		gpio_spi.config = ALTERNATE_MODE;
		alternate = GPIO_SPI2_MISO_AF;
		gpio_spi.priv = &alternate;
		gpio_init(&gpio_spi);
		
		gpio_spi.port = GPIO_SPI2_MOSI;
		gpio_spi.config = ALTERNATE_MODE;
		alternate = GPIO_SPI2_MOSI_AF;
		gpio_spi.priv = &alternate;
		gpio_init(&gpio_spi);
		break;
		
	case E_SPI3:
		gpio_spi.port = GPIO_SPI3_SCK;
		gpio_spi.config = ALTERNATE_MODE;
		alternate = GPIO_SPI3_SCK_AF;
		gpio_spi.priv = &alternate;
		gpio_init(&gpio_spi);

		gpio_spi.port = GPIO_SPI3_MISO;
		gpio_spi.config = ALTERNATE_MODE;
		alternate = GPIO_SPI3_MISO_AF;
		gpio_spi.priv = &alternate;
		gpio_init(&gpio_spi);
		
		gpio_spi.port = GPIO_SPI3_MOSI;
		gpio_spi.config = ALTERNATE_MODE;
		alternate = GPIO_SPI3_MOSI_AF;
		gpio_spi.priv = &alternate;
		gpio_init(&gpio_spi);
		break;
		
	case E_SPI4:
		gpio_spi.port = GPIO_SPI4_SCK;
		gpio_spi.config = ALTERNATE_MODE;
		alternate = GPIO_SPI4_SCK_AF;
		gpio_spi.priv = &alternate;
		gpio_init(&gpio_spi);

		gpio_spi.port = GPIO_SPI4_MISO;
		gpio_spi.config = ALTERNATE_MODE;
		alternate = GPIO_SPI4_MISO_AF;
		gpio_spi.priv = &alternate;
		gpio_init(&gpio_spi);
		
		gpio_spi.port = GPIO_SPI4_MOSI;
		gpio_spi.config = ALTERNATE_MODE;
		alternate = GPIO_SPI4_MOSI_AF;
		gpio_spi.priv = &alternate;
		gpio_init(&gpio_spi);
		break;
		
	case E_SPI5:
		gpio_spi.port = GPIO_SPI5_SCK;
		gpio_spi.config = ALTERNATE_MODE;
		alternate = GPIO_SPI5_SCK_AF;
		gpio_spi.priv = &alternate;
		gpio_init(&gpio_spi);

		gpio_spi.port = GPIO_SPI5_MISO;
		gpio_spi.config = ALTERNATE_MODE;
		alternate = GPIO_SPI5_MISO_AF;
		gpio_spi.priv = &alternate;
		gpio_init(&gpio_spi);
		
		gpio_spi.port = GPIO_SPI5_MOSI;
		gpio_spi.config = ALTERNATE_MODE;
		alternate = GPIO_SPI5_MOSI_AF;
		gpio_spi.priv = &alternate;
		gpio_init(&gpio_spi);
		break;

//	case E_SPI6:
//		gpio_spi.port = GPIO_SPI6_SCK;
//		gpio_spi.config = ALTERNATE_MODE;
//		alternate = GPIO_SPI6_SCK_AF;
//		gpio_spi.priv = &alternate;
//		gpio_init(&gpio_spi);
//		
//		gpio_spi.port = GPIO_SPI6_MISO;
//		gpio_spi.config = ALTERNATE_MODE;
//		alternate = GPIO_SPI6_MISO_AF;
//		gpio_spi.priv = &alternate;
//		gpio_init(&gpio_spi);
//		
//		gpio_spi.port = GPIO_SPI6_MOSI;
//		gpio_spi.config = ALTERNATE_MODE;
//		alternate = GPIO_SPI6_MOSI_AF;
//		gpio_spi.priv = &alternate;
//		gpio_init(&gpio_spi);
//		break;

	default:
		break;
	}

	return ret;
}


static int32_t fram_gpio_init(void)
{
	uint8_t tmp8 = 1;
	gpio_fram_cs.priv = &tmp8;
	
	gpio_init(&gpio_fram_cs);
	
	tmp8 = 0;
	gpio_fram_wp.priv = &tmp8;
	gpio_init(&gpio_fram_wp);
	
	return 0;
}

int32_t fram_enable(uint8_t status)
{
	if(status == 0){
		gpio_output_low(&gpio_fram_cs);
	}else {
		gpio_output_high(&gpio_fram_cs);
	}
	
	return 0;
}

void flash_gpio_cs(uint32_t status)
{
	if(status == 0){
		gpio_output_low(&gpio_flash_cs);
	}else{
		gpio_output_high(&gpio_flash_cs);
	}
}
void flash_init(void)
{

}

void eth_gpio_init(void)
{
	uint32_t tmp = GPIO_ETH_RMII_RXD0_AF;
	gpio_dev_t eth_gpio ={
		.port = GPIO_ETH_RMII_RXD0,
		.config = ALTERNATE_MODE,
		.priv = &tmp};
	
	gpio_init(&eth_gpio);
		
	eth_gpio.port = GPIO_ETH_RMII_RXD1;
	gpio_init(&eth_gpio);
		
	eth_gpio.port = GPIO_ETH_RMII_TXD0;
	gpio_init(&eth_gpio);

	eth_gpio.port = GPIO_ETH_RMII_TXD1;
	gpio_init(&eth_gpio);

	eth_gpio.port = GPIO_ETH_RMII_TX_EN;
	gpio_init(&eth_gpio);

	eth_gpio.port = GPIO_ETH_RMII_CRS_DV;
	gpio_init(&eth_gpio);

	eth_gpio.port = GPIO_ETH_RMII_REF_CLK;
	gpio_init(&eth_gpio);

	eth_gpio.port = GPIO_ETH_MDC;
	gpio_init(&eth_gpio);

	eth_gpio.port = GPIO_ETH_MDIO;
	gpio_init(&eth_gpio);
}

uint32_t get_msec(void)
{
	OS_ERR err;
	uint32_t ms = 0;
	ms = OSTimeGet(&err);
	return ms;
}



#if defined(DEBUG_PRINTF)
struct __FILE { int handle; /* Add whatever you need here */ };
FILE __stdout;
FILE __stdin;

int fputc(int ch, FILE *f)
{
	uint8_t buf[2];
	
	buf[0] = (uint8_t)ch;
	uart_send(&print_uart,buf,1);
	
	return(ch);
}
#endif

/*
*********************************************************************************************************
*                                            BSP_CPU_ClkFreq()
*
* Description : Read CPU registers to determine the CPU clock frequency of the chip.
*
* Argument(s) : none.
*
* Return(s)   : The CPU clock frequency, in Hz.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

CPU_INT32U  BSP_CPU_ClkFreq (void)
{
 
    return 168000000;
}




/*
*********************************************************************************************************
*                                            BSP_Tick_Init()
*
* Description : Initialize all the peripherals that required OS Tick services (OS initialized)
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/
void BSP_Tick_Init (void)
{
    CPU_INT32U  cpu_clk_freq;
    CPU_INT32U  cnts;

    cpu_clk_freq = BSP_CPU_ClkFreq();                           /* Determine SysTick reference freq.                    */

#if (OS_VERSION >= 30000u)
    cnts  = cpu_clk_freq / (CPU_INT32U)OSCfg_TickRate_Hz;       /* Determine nbr SysTick increments.                    */
#else
    cnts  = cpu_clk_freq / (CPU_INT32U)OS_TICKS_PER_SEC;        /* Determine nbr SysTick increments.                    */
#endif

    OS_CPU_SysTickInit(cnts);                                   /* Init uC/OS periodic time src (SysTick).              */
//	SysTick_Config(cnts);   //这里默认的是最低优先级
}

/*
*********************************************************************************************************
*	函 数 名: bsp_DelayUS
*	功能说明: 这里的延时采用CPU的内部计数实现，32位计数器
*             	OSSchedLock(&err);
*				bsp_DelayUS(5);
*				OSSchedUnlock(&err); 根据实际情况看看是否需要加调度锁或选择关中断
*	形    参：n : 延迟长度，单位1 us
*	返 回 值: 无
*********************************************************************************************************
*/
void bsp_DelayUS(uint32_t _ulDelayTime)
{
	uint32_t ticks;
	uint32_t told,tnow,tcnt=0;
		    	 
	ticks = _ulDelayTime * (168000000 / 1000000);	 /* 需要的节拍数 */ 		 
	tcnt = 0;
	told = (uint32_t)CPU_TS_TmrRd();         /* 刚进入时的计数器值 */

	while(1){
		tnow = (uint32_t)CPU_TS_TmrRd();	
		if(tnow != told){	
			/* 32位计数器是递增计数器 */    
			if(tnow > told){
				tcnt += tnow - told;	
			}else{//* 重新装载 */
				tcnt += UINT32_MAX - told + tnow;	
			}	
			
			told = tnow;

			/*时间超过/等于要延迟的时间,则退出 */
			if(tcnt >= ticks)break;
		}  
	}
}


