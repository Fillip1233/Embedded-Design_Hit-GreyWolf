/*
 * FILE: framebuffer.h
 * ��framebuffer�ϻ��㡢���ߡ���ͬ��Բ�������ĺ����ӿ�
 */

#ifndef __FRAMEBUFFER_H__
#define __FRAMEBUFFER_H__

#include <types.h>

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
void PutPixel(UINT32 x, UINT32 y, UINT32 color);


/* 
 * ����Ļ��ɵ�ɫ
 * ���������
 *     color: ��ɫֵ
 *         ����16BPP: color�ĸ�ʽΪ0xAARRGGBB (AA = ͸����),
 *     ��Ҫת��Ϊ5:6:5��ʽ
 *         ����8BPP: colorΪ��ɫ���е�����ֵ��
 *     ����ɫȡ���ڵ�ɫ���е���ֵ
 */
void ClearScr(UINT32 color);
void picture_show(const unsigned char img[]);
void hole1(const unsigned char img[]);
void hole2(const unsigned char img[]);
void hole3(const unsigned char img[]);
void judge_num(int num);
void show_num(const unsigned char img[]);
void show_exit(const unsigned char img[]);
void res_show(const unsigned char img[]);
void show_top(const unsigned char img[]);

#endif /*__FRAMEBUFFER_H__*/
