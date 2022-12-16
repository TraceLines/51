/*
 * @Author       :
 * @Date         : 2022-12-16 10:47:17
 * @LastEditors  : miduoduo
 * @LastEditTime : 2022-12-16 13:39:51
 * @FilePath     : \AT24C02\Bsp\I2C\I2C.H
 */
#ifndef __BSP_I2C_H__
#define __BSP_I2C_H__

// 函数声明
void I2C_Start(void);
void I2C_Stop(void);
void I2C_SendByte(unsigned char Byte);
unsigned char I2C_ReceiveByte(void);
void I2C_SendACK(unsigned char AckBit);
unsigned char I2C_ReceiveACK(void);

#endif