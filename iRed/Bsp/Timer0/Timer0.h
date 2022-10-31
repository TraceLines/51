/*
 * @Author: king jing
 * @Date: 2022-10-31 16:37:59
 * @LastEditTime: 2022-10-31 17:34:37
 * @Description: Do not edit
 */
#ifndef __BSP_TIMER0_H__
#define __BSP_TIMER0_H__

void Timer0_init();
void Timer0_setCounter(unsigned int Value);
unsigned int Timer0_getCounter();
void Timer0_run(unsigned char Flag);


#endif