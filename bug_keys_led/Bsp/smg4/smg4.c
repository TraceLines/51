/*
 * @Author: king jing
 * @Date: 2022-10-21 15:08:59
 * @LastEditTime: 2022-10-21 15:10:01
 * @Description: 4位数码显示
 */

#include "smg4.h"


void DigDisplay()
{
  u8 i;
  for (i = 0; i < 4; i++)
  {
    switch (i) //位选，选择点亮的数码管，
    {
    case (0):
      LSA = 1;
      LSB = 1;
      LSC = 0;
      break; //显示第0位
    case (1):
      LSA = 0;
      LSB = 1;
      LSC = 0;
      break; //显示第1位
    case (2):
      LSA = 1;
      LSB = 0;
      LSC = 0;
      break; //显示第2位
    case (3):
      LSA = 0;
      LSB = 0;
      LSC = 0;
      break; //显示第3位
    }
    P0 = disp[i]; //发送数据
    delay(100);   //间隔一段时间扫描
    P0 = 0x00;    //消隐
  }
}