/*
 * @Author: king jing
 * @Date: 2022-10-26 15:04:06
 * @LastEditTime: 2022-10-26 21:11:15
 * @Description: 一个时钟
 */

// 引入头文件
#include "Public.h"
#include "ds1302.h"
#include "lcd1602.h"

void main()
{
  u8 readByte = 0;
  LCD_init();
  DS1302_writeByte(0X8E, 0x00);
  DS1302_writeByte(0X80, 0x02);
  while (1)
  {
    readByte = DS1302_readByte(0X81);
    LCD_ShowHexNum(1, 1, readByte, 2); //验证时序的正确性
    LCD_ShowBinNum(1, 5, readByte, 8); //验证时序的正确性
    /* code */
  }
}