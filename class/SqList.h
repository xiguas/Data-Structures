#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>

# define LIST_INIT_SIZE   100 	//���Ա��ʼ������
# define LISTINCREMENT   10 	 //���Ա��������

#define  TRUE    1               
#define  FLASE   0
#define  OK      1               
#define  ERROR   0
#define INFEASIBLE   -1    
#define OVERFLOW     -2

// Status�Ǻ��������ͣ���ֵ�Ǻ������״̬������OK�� 
typedef  int  Status;
typedef  int  ElemType;

typedef  struct {
	ElemType  *elem; 		 //�洢�ռ��ַ
	int length ;			 //��ǰ����
    int ListSize;	   //��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ��
} SqList;

Status InitList_Sq(SqList &L);
Status ListInsert_Sq(SqList &L, int i, ElemType e);
Status ListDelete_Sq(SqList &L, int i, ElemType &e);
Status compare(ElemType m, ElemType n);
int LocateElem_Sq(SqList L, ElemType e);
void PrintElem_Sq(SqList L);
int ListLength_Sq(SqList L);
void ListClear_Sq(SqList &L); 
void ListDestroy_Sq(SqList &L);

#endif 

