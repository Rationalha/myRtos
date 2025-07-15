#include  "list.h"

/*    int* const x; ����Ϊ����ָ�룬
			ָ��ָ��ĵ�ַ���ܱ䣬����ַ�ڵ����ݿ��Ա�
*/


/*�ڵ��ʼ��*/
void  vListInitialiseItem(ListItem_t* const pvListItem){
		pvListItem->pvContainer=NULL;
}

/*�����ʼ��*/
void vListInitialise(List_t* const pvList){
	
		pvList->uxNumberOfItems=0U;  //�ڵ�������Ϊ0
		pvList->pxIndex=(ListItem_t*)&pvList->xListEnd; //����ǰ�ڵ�����ָ��ĩβ
		pvList->xListEnd.xItemValue=portMAX_DELAY; //�����һ���ڵ�ĸ�������ֵ��Ϊ���
		//���һ���ڵ��previous��next��ָ������
		pvList->xListEnd.pxNext=(ListItem_t*)&pvList->xListEnd;
		pvList->xListEnd.pxPrevious=(ListItem_t*)&pvList->xListEnd;
}

/*�������ĩβ����ڵ�*/
void vListInsertEnd(List_t* const pvList,ListItem_t* const pvNewItem){
		ListItem_t* const listitem=pvList->pxIndex; //��ȡend�ڵ�
		
		pvNewItem->pxNext=listitem;
		pvNewItem->pxPrevious=listitem->pxPrevious;
		listitem->pxPrevious->pxNext=pvNewItem;
		listitem->pxPrevious=pvNewItem;
	
		pvNewItem->pvContainer=(void *)pvList; //���ýڵ������
	
		(pvList->uxNumberOfItems)++;  //��������++
}
/*���ڵ㰴���������в��뵽����*/
void vListInsert(List_t* const pvList,ListItem_t* const pvNewItem){

	 TickType_t value=pvNewItem->xItemValue; //�½ڵ�ĸ�������ֵ
	 ListItem_t*  iterator;
	
	 if(value==portMAX_DELAY){ //����ĩβ
			iterator=pvList->xListEnd.pxPrevious;
	 }else{ //���ҵ�ָ��λ��
		 for(iterator=(ListItem_t*)&(pvList->xListEnd); //��ǰ���
				 iterator->xItemValue<=value;
				 iterator=iterator->pxPrevious){		 
			}
	 }
   pvNewItem->pxNext=iterator->pxNext;
	 pvNewItem->pxNext->pxPrevious=pvNewItem;
	 pvNewItem->pxPrevious=iterator;
	 iterator->pxNext=pvNewItem;
	 
		pvNewItem->pvContainer=(void *)pvList; //���ýڵ������
	
		(pvList->uxNumberOfItems)++;  //��������++
}

/*���ڵ���������Ƴ�*/
UBaseType_t uxListRemove(ListItem_t* const item){
     //��ȡ�ڵ������
	List_t*  list=(List_t*)item->pvContainer;
	//ɾ���ýڵ�
	item->pxPrevious->pxNext=item->pxNext;
	item->pxNext->pxPrevious=item->pxPrevious;
	//ȷ�������index��Ч
    if(list->pxIndex==item){
        list->pxIndex=item->pxPrevious;
	}
	item->pvContainer=NULL; //��սڵ��������Ϣ

	(list->uxNumberOfItems)--; //��������--
	
	return list->uxNumberOfItems;
}
