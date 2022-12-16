/*
 * @Author: king jing
 * @Date: 2022-10-31 16:38:30
 * @LastEditTime: 2022-11-01 12:34:18
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
}

unsigned int Timer0_getCounter()
{
  return (TH0 << 8) | TL0;
}
void Timer0_run(unsigned char Flag)
{
  TR0 = Flag;
}