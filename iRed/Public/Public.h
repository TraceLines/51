/*
 * @Author: king jing
 * @Date: 2022-10-24 14:29:50
 * @LastEditTime: 2022-10-24 15:45:01
 * @Description: Do not edit
 */
#ifndef __PUBLIC_H__
#define __PUBLIC_H__

typedef unsigned int u16; //对数据类型进行声明定义
typedef unsigned char u8;

void Delay1ms();
void Delayx1m(unsigned int xms);

// math
u16 math_power(u8 base, u8 expo);


#endif