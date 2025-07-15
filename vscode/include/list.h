#ifndef __LIST_H__
#define __LIST_H__

#include "portmacro.h"


/*节点结构体定义*/
typedef struct xLIST_ITEM{
	 TickType_t   xItemValue;   //辅助值，用于给节点做排序
     struct xLIST_ITEM*  pxNext;   //下一个节点
	 struct xLIST_ITEM*  pxPrevious;  //前一个节点
	 void*  pvOwner;      //该节点的拥有者，通常为TCB         
	 void*  pvContainer;  //指向该链表根节点
}ListItem_t;

/*定义一个双向链表的结尾节点*/
typedef struct xMINI_LIST_ITEM{
	TickType_t   xItemValue;   //辅助值，用于给节点做排序
	ListItem_t*  pxNext;
  ListItem_t*  pxPrevious;  	
}MiniListItem_t;


/*定义一个链表*/
typedef struct xLIST{
	UBaseType_t     uxNumberOfItems; //链表节点数量
	ListItem_t*     pxIndex;   //节点索引
	MiniListItem_t  xListEnd;  //最后一个节点
}List_t;

/*节点初始化*/
void vListInitialiseItem(ListItem_t* const pvListItem);

/*链表初始化*/
void vListInitialise(List_t* const pvList);

/*在链表的末尾插入节点*/
void vListInsertEnd(List_t* const pvList,ListItem_t* const pvListItem);

/*将节点按照升序排列插入到链表*/
void vListInsert(List_t* const pvList,ListItem_t* const pvNewItem);

/*将节点从链表中移除*/
UBaseType_t uxListRemove(ListItem_t* const item);

#endif


