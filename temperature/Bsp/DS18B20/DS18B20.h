/*
 * @Author: king jing
 * @Date: 2022-10-21 16:56:24
 * @LastEditTime: 2022-10-21 22:27:05
 * @Description: Do not edit
 */
#ifndef __BSP_DS18B20
#define __BSP_DS18B20

//
#include "reg52.h"
#include "Public.h"

// GPIO定义
sbit DSPORT = P3 ^ 7;
// 函数声明
void ds18b20_reset();
u8 ds18b20_check();
u8 ds18b20_initial();
void ds18b20_write_byte(u8 dat);
u8 ds18b20_read_byte();

float ds18b20_read_temperature();

#endif