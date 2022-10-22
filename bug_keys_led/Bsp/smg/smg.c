/*
 * @Author: king jing
 * @Date: 2022-10-18 17:10:02
 * @LastEditTime: 2022-10-21 15:09:55
 * @Description: Do not edit
 */
#include "smg.h"

u8 code gsmg_code[17] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
                         0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};
// u8 code gsmg_code[17] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8,
//                        0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e};
/**
 * @description:
 * @param {u8} bitNum，要显示的位数
 * @param {u8} bitValue，要显示的值
 * @param {bit} align 定义左边显示还是右边显示
 * align =1,left.align=0,right;
 * @return {*}
 */
void LED_display(u8 bitNum, u8 *valueArr)
{
  u8 i;

  for (i = bitNum; i < 8; i++)
  {
    switch (i)
    {
    case 0:
      SEG_BIT_SELECT_0 = 1;
      SEG_BIT_SELECT_1 = 1;
      SEG_BIT_SELECT_2 = 1;
      break;
    case 1:
      SEG_BIT_SELECT_0 = 0;
      SEG_BIT_SELECT_1 = 1;
      SEG_BIT_SELECT_2 = 1;
      break;
    case 2:
      SEG_BIT_SELECT_0 = 1;
      SEG_BIT_SELECT_1 = 0;
      SEG_BIT_SELECT_2 = 1;
      break;
    case 3:
      SEG_BIT_SELECT_0 = 0;
      SEG_BIT_SELECT_1 = 0;
      SEG_BIT_SELECT_2 = 1;
      break;
    case 4:
      SEG_BIT_SELECT_0 = 1;
      SEG_BIT_SELECT_1 = 1;
      SEG_BIT_SELECT_2 = 0;
      break;
    case 5:
      SEG_BIT_SELECT_0 = 0;
      SEG_BIT_SELECT_1 = 1;
      SEG_BIT_SELECT_2 = 0;
      break;
    case 6:
      SEG_BIT_SELECT_0 = 1;
      SEG_BIT_SELECT_1 = 0;
      SEG_BIT_SELECT_2 = 0;
      break;
    case 7:
      SEG_BIT_SELECT_0 = 0;
      SEG_BIT_SELECT_1 = 0;
      SEG_BIT_SELECT_2 = 0;
      break;
    default:
      break;
    }
    SEG_PORT = gsmg_code[valueArr[i - bitNum]];
    delay(100);
    SEG_PORT = 0x00;
  }
}
