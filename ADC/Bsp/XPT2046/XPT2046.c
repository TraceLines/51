/*
 * @Author: king jing
 * @Date: 2022-10-31 09:28:34
 * @LastEditTime: 2022-10-31 09:40:05
 * @Description: PT2046驱动程序
 */

#include "reg52.h"

sbit XPT2046_DIN = P3 ^ 4;
sbit XPT2046_CS = P3 ^ 5;
sbit XPT2046_DCLK = P3 ^ 6;
sbit XPT2046_DOUT = P3 ^ 7;
