/**
  *文件名: cheese_page.c
  *创建时间: 2024-03-04 13:11:40
  *作者: ZZSZSZSZZ
  *描述: 实现了页面链表的初始化和操作，它包括了页面节点和项节点的添加、尾插和尾删等功能
*/

/* include */
#include "cheese_page.h"

/* define */

/* variables */
PageLinkList pageLinkList; //页面链表
uint16_t _pageID;
bool initPageLink = false;
/* function prototype */

/// @brief 页面链表初始化
/// @return 页面链表
PageLinkList InitPageLinkList()
{
  PageLinkList _pageLinkList = (PageNode*)malloc(sizeof(PageNode));
  _pageLinkList->prev = _pageLinkList;
  _pageLinkList->next = _pageLinkList;
  initPageLink = true;
  return _pageLinkList;
}

PageLinkList GetPageLinkList()
{
  return pageLinkList;
}

/**
  * @brief  添加页面
  * @param  page: 需要添加的页面节点
  * @param  usePageTitle: 是否使用页面标题, true (非零) or false (0)
  * @param  pageTitle: 为你的页面取个名字吧 (｡･∀･)ﾉﾞ
  * @param  funcType: 定义页面类型, PAGE_LIST: 列表类型, PAGE_CUSTOM: 自定义类型
  * @retval None
  */
void AddPage(PageNode* page, bool usePageTitle, char* pageTitle, PageType funcType)
{
  //页面链表初始化(只会执行一次)
  if (initPageLink == false)
  {
    pageLinkList = InitPageLinkList();
  }

  //项列表初始化
  page->itemLinkList = (ItemNode*)malloc(sizeof(ItemNode));
  page->itemLinkList->prev = page->itemLinkList;
  page->itemLinkList->next = page->itemLinkList;

  //页面节点赋值
  page->usePageTitle = usePageTitle;
  if (usePageTitle == 1)
  {
    page->pageTitle = pageTitle;
  }
  page->pageID = _pageID++;

  va_list argp; //用于存储通过va_arg获取的额外参数
  va_start(argp, funcType); //初始化argp变量，让argp指向可变参数表里面的第一个参数

  page->funcType = funcType;

  switch (funcType)
  {
  case PAGE_LIST:
    break;
  case PAGE_SIDEBAR:
    break;
  case PAGE_CUSTOM:
    break;
  default:
    break;
  }
  va_end(argp);

  //把页面节点添加到页面链表里(尾插)
  page->next = NULL;
  PageNode* tail = pageLinkList->prev;
	page->next = pageLinkList;
	pageLinkList->prev = page;
	tail->next = page;
	page->prev = tail;
}

/**
  * @brief  添加项
  * @param  page: 页面节点
  * @param  item: 需要添加的项节点
  * @param  itemTitle: 为你的项取个名字吧 (｡･∀･)ﾉﾞ
  * @param  funcType: 定义项类型
  * @param  ... 可变参数，由funcType决定
  * @retval None
  */
void AddItem(PageNode* page, ItemNode* item, char* itemTitle, ItemType funcType, ...)
{
  va_list argp; //用于存储通过va_arg获取的额外参数
  va_start(argp, funcType); //初始化argp变量，让argp指向可变参数表里面的第一个参数

  item->funcType = funcType;
  switch (funcType)
  {
  case ITEM_JUMP_PAGE:
    item->item_PageID = va_arg(argp, int);
    // char* c = strTcpy(itemTitle,"+ ");
    item->title = itemTitle;
    break;
  case ITEM_BOOL:
    // item->boolSwitch = va_arg(argp, bool);
    item->title = itemTitle;
    break;
  case ITEM_MESSAGE:
    item->title = itemTitle;
    break;
  default:
    break;
  }
  va_end(argp);

  item->listId = page->itemLength;
  page->itemLength++;

  //将项节点插入页面节点里的项链表(尾插)
  item->next = NULL;
  ItemNode* tail = page->itemLinkList->prev;
	item->next = page->itemLinkList;
	page->itemLinkList->prev = item;
	tail->next = item;
	item->prev = tail;
}

/// @brief 链表尾插
/// @param _pageLinkList 页面链表
/// @param page 页面节点
void ListPushBack(PageLinkList _pageLinkList, PageNode* page)
{
  PageNode* _page = (PageNode*)malloc(sizeof(PageNode));
  *_page = *page;

	PageNode* tail = _pageLinkList->prev;
	_page->next = _pageLinkList;
	_pageLinkList->prev = _page;
	tail->next = _page;
	_page->prev = tail;
}

/// @brief 链表尾删
/// @param _pageLinkList 页面链表
void ListPopBack(PageLinkList _pageLinkList)
{
	PageNode* tail = _pageLinkList->prev;//记录头结点的前一个结点
	PageNode* newtail = tail->prev;//记录tail结点的前一个结点
	//建立头结点与newtail结点之间的双向关系
	newtail->next = _pageLinkList;
	_pageLinkList->prev = newtail;
	free(tail);//释放tail结点
}

/// @brief 根据页面ID查找对应页面
/// @param pageID 页面ID
/// @return 页面节点
PageNode* LocateElem(uint16_t pageID)
{
  PageNode* cur = pageLinkList->next;

  while (cur != pageLinkList)
  {
    if (cur->pageID == pageID)
		{
			return cur;
		}
		cur = cur->next;
  }
  return NULL;
}
