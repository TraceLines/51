#include "reg52.h"

#include "lcd1602.h"
#include "AT24C02.h"

unsigned char ReadByteData = 0x11;
void main(void)
{
    LCD_init();
    // 先写，等待5MMS才能写完成
    AT24C02_WriteByte(1, 66);
    Delayx1m(50);
    // 再读
    ReadByteData = AT24C02_ReadByte(1);
    LCD_ShowString(1, 1, "hello");
    LCD_ShowNum(2, 1, ReadByteData, 3);

    while (1)
    {
    }
}
