/*
 * @Author: king jing
 * @Date: 2022-10-21 16:50:05
 * @LastEditTime: 2022-10-25 11:47:36
 * @Description: Do not edit
 */

#include "Public.h"
#include "DS18B20.h"
#include "LCD1602.h"
// extern u8 code gsmg_code[17];

float T;
void main(void)
{

	LCD_init();
	// LCD_ShowString(1, 1, "temperature");
	while (1)
	{
		// 开始转换温度
		DS18B20_convertT();
		// 读取温度
		T = DS18B20_readT();
		// 显示温度
		if (T < 0)
		{
			LCD_ShowChar(2, 1, '-');
			T = -T;
		}
		else
		{
			LCD_ShowChar(2, 1, '+');
		}
		LCD_ShowNum(2, 2, T, 3);
		LCD_ShowChar(2, 5, '.');
		LCD_ShowNum(2, 6, (unsigned long)(T * 10000) % 10000, 4);
	}
}