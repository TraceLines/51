/*
 * @Author: king jing
 * @Date: 2022-10-31 16:37:09
 * @LastEditTime: 2022-11-01 14:10:18
 * @Description: Do not edit
 */

#include "iRed.h"
// #include "Timer1.h"
// #include "Timer0.h"
#include "lcd1602.h"

// #include "Public.h"

unsigned int timeNum;
unsigned char Address, Command;
void main()
{

  iRed_init();
  // LCD_init();
  // Timer1_init();
  // Timer1_setCounter(0);
  // Timer1_run(1);
  // Delayx1m(1);
  // timeNum = Timer1_getCounter();
  // LCD_ShowBinNum(1, 1, timeNum, 16);
  // LCD_ShowHexNum(1, 6, 12, 4);
  // LCD_ShowBinNum(2, 1, 12, 8);

  // Timer1_run(0);

  while (1)
  {
    if (IR_getDataFlag() || IR_getRepeat())
    {
      Address = IR_getAddress();
      Command = IR_getCommand();
      LCD_ShowHexNum(2, 1, Address, 2);
      LCD_ShowHexNum(2, 5, Command, 2);
      if (Command == 0x40)
      {
        timeNum++;
      }
      if (Command == 0x19)
      {
        timeNum--;
      }
      LCD_ShowHexNum(2, 8, timeNum, 2);
    }
  }
}
