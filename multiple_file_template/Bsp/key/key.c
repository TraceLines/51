/*
 * @Author: king jing
 * @Date: 2022-10-21 15:13:47
 * @LastEditTime: 2022-10-21 16:17:11
 * @Description: Do not edit
 */

#include "key.h"

char num = 0;
void Keypros()
{
  if (k1 == 0)
  {
    delay(1000); //消抖处理
    if (k1 == 0)
    {
      At24c02Write(1, num); //在地址1内写入数据num
    }
    while (!k1)
      ;
  }
  if (k2 == 0)
  {
    delay(1000); //消抖处理
    if (k2 == 0)
    {
      num = At24c02Read(1); //读取EEPROM地址1内的数据保存在num中
    }
    while (!k2)
      ;
  }
  if (k3 == 0)
  {
    delay(100); //消抖处理
    if (k3 == 0)
    {
      num++; //数据加1
      if (num > 255)
        num = 0;
    }
    while (!k3)
      ;
  }
  if (k4 == 0)
  {
    delay(1000); //消抖处理
    if (k4 == 0)
    {
      num = 0; //数据清零
    }
    while (!k4)
      ;
  }
}