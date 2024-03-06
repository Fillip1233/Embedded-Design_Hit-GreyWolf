#include <stdio.h>
#include "serial.h"
#include "lcdlib.h"
#include "s3c24xx.h"
#include "timer.h"

int main()
{
    while (1)
    {
        keys_Init();//按键初始化
	    LEDs_Init();//LED灯初始化
	    EINT_Init();//中断初始化
        EINT_Start();//开启中断
        Test_Lcd_Tft_16Bit_480272();//进入主页面
    }
    return 0;
}
