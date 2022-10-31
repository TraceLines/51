/*
 * @Author: king jing
 * @Date: 2022-10-31 16:38:30
 * @LastEditTime: 2022-10-31 21:42:51
 * @Description: 定时器0的功能函数
 */

#include "reg52.h"
#include "lcd1602.h"
/**
 * @description: TImer0初始化
 * @return {*}
 */
void Timer0_init()
{
  TMOD &= 0xF0; // 设置定时器模式
  TMOD |= 0x01;
  TL0 = 0; // 设置定时初始值
  TH0 = 0; // 设置定时初始值
  TF0 = 0; // 清除TF0标志
  TR0 = 0; // 定时器0开始计时
}

void Timer0_setCounter(unsigned int Value)
{
  TH0 = Value / 256; // 设置定时初始值
  TL0 = Value % 256; // 清除TF0标志
  LCD_ShowNum(1, 1, TH0, 3);
  LCD_ShowNum(1, 5, TL0, 3);
}

unsigned int Timer0_getCounter()
{
  unsigned int timer = 0;
  timer = (TH0 << 8) | TL0;
  LCD_ShowNum(2, 1, TH0, 3);
  LCD_ShowBinNum(2, 5, TL0, 4);
  LCD_ShowNum(2, 10, timer, 7);

  return timer;
}
void Timer0_run(unsigned char Flag)
{
  TR0 = Flag;
}