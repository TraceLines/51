/*
 * @Author: king jing
 * @Date: 2022-10-18 17:00:52
 * @LastEditTime: 2022-10-24 09:17:53
 * @Description: Do not edit
 */
#include "Public.h"
//#include "instr"
// #include "intrins.h"

/**
 * @description:
 * @param {uint} j
 * @return {*}
 *
 */
void Delay1ms(u16 y)
{
	u16 x;
	for (; y > 0; y--)
	{
		for (x = 110; x > 0; x--)
			;
	}
}

// void Delayms(u16 n)

// {

// 	u16 i, j;

// 	for (j = n; j > 0; j--)

// 		for (i = 112; i > 0; i--)
// 			;
// }

void Delay10us() //@11.0592MHz
{
	unsigned char i;

	i = 2;
	while (--i)
		;
}
void Delay100us() //@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 43;
	while (--i)
		;
}
void Delay1ms() //@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j)
			;
	} while (--i);
}

void delay(u16 i)
{
	while (i--)
		;
}

// //非精确延时10*X us，固定误差10us
// //@12.000MHz 12T模式
// void DelayX10us(unsigned char x)
// {
// 	unsigned char i;
// 	for (; x > 0; x--)
// 	{
// 		_nop_();
// 		_nop_();
// 	}
// }