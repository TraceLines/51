<!--
 * @Author: king jing
 * @Date: 2022-10-27 17:48:17
 * @LastEditTime: 2022-10-27 17:52:56
 * @Description: Do not edit
-->
```
void Timer0_interrupt() interrupt 1 // 每100us时间会进入这个中断函数中
{
  // LED1 = ~LED1;
  TL0 = 0xA4; // 设置定时初始值
  TH0 = 0xFF; // 设置定时初始值
  counter++;
  counter %= 100;
  if (counter < 5) 
  {
    LED1 = 0;
  }
  else
  {
    LED1 = 1;
  }
}
```

＿＿＿＿＿|￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣.... //100us进来产生一个电平，这些电平共计100个，所以一个周期时间为100*100us = 10ms。
改变counter的值，可以控制高电平的占空比。