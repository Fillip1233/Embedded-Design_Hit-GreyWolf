/*
 * FILE: lcdlib.c
 * 实现TFT LCD的测试函数
 */

#include <stdio.h>
#include "lcddrv.h"
#include "framebuffer.h"
#include "images.h"
int windowstate=0;
/* 
 * 以480x272,16bpp的显示模式测试TFT LCD
 */
void Test_Lcd_Tft_16Bit_480272(void)
{
    Lcd_Port_Init();                     // 设置LCD引脚
    Tft_Lcd_Init(MODE_TFT_16BIT_480272); // 初始化LCD控制器
    Lcd_PowerEnable(0, 1);               // 设置LCD_PWREN有效，它用于打开LCD的电源
    Lcd_EnvidOnOff(1);                   // 使能LCD控制器输出信号

    // picture_show(prule);
    // ClearScr(0x0);  // 清屏，黑色
    while(windowstate!=2)
    {
        if(windowstate==0)
            picture_show(selfphoto);//个人信息
        if(windowstate==1)
            picture_show(prule);//游戏规则
    }
    picture_show(yangchun);//游戏主页面
    judge_num(20);//分数初始化
    game();//进入游戏
    Lcd_EnvidOnOff(0);
}

