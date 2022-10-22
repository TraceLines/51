/*
 * @Author: king jing
 * @Date: 2022-10-18 17:00:57
 * @LastEditTime: 2022-10-21 15:02:13
 * @Description: Do not edit
 */
#ifndef __PUBLIC_H
#define __PUBLIC_H

#include "reg52.h"

typedef unsigned int u16; //对数据类型进行声明定义
typedef unsigned char u8;

void Delay10us();
void Delay1ms(u16 j);
void Delay10us_times(u16 j);
void delay(u16 i);
#endif