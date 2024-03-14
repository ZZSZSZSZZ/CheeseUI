/**
  *文件名: cheese_displayPort.c
  *创建时间: 2024-03-08 13:36:29
  *作者: ZZSZSZSZZ
  *描述: 
*/

/* include */
#include "cheese_displayPort.h"

/* define */

/* variables */
u8g2_t u8g2;
/* function prototype */

/// @brief 屏幕初始化
void Display_Init()
{
  u8g2Init(&u8g2);
}

/// @brief 清空缓冲区内容
void Display_ClearBuffer()
{
  u8g2_ClearBuffer(&u8g2);
}

/// @brief 绘制缓冲区内容
void Display_SendBuffer()
{
  u8g2_SendBuffer(&u8g2);
}

/// @brief 设置绘制颜色
/// @param color 0:无色, 1:有色, 2:反色
void Display_SetDrawColor(uint8_t color)
{
  u8g2_SetDrawColor(&u8g2, color);
}

/// @brief 设置字体
/// @param font 字体名
void Display_SetFont(const uint8_t *font)
{
  u8g2_SetFont(&u8g2, font);
}

uint16_t Display_GetUTF8Width(const char *str)
{
  return u8g2_GetUTF8Width(&u8g2, str);
}

/**
 * 绘制字符串
 * @param x 左上角的x坐标
 * @param y 左上角的y坐标
 * @param str 绘制字符串内容
 * @return 字符串的长度
 */
uint16_t Display_DrawStr(uint16_t x, uint16_t y, const char *str)
{
  return u8g2_DrawStr(&u8g2, x, y, str);
}

void Display_DrawNum(u8g2_uint_t x, u8g2_uint_t y, int num)
{
  u8g2_DrawNum(&u8g2, x, y, num);
}

/**
 * 绘制线
 * @param x1 首端点的x坐标
 * @param y1 首端点的y坐标
 * @param x2 尾端点的x坐标
 * @param y2 尾端点的y坐标
 */
void Display_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
  u8g2_DrawLine(&u8g2, x1, y1, x2, y2);
}

/**
 * 绘制实心矩形
 * @param x 左上角的x坐标
 * @param y 左上角的y坐标
 * @param w 矩形的宽度
 * @param h 矩形的高度
 */
void Display_DrawBox(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
  u8g2_DrawBox(&u8g2, x, y, w, h);
}

/**
 * 绘制实心圆角矩形
 * @param x 左上角的x坐标
 * @param y 左上角的y坐标
 * @param w 圆角矩形的宽度
 * @param h 圆角矩形的高度
 * @param r 圆角半径
 */
void Display_DrawRBox(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t r)
{
  u8g2_DrawRBox(&u8g2, x, y, w, h, r);
}

/**
 * 绘制空心矩形
 * @param x 左上角的x坐标
 * @param y 左上角的y坐标
 * @param w 矩形的宽度
 * @param h 矩形的高度
 */
void Display_DrawFrame(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
  u8g2_DrawFrame(&u8g2, x, y, w, h);
}

/**
 * 绘制空心圆角矩形
 * @param x 左上角的x坐标
 * @param y 左上角的y坐标
 * @param w 圆角矩形的宽度
 * @param h 圆角矩形的高度
 * @param r 圆角半径
 */
void Display_DrawRFrame(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t r)
{
  u8g2_DrawRFrame(&u8g2, x, y, w, h, r);
}
