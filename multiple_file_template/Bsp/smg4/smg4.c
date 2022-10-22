/*
 * @Author: king jing
 * @Date: 2022-10-21 15:08:59
 * @LastEditTime: 2022-10-21 16:22:49
 * @Description: 4位数码显示
 */

#include "smg4.h"
// #include "key.h"
// 此处创建一个外部变量的引用声明，声明这个变量是在别处定义的，此处仅为引用，可通过编译。
extern char num;



u8 disp[4];
u8 code smgduan[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

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

void datapros()
{
  disp[0] = smgduan[num / 1000];            //千位
  disp[1] = smgduan[num % 1000 / 100];      //百位
  disp[2] = smgduan[num % 1000 % 100 / 10]; //个位
  disp[3] = smgduan[num % 1000 % 100 % 10];
}