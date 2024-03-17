/**
  *文件名: cheese_ui.c
  *创建时间: 2024-03-06 22:16:44
  *作者: ZZSZSZSZZ
  *描述: 
*/

/* include */
#include "cheese_ui.h"

/* define */

/* variables */
PageLinkList pageOperLinkList; //页面操作链表

ItemNode* currentItem; //当前项
Cursor cursor;
uint16_t butt = 0;
uint16_t b = 0;
/* function prototype */

void UIInit()
{
  pageOperLinkList = InitPageLinkList(); //初始化操作链表

  ListPushBack(pageOperLinkList, GetPageLinkList()->next); //把页面链表的第一个页面添加到操作链表

  currentItem = pageOperLinkList->next->itemLinkList->next;
  cursor.cursorPos = 16;
}

void Input()
{
  uint16_t itemLength = pageOperLinkList->prev->itemLength;

  if (b + butt >= itemLength-1)
  {
    b = 0;
    butt = 0;
    cursor.cursorPos = 16 + butt * ITEM_ROW_H;
    currentItem = pageOperLinkList->prev->itemLinkList->next;
    return;
  }

  if (cursor.cursorPos + CURSOR_H >= DISP_H - ITEM_ROW_H)
  {
    b++;
  }
  else
  {
    butt++;
    cursor.cursorPos = 16 + butt * ITEM_ROW_H;
  }

  currentItem = currentItem->next;
}

void Jamp()
{
  // ListPushBack(pageOperLinkList, LocateElem(1));
  ListPushBack(pageOperLinkList, LocateElem(currentItem->item_PageID));
  currentItem = pageOperLinkList->prev->itemLinkList->next;

  b = 0;
  butt = 0;
  cursor.cursorPos = 16;
}

void Buck()
{
  if (pageOperLinkList->prev == pageOperLinkList->next)
  {
    return;
  }

  ListPopBack(pageOperLinkList);
  currentItem = pageOperLinkList->prev->itemLinkList->next;

  b = 0;
  butt = 0;
  cursor.cursorPos = 16;
}

void Draw_Page()
{
  PageNode* page = pageOperLinkList->prev;
  ItemNode* item = page->itemLinkList->next;
  uint16_t h = 0 - b * ITEM_ROW_H;

  Display_SetFont(ITEM_FONT);

  h += 13;
  while (item != page->itemLinkList)
  {
    h += ITEM_ROW_H;
    Display_DrawStr(8,h,item->title);
    item = item->next;
  }

  // 标题栏 //
  Display_SetDrawColor(0); Display_DrawBox(0,0,DISP_W,PAGE_TITLE_H); //创建标题栏蒙版
  Display_SetDrawColor(1);
  Display_DrawStr(6, 10, page->pageTitle);
  Display_DrawLine(5,PAGE_TITLE_H-1,DISP_W-5,PAGE_TITLE_H-1);
  // test //
  Display_DrawStr(45,10,"CurrentItem:");
  Display_DrawNum(117,10, currentItem->listId);
  Display_DrawStr(85,60,"Item:");
  Display_DrawNum(115,60, page->itemLength);
  // Display_DrawBox(0,0,128,15);
}

void Draw_Cursor()
{
  Display_SetDrawColor(2);
  Display_DrawRBox(5,cursor.cursorPos,Display_GetUTF8Width(currentItem->title)+6,CURSOR_H,0);
}