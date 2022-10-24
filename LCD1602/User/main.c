/*
 * @Author: king jing
 * @Date: 2022-10-24 12:11:12
 * @LastEditTime: 2022-10-24 16:08:47
 * @Description: Do not edit
 */

#include "lcd1602.h"

void main()
{

  LCD_init();

  LCD_ShowChar(1, 1, 'B');
  LCD_ShowString(1, 3, "hello");
  LCD_ShowNum(2, 1, 234, 3);
  LCD_ShowSignedNums(2, 7, -88, 2);
  while (1)
  {
    /* code */
  }
}