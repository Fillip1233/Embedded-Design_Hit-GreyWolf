#include "s3c24xx.h"
#include"framebuffer.h"
extern int hole,hit,exit,windowstate,usetime;
extern const char gexit[42966],lossshow[260576],noexit[42966];
//extern void I2CIntHandle(void);

void (*isr_handle_array[50])(void);

void Dummy_isr(void)
{
    while(1);
}

void init_irq(void)
{
    int i = 0;
    for (i = 0; i < sizeof(isr_handle_array) / sizeof(isr_handle_array[0]); i++)
    {
        isr_handle_array[i] = Dummy_isr;
    }

    INTMOD = 0x0;	      // 所有中断都设为IRQ模式
    INTMSK = BIT_ALLMSK;  // 先屏蔽所有中断

//	isr_handle_array[ISR_IIC_OFT]  = I2CIntHandle;
}

void EINT0_Handle(void)
{
    if(exit==1)//退出键按下
    {
        exit=0;//确认退出

    }
    else if(hole==1)//1号洞有狼
        hit=1;//击打
    if(windowstate==1)//规则显示页面
        windowstate=0;//返回个人信息页
}

void EINT2_Handle(void)
{
    if(exit==1)//退出键按下
    {
        exit++;//取消退出
        show_exit(noexit);
    }
    if(hole==2)//2号洞有狼
        hit=1;//击打
    if(windowstate==0)//个人信息显示页面
        windowstate=1;//进入规则显示页面
}

void EINT8_23_Handle(void)
{
    unsigned long val = EINTPEND;
    if (val & (1 << 11))
    {
        if(windowstate==1)//规则显示页面
            windowstate=2;//进入游戏
        if(hole==3)//3号洞有狼
            hit=1;//击打
    }
    else if (val & (1 << 19))
    {
        if(windowstate==1)//规则显示页面
            windowstate=2;//进入游戏
        if(windowstate==2&&usetime>5)//以及进入游戏
        {
            unsigned long oft = INTOFFSET;
            show_exit(gexit);//显示退出页面
            EINTPEND=(1<<19);//清除本次中断，等待退出确认
            SRCPND = 1<<oft;	
	        INTPND = INTPND;
            exit=1;//进入退出确认
            exit_wait();//等待退出确认
        }
    }
    EINTPEND = (1 << 11) | (1 << 19);
}

void Timer0_Handle(void)
{
    usetime+=1;//计时增加
    UINT32 x;
    UINT32 color;
    int j=0;
    for (x = 0; x < usetime*12; x++)//显示进度条 
    { 
        PutPixel(x, 0, 0xc0c0);
        PutPixel(x, 1, 0xc0c0);
        PutPixel(x, 2, 0xc0c0);
        PutPixel(x, 3, 0xc0c0);
        j++;     
    }
}

void IRQ_Handle(void)
{
	unsigned long oft = INTOFFSET;
	//清中断
	if (oft == 4)
        EINTPEND = 1<<7;    //EINT4-7合用IRQ4，注意EINTPEND[3:0]保留未用，向这些位写入1可能导致未知结果
	SRCPND = 1<<oft;	
	INTPND = INTPND;	 

    /* 调用中断服务程序 */
     isr_handle_array[oft]();
}