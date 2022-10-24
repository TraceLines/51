/*
 * @Author: king jing
 * @Date: 2022-10-21 16:50:05
 * @LastEditTime: 2022-10-22 18:11:50
 * @Description: Do not edit
 */

#include "Public.h"
#include "DS18B20.h"
#include "smg.h"
#include "uart.h"

sbit LED_inform1 = P2 ^ 7;
sbit LED_inform2 = P2 ^ 6;


extern u8 code gsmg_code[17];


void main(void)
{

	int i;
	int temp_value = 0;
	u8 temp_buf[5];
	u8 isExist;
	isExist = ds18b20_initial();
	usart_init();
	if (isExist)
	{
		LED_inform1 = 0;
	}
	else
	{
		LED_inform2 = 0;
	}

	while (1)
	{
		i++;
		if (i % 50)
			temp_value = ds18b20_read_temperature() * 10;
		if (temp_value < 0)
		{
			temp_value = -temp_value;
			temp_buf[0] = 0x40;
		}
		else
		{
			temp_buf[0] = 0x00;
		}
		temp_buf[1] = gsmg_code[temp_value / 1000];
		temp_buf[2] = gsmg_code[temp_value % 1000 / 100];
		temp_buf[3] = gsmg_code[temp_value % 1000 % 100 / 10] | 0x80;
		temp_buf[4] = gsmg_code[temp_value % 1000 % 100 % 10];
		LED_display(3, temp_buf);
	}
}