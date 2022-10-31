/*
 * @Author: king jing
 * @Date: 2022-10-27 15:42:17
 * @LastEditTime: 2022-10-27 17:10:52
 * @Description: Do not edit
 */

#include "reg52.h"
#include "Public.h"

// bsp 驱动引入

#include "Timer0.h"
sbit LED0 = P2 ^ 0;
void main()
{
  unsigned char Timer, i;
  LED0 = 0;
  Timer0_init();
  while (1)
  {
    for (Timer = 0; Timer < 100; Timer++)
    {
      for (i = 0; i < 20; i++)
      {
        LED0 = 0;
        Delay(Timer);
        LED0 = 1;
        Delay(100 - Timer);
      }
    }
    for (Timer = 100; Timer > 0; Timer--)
    {
      for (i = 0; i < 20; i++)
      {
        LED0 = 0;
        Delay(Timer);
        LED0 = 1;
        Delay(100 - Timer);
      }
    }
  }
}