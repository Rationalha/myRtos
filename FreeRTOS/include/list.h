#ifndef __LIST_H__
#define __LIST_H__

#include "portmacro.h"


/*节点结构体定义*/
struct xLIST_ITEM{
	 TickType_t   xItemValue;   //辅助值，用于给节点做排序
   struct xLIST_ITEM*  pxNext;   //下一个节点
	 struct xLIST_ITEM*  pxPrevious;  //前一个节点
	 void*  pvOwner;      //该节点的拥有者，通常为TCB         
	 void*  pvContainer;  //指向该链表根节点
};
typedef struct xLIST_ITEM  ListItem_t;

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


void vListInitialiseItem(ListItem_t* const pvListItem);

void vListInitialise(List_t* const pvList);

#endif


