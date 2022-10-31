/*
 * @Author: king jing
 * @Date: 2022-10-31 17:36:49
 * @LastEditTime: 2022-10-31 17:42:24
 * @Description: Do not edit
 */
/*
 * @Author: king jing
 * @Date: 2022-10-31 17:36:49
 * @LastEditTime: 2022-10-31 17:42:04
 * @Description: Do not edit
 */
#include "reg52.h"

#include "LCD1602.h"
#include "Exti0.h"
#include "Timer0.h"
#include "Public.h"

unsigned int IR_Time;
unsigned char IR_State;

unsigned char IR_Data[4];
unsigned char IR_indexData;

unsigned char IR_DataFlag;
unsigned char IR_RepeatFlag;
unsigned char IR_Address;
unsigned char IR_Command;

void iRed_init()
{
  LCD_init();
  Timer0_init();
  Exti0_init();
}
void Exti0_interrupt() interrupt 0
{
  P2 = 0;
}