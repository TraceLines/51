/*
 * @Author: king jing
 * @Date: 2022-10-24 12:11:12
 * @LastEditTime: 2022-10-24 16:52:50
 * @Description: Do not edit
 */

#include "lcd1602.h"
#include "Public.h"
void main()
{

  LCD_init();

  LCD_ShowChar(1, 1, 'B');
  LCD_ShowString(1, 3, "Welcom to guangdong!");
  LCD_ShowNum(2, 1, 234, 3);
  LCD_ShowSignedNums(2, 5, 84, 2);
  // LCD_ShowHexNum(2, 9, 0xF1, 2);
  LCD_ShowBinNum(2, 9, 0xA5, 8);

  while (1)
  {
    /* code */
    LCD_WriteCommand(0x18);
    Delayx1m(1000);
  }
}