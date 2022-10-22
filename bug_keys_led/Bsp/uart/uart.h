/*
 * @Author: king jing
 * @Date: 2022-10-19 17:09:06
 * @LastEditTime: 2022-10-19 22:00:03
 * @Description: Do not edit
 */

#ifndef __BSP_UART_H
#define __BSP_UART_H
#include "reg52.h"
#include "Public.h"

sbit UART_SINGAL_LED = P2 ^ 7;

void UsartInit();
void UART_sendData(u8 *dataArr);
// void UART_ReciveData();
#endif