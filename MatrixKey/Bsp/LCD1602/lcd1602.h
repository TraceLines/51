/*
 * @Author: king jing
 * @Date: 2022-10-24 12:12:05
 * @LastEditTime: 2022-10-24 16:50:04
 * @Description: LCD1620驱动程序 模拟Arduino中的功能，实现接口调用以使用LCD1602
 */
#ifndef __LCD1602_H__
#define __LCD1602_H__

#include "Public.h"

// LCD命令操作函数
void LCD_WriteCommand(u8 Command);
// 功能函数
void LCD_init();
void LCD_ShowChar(u8 Line, u8 Column, u8 charts);
void LCD_ShowString(u8 Line, u8 Column, u8 *Strings);
void LCD_ShowNum(u8 Line, u8 Column, u16 nums, u8 length);
void LCD_ShowSignedNums(u8 Line, u8 Column, int nums, u8 length);
//不是我写的
void LCD_ShowHexNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);
void LCD_ShowBinNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);
#endif