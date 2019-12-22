/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	drv_w25q64fv.c
*      Abstract:	简要描述文件的内容
*
*      Filename:	drv_w25q64fv.c
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-08 16:09:53
*   Description:	修改说明
*
*
*********************************************************************/

#include "drv_w25q64fv.h"
#include "spi.h"
#include "gpio.h"
#include "bsp.h"

#define FLASH_SPI_PORT	&flash_spi
extern spi_dev_t flash_spi;

#define FLASH_CS_ENABLE()		flash_gpio_cs(0)
#define FLASH_CS_DISABLE()	flash_gpio_cs(1)



#define FLASH_ID		0X6000
#define FLASH_CMD_EWSR		0x50		                                             //enalbe-write-status-register
#define FLASH_CMD_RDSR		0x05		                                             //read-status-register
#define FLASH_CMD_WRSR		0x01		                                             //write-status-register

#define FLASH_CMD_WREN		0x06		                                             //write-enable
#define FLASH_CMD_WRDI		0x04		                                             //write-disable

#define FALSH_CMD_SEC_E		0x20		                                             //erase 4KByte block of memory array
#define	FLASH_CMD_BLK_E		0xD8		                                             //erase 64KByte block of memory array
#define FLASH_CMD_CHIP_E	0xC7		                                             //or 60H,erase full memory array

#define FLASH_CMD_PAGE_P	0x02		                                             //to program 1 to 255 data bytes

#define FLASH_CMD_RD		0x03		                                             //read memory
#define FLASH_CMD_FRD		0x0B		                                             //read memory at higher speed
#define FLASH_CMD_FRDIO		0xBB		                                             //read memory with dual address input and data output
#define FLASH_CMD_FRDO		0x3B		                                             //read memory with dual output

#define FLASH_CMD_DPD		0xB9                                                 //deep power down
#define FLASH_CMD_RDPD		0xAB                                                 //release deep power down
#define FLASH_CMD_RDID		0x90 		                                             //read device ID/Manufacturer ID
#define FLASH_CMD_JEDID		0x9F		                                             //jedec ID read
#define FLASH_CMD_UNIID		0x4B		                                             //unique ID read

#define FLASH_CMD_RSER		0x48                                                 //read security register
#define FLASH_CMD_ESER		0x44                                                 //eraser security register
#define FLASH_CMD_PSER		0x42                                                 //program security register

static uint8_t read_flash_status_register(void);
static void enable_flash_write(void);
static void enable_flash_wrreg(void);
static void write_flash_sreg(uint8_t data );
static void spi_send_32_address(uint32_t Address);



/************************************************************************
//unsigned char Read_Flash_Status_Register(void)
//读状态寄存器

***********************************************************************/
static uint8_t read_flash_status_register(void)
{
	uint8_t data = 1;

	FLASH_CS_ENABLE();
	spi_send_recv(FLASH_SPI_PORT, FLASH_CMD_RDSR);				// 0x05 send RDSR command
	data = spi_send_recv(FLASH_SPI_PORT, 0xff);			    // receive byte
	FLASH_CS_DISABLE();
	
	return data;
}

/************************************************************************
//void enable_flash_wrreg(void)
//使能写状态寄存器
************************************************************************/
static void enable_flash_wrreg(void)
{
	FLASH_CS_ENABLE();
	spi_send_recv(FLASH_SPI_PORT, FLASH_CMD_EWSR);				//0x50 enable writing to the status register
	FLASH_CS_DISABLE();
}

/************************************************************************/
//void write_flash_sreg( unsigned char data )
//写1byte到状态寄存器
/************************************************************************/
static void write_flash_sreg(uint8_t data )
{
	FLASH_CS_ENABLE();
	spi_send_recv(FLASH_SPI_PORT, FLASH_CMD_WRSR);    //0x01 select write to status register
	spi_send_recv(FLASH_SPI_PORT, data);              //data that will change the status of BPx							                       //or BPL (only bits 2,3,7 can be written)
	FLASH_CS_DISABLE();
}

/************************************************************************/
//void enable_flash_write()
//写使能
/************************************************************************/
static void enable_flash_write(void)
{
	FLASH_CS_ENABLE();
	spi_send_recv(FLASH_SPI_PORT, FLASH_CMD_WREN); //0x06 send WREN command
	FLASH_CS_DISABLE();
}

