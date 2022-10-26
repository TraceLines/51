/*
 * @Author: king jing
 * @Date: 2022-10-26 11:33:17
 * @LastEditTime: 2022-10-26 14:09:36
 * @Description: 74hc595驱动
 */

// 寄存器文件引入
#include "reg52.h"
// #include <intrins.h>
// 本功能要使用引脚的声明

sbit RCK595 = P3 ^ 5;   //数据锁存位
sbit SRCLK595 = P3 ^ 6; //数据传输时钟 上升沿有效
sbit SER595 = P3 ^ 4;   //数据传输位
/**
 * @description:74hc595写功能，另外要说明的是，这个器件不需要初始化，直接进行读和写就可以。
 * @param {unsigned char} bytes
 * @return {*}
 */
void _74hc595_write(unsigned char bytes)
{
  unsigned char i;

  SRCLK595 = 0; //拉低时钟沿
  RCK595 = 0;   //拉低寄存器锁存位
                // 开始位传输
  for (i = 0; i < 8; i++)
  {
    SER595 = bytes & (0x80 >> i);
    SRCLK595 = 1; //制造上升沿
    // _nop_();      //其实不加延时应该也是可以的
    // _nop_();
    SRCLK595 = 0; //再拉低，为下一次位传输准备
  }
  // 锁存寄存器，将值输出到相应的引用中
  RCK595 = 1;
}