/*
 * @Author: king jing
 * @Date: 2022-10-31 16:38:30
 * @LastEditTime: 2022-10-31 22:56:17
 * @Description: 定时器0的功能函数
 */

#include "reg52.h"
#include "lcd1602.h"
/**
 * @description: TImer0初始化
 * @return {*}
 */
void Timer1_init()
{
  TMOD &= 0xF0; // 设置定时器模式
  TMOD |= 0x10;
  TL1 = 0; // 设置定时初始值
  TH1 = 0; // 设置定时初始值
  TF1 = 0; // 清除TF0标志
  TR1 = 0; // 定时器0开始计时
}

void Timer1_setCounter(unsigned int Value)
{
  TH1 = Value / 256;
  TL1 = Value % 256;
}

/**
 * @brief  定时器0获取计数器值
 * @param  无
 * @retval 计数器值，范围：0~65535
 */
unsigned int Timer1_getCounter(void)
{
  return (TH1 << 8) | TL1;
}

/**
 * @brief  定时器0启动停止控制
 * @param  Flag 启动停止标志，1为启动，0为停止
 * @retval 无
 */
void Timer1_run(unsigned char Flag)
{
  TR1 = Flag;
}