/**
  *文件名: cheese_cursor.h
  *创建时间: 2024-03-08 12:04:39
  *作者: ZZSZSZSZZ
  *描述: 
*/

#ifndef __CHEESE_CURSOR_H__
#define __CHEESE_CURSOR_H__

#ifdef __cplusplus
extern "C" {
#endif

/* include */
#include "main.h"

/// @brief 光标结构体
typedef struct Cursor
{
  uint16_t cursorWidth;
  uint16_t cursorPos;
} Cursor;


#ifdef __cplusplus
}
#endif

#endif