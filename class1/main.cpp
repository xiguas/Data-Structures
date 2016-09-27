#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "SqList.h"

using namespace std;
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main()
{
    int number;         // 选项 
	int flag = 1;       // 标志 
	int length, i, position;
	ElemType e; 
    
	SqList L;           // 线性表 L 
    L.elem = NULL; 

    while (flag) {
    	
       printf("|******************************************|\n");  	
       printf("|           线性表的基本操作               |\n");
       printf("|******************************************|\n");    
       printf("|            1. 初始化线性表               |\n");    
       printf("|            2. 向线性表中增加元素         |\n");    
       printf("|            3. 从线性表中删除元素         |\n");    
       printf("|            4. 查找元素                   |\n");    
       printf("|            5. 返回线性表的长度           |\n");    
       printf("|            6. 输出线性表                 |\n");    
       printf("|            7. 清空线性表                 |\n");    
       printf("|            8. 销毁线性表                 |\n");    
       printf("|******************************************|\n");
       printf("请选择功能 ：                               \n");
        
       cin >> number;
	    
       switch( number ) {
            case 1 :
                if (InitList_Sq(L)) {
					printf("初始化成功...\n");
			    }
                break; 
            
            case 2 :
                if (!L.elem) {
                   	printf("请先初始化哦....\n");
                } 
				else {
					printf("请输入需要插入的位置：");
					scanf("%d", &i);
					printf("请输入需要插入的元素：");
					scanf("%d", &e);
					if (ListInsert_Sq(L, i, e)) {
						printf("插入成功....\n"); 
					}
				} 
                break;
                
            case 3 :
                if (!L.elem) {
                    printf("请先初始化哦....\n");
                } 
				else {
					printf("请输入需要删除的位置：");
					scanf("%d", &i);
					printf("请输入需要删除的元素：");
					scanf("%d", &e);
					if (ListDelete_Sq(L, i, e)) {
						printf("删除 %d 成功....\n", e); 
					}
				} 
                break;
                
				
            case 4 :
                if (!L.elem) {
                    printf("请先初始化哦....\n");
                } 
				else {
					printf("请输入需要查找的元素：");
					scanf("%d", &e);
					
					position = LocateElem_Sq(L, e);
					if (position) {
						printf("%d 的位置在第 %d  ....\n", e, position);
					}
					else {
						printf(" %d 元素不存在...\n");
					}
				} 
                break;
                
           case 5 :
                if (!L.elem) {
                    printf("请先初始化哦....\n");
                } 
				else {
					length = ListLength_Sq(L);
					printf("线性表的长度为 %d \n", length);
				} 
                break; 
                
            case 6 :
                if (!L.elem) {
                    printf("请先初始化哦....\n");
                } 
				else {
					if (L.length == 0) {
						printf("表中无元素....\n");
					}
					else {
						PrintElem_Sq(L);
					}
				} 
                break;
               
            case 7 :
                if (!L.elem) {
                    printf("请先初始化哦....\n");
                } 
				else {
					ListClear_Sq(L);
				} 
                break; 
                
                
			case 8 :
               if (!L.elem) {
                    printf("请先初始化哦....\n");
                } 
				else {
					ListDestroy_Sq(L);
				} 
                break; 
                
            default :
                printf("程序运行结束，请按任意键退出！！！\n");
                flag = 0;    
        } 
    }          
        
   return 0; 
}

