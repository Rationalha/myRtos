#include  "list.h"

/*    int* const x; 这种为常量指针，
			指针指向的地址不能变，但地址内的数据可以变
*/


/*节点初始化*/
void  vListInitialiseItem(ListItem_t* const pvListItem){
		pvListItem->pvContainer=NULL;
}

/*链表初始化*/
void vListInitialise(List_t* const pvList){
	
		pvList->uxNumberOfItems=0U;  //节点数量设为0
		pvList->pxIndex=(ListItem_t*)&pvList->xListEnd; //将当前节点索引指向末尾
		pvList->xListEnd.xItemValue=portMAX_DELAY; //将最后一个节点的辅助排序值设为最大
		//最后一个节点的previous和next都指向自身
		pvList->xListEnd.pxNext=(ListItem_t*)&pvList->xListEnd;
		pvList->xListEnd.pxPrevious=(ListItem_t*)&pvList->xListEnd;
}

/*在链表的末尾插入节点*/
void vListInsertEnd(List_t* const pvList,ListItem_t* const pvNewItem){
		ListItem_t* const listitem=pvList->pxIndex; //获取end节点
		
		pvNewItem->pxNext=listitem;
		pvNewItem->pxPrevious=listitem->pxPrevious;
		listitem->pxPrevious->pxNext=pvNewItem;
		listitem->pxPrevious=pvNewItem;
	
		pvNewItem->pvContainer=(void *)pvList; //设置节点的链表
	
		(pvList->uxNumberOfItems)++;  //链表数量++
}
/*将节点按照升序排列插入到链表*/
void vListInsert(List_t* const pvList,ListItem_t* const pvNewItem){

	 TickType_t value=pvNewItem->xItemValue; //新节点的辅助排序值
	 ListItem_t*  iterator;
	
	 if(value==portMAX_DELAY){ //插入末尾
			iterator=pvList->xListEnd.pxPrevious;
	 }else{ //查找到指定位置
		 for(iterator=(ListItem_t*)&(pvList->xListEnd); //从前向后
				 iterator->xItemValue<=value;
				 iterator=iterator->pxPrevious){		 
			}
	 }
   pvNewItem->pxNext=iterator->pxNext;
	 pvNewItem->pxNext->pxPrevious=pvNewItem;
	 pvNewItem->pxPrevious=iterator;
	 iterator->pxNext=pvNewItem;
	 
		pvNewItem->pvContainer=(void *)pvList; //设置节点的链表
	
		(pvList->uxNumberOfItems)++;  //链表数量++
}

/*将节点从链表中移除*/
UBaseType_t uxListRemove(ListItem_t* const item){
     //获取节点的链表
	List_t*  list=(List_t*)item->pvContainer;
	//删除该节点
	item->pxPrevious->pxNext=item->pxNext;
	item->pxNext->pxPrevious=item->pxPrevious;
	//确保链表的index有效
    if(list->pxIndex==item){
        list->pxIndex=item->pxPrevious;
	}
	item->pvContainer=NULL; //清空节点的链表信息

	(list->uxNumberOfItems)--; //链表数量--
	
	return list->uxNumberOfItems;
}
