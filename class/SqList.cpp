#include "SqList.h"

Status InitList_Sq(SqList &L)
{
	//����һ���յ����Ա�L
	
	L.elem = (ElemType *) malloc (LIST_INIT_SIZE * sizeof(ElemType));
	if(!L.elem) {
		printf("�ڴ����ʧ��, ���˳�...\n");
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
	 	printf("i ��ֵ���Ϸ������˳�...\n");
		return ERROR;				           //iֵ���Ϸ�
	}
	 
	if (L.length >= L.ListSize) {		//��ǰ�洢�ռ����������ӷ���
		newbase = (ElemType *)realloc(L.elem, (L.ListSize + LISTINCREMENT) * sizeof (ElemType));
		if (!newbase) {
			printf("�ռ䲻�������·���ʧ�ܣ����˳�...\n");
			exit(OVERFLOW);		// �洢����ʧ�� 
		}	
		L.elem = newbase;			// �µ�ַ 
		L.ListSize += LISTINCREMENT;
	}    
	
	int j; 
	for(j = L.length; j >= i; j--) {        //����λ�ü�֮���Ԫ�غ��� 
		L.elem[j] = L.elem[j-1];
	}					              
	L.elem[j] = e;							//����e
	++L.length;//����1
	
	return OK;
	
} //IistInsert_Sq   


Status ListDelete_Sq(SqList &L,int i,ElemType &e)  
{   
    if (i < 1 || i > L.length) {
		printf("i ��ֵ���Ϸ���������...\n"); 
	    return ERROR;		//iֵ���Ϸ�
	}
	
    if(e != L.elem[i-1]) {
    	printf("�� %d λ���ϲ�����Ԫ�� %d, ����������..\n", i, e);
    	return ERROR; 
	}
    	
   	
	for (int j = i; j < L.length; j++) {
		L.elem[j-1] = L.elem[j];
	}
    --L.length;  //����1
    
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
		printf("˳������ڣ����ܱ���գ�\n");
	}
	else {
		printf("˳������...\n");
		L.length = 0;
	}
}

 void ListDestroy_Sq(SqList &L)
 {
	 	if(L.elem == NULL) {
			printf("˳������ڣ����ܱ����٣�\n");
		}
		else {		
			free(L.elem);
			printf("˳������٣�\n");
			L.elem = NULL;
		}
 }
 
