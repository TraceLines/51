/*
 * @Author: king jing
 * @Date: 2022-10-31 16:38:36
 * @LastEditTime: 2022-10-31 16:49:50
 * @Description: 外部中断驱动
 */

#include "reg52.h"
/**
 * @description: 使能外部中断0的
 * @return {*}
 */
void Exti0_init()
{
  IT0 = 1;
  EX0 = 1;
  EA = 1;
}

