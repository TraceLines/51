/*
 * @Author: king jing
 * @Date: 2022-10-18 17:07:02
 * @LastEditTime: 2022-10-21 16:13:58
 * @Description: Do not edit
 */
#include "key.h"

int charactersPair[16][2] =
    {
        {81, 0}, {82, 1}, {42, 2}, {22, 3}, {84, 4}, {44, 5}, {24, 6}, {88, 7}, {48, 8}, {28, 9}, {18, 10}, {14, 11}, {12, 12}, {11, 13}, {21, 14}, {41, 15}};
u8 keyValue;
/**
 * @description:
 * @return {*}
 */
void handleKeyPress()
{
  u8 keyPosition, cmd;
  keyPosition = 0;
  while (keyPosition == 0)
  {
    KEY_PORT = 0X0F; //令KEY_PORT的值为0x0f
    //在这keyValue里再去读KEY_PORT寄存器的值，如果不为0x0f，则说明有按键触发。
    // 这里的重点是要理解，为什么再去读时，值变了。因为GPIO是硬件部分，在51单片机中，除了软件进行控制发出指令外，硬件内部也会有相关的操作，特别是GPIO口，会因为外部电路的电平而置为1或为0。
    // 它不像软件中，将一个变量存储为一个值后，这个值是放入RAM中的，当再次读取时，这里指赋值之后立即读取，一定还是原先的值。但在这里，KEY_PORT是端口，值与端口的电平的高低有关，写时是写入电平的高低，读时，是在读电平的高低。
    //这是非常重要的一点，与软件中的写法完全不同。
    if (KEY_PORT != 0X0F)
    {
      delay(1000);
      if (KEY_PORT != 0x0f)
      {
        cmd = 0xef;
        while (cmd != 0xff)
        {
          KEY_PORT = cmd;
          if (KEY_PORT != cmd)
          {
            keyPosition = KEY_PORT ^ 0XFF;
            break; //跳出当前while循环
          }
          else
            cmd = (cmd << 1) + 1; //说明当前没有按键按下，继续扫描行，返回当前while的循环，并设置好下一个要设置的列，通过此列进行行扫描
        }
      }
    }
  }
  KEY_PORT = 0X0F;
  do
  {
    while (KEY_PORT != 0X0F)
      ;
    Delay1ms(1);
  } while (KEY_PORT != 0X0F);
  keyValue = getsmgNum(keyPosition);
}

void KeyDown(void)
{
  char a = 0;
  GPIO_KEY = 0x0f;
  if (GPIO_KEY != 0x0f) //读取按键是否按下
  {
    delay(100);          //延时10ms进行消抖
    if (GPIO_KEY != 0x0f) //再次检测键盘是否按下
    {
      //测试列
      GPIO_KEY = 0X0F;
      switch (GPIO_KEY)
      {
      case (0X07):
        keyValue = 0;
        break;
      case (0X0b):
        keyValue = 1;
        break;
      case (0X0d):
        keyValue = 2;
        break;
      case (0X0e):
        keyValue = 3;
        break;
      }
      //测试行
      GPIO_KEY = 0XF0;
      switch (GPIO_KEY)
      {
      case (0X70):
        keyValue = keyValue;
        break;
      case (0Xb0):
        keyValue = keyValue + 4;
        break;
      case (0Xd0):
        keyValue = keyValue + 8;
        break;
      case (0Xe0):
        keyValue = keyValue + 12;
        break;
      }
    }
  }
  while ((a < 50) && (GPIO_KEY != 0xf0)) //检测按键松手检测
  {
    delay(100);
    a++;
  }
}

/**
 * @description:
 * @param {u8} keyNum
 * @return {*}
 */
u8 getsmgNum(u8 keyNum)
{
  u8 theNum;
  int i;
  for (i = 0; i < 16; i++)
  {
    if (keyNum == charactersPair[i][0])
    {
      theNum = charactersPair[i][1];
      break;
    }
  }
  return theNum;
}