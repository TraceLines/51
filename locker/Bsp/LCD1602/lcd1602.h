/*
 * @Author: king jing
 * @Date: 2022-10-24 12:12:05
 * @LastEditTime: 2022-10-25 21:54:42
 * @Description: LCD1620驱动程序 模拟Arduino中的功能，实现接口调用以使用LCD1602
 */
#ifndef __LCD1602_H__
#define __LCD1602_H__

// LCD命令操作函数
void LCD_WriteCommand(unsigned char Command);
// 功能函数
void LCD_init();
void LCD_ShowChar(unsigned char Line, unsigned char Column, unsigned char charts);
void LCD_ShowString(unsigned char Line, unsigned char Column, unsigned char *Strings);
void LCD_ShowNum(unsigned char Line, unsigned char Column, unsigned int nums, unsigned char length);
void LCD_ShowSignedNums(unsigned char Line, unsigned char Column, int nums, unsigned char length);

// 清屏
void LCD_Clear();
//不是我写的
void LCD_ShowHexNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);
void LCD_ShowBinNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length);
#endif