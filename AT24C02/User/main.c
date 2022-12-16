#include "reg52.h"

#include "lcd1602.h"

void main(void)
{
    LCD_init();
    LCD_ShowString(1, 1, "hello world");
    while (1)
    {
    }
}
