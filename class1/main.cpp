#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "SqList.h"

using namespace std;
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main()
{
    int number;         // ѡ�� 
	int flag = 1;       // ��־ 
	int length, i, position;
	ElemType e; 
    
	SqList L;           // ���Ա� L 
    L.elem = NULL; 

    while (flag) {
    	
       printf("|******************************************|\n");  	
       printf("|           ���Ա�Ļ�������               |\n");
       printf("|******************************************|\n");    
       printf("|            1. ��ʼ�����Ա�               |\n");    
       printf("|            2. �����Ա�������Ԫ��         |\n");    
       printf("|            3. �����Ա���ɾ��Ԫ��         |\n");    
       printf("|            4. ����Ԫ��                   |\n");    
       printf("|            5. �������Ա�ĳ���           |\n");    
       printf("|            6. ������Ա�                 |\n");    
       printf("|            7. ������Ա�                 |\n");    
       printf("|            8. �������Ա�                 |\n");    
       printf("|******************************************|\n");
       printf("��ѡ���� ��                               \n");
        
       cin >> number;
	    
       switch( number ) {
            case 1 :
                if (InitList_Sq(L)) {
					printf("��ʼ���ɹ�...\n");
			    }
                break; 
            
            case 2 :
                if (!L.elem) {
                   	printf("���ȳ�ʼ��Ŷ....\n");
                } 
				else {
					printf("��������Ҫ�����λ�ã�");
					scanf("%d", &i);
					printf("��������Ҫ�����Ԫ�أ�");
					scanf("%d", &e);
					if (ListInsert_Sq(L, i, e)) {
						printf("����ɹ�....\n"); 
					}
				} 
                break;
                
            case 3 :
                if (!L.elem) {
                    printf("���ȳ�ʼ��Ŷ....\n");
                } 
				else {
					printf("��������Ҫɾ����λ�ã�");
					scanf("%d", &i);
					printf("��������Ҫɾ����Ԫ�أ�");
					scanf("%d", &e);
					if (ListDelete_Sq(L, i, e)) {
						printf("ɾ�� %d �ɹ�....\n", e); 
					}
				} 
                break;
                
				
            case 4 :
                if (!L.elem) {
                    printf("���ȳ�ʼ��Ŷ....\n");
                } 
				else {
					printf("��������Ҫ���ҵ�Ԫ�أ�");
					scanf("%d", &e);
					
					position = LocateElem_Sq(L, e);
					if (position) {
						printf("%d ��λ���ڵ� %d  ....\n", e, position);
					}
					else {
						printf(" %d Ԫ�ز�����...\n");
					}
				} 
                break;
                
           case 5 :
                if (!L.elem) {
                    printf("���ȳ�ʼ��Ŷ....\n");
                } 
				else {
					length = ListLength_Sq(L);
					printf("���Ա�ĳ���Ϊ %d \n", length);
				} 
                break; 
                
            case 6 :
                if (!L.elem) {
                    printf("���ȳ�ʼ��Ŷ....\n");
                } 
				else {
					if (L.length == 0) {
						printf("������Ԫ��....\n");
					}
					else {
						PrintElem_Sq(L);
					}
				} 
                break;
               
            case 7 :
                if (!L.elem) {
                    printf("���ȳ�ʼ��Ŷ....\n");
                } 
				else {
					ListClear_Sq(L);
				} 
                break; 
                
                
			case 8 :
               if (!L.elem) {
                    printf("���ȳ�ʼ��Ŷ....\n");
                } 
				else {
					ListDestroy_Sq(L);
				} 
                break; 
                
            default :
                printf("�������н������밴������˳�������\n");
                flag = 0;    
        } 
    }          
        
   return 0; 
}

