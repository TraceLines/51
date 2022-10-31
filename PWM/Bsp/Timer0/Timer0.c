/*
 * @Author: king jing
 * @Date: 2022-10-27 16:18:47
 * @LastEditTime: 2022-10-27 17:49:08
 * @Description: 计时器驱动
 */
/**
 * @description: 定时器0初始化
 * @return {*}
 */

#include "reg52.h"

sbit LED1 = P2 ^ 6;
unsigned char counter, compare;
void Timer0_init() // 100微秒@11.0592MHz
{

  // AUXR &= 0x7F; // 定时器时钟12T模式
  TMOD &= 0xF0; // 设置定时器模式
  TMOD |= 0x01; // 设置定时器模式
  TL0 = 0xA4;   // 设置定时初始值
  TH0 = 0xFF;   // 设置定时初始值
  TF0 = 0;      // 清除TF0标志
  TR0 = 1;      // 定时器0开始计时
  ET0 = 1;      // 允许T0产生中断
  EA = 1;       // 总中断开关
}

/**
 * @description: 定时器T0的中断函数
 * @return {*}
 */
void Timer0_interrupt() interrupt 1 // 每100us时间会进入这个中断函数中
{
  // LED1 = ~LED1;
  TL0 = 0xA4; // 设置定时初始值
  TH0 = 0xFF; // 设置定时初始值
  counter++;
  counter %= 100;
  if (counter < 5) 
  {
    LED1 = 0;
  }
  else
  {
    LED1 = 1;
  }
}