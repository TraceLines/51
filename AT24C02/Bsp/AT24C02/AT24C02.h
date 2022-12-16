#ifndef __BSP_AT24C02_H__
#define __BSP_AT24C02_H__

void AT24C02_WriteByte(unsigned char WordAddress, ByteData);
unsigned char AT24C02_ReadByte(unsigned char WordAddress);
#endif