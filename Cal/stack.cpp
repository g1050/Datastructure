#include <iostream>
#include <cstdlib>
#include "stack.h"
using namespace std;
template <class T>
bool stack<T>::empty()
{
	if(first == NULL)
		return true;
	else return false;
}

template <class T>
int stack<T>::size()
{
	return qsize;
}

template <class T>
stack<T>::stack()
{
	qsize = 0;
	
	//采用单链表,且不设置头结点
	first = NULL;
}

template <class T>
void stack<T>::push(T elem)
{
	node* ins = new node;
	if(ins == NULL){
		cout << "func: push(T elem) error\n" ;
		exit(0);
		//cout << "func:stack<T>::push(T elem) error line::" << __line__ << "\n";
	}
	ins->data = elem;
	
	ins->next = first;//采用头插法
	first = ins;
	
	qsize++; 
	return ;
}

template <class T>
void stack<T>::pop()
{
	if(first == NULL){//栈此时为空 
		cout << "func: pop() error \n"; 
		exit(0) ;
	}
	//头结点的后继节点出队 
	node *tmp = first;//待出栈节点
	first = tmp->next;//向后跳
	
	delete tmp;
	qsize--;
	return ;
}

template <class T>
T stack<T>::top()
{
	if(first == NULL){//队列此时为空 
		cout << "func: top() error \n"; 
		exit(0) ;
	}
	return first->data;
}


/*
int main()
{
	stack<int> q;
	
	if(q.empty())
		cout << "Stack is empty!\n";
		
	for(int i = 0;i<5;i++){
		q.push(i);
		cout << "top = " << q.top() << "\n";
	}
	
	if(q.empty())
		cout << "Stack is empty!\n";
		
	for(int i = 0;i<5;i++){
		cout << q.top() << endl;
		
		q.pop();
		
		cout << "size = " << q.size() << endl;
	}
	return 0;
}
*/

