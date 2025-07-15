#ifndef __LIST_H__
#define __LIST_H__

#include "portmacro.h"


/*�ڵ�ṹ�嶨��*/
typedef struct xLIST_ITEM{
	 TickType_t   xItemValue;   //����ֵ�����ڸ��ڵ�������
     struct xLIST_ITEM*  pxNext;   //��һ���ڵ�
	 struct xLIST_ITEM*  pxPrevious;  //ǰһ���ڵ�
	 void*  pvOwner;      //�ýڵ��ӵ���ߣ�ͨ��ΪTCB         
	 void*  pvContainer;  //ָ���������ڵ�
}ListItem_t;

/*����һ��˫������Ľ�β�ڵ�*/
typedef struct xMINI_LIST_ITEM{
	TickType_t   xItemValue;   //����ֵ�����ڸ��ڵ�������
	ListItem_t*  pxNext;
  ListItem_t*  pxPrevious;  	
}MiniListItem_t;


/*����һ������*/
typedef struct xLIST{
	UBaseType_t     uxNumberOfItems; //����ڵ�����
	ListItem_t*     pxIndex;   //�ڵ�����
	MiniListItem_t  xListEnd;  //���һ���ڵ�
}List_t;

/*�ڵ��ʼ��*/
void vListInitialiseItem(ListItem_t* const pvListItem);

/*�����ʼ��*/
void vListInitialise(List_t* const pvList);

/*�������ĩβ����ڵ�*/
void vListInsertEnd(List_t* const pvList,ListItem_t* const pvListItem);

/*���ڵ㰴���������в��뵽����*/
void vListInsert(List_t* const pvList,ListItem_t* const pvNewItem);

/*���ڵ���������Ƴ�*/
UBaseType_t uxListRemove(ListItem_t* const item);

#endif


