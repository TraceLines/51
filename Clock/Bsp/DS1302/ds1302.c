/*
 * @Author: king jing
 * @Date: 2022-10-26 15:07:50
 * @LastEditTime: 2022-10-26 17:15:00
 * @Description: DS1302芯片驱动/功能
 */

#include "reg52.h"
#include "Public.h"
// 定义相关引脚

sbit DS1302_SCLK = P3 ^ 6;
sbit DS1302_IO = P3 ^ 4;
sbit DS1302_CE = P3 ^ 5;

// 芯片常用指令集
#define DS1302_CMD_SECOND 0X80
#define DS1302_CMD_MINUTES 0X82
#define DS1302_CMD_HOUR 0X84
#define DS1302_CMD_DATE 0X86
#define DS1302_CMD_MONTH 0X88
#define DS1302_CMD_DAY 0X8A
#define DS1302_CMD_YEAR 0X8C
#define DS1302_CMD_WP 0X8E

/**
 * @description: 读操作，根据时序图可以，要操作的引脚有CE、SCLK、IO
 * @param {u8} command  功能的指令
 * @return {*}读取的值
 */
u8 DS1302_readByte(u8 command)
{
  u8 i;
  u8 recieve_byte = 0;
  command |= 0x01; //将相关写指令转换为读指令
  DS1302_CE = 0;   //拉低CE引脚
  DS1302_SCLK = 0; //拉低时钟引脚
  DS1302_CE = 1;   //拉高，使能通信
  // 发送命令 将命令通过IO引脚bit by bit传给DS1302
  for (i = 0; i < 8; i++)
  {
    DS1302_IO = command & (0x01 << i);
    DS1302_SCLK = 1; //拉高，制造上升沿，使位得以传输
    DS1302_SCLK = 0; //拉低，为下次传位做准备
  }
  DS1302_SCLK = 1;
  DS1302_IO = 0;
  // 接收数据
  for (i = 0; i < 8; i++)
  {

    DS1302_SCLK = 0; //拉低，制造下降沿，使位得以传输
    if (DS1302_IO)   //先判断值是否为1，若为1，则将0x01移动到第i位，与原值执行或运算以保留原值
    {                //若不存储，则保留原值不变，这个处理挺巧妙的
      recieve_byte |= (0x01 << i);
    }
    DS1302_SCLK = 1; //拉高，为下次传位做准备
  }

  // 完成通信，关闭通信使能位
  DS1302_CE = 0;
  return recieve_byte;
}
/**
 * @description: 写操作
 * @param {u8} command 功能指令
 * @param {u8} d_byte 要写入的值
 * @return {*} 无
 */
void DS1302_writeByte(u8 command, u8 d_byte)
{

  u8 i;
  DS1302_CE = 0;   //拉低CE引脚
  DS1302_SCLK = 0; //拉低时钟引脚
  DS1302_CE = 1;   //拉高，使能通信
  // 发送命令 将命令通过IO引脚bit by bit传给DS1302
  for (i = 0; i < 8; i++)
  {
    DS1302_IO = command & (0x01 << i);
    DS1302_SCLK = 1; //拉高，制造上升沿，使位得以传输
    DS1302_SCLK = 0; //拉低，为下次传位做准备
  }
  // 通过IO引脚将数据发送出去
  for (i = 0; i < 8; i++)
  {
    DS1302_IO = d_byte & (0x01 << i);
    DS1302_SCLK = 1; //拉高，制造上升沿，使位得以传输
    DS1302_SCLK = 0; //拉低，为下次传位做准备
  }
  // 完成通信，关闭通信使能位
  DS1302_CE = 0;
}