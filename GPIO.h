#ifndef __GPIO_H
#define __GPIO_H

/* 引入头文件 */
#include "s3c24xx.h"
/* 按键中断模式 */
#define GPF0_EINT (2 << (0 * 2))   // EINT0
#define GPF2_EINT (2 << (2 * 2))   // EINT2
#define GPG3_EINT (2 << (3 * 2))   // EINT11
#define GPG11_EINT (2 << (11 * 2)) // EINT19
/* 按键 Mask */
#define GPF0_msk (3 << (0 * 2))   // EINT0  Mask
#define GPF2_msk (3 << (2 * 2))   // EINT2  Mask
#define GPG3_msk (3 << (3 * 2))   // EINT11 Mask
#define GPG11_msk (3 << (11 * 2)) // EINT19 Mask
/* LED输出模式 */
#define GPF4_out (1 << (4 * 2))
#define GPF5_out (1 << (5 * 2))
#define GPF6_out (1 << (6 * 2))
/* LED Mask */
#define GPF4_msk (3 << (4 * 2))
#define GPF5_msk (3 << (5 * 2))
#define GPF6_msk (3 << (6 * 2))
/* LED DATA */
#define ALL_LED_OFF (7 << 4)
#define ALL_LED_ON ~(7 << 4)
#define GPF4_ON (1 << 4)
#define GPF5_ON (1 << 5)
#define GPF6_ON (1 << 6)
/* EINTMASK */
#define EINT11_ON (1 << 11)
#define EINT19_ON (1 << 19)
/* PRIORITY */
#define ARB_SEL0_ON (3 << 7)  // ARB_SEL0置一
#define ARB_MODE0_ON (1 << 0) // ARB_MODE0置一
/* INTMSK */
#define INTMSK_EINT0 (1 << 0)
#define INTMSK_EINT2 (1 << 2)
#define INTMSK_EINT8_23 (1 << 5)

/* 声明函数 */
void keys_Init();
void LEDs_Init();
void EINT_Init();
void EINT_Start();
void LED4_ON();
void LED5_ON();
void LED6_ON();
void LEDs_ON();
void LEDs_OFF();
#endif // !__GPIO_H
