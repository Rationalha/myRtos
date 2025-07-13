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

