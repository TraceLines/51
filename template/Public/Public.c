/*
 * @Author: king jing
 * @Date: 2022-10-18 17:00:52
 * @LastEditTime: 2022-10-21 15:44:39
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
void Delay1ms(u16 j)
{
	u16 i;
	while (j--)
	{
		i = 110;
		while (--i)
			;
	}
}


void Delay10us()
{
	unsigned char a,b;
	for(b=1;b>0;b--)
		for(a=2;a>0;a--);

}

void delay(u16 i)
{
	while(i--);	
}
