/*
 * @Author: king jing
 * @Date: 2022-10-21 16:56:21
 * @LastEditTime: 2022-10-22 15:27:48
 * @Description: DS18B20的驱动程序
 */
#include "DS18B20.h"
#include "intrins.h"
/**
 * @description: 初始化DS18B20器件
 * @return {*}
 */

void ds18b20_reset()
{
  u8 i = 70;
  DSPORT = 0; //将总线拉低480us~960us
  while (i--)
    ;         //延时642us //延时642us --事实上可能是100多微秒，不是600多
  DSPORT = 1; //然后拉高总线，如果DS18B20做出反应会将在15us~60us后总线拉低
  Delay10us_times(60);
}
/**
 * @description:检测DS18B20是否存在
 * @return {success:0, fail:1}
 */
u8 ds18b20_check()
{
  int i = 0;

  while (DSPORT && i < 20) //等待DS18B20拉低总线，即时序图上的低电平检测，等待设置一个时间限制，等跳出
  {
    i++;
    Delay10us_times(20);
  }
  if (i >= 20)
    return 1; //没有检测到低电平，返回检测失败
  else
    i = 0; //检没到时序图中的低电平，接下来检测高电平
  while (!DSPORT && i < 20)
  {
    i++;
    Delay10us_times(15);
  }
  if (i >= 20)
    return 1; //没有检测到低电平，返回检测失败
  return 0;
}
/**
 * @description: DS18B20初始化
 * @return {sucess:0,fail:1}
 */
u8 ds18b20_initial()
{
  void ds18b20_reset();
  return ds18b20_check();
}
/**
 * @description:向18B20写入一个字节
 * @param {u8} dat,要写入的字节
 * @return {*}
 */
void ds18b20_write_byte(u8 dat)
{
  u8 i;
  u8 temp = 0;
  // 一个字节8个位，建立一个for循环，将8个位依次写出去。根据时序图特殊，并进行适当延时。
  for (i = 0; i < 8; i++)
  {
    temp = dat & 0x01;
    dat >>= 1;
    if (temp) //写1的时序
    {
      DSPORT = 0;
      _nop_();
      _nop_();
      DSPORT = 1;
      // 将PORT端口拉高之后，进行延时，以被DS18B20采集到数据
      Delay10us_times(6);
    }
    else //写0的时序
    {
      DSPORT = 0;
      // 写0时序，直接进行延时
      Delay10us_times(7);
      // 拉高端口，释放总线
      DSPORT = 1;
      _nop_();
      _nop_();
    }
  }
}

u8 ds18b20_read_byte()
{
  u8 temp = 0;
  u8 i;
  for (i = 0; i < 8; i++)
  {
    DSPORT = 0;
    _nop_();
    _nop_();
    Delay10us_times(1);
    temp = DSPORT;
    temp >>= 1;
    temp |= temp << 7;
    Delay10us_times(5);
    DSPORT = 1;
    _nop_();
    _nop_();
  }
  return temp;
}

float ds18b20_read_temperature()
{
  u8 tempH, tempL;
  u8 tempValue;
  float temNum;
  // 读步骤：复位，可以增加一个判断，判断这个器件是否存在
  ds18b20_initial();
  //
  ds18b20_write_byte(0xcc);
  ds18b20_write_byte(0x44);
  Delay10us();
  ds18b20_reset();
  ds18b20_write_byte(0xcc);
  ds18b20_write_byte(0xBE);
  tempL = ds18b20_read_byte();
  tempH = ds18b20_read_byte();
  tempValue = tempH << 8 | tempL;
  if (tempValue & 0xf800 == 0xf800)
  {
    tempValue = ~tempValue + 1;
    temNum = tempValue * 0.0625;
  }
  else
  {
    temNum = tempValue * 0.0625;
  }
  return temNum;
}
