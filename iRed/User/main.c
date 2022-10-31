/*
 * @Author: king jing
 * @Date: 2022-10-31 16:37:09
 * @LastEditTime: 2022-10-31 22:09:40
 * @Description: Do not edit
 */

// #include "iRed.h"
// #include "Timer_1.h"
// #include "Timer0.h"
#include "lcd1602.h"
#include "copy.h"

// #include "Public.h"

unsigned int timeNum;
void main()
{

  // iRed_init();
  LCD_init();
  Timer1_init();
  Timer1_setCounter(0);
  Timer1_run(1);
  Delayx1m(1);
  timeNum = Timer1_getCounter();
  // LCD_ShowNum(1, 1, timeNum, 16);

  Timer1_run(0);

  while (1)
  {
  }
}
