/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	gpio_define.h
*      Abstract:	简要描述文件的内容
*
*      Filename:	gpio_define.h
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2019-03-14 14:50:47
*   Description:	修改说明
*
*
*********************************************************************/

#ifndef __GPIO_DEFINE_H__
#define __GPIO_DEFINE_H__
// <<< Use Configuration Wizard in Context Menu >>>
// <e1> 串口配置


// <h> UART1_TX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART1_TX		9
#define GPIO_UART1_TX_AF	7

// <h> UART1_RX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART1_RX		23
#define GPIO_UART1_RX_AF	7

// <h> UART2_TX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART2_TX		53
#define GPIO_UART2_TX_AF	7

// <h> UART2_RX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART2_RX		54
#define GPIO_UART2_RX_AF	7

// <h> UART3_TX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART3_TX		26
#define GPIO_UART3_TX_AF	7

// <h> UART3_RX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART3_RX		27
#define GPIO_UART3_RX_AF	7


// <h> UART4_TX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART4_TX		42
#define GPIO_UART4_TX_AF	8

// <h> UART4_RX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART4_RX		43
#define GPIO_UART4_RX_AF	8


// <h> UART5_TX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART5_TX		44
#define GPIO_UART5_TX_AF	8

// <h> UART5_RX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART5_RX		50
#define GPIO_UART5_RX_AF	8


// <h> UART6_TX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART6_TX		38
#define GPIO_UART6_TX_AF	8

// <h> UART6_RX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART6_RX		105
#define GPIO_UART6_RX_AF	8


// <h> UART7_TX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART7_TX		72
#define GPIO_UART7_TX_AF	8

// <h> UART7_RX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART7_RX		71
#define GPIO_UART7_RX_AF	8

// <h> UART8_RX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART8_RX		64
#define GPIO_UART8_RX_AF	8

// <h> UART8_TX
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_UART8_TX		65
#define GPIO_UART8_TX_AF	8
// </e>

// <e2> SPI配置
// <h> SPI1_MOSI
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI1_MOSI		105
#define GPIO_SPI1_MOSI_AF	8


// <h> SPI1_MISO
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI1_MISO		1
#define GPIO_SPI1_MISO_AF	8

// <h> SPI1_SCK
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI1_SCK		86
#define GPIO_SPI1_SCK_AF	8


// <h> SPI2_MOSI
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI2_MOSI		105
#define GPIO_SPI2_MOSI_AF	8


// <h> SPI2_MISO
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI2_MISO		87
#define GPIO_SPI2_MISO_AF	8

// <h> SPI2_SCK
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI2_SCK		86
#define GPIO_SPI2_SCK_AF	8


// <h> SPI3_MOSI
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI3_MOSI		105
#define GPIO_SPI3_MOSI_AF	8


// <h> SPI3_MISO
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI3_MISO		87
#define GPIO_SPI3_MISO_AF	8

// <h> SPI3_SCK
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI3_SCK		86
#define GPIO_SPI3_SCK_AF	8


// <h> SPI4_MOSI
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI4_MOSI		70
#define GPIO_SPI4_MOSI_AF	5


// <h> SPI4_MISO
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI4_MISO		69
#define GPIO_SPI4_MISO_AF	5

// <h> SPI4_SCK
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI4_SCK		66
#define GPIO_SPI4_SCK_AF	5


// <h> SPI5_MOSI
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI5_MOSI		89
#define GPIO_SPI5_MOSI_AF	5


// <h> SPI5_MISO
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI5_MISO		88
#define GPIO_SPI5_MISO_AF	5

// <h> SPI5_SCK
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_SPI5_SCK		118
#define GPIO_SPI5_SCK_AF	5
// </e>

// <e1> gpio配置

// <h> FRAM_CS
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_FRAM_CS		68

// <h> FRAM_WP
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_FRAM_WP		67

// <h> FLASH_CS
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_FLASH_CS		117


// <h> FLASH_WP
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_FLASH_WP		116
// <h> 第一路485收发使能
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_485_1		40
// <h> 第二路485收发使能
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_485_2		136

// <h> 运行灯
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_RUN_LED		60

// <h> 报警灯
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_ALARM_LED		128

// <h> 载板运行灯
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_B_RUN_LED		130

// <h> wifi灯
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_WIFI_LED		55

