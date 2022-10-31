/*
 * @Author: king jing
 * @Date: 2022-10-25 20:53:30
 * @LastEditTime: 2022-10-25 21:03:43
 * @Description: 中断配置
 */

#include "reg52.h"
/**
 * @description: 开启外部中断，以及初始化
 * @return {*}
 */
void exti_init()
{
  // 电平触发
  IE0 = 1;
  IE1 = 1;
  EX0 = 1;
  EX1 = 1;
  EA = 1;
}