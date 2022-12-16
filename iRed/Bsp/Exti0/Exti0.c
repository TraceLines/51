/*
 * @Author: king jing
 * @Date: 2022-10-31 16:38:36
 * @LastEditTime: 2022-11-01 12:35:27
 * @Description: 外部中断驱动
 */

#include "reg52.h"
/**
 * @description: 使能外部中断0的
 * @return {*}
 */
void Exti0_init()
{
  // IT0 = 1;
  // EX0 = 1;
  // EA = 1;
  IT0 = 1;
  IE0 = 0;
  EX0 = 1;
  EA = 1;
  PX0 = 1;
}
