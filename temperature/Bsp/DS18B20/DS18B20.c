/*
 * @Author: king jing
 * @Date: 2022-10-21 16:56:21
 * @LastEditTime: 2022-10-25 11:47:29
 * @Description: DS18B20的驱动程序
 */
// #include "DS18B20.h"
// #include "intrins.h"

#include "Public.h"
#include "onewire.h"
#include "LCD1602.h"
// define the command
#define DS18B20_SKIP_ROM 0XCC
#define DS18B20_CONVERT_T 0X44
#define DS18B20_READ_SCRATCHPAD 0xBE

void DS18B20_convertT()
{
  oneWire_init();
  oneWire_sendByte(DS18B20_SKIP_ROM);
  oneWire_sendByte(DS18B20_CONVERT_T);
}

float DS18B20_readT()
{
  u8 TLSB, TMSB;
  float T;
  int temp;
  oneWire_init();
  oneWire_sendByte(DS18B20_SKIP_ROM);
  oneWire_sendByte(DS18B20_READ_SCRATCHPAD);
  TLSB = oneWire_receiveByte();
  TMSB = oneWire_receiveByte();

  LCD_ShowBinNum(1, 1, TMSB, 8);
  LCD_ShowBinNum(1, 9, TLSB, 8);

  temp = (TMSB << 8) | TLSB;
  T = temp / 16.0;
  return T;
}