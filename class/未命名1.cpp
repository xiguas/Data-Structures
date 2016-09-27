#include <iostream>
#include <stack>
using namespace std;

class classWithMax {
private:
	stack<int> valueStack;
	stack<int> maxStack;
	
public:
	void push(int);
	int pop();
	int max();		
}; 

void classWithMax::push(int value)
{
	if (maxStack.empty() || maxStack.top() <= value)
 } 