// <h> wifi_reload
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_WIFI_RELOAD		125

// <h> wifi_reset
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_WIFI_RESET		52

// <h> wifi_link
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_WIFI_LINK		138

// <h> 4G开机引脚
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_4G_PWR		10

// <h> 4G电源开关
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_4G_PWR_EN		74

// <h> 4G的复位
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_4G_RESET		78

// <h> 交流电检测
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_AC_DECTECT		39

// <h> 24V电源开关
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_24V_EN		108

// <h> WIFI电源开关
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_WIFI_EN		103

// <h> DO_1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DO_1		4

// <h> DO_2
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DO_2		134

// <h> DO_3
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DO_3		51

// <h> DO_4
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DO_4		126

// <h> DO_5
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DO_5		124

// <h> DO_6
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DO_6		123

// <h> DO_7
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DO_7		122

// <h> DI_1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI_1		75

// <h> DI_2
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI_2		86

// <h> DI_3
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI_3		87

// <h> DI_4
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_DI_4		6

// <h> 模拟量采集1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_AI_1		3

// <h> 模拟量采集2
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_AI_2		5

// <h> RT电阻1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_RT_1		16


// <h> RT电阻2
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_RT_2		17


// <h> RT电阻3
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_RT_3		90


// <h> RT电阻4
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_RT_4		83

// <h> RT电阻5
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_RT_5		84

// <h> RT电阻6
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_RT_6		85

// </e>



// <e1> I2C 配置
// <h> I2C1_SCL
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_I2C1_SCL		24
// <h> I2C1_SDA
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_I2C1_SDA		25
// </e>

// <h> RTC_INT
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// </h>
#define GPIO_RTC_INT		132



// <e2> ETH配置
// <h> ETH_RMII_RXD0
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_RMII_RXD0		36
#define GPIO_ETH_RMII_RXD0_AF		11

// <h> ETH_RMII_RXD1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_RMII_RXD1		37
#define GPIO_ETH_RMII_RXD1_AF		11

// <h> ETH_RMII_TXD0
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_RMII_TXD0		109
#define GPIO_ETH_RMII_TXD0_AF		11

// <h> ETH_RMII_TXD1
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_RMII_TXD1		110
#define GPIO_ETH_RMII_TXD1_AF		11

// <h> ETH_RMII_TX_EN
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_RMII_TX_EN		107
#define GPIO_ETH_RMII_TX_EN_AF		11


// <h> ETH_RMII_CRS_DV
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_RMII_CRS_DV		7
#define GPIO_ETH_RMII_CRS_DV_AF		11


// <h> ETH_RMII_REF_CLK
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_RMII_REF_CLK		1
#define GPIO_ETH_RMII_REF_CLK_AF		11


// <h> ETH_MDC
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_MDC		33
#define GPIO_ETH_MDC_AF		11

// <h> ETH_MDIO
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_MDIO		2
#define GPIO_ETH_MDIO_AF		11

// <h> ETH_nRST
// <o0.4..7>端口	<0=> GPIOA <1=> GPIOB  <2=> GPIOC  <3=> GPIOD  <4=> GPIOE  <5=> GPIOF  <6=> GPIOG  <7=> GPIOH <8=> GPIOI 
// <o0.0..3>引脚	<0=> PIN0 <1=> PIN1 <2=> PIN2 <3=> PIN3 <4=> PIN4 <5=> PIN5 <6=> PIN6 <7=> PIN7 <8=> PIN8 <9=> PIN9 <10=> PIN10 <11=> PIN11 <12=> PIN12 <13=> PIN13 <14=> PIN14 <15=> PIN15
// <o1.0..3>扩展功能	<0=> APP_AF_0 <1=> APP_AF_1 <2=> APP_AF_2 <3=> APP_AF_3 <4=> APP_AF_4 <5=> APP_AF_5 <6=> APP_AF_6 <7=> APP_AF_7 <8=> APP_AF_8 <9=> APP_AF_9 <10=> APP_AF_10 <11=> APP_AF_11 <12=> APP_AF_12 <13=> APP_AF_13 <14=> APP_AF_14 <15=> APP_AF_15 
// </h>
#define GPIO_ETH_NRST		129
#define GPIO_ETH_NRST_AF		8


// </e>
// <<< end of configuration section >>>
#endif //__GPIO_DEFINE_H__

