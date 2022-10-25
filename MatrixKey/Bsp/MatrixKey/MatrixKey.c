/*
 * @Author: king jing
 * @Date: 2022-10-21 15:13:47
 * @LastEditTime: 2022-10-25 17:15:31
 * @Description: Do not edit
 */
#include "reg52.h"
#include "Public.h"
#include "MatrixKey.h"

#define GPIO_KEY P1

int charactersPair[16][2] =
    {
        {0x81, 'A'}, {0x82, 3}, {0x84, 2}, {0x88, 1}, {0x41, 'B'}, {0x42, 6}, {0x44, 5}, {0x48, 4}, {0x21, 'C'}, {0x22, 9}, {0x24, 8}, {0x28, 7}, {0X11, 'D'}, {0X12, '#'}, {0X14, 0}, {0X18, '*'}};
/**
 * @description:
 * @return {*}
 */
u8 handleKeyPress()
{
  u8 keyPosition, cmd, KeyValue;
  keyPosition = 0;
  while (keyPosition == 0)
  {
    GPIO_KEY = 0X0F; //令GPIO_KEY的值为0x0f

    if (GPIO_KEY != 0X0F) //检测到有按下
    {
      Delayx1m(100);        //消抖
      if (GPIO_KEY != 0x0f) //确定有键按下
      {
        cmd = 0xef;         // 1110 1111 开始扫描第1行第1列
        while (cmd != 0xff) //这里有点不明白，与oxff比较是为了退出循环体它是由下面的cmd = (cmd << 1) + 1;结果产生的，当cmd ==0xff，表明已经完成一轮的循环
        {
          GPIO_KEY = cmd;
          if (GPIO_KEY != cmd)
          {
            keyPosition = GPIO_KEY ^ 0XFF; //进行异或逻辑运算，取得特征字，并结束循环 while (keyPosition == 0)
            break;                         //跳出当前while循环
          }
          else
            cmd = (cmd << 1) + 1; //说明当前没有按键按下，继续扫描行，返回当前while的循环，并设置好下一个要设置的列，通过此列进行行扫描
        }
      }
    }
  }
  GPIO_KEY = 0X0F;
  do
  {
    while (GPIO_KEY != 0X0F)
      ;
    Delayx1m(10);
  } while (GPIO_KEY != 0X0F);
  KeyValue = getsmgNum(keyPosition);
  return KeyValue;
}

// void KeyDown(void)
// {
//   u8 keyValue;
//   char a = 0;
//   GPIO_KEY = 0x0f;
//   if (GPIO_KEY != 0x0f) //读取按键是否按下
//   {
//     Delayx1m(10);         //延时10ms进行消抖
//     if (GPIO_KEY != 0x0f) //再次检测键盘是否按下
//     {
//       //测试列
//       GPIO_KEY = 0X0F;
//       switch (GPIO_KEY)
//       {
//       case (0X07):
//         keyValue = 0;
//         break;
//       case (0X0b):
//         keyValue = 1;
//         break;
//       case (0X0d):
//         keyValue = 2;
//         break;
//       case (0X0e):
//         keyValue = 3;
//         break;
//       }
//       //测试行
//       GPIO_KEY = 0XF0;
//       switch (GPIO_KEY)
//       {
//       case (0X70):
//         keyValue = keyValue;
//         break;
//       case (0Xb0):
//         keyValue = keyValue + 4;
//         break;
//       case (0Xd0):
//         keyValue = keyValue + 8;
//         break;
//       case (0Xe0):
//         keyValue = keyValue + 12;
//         break;
//       }
//     }
//   }
//   while ((a < 50) && (GPIO_KEY != 0xf0)) //检测按键松手检测
//   {
//     Delayx1m(10);
//     a++;
//   }
// }

/**
 * @description:
 * @param {u8} keyPosition
 * @return {*}
 */
u8 getsmgNum(u8 keyPosition)
{
  u8 theNum;
  int i;
  for (i = 0; i < 16; i++)
  {
    if (keyPosition == charactersPair[i][0])
    {
      theNum = charactersPair[i][1];
      break;
    }
  }
  return theNum;
}