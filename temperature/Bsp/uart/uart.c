/*
 * @Author: king jing
 * @Date: 2022-10-21 22:45:20
 * @LastEditTime: 2022-10-22 18:11:02
 * @Description: UART串行通信驱动
 */

#include "uart.h"

void usart_init()
{
  SCON = 0X50; //设置为工作方式1
  TMOD = 0X20; //设置计数器工作方式2
  PCON = 0X80; //波特率加倍
  TH1 = 0XFD;  //计数器初始值设置，注意波特率是4800的
  TL1 = 0XFD;
  ES = 1;  //打开接收中断
  EA = 1;  //打开总中断
  TR1 = 1; //打开计数器
}

void uart_interrupt() interrupt 4
{
  // u8 receiveData;

  // receiveData = SBUF; //出去接收到的数据
  // RI = 0;             //清除接收中断标志位
  // SBUF = receiveData; //将接收到的数据放入到发送寄存器
  UART_SINGAL_LED = 0;
  while (!TI)
    ; //等待发送数据完成
  UART_SINGAL_LED = 1;
  TI = 0; //清除发送完成标志位
}