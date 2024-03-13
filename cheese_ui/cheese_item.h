/**
  *文件名: cheese_item.h
  *创建时间: 2024-03-03 17:10:58
  *作者: ZZSZSZSZZ
  *描述: 项
*/

#ifndef __CHEESE_ITEM_H__
#define __CHEESE_ITEM_H__

#ifdef __cplusplus
extern "C" {
#endif

/* include */
#include "main.h"

/// @brief 项类型
typedef enum
{
  ITEM_PAGE_DESCRIPTION, //项页面描述
  ITEM_JUMP_PAGE, //项跳转页面
  ITEM_SWITCH, //项切换
  ITEM_CHANGE_VALUE, //项更改值
  ITEM_PROGRESS_BAR, //项进度条
  ITEM_RADIO_BUTTON, //项单选按钮
  ITEM_CHECKBOX, //项复选框
  ITEM_MESSAGE //项消息类型
} ItemType;

/// @brief 项节点
typedef struct Item
{
  //数据域
  ItemType funcType; //项类型
  int16_t listId; //项ID
  char* title;

  char* msg;
  uint16_t pageID;

  //指针域
	struct Item* prev; //前驱指针
  struct Item* next; //后继指针
} ItemNode, *ItemLinkList;

#ifdef __cplusplus
}
#endif

#endif