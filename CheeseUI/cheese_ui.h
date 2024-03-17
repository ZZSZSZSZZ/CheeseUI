/**
  *文件名: cheese_ui.h
  *创建时间: 2024-03-03 23:14:19
  *作者: ZZSZSZSZZ
  *描述: 
*/

#ifndef __CHEESE_UI_H__
#define __CHEESE_UI_H__

#ifdef __cplusplus
extern "C" {
#endif

/* include */
#include "main.h"
#include "stdbool.h"
#include "cheese_defs.h"
#include "cheese_input.h"
#include "cheese_displayPort.h"
#include "cheese_page.h"
#include "cheese_cursor.h"

void UIInit();
void Draw_Page();
void Draw_Cursor();
void Input();
void Jamp();
void Buck();

#ifdef __cplusplus
}
#endif

#endif