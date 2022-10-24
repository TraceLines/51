/*
 * @Author: king jing
 * @Date: 2022-10-24 12:11:57
 * @LastEditTime: 2022-10-24 16:42:18
 * @Description: Do not edit
 */
#include "reg52.h"

// 公用功能库引入

#include "Public.h"

sbit LCD_EN = P2 ^ 7;
sbit LCD_RS = P2 ^ 6;
sbit LCD_WR = P2 ^ 5;

#define LCD_PORT P0

void LCD_WriteCommand(u8 Command)
{
  LCD_RS = 0;
  LCD_WR = 0;
  LCD_PORT = Command;
  LCD_EN = 1;
  // 还需要拉低EN，以释放使能，为下次使用准备。
  Delay1ms();
  LCD_EN = 0;
  Delay1ms();
}
void LCD_WriteData(u8 Data)
{
  LCD_RS = 1;
  LCD_WR = 0;
  LCD_PORT = Data;
  LCD_EN = 1;
  Delay1ms();
  LCD_EN = 0;
  Delay1ms();
}
/**
 * @description: LCD功能的初始化
 * @return {*}
 */
void LCD_init()
{
  //
  LCD_WriteCommand(0x38); // 8位数据接口，两行显示 5*7点阵
  LCD_WriteCommand(0x0c); //显示开，光标关，闪烁关
  LCD_WriteCommand(0x06); //数据读写操作后，光标自动加1，画片不移动
  LCD_WriteCommand(0x01); //清屏
}

/**
 * @description:
 * 1、设置光标位置，标注从哪里开始写，将给的行列号，转换为LCD内部的对应的DDRAM中的地址。
 * 2、数据显示区：LCD控制器内部带有80x8的RAM缓冲区，对应关系见手册中的图，而LCD的一个显示位，对应一个DDRAM中的地址里的值，图中的地址是实际地址，需要或上0x80代表操作DDRAM的命令，以达成正确的址。
 * 3、为何不用每次都操作光标，即写完一个后，不用每次都去移动一下光标，因为初始化时LCD_WriteCommand(0x06);，已经设置了读写后，AC自动加1，且不移动画面。
 * 4、只有在需要设置起始位置时，才需要调用次函数，后续会在读写后自动移动光标位置
 * @param {u8} Line
 * @param {u8} Column
 * @return {*}
 */
void LCD_SetCursor(u8 Line, u8 Column)
{
  if (Line == 1)
  {

    LCD_WriteCommand(0x80 | (Column - 1));
  }
  else
  {
    LCD_WriteCommand(0x80 | (0x3f + Column));
  }
}
/**
 * @description:单个字符的显示
 * @return {*}
 */
void LCD_ShowChar(u8 Line, u8 Column, u8 charts)
{
  LCD_SetCursor(Line, Column);
  LCD_WriteData(charts);
}

/**
 * @description: sting的显示
 * @param {u8} Line
 * @param {u8} Column
 * @param {u8} *Strings
 * @return {*}
 */
void LCD_ShowString(u8 Line, u8 Column, u8 *Strings)
{
  u16 i = 0;
  LCD_SetCursor(Line, Column);
  while (Strings[i] != '\0')
  {
    LCD_WriteData(Strings[i]);
    i++;
  }
}

/**
 * @description: 无符号数字显示
 * @param {u8} Line
 * @param {u8} Column
 * @param {u16} nums
 * @param {u8} length
 * @return {*}
 */
void LCD_ShowNum(u8 Line, u8 Column, u16 nums, u8 length)
{
  u16 i = 0;
  LCD_SetCursor(Line, Column);
  for (i = length; i > 0; i--)
  {
    LCD_WriteData('0' + nums / math_power(10, i - 1) % 10);
  }
}

/**
 * @description: 在LCD1602指定位置开始以有符号十进制显示所给数字
 * @param  Line 起始行位置，范围：1~2
 * @param  Column 起始列位置，范围：1~16
 * @param  Number 要显示的数字，范围：-32768~32767
 * @param  Length 要显示数字的长度，范围：1~5
 * @return {*}元
 */
/**
 * @description: 在LCD1602指定位置开始以有符号十进制显示所给数字
 * @param {u8} Line 起始行位置，范围：1~2
 * @param {u8} Column 始列位置，范围：1~16
 * @param {int} nums 要显示的数字，范围：-32768~32767，
 * @param {u8} length
 * @return {*}
 */
void LCD_ShowSignedNums(u8 Line, u8 Column, int nums, u8 length)
{
  u8 i;
  u16 Number;
  LCD_SetCursor(Line, Column);

  if (nums >= 0)
  {
    LCD_WriteData('+');
    Number = nums;
  }
  else
  {
    LCD_WriteData('-');
    Number = -nums;
  }
  for (i = length; i > 0; i--)
  {
    LCD_WriteData('0' + Number / math_power(10, i - 1) % 10);
  }
}

/**
 * @description: 在LCD1602指定位置开始以十六进制显示所给数字
 * @param {unsigned char} Line
 * @param {unsigned char} Column
 * @param {unsigned int} Number
 * @param {unsigned char} Length
 * @return {*}
 */
void LCD_ShowHexNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length)
{
  unsigned char i;
  unsigned char SingleNumber;
  LCD_SetCursor(Line, Column);
  for (i = Length; i > 0; i--)
  {
    SingleNumber = Number / math_power(16, i - 1) % 16;
    if (SingleNumber < 10)
    {
      LCD_WriteData('0' + SingleNumber);
    }
    else
    {
      LCD_WriteData('A' + SingleNumber - 10);
    }
  }
}

/**
 * @description:在LCD1602指定位置开始以二进制显示所给数字
 * @param {unsigned char} Line
 * @param {unsigned char} Column
 * @param {unsigned int} Number
 * @param {unsigned char} Length
 * @return {*}无
 */
void LCD_ShowBinNum(unsigned char Line, unsigned char Column, unsigned int Number, unsigned char Length)
{
  unsigned char i;
  LCD_SetCursor(Line, Column);
  for (i = Length; i > 0; i--)
  {
    LCD_WriteData('0' + Number / math_power(2, i - 1) % 2);
  }
}
