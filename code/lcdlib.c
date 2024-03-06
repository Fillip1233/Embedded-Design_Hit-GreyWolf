/*
 * FILE: lcdlib.c
 * ʵ��TFT LCD�Ĳ��Ժ���
 */

#include <stdio.h>
#include "lcddrv.h"
#include "framebuffer.h"
#include "images.h"
int windowstate=0;
/* 
 * ��480x272,16bpp����ʾģʽ����TFT LCD
 */
void Test_Lcd_Tft_16Bit_480272(void)
{
    Lcd_Port_Init();                     // ����LCD����
    Tft_Lcd_Init(MODE_TFT_16BIT_480272); // ��ʼ��LCD������
    Lcd_PowerEnable(0, 1);               // ����LCD_PWREN��Ч�������ڴ�LCD�ĵ�Դ
    Lcd_EnvidOnOff(1);                   // ʹ��LCD����������ź�

    // picture_show(prule);
    // ClearScr(0x0);  // ��������ɫ
    while(windowstate!=2)
    {
        if(windowstate==0)
            picture_show(selfphoto);//������Ϣ
        if(windowstate==1)
            picture_show(prule);//��Ϸ����
    }
    picture_show(yangchun);//��Ϸ��ҳ��
    judge_num(20);//������ʼ��
    game();//������Ϸ
    Lcd_EnvidOnOff(0);
}

