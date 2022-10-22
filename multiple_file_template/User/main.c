/*
 * @Author: king jing
 * @Date: 2022-10-21 15:11:07
 * @LastEditTime: 2022-10-21 15:24:26
 * @Description: 拆解EERPOM-IIC多文件
 */

#include "key.h"
#include "smg4.h"
#include "i2c.h"
#include "Public.h"

void main(void)
{

	while (1)
	{

		Keypros();		//按键处理函数
		datapros();		//数据处理函数
		DigDisplay(); //数码管显示函数
	}
}