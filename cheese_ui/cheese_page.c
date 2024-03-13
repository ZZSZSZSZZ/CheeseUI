/**
  *文件名: cheese_page.c
  *创建时间: 2024-03-04 13:11:40
  *作者: ZZSZSZSZZ
  *描述: 
*/

/* include */
#include "cheese_page.h"

/* define */

/* variables */
PageLinkList pageLinkList; //页面链表
uint16_t _pageID = -1;
bool initPageLink;
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
  if (initPageLink == false)
  {
    pageLinkList = InitPageLinkList();
  }

  page->itemLinkList = (ItemNode*)malloc(sizeof(ItemNode));
  page->itemLinkList->prev = page->itemLinkList;
  page->itemLinkList->next = page->itemLinkList;

  page->next = NULL;
  page->usePageTitle = usePageTitle;

  if (usePageTitle == 1)
  {
    page->pageTitle = pageTitle;
  }

  page->funcType = funcType;

  page->pageID = ++_pageID;

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
  * @retval None
  */
void AddItem(PageNode* page, ItemNode* item, char* itemTitle, ItemType funcType)
{
  item->title = itemTitle;
  item->funcType = funcType;
  item->next = NULL;

  item->listId = page->itemLength;
  page->itemLength++;

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
