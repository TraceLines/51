/*
 * @Author: king jing
 * @Date: 2022-10-21 15:11:07
 * @LastEditTime: 2022-10-26 09:02:42
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

	locker_init("password:");
	while (1)
	{
		handleLockerStatus();
	}
}