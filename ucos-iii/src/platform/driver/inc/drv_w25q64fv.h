/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	drv_w25q64fv.h
*      Abstract:	��Ҫ�����ļ�������
*
*      Filename:	drv_w25q64fv.h
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-08 16:11:07
*   Description:	�޸�˵��
*
*
*********************************************************************/

#ifndef __DRV_W25Q64FV_H__
#define __DRV_W25Q64FV_H__
#include <stdint.h>


			


uint8_t flash_is_busy(void);                                                   /*0:idle ���㣺busy;����/����д�����֮��
                                                                             ���н�����������֮ǰ�ж�flash�Ƿ����*/
																																						 
void unprotect_flash(void);                                                    //��д����
void protect_flash(void);                                                      //д����

void flash_init(void);
void flash_chip_erase(void);
void flash_block_erase(uint32_t Address);                                      //����64K
void flash_sector_erase(uint32_t Address);                                     //����4k

void write_flash_byte(uint32_t Address, uint8_t data);           
void write_flash_multibyte(uint32_t Address, uint8_t n, uint8_t *Buf);         //����д�룬���255�ֽڣ�����ͬһҳ�ڣ�����д��256�ֽ���Ҫ����������������

uint8_t read_flash_byte(uint32_t Address);
void read_flash_multibyte(uint32_t Address, uint8_t n, uint8_t *Buf);

void flash_wakeup(void);
void flash_powerdown(void);

uint8_t read_flash_device_ID(void);
uint8_t read_flash_manu_ID(void);
void read_flash_uniq_ID(uint8_t *uid_buf);
#endif //__DRV_W25Q64FV_H__

