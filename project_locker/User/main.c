/*
 * @Author: king jing
 * @Date: 2022-10-21 15:11:07
 * @LastEditTime: 2022-10-25 21:46:09
 * @Description: 一个简易的密码锁
 */

// #include "Public.h"
#include "lcd1602.h"
// #include "Exti.h"
#include "Lock.h"

void main()
{

	// exti_init();
	// 初始化LCD显示
  LCD_init();

	locker_init();
	while (1)
	{
		handleLockerStatus();
	}
}