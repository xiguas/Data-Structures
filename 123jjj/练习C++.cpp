#include<iostream>
#include<string>
#include<vector>
#include <cstdio>

typedef int ElementType;

using namespace std;

typedef struct NodeList {
	ElementType value;
	struct NodeList* next;
}Node;

//创建一个链表
Node* CreateList()
{
	Node* root;
//	root->value = 0;
	root->next = NULL;
	if (!root) {
		return NULL;
	}
	else {
		return root;
	} 
} 

//链表中查找

Node* Search(Node* root, int val)
{
	if (!root) {
		return NULL;
	} 
	Node* pNode = root;
	while(pNode) {
		if (pNode->value == val) {
			return pNode;
		}
		pNode = pNode->next; 
	}
	return NULL;
}

void Insert(Node* root, int val)
{
	Node* pNode;
//	pNode->value = val;
	
	pNode = root->next;
	pNode->value = val;
	root->next = pNode; 
}

void Delete(Node* root, int val)
{
	Node* p1 = root->next;
	Node* p2 = root;
	
	while (p1) {
		if (p1->value == val) {
			p2->next = p1->next;
			free(p1);
			break; 
		}
		p1 = p1->next;
		p2 = p2->next;  
	}
}


int main()
{ 
   Node *List ;//= CreateList();
   Insert(List, 1);
   Insert(List, 2);
   Insert(List, 3);
   Insert(List, 4);
   Insert(List, 5);
   
   Delete(List, 3);
   Delete(List, 5);
   
   while(List) {
		printf("%d ", List->value);
		List = List->next; 
   } 
   
   printf("\n*************\n");
   Node *P = Search(List, 4);
   printf("%d", P->value );
   
   
   return 0;
}
