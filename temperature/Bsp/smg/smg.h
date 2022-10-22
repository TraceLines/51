/*
 * @Author: king jing
 * @Date: 2022-10-18 17:10:06
 * @LastEditTime: 2022-10-18 23:15:47
 * @Description: Do not edit
 */
#ifndef __BSP_SMG_H

#define __BSP_SMG_H

#include "reg52.h"
#include "Public.h"

#define SEG_PORT P0

/*
定义数码管的段选和位选引脚
*/
sbit SEG_BIT_SELECT_0 = P2 ^ 2;
sbit SEG_BIT_SELECT_1 = P2 ^ 3;
sbit SEG_BIT_SELECT_2 = P2 ^ 4;

// 数码管段选

void LED_display(u8 bitNum, u8 *bitValue);

#endif