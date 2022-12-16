/*
 * @Author: king jing
 * @Date: 2022-10-31 09:28:34
 * @LastEditTime: 2022-10-31 11:56:36
 * @Description: PT2046驱动程序
 */

#include "reg52.h"
#include "LCD1602.h"

sbit XPT2046_DIN = P3 ^ 4;
sbit XPT2046_CS = P3 ^ 5;
sbit XPT2046_DCLK = P3 ^ 6;
sbit XPT2046_DOUT = P3 ^ 7;

/**
 * @description:
 * @param {unsigned char} command
 * @return {*}
 */
unsigned int XPT2046_ADRead(unsigned char command)
{
  unsigned char i;
  unsigned int ReceiveData = 0;
  XPT2046_DCLK = 0;
  XPT2046_CS = 0;

  // begin to send command
  for (i = 0; i < 8; i++)
  {
    XPT2046_DIN = command & (0x80 >> i);
    XPT2046_DCLK = 1;
    XPT2046_DCLK = 0;
  }
  // begin to receive the data
  for (i = 0; i < 16; i++)
  {
    XPT2046_DCLK = 1;
    XPT2046_DCLK = 0;
    if (XPT2046_DOUT)
    {
      ReceiveData |= (0x8000 >> i);
    }
  }
  XPT2046_CS = 1;
  // LCD_ShowNum(2, 9, ReceiveData, 8);
  return ReceiveData >> 8;
}