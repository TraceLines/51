/*
 * @Author: king jing
 * @Date: 2022-10-21 15:11:07
 * @LastEditTime: 2022-10-26 14:29:40
 * @Description:
 */

#include "Public.h"
#include "reg52.h"
#include "74HC595.h"
// sbit LED = P0 ^ 5;

void main(void)
{
	// unsigned char i;
	unsigned char ROW = 0;
	unsigned char COLUMN = 0x7f;
	// LED = 0;
	// P0 = 0x7f;
	while (1)
	{
		P0 = COLUMN;
		if (COLUMN == 0)
		{
			COLUMN = 0x7f;
		}
		else
		{
			COLUMN >>= 1;
		}
		_74hc595_write(0x01);
		Delayx1m(500);
	}
}