/************************************************************************
// void spi_send_32_address(unsigned long Address)
// 发送32位地址
************************************************************************/
static void spi_send_32_address(uint32_t Address)
{
	spi_send_recv(FLASH_SPI_PORT, (uint8_t)(Address>>16));
	spi_send_recv(FLASH_SPI_PORT, (uint8_t)((Address>>8)&0xff));
	spi_send_recv(FLASH_SPI_PORT, (uint8_t)(Address&0xff));
}


/************************************************************************/
//flash_wait_busy(void)
//判断忙状态
//输出:0:空闲, 非0：忙，超时失败推出
//函数说明:被以下功能使用：
//  （Byte-Program, Sector-Erase, Block-Erase, Chip-Erase)
/************************************************************************/

uint8_t flash_is_busy(void)
{
	uint8_t busy = 1;
	busy = read_flash_status_register();
	return (busy & 0x01);
}

/************************************************************************/
//void UnProtect_Flash(void)
//关闭写保护
/************************************************************************/
void unprotect_flash(void)
{
	enable_flash_wrreg();
	write_flash_sreg(0x00);
}

void protect_flash(void)
{
	enable_flash_wrreg();
	write_flash_sreg(0xff);
}

/************************************************************************/
//void Flash_Chip_Erase(void)
//芯片擦除
/************************************************************************/
void flash_chip_erase(void)
{
	enable_flash_write();                  //写使能
	FLASH_CS_ENABLE();
	spi_send_recv(FLASH_SPI_PORT, FLASH_CMD_CHIP_E);      //0x60 send chip Erase command
	FLASH_CS_DISABLE();
}

/************************************************************************/
//void Flash_Block_Erase( uint32_t Address )
//块擦除(1个块64Kbyte)
//地址：Address 000000H - 3FFFFFH
/************************************************************************/
void flash_block_erase(uint32_t Address)
{
	enable_flash_write();                  //写使能
	FLASH_CS_ENABLE();
	spi_send_recv(FLASH_SPI_PORT, FLASH_CMD_BLK_E);       //0x52 send Block Erase command
	spi_send_32_address(Address);          //send 3 address bytes
	FLASH_CS_DISABLE();
}

/************************************************************************/
//void Flash_Sector_Erase( uint32_t Address )
//扇区擦除(1个扇区4Kbyte)
//地址：Address 000000H - 3FFFFFH
/************************************************************************/
void flash_sector_erase(uint32_t Address )
{
	enable_flash_write();                       //写使能
	FLASH_CS_ENABLE();
	spi_send_recv(FLASH_SPI_PORT, FALSH_CMD_SEC_E);            //0x20 send Block Erase command
	spi_send_32_address(Address);               // send 3 address bytes
	FLASH_CS_DISABLE();
}

/************************************************************************/
//void Program_Flash_Byte( unsigned long Address, unsigned char data )
//字节编程
//Address--地址 000000H - 3FFFFFH
//data 数据
/************************************************************************/
void write_flash_byte(uint32_t Address, uint8_t data )
{
	enable_flash_write();               //写使能
	FLASH_CS_ENABLE();
	spi_send_recv(FLASH_SPI_PORT, FLASH_CMD_PAGE_P);   //0x02 send Byte Program command
	spi_send_32_address(Address);       // send 3 address bytes
	spi_send_recv(FLASH_SPI_PORT, data);               // send byte to be programmed
	FLASH_CS_DISABLE();
}

/************************************************************************/
//void Write_Flash_MultiByte(unsigned char cs,unsigned long Address, unsigned int n, unsigned char *Buf)
//编程多个字节，使用地址自动增加命令
//Address--地址
//Buf--数据
//n--数据量
/************************************************************************/
void write_flash_multibyte(uint32_t Address, uint8_t n, uint8_t *Buf)
{
	uint8_t count = 0;
	
	if (n <= (Address/256+1)*256 - Address) {
		enable_flash_write();                        //写使能
		FLASH_CS_ENABLE();
		spi_send_recv(FLASH_SPI_PORT, FLASH_CMD_PAGE_P);            //0x02 send Byte Program command
		spi_send_32_address(Address);                // send 3 address bytes
		for (count = 0; count < n; count++) {
			spi_send_recv(FLASH_SPI_PORT, Buf[count]);                // send byte to be programmed
		}
		FLASH_CS_DISABLE();
	} else {
		
		uint8_t len = 0;
		
		enable_flash_write();                        //写使能
		FLASH_CS_ENABLE();
		spi_send_recv(FLASH_SPI_PORT, FLASH_CMD_PAGE_P);            //0x02 send Byte Program command
		spi_send_32_address(Address);                // send 3 address bytes
		for (count = 0; count < (Address/256+1)*256 - Address; count++) {
			spi_send_recv(FLASH_SPI_PORT, Buf[len++]);                // send byte to be programmed
		}
		FLASH_CS_DISABLE();
		
		while (flash_is_busy() != 0);
		
		enable_flash_write();                        //写使能
		FLASH_CS_ENABLE();
		spi_send_recv(FLASH_SPI_PORT, FLASH_CMD_PAGE_P);            //0x02 send Byte Program command
		spi_send_32_address((Address/256+1)*256);                // send 3 address bytes
		for (count = 0; count < Address + n - (Address/256+1)*256; count++) {
			spi_send_recv(FLASH_SPI_PORT, Buf[len++]);                // send byte to be programmed
		}
		FLASH_CS_DISABLE();
	}
	
}

