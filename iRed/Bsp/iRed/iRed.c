/*
 * @Author: king jing
 * @Date: 2022-10-31 17:36:49
 * @LastEditTime: 2022-11-01 14:02:15
 * @Description: Do not edit
 */
/*
 * @Author: king jing
 * @Date: 2022-10-31 17:36:49
 * @LastEditTime: 2022-10-31 17:42:04
 * @Description: Do not edit
 */
#include "reg52.h"

#include "LCD1602.h"
#include "Exti0.h"
#include "Timer0.h"
#include "Public.h"

unsigned int IR_Time;        // 时间记录变量
unsigned char IR_State;      // 状态变量：0:idle,1:,2:
unsigned char IR_Data[4];    // 数据缓存
unsigned char IR_DataIndex;  // 被处理的数据的位置索引
unsigned char IR_DataFlag;   // 数据结果标志，1:成功，0:失败
unsigned char IR_RepeatFlag; // 重发标志位,1:
unsigned char IR_Address;    // 最终结果保存——地址
unsigned char IR_Command;    // 最终结果保存——命令

void iRed_init()
{
  LCD_init();
  Timer0_init();
  Exti0_init();
}

unsigned char IR_getDataFlag()
{
  if (IR_DataFlag)
  {
    IR_DataFlag = 0;
    return 1;
  }
  return 0;
}
unsigned char IR_getRepeat()
{
  if (IR_RepeatFlag)
  {
    IR_RepeatFlag = 0;
    return 1;
  }
  return 0;
}
unsigned char IR_getAddress()
{
  return IR_Address;
}
unsigned char IR_getCommand()
{
  return IR_Command;
}
/**
 * @description: 外部中断函数，INT0下降沿发生时，会调用此函数，使用状态机来处理
 * @return {*}
 */
void Exti0_interrupt() interrupt 0
{
  if (IR_State == 0) // 空闲状态
  {
    P2 = 0xef;
    Timer0_setCounter(0);
    Timer0_run(1);
    IR_State = 1; // 状态切换为1，表明已经做过起始位检测。因为红外发送的数据帧长达32位，后续还有好多下降沿
  }
  else if (IR_State == 1) // 状态1
  {
    IR_Time = Timer0_getCounter(); // 检测经过了多少时间，用以判断是否是发起时序
    Timer0_setCounter(0);          // 清零，为下次计时做准备

    if ((IR_Time > 12442 - 500) && (IR_Time < 12442 + 500))
    {
      IR_State = 2; // 判断到是起始时序，切换为2状态，以装备接收数据
    }
    else if ((IR_Time > 10368 - 500) && (IR_Time < 10368 + 500))
    {
      // P2 = 0;
      // 判断到是repeat时序
      IR_RepeatFlag = 1;
      IR_State = 0;  // 状态置为0，返回空闲状态
      Timer0_run(0); // 停止计时器，在不能放在上面，要在返回状态0时做准备
    }
    else
    {
      IR_State = 1; // 继续搜寻起始信号
    }
  }
  else if (IR_State == 2) // 状态2，解码数据
  {
    IR_Time = Timer0_getCounter();                        // 获取上一次中断到此次中断的时间
    Timer0_setCounter(0);                                 // 定时计数器清0
    if ((IR_Time > 1032 - 500) && (IR_Time < 1032 + 500)) // 接收到了数据0
    {
      IR_Data[IR_DataIndex / 8] &= ~(0x01 << (IR_DataIndex % 8)); // 数据对应位清0
      IR_DataIndex++;
    }
    else if ((IR_Time > 2074 - 500) && (IR_Time < 2074 + 500)) // 接收到了数据1
    {
      IR_Data[IR_DataIndex / 8] |= (0x01 << (IR_DataIndex % 8));
      IR_DataIndex++;
    }
    else // 接收数据位出错
    {
      IR_DataIndex = 0;
      IR_State = 1;
    }
    if (IR_DataIndex >= 32)
    { // 如果接收到了32位数据

      IR_DataIndex = 0;
      if ((IR_Data[0] == ~IR_Data[1]) && (IR_Data[2] == ~IR_Data[3])) // 数据验证
      {
        IR_Address = IR_Data[0]; // 转存数据
        IR_Command = IR_Data[2];
        IR_DataFlag = 1; // 置收到连发帧标志位为1
      }
      Timer0_run(0); // 定时器停止
      IR_State = 0;  // 置状态为0
    }
  }
}
