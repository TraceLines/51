/*
 * @Author: king jing
 * @Date: 2022-10-19 17:08:32
 * @LastEditTime: 2022-10-19 21:58:37
 * @Description: UART通信
 */
#include "uart.h"

void UsartInit()
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

// void Usart() interrupt 4
// {
//   // u8 receiveData;

//   // receiveData = SBUF; //出去接收到的数据
//   // RI = 0;             //清除接收中断标志位
//   // SBUF = receiveData; //将接收到的数据放入到发送寄存器
//   UART_SINGAL_LED = 0;
//   while (!TI)
//     ; //等待发送数据完成
//   UART_SINGAL_LED = 1;
//   TI = 0; //清除发送完成标志位
// }
void UART_sendData(u8 *dataArr)
{
  u8 i;
  u8 dataLen = sizeof(dataArr);
  for (i = 0; i < dataLen; i++)
  {
    UART_SINGAL_LED = 0;
    SBUF = dataArr[i];
    while (!TI)
      ;
    UART_SINGAL_LED = 1;
    TI = 0;
  }
}
// void UART_ReciveData() {}