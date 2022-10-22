/*
 * @Author: king jing
 * @Date: 2022-10-21 15:13:50
 * @LastEditTime: 2022-10-21 16:23:16
 * @Description: Do not edit
 */
#ifndef __BSP_KEY_H

#define __BSP_KEY_H

#include "reg52.h"
#include "Public.h"

#include "i2c.h"

sbit k1 = P3 ^ 1;
sbit k2 = P3 ^ 0;
sbit k3 = P3 ^ 2;
sbit k4 = P3 ^ 3; //定义按键端口

// extern char num;

void Keypros();

#endif