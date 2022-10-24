/*
 * @Author: king jing
 * @Date: 2022-10-21 22:45:25
 * @LastEditTime: 2022-10-22 18:11:53
 * @Description: 串行通信接口
 *
 */
#ifndef __BSP_UART_H

#define __BSP_UART_H

#include "reg52.h"
#include "Public.h"

sbit UART_SINGAL_LED = P2 ^ 1;

void usart_init();
#endif