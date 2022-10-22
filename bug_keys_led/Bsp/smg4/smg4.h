/*
 * @Author: king jing
 * @Date: 2022-10-21 15:09:04
 * @LastEditTime: 2022-10-21 15:09:21
 * @Description: Do not edit
 */
#ifndef __BSP_SMG4_H

#define __BSP_SMG4_H

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


#endif