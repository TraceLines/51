/*
 * @Author: king jing
 * @Date: 2022-10-21 15:09:04
 * @LastEditTime: 2022-10-21 15:34:37
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
sbit LSA = P2 ^ 2;
sbit LSB = P2 ^ 3;
sbit LSC = P2 ^ 4;

// 数码管段选
void datapros();
void DigDisplay();

#endif