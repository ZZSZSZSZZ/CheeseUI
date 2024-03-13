/**
  *文件名: cheese_displayPort.h
  *创建时间: 2024-03-08 14:05:34
  *作者: ZZSZSZSZZ
  *描述: 
*/

#ifndef __CHEESE_DISPLAYPORT_H__
#define __CHEESE_DISPLAYPORT_H__

#ifdef __cplusplus
extern "C" {
#endif

/* include */
#include "main.h"
#include "u8g2.h"
#include "oled.h"

void Display_Init();
void Display_ClearBuffer();
void Display_SendBuffer();
void Display_SetDrawColor(uint8_t color);
void Display_SetFont(const uint8_t *font);
uint16_t Display_GetUTF8Width(const char *str);
uint16_t Display_DrawStr(uint16_t x, uint16_t y, const char *str);
void Display_DrawNum(u8g2_uint_t x, u8g2_uint_t y, int num);
void Display_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void Display_DrawBox(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
void Display_DrawRBox(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t r);
void Display_DrawFrame(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
void Display_DrawRFrame(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t r);

#ifdef __cplusplus
}
#endif

#endif