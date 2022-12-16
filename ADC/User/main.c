/*
 * @Author: king jing
 * @Date: 2022-10-31 09:28:14
 * @LastEditTime: 2022-10-31 11:57:12
 * @Description:模块转换
 */

#include "lcd1602.h"
#include "Public.h"
#include "XPT2046.h"

unsigned int ADValue;

void main()
{
  // init the lcd
  LCD_init();
  LCD_ShowString(1, 1, "ADJ  NTC  GR");
  /* code */
  while (1)
  {

    ADValue = XPT2046_ADRead(XPT2046_XP); // 读取AIN0，可调电阻
    LCD_ShowNum(2, 1, ADValue, 3);        // 显示AIN0
    ADValue = XPT2046_ADRead(XPT2046_YP);   // 读取AIN1，热敏电阻
    LCD_ShowNum(2, 6, ADValue, 3);          // 显示AIN1
    ADValue = XPT2046_ADRead(XPT2046_VBAT); // 读取AIN2，光敏电阻
    LCD_ShowNum(2, 11, ADValue, 3);         // 显示AIN2
    Delayx1m(100);
  }
}
