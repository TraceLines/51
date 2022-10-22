/*
 * @Author: king jing
 * @Date: 2022-10-18 17:00:52
 * @LastEditTime: 2022-10-22 15:20:52
 * @Description: Do not edit
 */
#include "Public.h"
//#include "instr"
// #include "intrins.h"

/**
 * @description:
 * @return {*}
 */
void Delay10us_times(u16 j)
{
	unsigned char i;
	while (j--)
	{
		i = 2;
		while (--i)
			;
	}
}

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

void Delay10us()
{
	unsigned char a, b;
	for (b = 1; b > 0; b--)
		for (a = 2; a > 0; a--)
			;
}

void delay(u16 i)
{
	while (i--)
		;
}
