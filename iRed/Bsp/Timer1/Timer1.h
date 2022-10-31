/*
 * @Author: king jing
 * @Date: 2022-10-31 16:37:59
 * @LastEditTime: 2022-10-31 22:52:05
 * @Description: Do not edit
 */
#ifndef __BSP_TIMER1_H__
#define __BSP_TIMER1_H__

void Timer1_init();
void Timer1_setCounter(unsigned int Value);
unsigned int Timer1_getCounter();
void Timer1_run(unsigned char Flag);

#endif