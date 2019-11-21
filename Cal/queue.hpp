#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class queue
{
	struct node
		{
			T data;
			struct node *next;	
		};
public:
	queue();
	void push(T elem);
	void pop();
	T front();
	int size();
	bool empty();
	T back();
private:
	node* first;
	node* last;
	int qsize; 
};

template <class T>
bool queue<T>::empty()
{
	if(first == last)
		return true;
	else return false;
}

template <class T>
int queue<T>::size()
{
	return qsize;
}

template <class T>
queue<T>::queue()
{
	qsize = 0;
	
	//采用单链表,且设置头结点
	first = new node;
	last = first; 
	first->next = NULL;
}

template <class T>
void queue<T>::push(T elem)
{
	node* ins = new node;
	if(ins == NULL){
		cout << "func: push(T elem) error\n" ;
		exit(0);
		//cout << "func:queue<T>::push(T elem) error line::" << __line__ << "\n";
	}
	ins->data = elem;
	
	ins->next = NULL;//采用尾插法
	last->next = ins;
	
	last = ins;//队尾向后转移
	qsize++; 
	return ;
}

template <class T>
void queue<T>::pop()
{
	if(first == last){//队列此时为空 
		cout << "func: pop() error \n"; 
		exit(0) ;
	}
	//头结点的后继节点出队 
	node *tmp = first->next;//待出队节点
	first->next = tmp->next;//向后跳
	
	if(tmp->next == NULL){//删除的是队尾元素，尾指针回到开始位置 
		last = first;
	} 
	delete tmp;
	qsize--;
	return ;
}

template <class T>
T queue<T>::front()
{
	if(first == last){//队列此时为空 
		cout << "func: front() error \n"; 
		exit(0) ;
	}
	return first->next->data;
}

template <class T>
T queue<T>::back()
{
	if(first == last){//队列此时为空 
		cout << "func: back() error \n"; 
		exit(0) ;
	}
	return last->data;
}

/*
int main()
{
	queue<int> q;
	
	if(q.empty())
		cout << "Queue is empty!\n";
		
	for(int i = 0;i<5;i++){
		q.push(i);
		cout << "back = " << q.back() << "\n";
	}
	
	if(q.empty())
		cout << "Queue is empty!\n";
		
	for(int i = 0;i<5;i++){
		cout << q.front() << endl;
		
		q.pop();
		
		cout << "size = " << q.size() << endl;
	}
	return 0;
}
*/
