/*
 * @Author: king jing
 * @Date: 2022-10-21 15:13:47
 * @LastEditTime: 2022-10-25 21:29:19
 * @Description: Do not edit
 */
#include "reg52.h"
#include "Public.h"
#include "MatrixKey.h"

#define GPIO_KEY P1

/**
 * @description:
 * @return {*}
 */
u8 handleKeyPress()
{
  u8 keyPosition, cmd;
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
  return keyPosition;
}

/**
 * @description:
 * @param {u8} keyPosition
 * @return {*}
 */
