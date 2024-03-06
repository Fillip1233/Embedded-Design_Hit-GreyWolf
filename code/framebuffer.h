/*
 * FILE: framebuffer.h
 * 在framebuffer上画点、画线、画同心圆、清屏的函数接口
 */

#ifndef __FRAMEBUFFER_H__
#define __FRAMEBUFFER_H__

#include <types.h>

/* 
 * 画点
 * 输入参数：
 *     x、y : 象素坐标
 *     color: 颜色值
 *         对于16BPP: color的格式为0xAARRGGBB (AA = 透明度),
 *     需要转换为5:6:5格式
 *         对于8BPP: color为调色板中的索引值，
 *     其颜色取决于调色板中的数值
 */
void PutPixel(UINT32 x, UINT32 y, UINT32 color);


/* 
 * 将屏幕清成单色
 * 输入参数：
 *     color: 颜色值
 *         对于16BPP: color的格式为0xAARRGGBB (AA = 透明度),
 *     需要转换为5:6:5格式
 *         对于8BPP: color为调色板中的索引值，
 *     其颜色取决于调色板中的数值
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
