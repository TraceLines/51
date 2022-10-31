/*
 * @Author: king jing
 * @Date: 2022-10-31 09:28:14
 * @LastEditTime: 2022-10-31 09:34:05
 * @Description:模块转换
 */

#include "lcd1602.h"
#include "Public.h"

void main()
{
  // init the lcd
  LCD_init();
  LCD_ShowNum(1, 1, 12, 2);
  /* code */
  while (1)
  {
    /* code */
  }
}
