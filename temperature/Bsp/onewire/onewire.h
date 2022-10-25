/*
 * @Author: king jing
 * @Date: 2022-10-25 08:54:24
 * @LastEditTime: 2022-10-25 11:20:33
 * @Description: Do not edit
 */
#ifndef __BSP_ONEWIRE_H

#define __BSP_ONEWIRE_H

u8 oneWire_init();
// handle the bit
void oneWire_sendBit(u8 chartBit);
u8 oneWire_receiveBit();
// handle the byte
void oneWire_sendByte(u8 charByte);
u8 oneWire_receiveByte();
#endif