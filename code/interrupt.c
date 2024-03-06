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

    INTMOD = 0x0;	      // �����ж϶���ΪIRQģʽ
    INTMSK = BIT_ALLMSK;  // �����������ж�

//	isr_handle_array[ISR_IIC_OFT]  = I2CIntHandle;
}

void EINT0_Handle(void)
{
    if(exit==1)//�˳�������
    {
        exit=0;//ȷ���˳�

    }
    else if(hole==1)//1�Ŷ�����
        hit=1;//����
    if(windowstate==1)//������ʾҳ��
        windowstate=0;//���ظ�����Ϣҳ
}

void EINT2_Handle(void)
{
    if(exit==1)//�˳�������
    {
        exit++;//ȡ���˳�
        show_exit(noexit);
    }
    if(hole==2)//2�Ŷ�����
        hit=1;//����
    if(windowstate==0)//������Ϣ��ʾҳ��
        windowstate=1;//���������ʾҳ��
}

void EINT8_23_Handle(void)
{
    unsigned long val = EINTPEND;
    if (val & (1 << 11))
    {
        if(windowstate==1)//������ʾҳ��
            windowstate=2;//������Ϸ
        if(hole==3)//3�Ŷ�����
            hit=1;//����
    }
    else if (val & (1 << 19))
    {
        if(windowstate==1)//������ʾҳ��
            windowstate=2;//������Ϸ
        if(windowstate==2&&usetime>5)//�Լ�������Ϸ
        {
            unsigned long oft = INTOFFSET;
            show_exit(gexit);//��ʾ�˳�ҳ��
            EINTPEND=(1<<19);//��������жϣ��ȴ��˳�ȷ��
            SRCPND = 1<<oft;	
	        INTPND = INTPND;
            exit=1;//�����˳�ȷ��
            exit_wait();//�ȴ��˳�ȷ��
        }
    }
    EINTPEND = (1 << 11) | (1 << 19);
}

void Timer0_Handle(void)
{
    usetime+=1;//��ʱ����
    UINT32 x;
    UINT32 color;
    int j=0;
    for (x = 0; x < usetime*12; x++)//��ʾ������ 
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
	//���ж�
	if (oft == 4)
        EINTPEND = 1<<7;    //EINT4-7����IRQ4��ע��EINTPEND[3:0]����δ�ã�����Щλд��1���ܵ���δ֪���
	SRCPND = 1<<oft;	
	INTPND = INTPND;	 

    /* �����жϷ������ */
     isr_handle_array[oft]();
}