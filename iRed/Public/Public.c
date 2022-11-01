/*
 * @Author: king jing
 * @Date: 2022-10-24 14:29:39
 * @LastEditTime: 2022-11-01 12:38:00
 * @Description: Do not edit
 */

#include "intrins.h"
#include "Public.h"

void Delay1ms() //@11.0592MHz
{
  unsigned char i, j;

  _nop_();
  i = 2;
  j = 239;
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
    j = 239;
    do
    {
      while (--j)
        ;
    } while (--i);
  }
}

u16 math_power(u8 base, u8 expo)
{
  u8 result = 1;
  u8 i;
  for (i = 0; i < expo; i++)
  {
    result *= base;
  }
  return result;
}
