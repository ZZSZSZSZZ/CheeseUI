/**
  *文件名: cheese_item.h
  *创建时间: 2024-03-03 17:10:58
  *作者: ZZSZSZSZZ
  *描述: 定义了项节点的结构和项类型的枚举
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
  ITEM_PAGE_DESCRIPTION, //项_页面描述
  ITEM_MESSAGE,
  ITEM_JUMP_PAGE, //项_跳转页面
  ITEM_BOOL, //项_布尔: 只有开和关
} ItemType;

/// @brief 项节点
typedef struct Item
{
  //数据域
    //核心数据
  ItemType funcType; //项类型
  int16_t listId; //项ID
  char* title;

    //可变数据
  char* msg;
  uint16_t item_PageID;
  bool boolSwitch;

  //指针域
	struct Item* prev; //前驱指针
  struct Item* next; //后继指针
} ItemNode, *ItemLinkList;

#ifdef __cplusplus
}
#endif

#endif