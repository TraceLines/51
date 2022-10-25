/*
 * @Author: king jing
 * @Date: 2022-10-21 15:11:07
 * @LastEditTime: 2022-10-25 20:08:50
 * @Description: 拆解EERPOM-IIC多文件
 */

#include "Public.h"
#include "MatrixKey.h"
#include "lcd1602.h"

unsigned char KeyValue;
void main(void)
{
	unsigned char column = 1; //显示位置
	// 初始化LCD显示
	LCD_init();

	while (1)
	{
		KeyValue = handleKeyPress();
		if (KeyValue)
		{
			if (KeyValue <= 9)
			{

				LCD_ShowNum(1, column, KeyValue, 1);
			}
			else if (KeyValue == 48)
			{
				LCD_ShowNum(1, column, 0, 1);
			}
			else
			{
				LCD_ShowChar(1, column, KeyValue);
			}
			column++;
		}
	}
}