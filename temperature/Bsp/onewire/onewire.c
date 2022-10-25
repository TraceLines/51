/*
 * @Author: king jing
 * @Date: 2022-10-25 08:54:28
 * @LastEditTime: 2022-10-25 14:16:23
 * @Description: 单总线功能
 */

#include "reg52.h"
#include "Public.h"
#include "LCD1602.h"
#include "intrins.h"

sbit oneWire_DQ = P3 ^ 7;

/**
 * @description: 单总线初始化
 * @return {0:sucess,1:fail}
 */
u8 oneWire_init()
{
  u8 ackBit = 0;
  u8 i; ////@11.0592MHz 500us延时
  oneWire_DQ = 1;
  oneWire_DQ = 0;

  i = 247;
  while (--i)
    ;
  oneWire_DQ = 1;
  i = 33; //@11.0592MHz 70us
  while (--i)
    ;
  ackBit = oneWire_DQ;
  i = 247;
  while (--i)
    ;
  return ackBit;
}

/**
 * @description: 单总线，位发送，对应写时序图
 * @return {*}
 */
void oneWire_sendBit(u8 chartBit)
{
  unsigned char i;
  oneWire_DQ = 0;

  i = 4; //@11.0592MHz 10us
  while (--i)
    ;
  oneWire_DQ = chartBit;
  i = 24; //@11.0592MHz 50us
  while (--i)
    ;
  oneWire_DQ = 1;
}
/**
 * @description: 单总线，位接收，对应读时序图
 * @return {*}返回收到的位
 */
u8 oneWire_receiveBit()
{
  u8 i, receiveBit;
  oneWire_DQ = 0; //先拉低总线，为接收做准备
  i = 2;          // @11.0592MHz 5us 程序调用有4个机器周期，实际使用软件计算时，输入的是9
  while (--i)
    ;
  oneWire_DQ = 1; //再拉高总线，即释放总线，为采样做准备，即应对doc文件中的疑惑——释放总线，松手以实现由电阻上拉的效果，在代码中如何实现？
  i = 2;          // @11.0592MHz 5us 释放5us后再采样
  while (--i)
    ;
  receiveBit = oneWire_DQ; //采样，读取从机传过来的位
  i = 24;                  //@11.0592MHz 50us
  while (--i)
    ;
  return receiveBit;
}

/**
 * @description: 单总线，字节发送
 * @param {u8} charByte
 * @return {*}
 */
void oneWire_sendByte(u8 charByte)
{
  u8 i;
  // _nop_();
  // LCD_ShowHexNum(2, 11, charByte, 2);
  for (i = 0; i < 8; i++)
  {
    oneWire_sendBit(charByte & (0x01 << i));
  }
}
/**
 * @description: 单总线字节接收
 * @return {*}
 */
u8 oneWire_receiveByte()
{
  u8 i;
  u8 receiveByte = 0x00;
  for (i = 0; i < 8; i++)
  {
    if (oneWire_receiveBit())
    {
      receiveByte |= (0x01 << i);
    }
  }
  // LCD_ShowHexNum(2, 11, receiveByte, 2);
  return receiveByte;
}