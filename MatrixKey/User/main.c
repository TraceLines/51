/*
 * @Author: king jing
 * @Date: 2022-10-21 15:11:07
 * @LastEditTime: 2022-10-25 17:43:19
 * @Description: 拆解EERPOM-IIC多文件
 */

#include "Public.h"
#include "MatrixKey.h"
#include "lcd1602.h"

unsigned char KeyValue;
void main(void)
{
	// 初始化LCD显示
	LCD_init();

	while (1)
	{
		KeyValue = handleKeyPress();
		if (KeyValue&& KeyValue<9)
		{
			LCD_ShowNum(1, 1, KeyValue, 2);
		}
	}
}