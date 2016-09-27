#include "SqList.h"

Status InitList_Sq(SqList &L)
{
	//构造一个空的线性表L
	
	L.elem = (ElemType *) malloc (LIST_INIT_SIZE * sizeof(ElemType));
	if(!L.elem) {
		printf("内存分配失败, 将退出...\n");
		exit(OVERFLOW);
	}

	L.length = 0;
	L.ListSize = LIST_INIT_SIZE;
	
	return OK;
	
}//InitList_Sq 


Status ListInsert_Sq(SqList &L,int i, ElemType e)
{
	ElemType *newbase;
	 
	if (i < 1 || i > L.length + 1) {
	 	printf("i 的值不合法，将退出...\n");
		return ERROR;				           //i值不合法
	}
	 
	if (L.length >= L.ListSize) {		//当前存储空间已满，增加分配
		newbase = (ElemType *)realloc(L.elem, (L.ListSize + LISTINCREMENT) * sizeof (ElemType));
		if (!newbase) {
			printf("空间不足且重新分配失败，将退出...\n");
			exit(OVERFLOW);		// 存储分配失败 
		}	
		L.elem = newbase;			// 新地址 
		L.ListSize += LISTINCREMENT;
	}    
	
	int j; 
	for(j = L.length; j >= i; j--) {        //插入位置及之后的元素后移 
		L.elem[j] = L.elem[j-1];
	}					              
	L.elem[j] = e;							//插入e
	++L.length;//表长增1
	
	return OK;
	
} //IistInsert_Sq   


Status ListDelete_Sq(SqList &L,int i,ElemType &e)  
{   
    if (i < 1 || i > L.length) {
		printf("i 的值不合法，将返回...\n"); 
	    return ERROR;		//i值不合法
	}
	
    if(e != L.elem[i-1]) {
    	printf("第 %d 位置上并不是元素 %d, 请重新输入..\n", i, e);
    	return ERROR; 
	}
    	
   	
	for (int j = i; j < L.length; j++) {
		L.elem[j-1] = L.elem[j];
	}
    --L.length;  //表长减1
    
	return OK;   
} //IistDelete_Sq 


Status compare(ElemType m, ElemType n)
{
	return(m == n);
}


int LocateElem_Sq(SqList L,ElemType e)
{
	int i = 1;
	ElemType *p = L.elem;
	
	while(i <= L.length &&  !compare(*p++, e)) {
			++i;
	}
	
	if(i <= L.length)
		return i;
	else
		return 0;
}


void PrintElem_Sq(SqList L)
{
	printf("\n");
	for(int i = 0;i < L.length; i++) {
		printf("%d    ",L.elem[i]);
	}
	printf("\n");
}


int ListLength_Sq(SqList L)
{
	return L.length;
}


 void ListClear_Sq(SqList &L)
{
	if(L.elem == NULL) {
		printf("顺序表不存在，不能被清空！\n");
	}
	else {
		printf("顺序表被清空...\n");
		L.length = 0;
	}
}

 void ListDestroy_Sq(SqList &L)
 {
	 	if(L.elem == NULL) {
			printf("顺序表不存在，不能被销毁！\n");
		}
		else {		
			free(L.elem);
			printf("顺序表被销毁！\n");
			L.elem = NULL;
		}
 }
 