uint8_t read_flash_byte(uint32_t Address)
{
	uint8_t data = 0;
	
	FLASH_CS_ENABLE();
	spi_send_recv(FLASH_SPI_PORT, FLASH_CMD_RD);                                          //0x02 send Byte Program command
	spi_send_32_address(Address);                                          // send 3 address bytes
	data = spi_send_recv(FLASH_SPI_PORT, 0xff);	                                         // send byte to be programmed
	FLASH_CS_DISABLE();

	return data;
}

void read_flash_multibyte(uint32_t Address, uint8_t n, uint8_t *Buf)
{
	uint16_t count = 0;
	FLASH_CS_ENABLE();
	spi_send_recv(FLASH_SPI_PORT, FLASH_CMD_RD);                                          //0x02 send Byte Program command
	spi_send_32_address(Address);                                          // send 3 address bytes
	for (count = 0; count < n; count++) {
		Buf[count] = spi_send_recv(FLASH_SPI_PORT, 0xff);                                   // send byte to be programmed
	}
	FLASH_CS_DISABLE();
}

uint8_t read_flash_device_ID(void)
{
	uint8_t id = 0;
	FLASH_CS_ENABLE();
	spi_send_recv(FLASH_SPI_PORT, FLASH_CMD_RDID);
	spi_send_recv(FLASH_SPI_PORT, 0);
	spi_send_recv(FLASH_SPI_PORT, 0);
	spi_send_recv(FLASH_SPI_PORT, 0);
	spi_send_recv(FLASH_SPI_PORT, 0xff);
	id = spi_send_recv(FLASH_SPI_PORT, 0xff);
	FLASH_CS_DISABLE();

	return id;
}

uint8_t read_flash_manu_ID(void)
{
	uint8_t id = 0;
	FLASH_CS_ENABLE();
	spi_send_recv(FLASH_SPI_PORT, FLASH_CMD_RDID);
	spi_send_recv(FLASH_SPI_PORT, 0);
	spi_send_recv(FLASH_SPI_PORT, 0);
	spi_send_recv(FLASH_SPI_PORT, 0);
	spi_send_recv(FLASH_SPI_PORT, 0);
	id = spi_send_recv(FLASH_SPI_PORT, 0xff);
	FLASH_CS_DISABLE();

	return id;
}

void read_flash_uniq_ID(uint8_t *uid_buf)
{
	uint8_t i = 0;
	FLASH_CS_ENABLE();
	spi_send_recv(FLASH_SPI_PORT, FLASH_CMD_UNIID);
	spi_send_recv(FLASH_SPI_PORT, 0);
	spi_send_recv(FLASH_SPI_PORT, 0);
	spi_send_recv(FLASH_SPI_PORT, 0xf8);
	spi_send_recv(FLASH_SPI_PORT, 0xff);
	
	for (i = 0; i < 8; i++) {
		uid_buf[i] = spi_send_recv(FLASH_SPI_PORT, 0xff);	
	}
	FLASH_CS_DISABLE();
}

void flash_powerdown(void)
{
	FLASH_CS_ENABLE();
	spi_send_recv(FLASH_SPI_PORT, FLASH_CMD_DPD);
	FLASH_CS_DISABLE();
}

void flash_wakeup(void)
{
	FLASH_CS_ENABLE();
	spi_send_recv(FLASH_SPI_PORT, FLASH_CMD_RDPD);
	FLASH_CS_DISABLE();
}

