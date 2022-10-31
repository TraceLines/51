/*
 * @Author: king jing
 * @Date: 2022-10-24 14:29:39
 * @LastEditTime: 2022-10-27 16:10:28
 * @Description: Do not edit
 */

#include "intrins.h"

void Delay1ms() //@11.0592MHz
{
  unsigned char i, j;

  _nop_();
  i = 2;
  j = 199;
  do
  {
    while (--j)
      ;
  } while (--i);
}

void Delayx1m(unsigned int xms) //@11.0592MHz
{
  unsigned char i, j;
  while (xms--)
  {
    i = 2;
    j = 199;
    do
    {
      while (--j)
        ;
    } while (--i);
  }
}
void Delay(unsigned int t)
{
  while (t--)
    ;
}

unsigned int math_power(unsigned char base, unsigned char expo)
{
  unsigned char result = 1;
  unsigned char i;
  for (i = 0; i < expo; i++)
  {
    result *= base;
  }
  return result;
}
