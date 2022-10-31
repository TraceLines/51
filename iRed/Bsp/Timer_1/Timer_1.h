/*
 * @Author: king jing
 * @Date: 2022-10-31 21:43:47
 * @LastEditTime: 2022-10-31 21:55:55
 * @Description: Do not edit
 */
#ifndef __BSP_TIMER1_H__
#define __BSP_TIMER1_H__

void Timer1_Init();
void Timer1_SetCounter(unsigned int Value);
unsigned int Timer1_GetCounter();
void Timer1_Run(unsigned char Flag);

#endif