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
	
	//���õ�����,������ͷ���
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
	
	ins->next = NULL;//����β�巨
	last->next = ins;
	
	last = ins;//��β���ת��
	qsize++; 
	return ;
}

template <class T>
void queue<T>::pop()
{
	if(first == last){//���д�ʱΪ�� 
		cout << "func: pop() error \n"; 
		exit(0) ;
	}
	//ͷ���ĺ�̽ڵ���� 
	node *tmp = first->next;//�����ӽڵ�
	first->next = tmp->next;//�����
	
	if(tmp->next == NULL){//ɾ�����Ƕ�βԪ�أ�βָ��ص���ʼλ�� 
		last = first;
	} 
	delete tmp;
	qsize--;
	return ;
}

template <class T>
T queue<T>::front()
{
	if(first == last){//���д�ʱΪ�� 
		cout << "func: front() error \n"; 
		exit(0) ;
	}
	return first->next->data;
}

template <class T>
T queue<T>::back()
{
	if(first == last){//���д�ʱΪ�� 
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
