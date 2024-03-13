/**
  *文件名: cheese_page.h
  *创建时间: 2024-03-03 16:29:06
  *作者: ZZSZSZSZZ
  *描述: 定义了页面节点的结构和页面类型的枚举
*/

#ifndef __CHEESE_PAGE_H__
#define __CHEESE_PAGE_H__

#ifdef __cplusplus
extern "C" {
#endif

/* include */
#include "main.h"
#include "stdbool.h"
#include "stdlib.h"
#include "stdarg.h"
#include "cheese_item.h"

typedef enum
{
    PAGE_LIST, //列表页面
    PAGE_SIDEBAR, //侧边栏页面
    PAGE_CUSTOM //定制页面
} PageType;

/// @brief 页面节点
typedef struct PageNode
{
  //数据域
  PageType funcType; //页面类型
  ItemLinkList itemLinkList;  //项链表
  uint16_t itemLength;
  uint16_t pageID; //页面ID
  bool usePageTitle; //是否使用页面标题
  char* pageTitle; //页面标题

  //指针域
  struct PageNode* prev; //前驱指针
  struct PageNode* next; //后继指针
} PageNode, *PageLinkList;

extern PageLinkList pageLinkList;

PageLinkList InitPageLinkList();
void AddPage(PageNode* page, bool usePageTitle, char* pageTitle, PageType funcType);
void AddItem(PageNode* page, ItemNode* item, char* title, ItemType funcType, ...);
void ListPushBack(PageLinkList _pageLinkList, PageNode* page);
void ListPopBack(PageLinkList _pageLinkList);
PageNode* LocateElem(uint16_t pageID);

#ifdef __cplusplus
}
#endif

#endif