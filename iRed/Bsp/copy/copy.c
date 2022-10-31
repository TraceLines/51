/*
 * @Author: king jing
 * @Date: 2022-10-31 21:43:39
 * @LastEditTime: 2022-10-31 21:56:11
 * @Description: Do not edit
 */
#include "reg52.h"

void Timer1_Init()
{
  TMOD &= 0xF0; // 设置定时器模式
  TMOD |= 0x10; // 设置定时器模式
  TL1 = 0;      // 设置定时初值
  TH1 = 0;      // 设置定时初值
  TF1 = 0;      // 清除TF1标志
  TR1 = 1;      // 定时器1开始计时
}

void Timer1_SetCounter(unsigned int Value)
{
  TH1 = Value / 256;
  TL1 = Value % 256;
}

unsigned int Timer1_GetCounter()
{
  return (TH1 << 8) | TL1;
}

void Timer1_Run(unsigned char Flag)
{
  TR1 = Flag;
}