/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	drv_fm25v05.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	drv_fm25v05.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-13 16:35:23
*   Description:	修改说明
*
*
*********************************************************************/

#include "drv_fm25v05.h"
#include "spi.h"
#include "bsp.h"

extern spi_dev_t fram_spi;
#define FRAM_CS_ENABLE()	fram_enable(0)
#define FRAM_CS_DISABLE()	fram_enable(1)
#define FRAM_SPI_PORT		&fram_spi

/*
TABLE 3-1: INSTRUCTION SET
Instruction Name Instruction Format Description
READ 0000 0011 Read data from memory array beginning at selected address
WRITE 0000 0010 Write data to memory array beginning at selected address
WRDI 0000 0100 Reset the write enable latch (disable write operations)
WREN 0000 0110 Set the write enable latch (enable write operations)
RDSR 0000 0101 Read STATUS register
WRSR 0000 0001 Write STATUS register
*/
#define READ_CMD		0x03     //读数据指令
#define WRITE_CMD		0x02     //写输入指令
#define WREN_CMD		0x06     //写使能指令
#define WRDI_CMD		0x04     //写禁止命令
#define RDSR_CMD		0x05     //读状态寄存器指令
#define WRSR_CMD		0x01     //写状态寄存器指令
#define READ_ID			0x9f
/*
#define  PAGE_ERASE_CMD     0x42     //页擦除指令
#define  SECTOR_ERASE_CMD   0xD8     //扇区擦除指令
#define  CHIP_ERASE_CMD     0xC7     //芯片擦除指令
#define  RDID_CMD           0xAB     //退出深度掉电，并读取电子签名
#define  DPD_CMD            0xB9     //深度掉电模式
*/

static void enable_fram_write(void);
static uint8_t fram_wait_busy(void);
static uint8_t read_fram_status_register(void);
uint8_t write_fram(uint16_t Address, uint8_t n, uint8_t *Buf);
uint8_t read_fram( uint16_t Address, uint8_t n, uint8_t *Buf);


static void spi_send_16_address(uint16_t Address)
{
	spi_send_recv(FRAM_SPI_PORT,(uint8_t)(Address>>8));
	spi_send_recv(FRAM_SPI_PORT,(uint8_t)(Address&0xff));
}

static void enable_fram_write()
{
	FRAM_CS_ENABLE();
	spi_send_recv(FRAM_SPI_PORT,WREN_CMD); //0x06 send WREN command
	FRAM_CS_DISABLE();
}

void disable_fram_Write(void)
{
	spi_send_recv(FRAM_SPI_PORT, WRDI_CMD );    //0x04 send WRDI command
}

uint8_t read_fram_status_register(void)
{
	uint8_t data = 0;

	FRAM_CS_ENABLE();
	spi_send_recv(FRAM_SPI_PORT, RDSR_CMD );      // 0x05 send RDSR command
	data = spi_send_recv(FRAM_SPI_PORT,0xff);          // receive byte
	FRAM_CS_DISABLE();

	return data;
}

uint8_t read_fram_ID(uint8_t *data)
{
	uint16_t i = 0;

	FRAM_CS_ENABLE();
	spi_send_recv(FRAM_SPI_PORT, READ_ID );
	for (i = 0; i < 9;i++){
		*(data+i) = spi_send_recv(FRAM_SPI_PORT,0xff);
	}
	FRAM_CS_DISABLE();

	return 0;
}

void write_fram_sreg( uint8_t data )
{
	FRAM_CS_ENABLE();
	spi_send_recv(FRAM_SPI_PORT, WRSR_CMD );   //0x01 select write to status register
	spi_send_recv(FRAM_SPI_PORT, data );       //data that will change the status of BPx
	FRAM_CS_DISABLE();

	fram_wait_busy();
}

uint8_t fram_wait_busy(void)
{
	uint16_t counter = 0;

	while ((read_fram_status_register() & 0x01) == 0x01){
		if ((++counter) > 500){								//?????0
			return (1);
		}
	}

	return(0);
}

static void read_fram_s(uint16_t Address, uint8_t n, uint8_t *Buf )
{
	uint8_t i = 0;

	FRAM_CS_ENABLE();
	spi_send_recv(FRAM_SPI_PORT,READ_CMD);			//0x03 read command
	spi_send_16_address(Address); 			// send 3 address bytes
	for ( i = 0; i < n; i++ ){				// read until no_bytes is reached
	    Buf[i] = spi_send_recv(FRAM_SPI_PORT,0xff);
	}
	FRAM_CS_DISABLE();
}

static void write_fram_s(uint16_t Address, uint8_t n, uint8_t *Buf )
{
	uint8_t i = 0;

	FRAM_CS_DISABLE();
	enable_fram_write();					//???
	FRAM_CS_ENABLE();
	spi_send_recv(FRAM_SPI_PORT,WRITE_CMD );					//0x02 send Byte Program command
	spi_send_16_address(Address);			// send 2 address bytes

	for ( i = 0; i < n; i++ ){				// read until no_bytes is reached
	spi_send_recv(FRAM_SPI_PORT,Buf[i]);
	}

	FRAM_CS_DISABLE();
	fram_wait_busy();
}

uint8_t write_fram(uint16_t Address, uint8_t n, uint8_t *Buf)
{
	write_fram_s(Address,n,Buf);
	
	return n;

}

uint8_t read_fram(uint16_t Address, uint8_t n, uint8_t *Buf)
{

	read_fram_s(Address,n,Buf);
	
	return n;
}

void fram_sleep(void)
{

	FRAM_CS_ENABLE();
	spi_send_recv(FRAM_SPI_PORT,0xb9);
	FRAM_CS_DISABLE();

}

void fram_wakeup(void)
{
//	uint16_t i = 0;

	FRAM_CS_ENABLE();
//	for(i = 0;i < 80;i++){
//		delay_5us();
//	}

	FRAM_CS_DISABLE();
}




