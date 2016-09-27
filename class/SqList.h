#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>

# define LIST_INIT_SIZE   100 	//线性表初始分配量
# define LISTINCREMENT   10 	 //线性表分配增量

#define  TRUE    1               
#define  FLASE   0
#define  OK      1               
#define  ERROR   0
#define INFEASIBLE   -1    
#define OVERFLOW     -2

// Status是函数的类型，其值是函数结果状态代码如OK等 
typedef  int  Status;
typedef  int  ElemType;

typedef  struct {
	ElemType  *elem; 		 //存储空间基址
	int length ;			 //当前长度
    int ListSize;	   //当前分配的存储容量（以sizeof(ElemType)为单位）
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

