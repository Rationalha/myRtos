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

