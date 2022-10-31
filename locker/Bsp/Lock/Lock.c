/*
 * @Author: king jing
 * @Date: 2022-10-25 20:27:12
 * @LastEditTime: 2022-10-26 09:04:38
 * @Description: Do not edit
 */
#include "reg52.h"
#include "Public.h"

#include "lcd1602.h"
#include "MatrixKey.h"

u8 charactersPair[16][2] = {{0x81, 'A'},
                            {0x82, 3},
                            {0x84, 2},
                            {0x88, 1},
                            {0x41, 'B'},
                            {0x42, 6},
                            {0x44, 5},
                            {0x48, 4},
                            {0x21, 'C'},
                            {0x22, 9},
                            {0x24, 8},
                            {0x28, 7},
                            {0X11, 'D'},
                            {0X12, '#'},
                            {0X14, '0'},
                            {0X18, '*'}};
u8 password[4] = {1, 2, 3, 4};
u8 inputPassword[4];
// 输入位
u8 inputLocal;
u8 column = 1;    //显示位置
u8 keyStatus = 0; //键盘状态0:默认输入，1:密码重置

/**
 * @description: 欢迎界面以及初始化
 * @return {*}
 */
void locker_init(u8 *tipsString)
{
  keyStatus = 0;
  inputLocal = 0;
  LCD_Clear();
  LCD_ShowString(1, 1, tipsString);
}

/**
 * @description: 设置-密码设置入口
 * @return {*}
 */
void locker_passwordSet()
{
  keyStatus = 1;
  inputLocal = 0;
  LCD_Clear();
  LCD_ShowString(1, 1, "input:");
}
/**
 * @description:获取键盘的键值
 * @param {u8} keyPosition
 * @return {*}
 */
u8 getsmgNum(u8 keyPosition)
{
  u8 theNum;
  int i;
  for (i = 0; i < 16; i++)
  {
    if (keyPosition == charactersPair[i][0])
    {
      theNum = charactersPair[i][1];
      break;
    }
  }
  return theNum;
}
/**
 * @description: 输入确认
 * @return {*}
 */
void locker_confirm()
{
  u8 i;
  if (keyStatus) //密码重置，成功提示
  {
    Delayx1m(1000);
    locker_init("done!");
  }
  else //输入确认，比较密码
  {
    for (i = 0; i < 4; i++)
    {
      if (inputPassword[i] != password[i])
      {
        LCD_ShowString(1, 13, "err!");
        return;
      }
    }
    locker_init("Welcome");
  }
}

/**
 * @description: 设置-取消密码设置
 * @return {*}
 */
void locker_cancelSet()
{
}

/**
 * @description: 设置-删除所设置的密码位
 * @return {*}
 */
void locker_deleteSetBit()
{
}

/**
 * @description: 输入密码检查
 * @return {*}
 */
void locker_checkPassword()
{
}

/**
 * @description:
 * @return {*}
 */
void handleLockerStatus()
{
  u8 keyPosition, KeyValue;
  keyPosition = handleKeyPress();
  if (keyPosition)
  {
    KeyValue = getsmgNum(keyPosition);
    if (KeyValue <= 9) //数字处理
    {
      if (inputLocal >= 4)
      {
        return;
      }
      LCD_ShowNum(2, inputLocal + 1, KeyValue, 1);
      if (keyStatus)
      {
        password[inputLocal] = KeyValue;
      }
      else
      {
        inputPassword[inputLocal] = KeyValue;
      }
      inputLocal++;
    }
    else //字符处理
    {
      switch (KeyValue)
      {
      case 'A': //设置密码
        locker_passwordSet();
        break;
      case 'B': //返回输入密码界面
        locker_init("password:");
        break;
      case 'D': //输入确认
        /* code */
        locker_confirm();
        break;
      case 'C': //取消设置
        locker_init("password:");
        break;
      default:
        break;
      }
      // LCD_ShowChar(1, column, KeyValue);
    }
  }
}
