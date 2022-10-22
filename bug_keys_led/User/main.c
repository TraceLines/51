/*
 * @Author: king jing
 * @Date: 2022-10-18 16:30:03
 * @LastEditTime: 2022-10-21 16:10:17
 * @Description: Do not edit
 */
#include "reg52.h"
#include "smg.h"
#include "key.h"
#include "uart.h"

// sbit LED_md = P2 ^ 0;
#define GPIO_DIG P0
extern u8 keyValue;
extern u8 gsmg_code[17];
void main(void)
{
	//u8 keyArrs[2];
	// u8 keybitPos;
	u8 initValue[4] = {5, 6, 4, 9};
	// LED_md = 0;
	// Delay10us(1);
	// Delay1ms(2);
	// 按键测试
	// UsartInit();
	// keyValue = -1;
	// 这种方法行不能，每次循环完之后，再次进入循环，keyvalue的值可能为空，不稳定。
	// keyValue的值,，即要被数码管显示的值，应该放在循环之外，是个全局变量，handleKeyPress时，可以去改变这个值，但涉及到不同文件间共用一个全局值的问题。extern能解决吗？
	// 这样在这个循环里，LED_display每次去拿的值，都是keyValue的最新值，保证按钮按下后，可以切换值，且不会熄灭或不稳定。
	// handleKeyPress这个值就不应该有返回值，
	while (1)
	{
		KeyDown();
		// if (keyValue >= 0)
		// {

		// if (keyValue < 10)
		// {
		// 	keybitPos = 7;
		// 	keyArrs[0] = keyValue;
		// }
		// else
		// {
		// 	keybitPos = 6;
		// 	keyArrs[0] = keyValue / 10;
		// 	keyArrs[1] = keyValue % 10;
		// }
		// }
		// LED_display(keybitPos, keyArrs);
		LED_display(4, initValue);
		// GPIO_DIG = ~gsmg_code[keyValue];
	}
}
