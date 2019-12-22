/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	drv_w25q64fv.h
*      Abstract:	简要描述文件的内容
*
*      Filename:	drv_w25q64fv.h
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-08 16:11:07
*   Description:	修改说明
*
*
*********************************************************************/

#ifndef __DRV_W25Q64FV_H__
#define __DRV_W25Q64FV_H__
#include <stdint.h>


			


uint8_t flash_is_busy(void);                                                   /*0:idle 非零：busy;擦除/连续写入操作之后
                                                                             进行其他操作之前判断flash是否空闲*/
																																						 
void unprotect_flash(void);                                                    //打开写保护
void protect_flash(void);                                                      //写保护

void flash_init(void);
void flash_chip_erase(void);
void flash_block_erase(uint32_t Address);                                      //擦除64K
void flash_sector_erase(uint32_t Address);                                     //擦除4k

void write_flash_byte(uint32_t Address, uint8_t data);           
void write_flash_multibyte(uint32_t Address, uint8_t n, uint8_t *Buf);         //连续写入，最大255字节，且在同一页内，（若写入256字节需要处理大量意外情况）

uint8_t read_flash_byte(uint32_t Address);
void read_flash_multibyte(uint32_t Address, uint8_t n, uint8_t *Buf);

void flash_wakeup(void);
void flash_powerdown(void);

uint8_t read_flash_device_ID(void);
uint8_t read_flash_manu_ID(void);
void read_flash_uniq_ID(uint8_t *uid_buf);
#endif //__DRV_W25Q64FV_H__

