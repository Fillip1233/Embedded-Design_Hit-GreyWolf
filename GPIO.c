#include "GPIO.h"
#include"interrupt.h"
extern void (*isr_handle_array[50])(void);
/*
    初始化GPIO
        GPF0(s2),GPF2(s3),GPG3(s4),GPG11(s5)
        GPF4(D10),GPF5(D11),GPF6(D12)
*/

void keys_Init()
{
    GPFCON &= ~(GPF0_msk | GPF2_msk);  // 清空GPFCON[1:0]、[5:4]
    GPFCON |= GPF0_EINT | GPF2_EINT;   // 设置GPF0和GPF2为中断模式
    GPGCON &= ~(GPG3_msk | GPG11_msk); // 清空 GPGCON[7:6]、[23:22]
    GPGCON |= GPG3_EINT | GPG11_EINT;  // 设置GPG3和GPG11模式为EINT
}

void LEDs_Init()
{
    GPFCON &= ~(GPF4_msk | GPF5_msk | GPF6_msk); // 清空GPFCON[13:8]
    GPFCON |= GPF4_out | GPF5_out | GPF6_out;    // 设置GPF4~GPF6为输出模式
    LEDs_OFF();                                  // 设置LED状态为关闭
}

void EINT_Init()
{
    EINTMASK &= ~(EINT11_ON | EINT19_ON);
    PRIORITY &= ~(ARB_SEL0_ON | ARB_MODE0_ON);
    isr_handle_array[ISR_EINT0_OFT] = EINT0_Handle;
    isr_handle_array[ISR_EINT2_OFT] = EINT2_Handle;
    isr_handle_array[ISR_EINT8_23_OFT] = EINT8_23_Handle;
    isr_handle_array[ISR_TIMER0_OFT] = Timer0_Handle;
}

void EINT_Start()
{
    INTMSK &= ~(INTMSK_EINT0 | INTMSK_EINT2 | INTMSK_EINT8_23);
}
/* 开LED4 */
void LED4_ON()
{
    GPFDAT &= ~GPF4_ON;
}
/* 开LED5 */
void LED5_ON()
{
    GPFDAT &= ~GPF5_ON;
}
/* 开LED6 */
void LED6_ON()
{
    GPFDAT &= ~GPF6_ON;
}
/* 开所有LED */
void LEDs_ON()
{
    GPFDAT &= ALL_LED_ON;
}
/* 关所有LED */
void LEDs_OFF()
{
    GPFDAT |= ALL_LED_OFF;
}
