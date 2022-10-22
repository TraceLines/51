/*
 * @Author: king jing
 * @Date: 2022-10-21 15:12:07
 * @LastEditTime: 2022-10-21 15:45:54
 * @Description: Do not edit
 */
#ifndef __BSP_I2C_H

#define __BSP_I2C_H

#include "reg52.h"
#include "Public.h"

sbit SCL = P2 ^ 1;
sbit SDA = P2 ^ 0;

void I2cStart();
void I2cStop();
unsigned char I2cSendByte(unsigned char dat);
unsigned char I2cReadByte();
void At24c02Write(unsigned char addr, unsigned char dat);
unsigned char At24c02Read(unsigned char addr);

#endif