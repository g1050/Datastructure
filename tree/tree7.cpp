#include <iostream>
#include <string>
using namespace std;
template <typename  T> 
struct node
{
    node<T> *lchild;
    node<T> *rchild;
    T data;
};

template <typename T>
class Tree
{
private:
    node<T> *t;
	string pre,in,post;
public:
    void createTree(node <T> *&p);
    void createTree();
    void preOrderTraverse();
    void preOrderTraverse(node <T> *p);
    void inOrderTraverse();
    void inOrderTraverse(node <T> *p);
    void postOrderTraverse();
    void postOrderTraverse(node <T> *p);
    void inputPreAndIn();
    void inputPostAndIn();
    void getPost();
    void getPost(string pre,string in,int len);
    void getIn();
    void getIn(string post,string in,int len); 
};

template <typename T>
void Tree<T>::getIn()
{
	getIn(post,in,in.length());
	return ;
}

template <typename T>
void Tree<T>::getIn(string post,string in,int len)
{
	//cout << post << "  " << in << "-------" << endl;
	if(len <= 0) return;
	
	int l = in.find(post[post.length()-1]);
	//cout << "l = " << l << "***** " << endl;
	cout << post[post.length()-1];
	{
		getIn(post.substr(0,l),in.substr(0,l),l);
		getIn(post.substr(l,len-l-1),in.substr(l+1,len-l-1),len-l-1);
	}
	
	return ;
}

template <typename T>
void Tree<T>::getPost()
{
	getPost(this->pre,this->in,this->in.length());
	return ;
}

template <typename T>
void Tree<T>::getPost(string pre,string in,int len)
{
	if(len <= 0) return;
	int l = in.find(pre[0]);
	//getPost(pre.substr(1,l),in.substr(0,l),l);
	//getPost(pre.substr(l+1,len-l-1),in.substr(l+1,len-l-1),len-l-1);
	//cout << "l = " << l << endl;
	cout << pre[0] ;
	return ;
}

template <typename T>
void Tree<T>::inputPreAndIn()
{
	cin >> pre >> in;
}

template <typename T>
void Tree<T>::inputPostAndIn()
{
	cin >> in >> post;
}
    template <typename  T>
void Tree<T>::postOrderTraverse()
{
    this->postOrderTraverse(t);
    return ;
}

    template <typename T>
void Tree<T>::postOrderTraverse(node <T> *p)
{
    if(p == NULL) return ;
    postOrderTraverse(p->lchild);
    postOrderTraverse(p->rchild);
    std::cout << p->data << " ";
    return ;
}

    template <typename T>
void Tree<T>::preOrderTraverse()
{
    this->preOrderTraverse(t);
    return ;
}

    template <typename T>
void Tree<T>::preOrderTraverse(node <T> *p)
{
    if(p == NULL) return ;
    std::cout << p->data << " ";
    preOrderTraverse(p->lchild);
    preOrderTraverse(p->rchild);
    return ;
}
    template <typename T>
void Tree<T>::inOrderTraverse()
{
    this->inOrderTraverse(t);
    return ;
}

    template <typename T>
void Tree<T>::inOrderTraverse(node <T> *p)
{
    if(p == NULL) return ;
    inOrderTraverse(p->lchild);
    std::cout << p->data << " ";
    inOrderTraverse(p->rchild);
    return ;
}


    template <typename T>
void Tree<T>::createTree(node <T> *&p)
{
    T tmp;
    std::cin >> tmp;
    if(tmp == '#'){
        p = NULL;
    }
    else{
        p = new node <T>;
        if(p == NULL){
            std::cout << "func createTree error\n";
            //exit(1);
        }
        /* std::cout << "p = " << p << std::endl; */
        p->data = tmp;
        /* std::cout << p->data << std::endl; */

        this->createTree(p->lchild);

        this->createTree(p->rchild);
    }
    return ;
}

    template <typename T>
void Tree<T>::createTree()
{
    this->createTree(t);
}

int main()
{
    Tree <char> t;
    t.inputPostAndIn();
    t.getIn();
    return 0;
}

