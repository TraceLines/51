/*
 * @Author: king jing
 * @Date: 2022-10-26 15:08:01
 * @LastEditTime: 2022-10-26 17:07:52
 * @Description: Do not edit
 */
#ifndef __BSP_DS1302_H__
#define __BSP_DS1302_H__

unsigned char DS1302_readByte(unsigned char command);
void DS1302_writeByte(unsigned char command, unsigned char d_byte);
#endif