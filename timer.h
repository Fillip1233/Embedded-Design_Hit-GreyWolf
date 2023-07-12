#ifndef __TIMER_H
#define __TIMER_H
/* 引入头文件 */
#include "s3c24xx.h"
/* INTMSK */
#define INTMSK_TIMER0 (1 << 10)
#define TCFG1_TIM0_16 (3 << 0) // 16分频
#define TCON_TIMER0_RELOAD (1 << 1)
#define TCON_TIMER0_ENABLE (9 << 0) // 开启定时器0和死区
/* 声明函数 */
void TIM0_Init(void);
void TIM0_STart(void);
void TIM0_Stop(void);

#endif // !__TIMER_H
