/*
 * FILE: framebuffer.c
 * ʵ����framebuffer�ϻ��㡢���ߡ���ͬ��Բ�������ĺ���
 */

#include "framebuffer.h"
#include"number.h"

extern unsigned int fb_base_addr;//����ɫ���׵�ַ 
extern unsigned int bpp; 
extern unsigned int xsize;
extern unsigned int ysize;
//extern const char p000[],p010[],p020[],p030[],p040[],p050[],p060[],p070[],p080[],p090[],p100[];

/* 
 * ����
 * ���������
 *     x��y : ��������
 *     color: ��ɫֵ
 *         ����16BPP: color�ĸ�ʽΪ0xAARRGGBB (AA = ͸����),
 *     ��Ҫת��Ϊ5:6:5��ʽ
 *         ����8BPP: colorΪ��ɫ���е�����ֵ��
 *     ����ɫȡ���ڵ�ɫ���е���ֵ
 */
void PutPixel(UINT32 x, UINT32 y, UINT32 color)
{
    //UINT8 red,green,blue;

    switch (bpp){
        case 16:
        {
            UINT16 *addr = (UINT16 *)fb_base_addr + (y * xsize + x);
            // red   = (color >> 19) & 0x1f;
            // green = (color >> 10) & 0x3f;
            // blue  = (color >>  3) & 0x1f;
            // color = (red << 11) | (green << 5) | blue; // ��ʽ5:6:5
            *addr = (UINT16) color;
            break;
        }
        
        case 8:
        {
            UINT8 *addr = (UINT8 *)fb_base_addr + (y * xsize + x);
            *addr = (UINT8) color;
            break;
        }

        default:
            break;
    }
}

void picture_show(const unsigned char img[])
{
    UINT32 x, y;
    UINT32 color;
    int j=0;
    for (y = 0; y < 270; y++)    
    {
        for (x = 0; x <480 ; x++) 
        {
             (UINT32)color = (img[2*j+1]<<8) | (img[2*j]); 
            PutPixel(x, y, color);
            j++;    
        } 
    }    
}

void hole1(const unsigned char img[])
{
    UINT32 x, y;
    UINT32 color;
    int j=0;
    for (y = 189; y < 263; y++)    
    {
        for (x = 60; x <164 ; x++) 
        {
             (UINT32)color = (img[2*j+1]<<8) | (img[2*j]); 
            PutPixel(x, y, color);
            j++;    
        } 
    }    
}

void hole2(const unsigned char img[])
{
    UINT32 x, y;
    UINT32 color;
    int j=0;
    for (y = 189; y < 262; y++)    
    {
        for (x = 191; x <296 ; x++) 
        {
             (UINT32)color = (img[2*j+1]<<8) | (img[2*j]); 
            PutPixel(x, y, color);
            j++;    
        } 
    }    
}

void hole3(const unsigned char img[])
{
    UINT32 x, y;
    UINT32 color;
    int j=0;
    for (y = 189; y < 262; y++)    
    {
        for (x = 329; x <434; x++) 
        {
             (UINT32)color = (img[2*j+1]<<8) | (img[2*j]); 
            PutPixel(x, y, color);
            j++;    
        } 
    }    
}
void show_num(const unsigned char img[])
{
    UINT32 x, y;
    UINT32 color;
    int j=0;
    for (y = 6; y < 29; y++)    
    {
        for (x = 390; x <471; x++) 
        {
             (UINT32)color = (img[2*j+1]<<8) | (img[2*j]); 
            PutPixel(x, y, color);
            j++;    
        } 
    }
}
void show_exit(const unsigned char img[])
{
    UINT32 x, y;
    UINT32 color;
    int j=0;
    for (y = 51; y < 150; y++)    
    {
        for (x = 134; x <351; x++) 
        {
             (UINT32)color = (img[2*j+1]<<8) | (img[2*j]); 
            PutPixel(x, y, color);
            j++;    
        } 
    }
}
void res_show(const unsigned char img[])
{
    UINT32 x, y;
    UINT32 color;
    int j=0;
    for (y = 0; y < 272; y++)    
    {
        for (x = 0; x <479 ; x++) 
        {
             (UINT32)color = (img[2*j+1]<<8) | (img[2*j]); 
            PutPixel(x, y, color);
            j++;    
        } 
    }    
}
void judge_num(int num)//�ж���Ҫ��ʾ������
{
    switch(num)
    {
        case 0:
            show_num(p000);
            break;
        case 10:
            show_num(p010);
            break;
        case 20:
            show_num(p020);
            break;
        case 30:
            show_num(p030);
            break;
        case 40:
            show_num(p040);
            break;
        case 50:
            show_num(p050);
            break;
        case 60:
            show_num(p060);
            break;
        case 70:
            show_num(p070);
            break;
        case 80:
            show_num(p080);
            break;
        case 90:
            show_num(p090);
            break;
        case 100:
            show_num(p100);
            break;
        default:
            break;
    }
}

void show_top(const unsigned char img[])//��ʾ����
{
    UINT32 x, y;
    UINT32 color;
    int j=0;
    for (y = 0; y < 3; y++)    
    {
        for (x = 0; x <480 ; x++) 
        {
             (UINT32)color = (img[2*j+1]<<8) | (img[2*j]); 
            PutPixel(x, y, color);
            j++;    
        } 
    } 
}
