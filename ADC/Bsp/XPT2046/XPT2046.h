/*
 * @Author: king jing
 * @Date: 2022-10-31 09:28:41
 * @LastEditTime: 2022-10-31 11:37:08
 * @Description: Do not edit
 */
#ifndef __BSP_XPT2046_H__

#define __BSP_XPT2046_H__

#define XPT2046_VBAT 0xAC
#define XPT2046_AUX 0xEC
#define XPT2046_XP 0x9C // 0xBC
#define XPT2046_YP 0xDC

// 函数声明
unsigned int XPT2046_ADRead(unsigned char command);
#endif