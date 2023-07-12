#include "timer.h"

/*
 * Timer input clock Frequency = PCLK / {prescaler value+1} / {divider value}
 * {prescaler value} = 0~255
 * {divider value} = 2, 4, 8, 16
 * 本实验的Timer0的时钟频率=100MHz/(99+1)/(16)=62500Hz
 * 设置Timer0 0.5秒钟触发一次中断：
 */

/* 初始化定时器0 */
void TIM0_Init(void)
{
    TCFG0 = 99;                 // TCFG0_Value = 99
    TCFG1 = TCFG1_TIM0_16;      // 16分频
    TCNTB0 = 31250;             // TCNTB0_Value = 31250
    TCON |= TCON_TIMER0_RELOAD; // 手动更新
    TCON = TCON_TIMER0_ENABLE;  // 启动定时器0
}

/* 开启定时器0 */
void TIM0_STart(void)
{
    INTMSK &= ~INTMSK_TIMER0; // 定时器0中断使能
}

/* 停止定时器0 */
void TIM0_Stop(void)
{
    INTMSK |= INTMSK_TIMER0;
}
