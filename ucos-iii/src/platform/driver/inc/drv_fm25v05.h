/*********************************************************************
*
*	Copyright (c) dreamczf@aliyun.com
*	All rights reserved.
*
*      Filename:	drv_fm25v05.h
*      Abstract:	��Ҫ�����ļ�������
*
*      Filename:	drv_fm25v05.h
*        Author:	caozhaofei
*       Version:	0.0.1
*          Date:	2017-11-13 16:35:58
*   Description:	�޸�˵��
*
*
*********************************************************************/

#ifndef __DRV_FM25V05_H__
#define __DRV_FM25V05_H__
#include <stdint.h>

void fram_init(void);
uint8_t read_fram_ID(uint8_t *data);
#endif //__DRV_FM25V05_H__

