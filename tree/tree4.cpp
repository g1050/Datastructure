#include <iostream>
#include <stack>
#include  <set>
using namespace std;
template <typename  T> 
struct node
{
    node<T> *lchild;
    node<T> *rchild;
    bool ltag;
    bool rtag;
    T data;
};

template <typename T>
class Tree
{
private:
    node<T> *t;

public:
    void createTree(node <T> *&p);
    void createTree();
    void preOrderTraverse();
    void preOrderTraverse(node <T> *p);
    void inOrderTraverse();
    void inOrderTraverse(node <T> *p);
    void postOrderTraverse();
    void postOrderTraverse(node <T> *p);
    void postOrderTraverse2();
};
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
    std::cout << p->data ;
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
        p->ltag = true;
        p->rtag = true;
        /* std::cout << "p = " << p << std::endl; */
        p->data = tmp;
        /* std::cout << p->data << std::endl; */

        this->createTree(p->lchild);

        this->createTree(p->rchild);
    }
    return ;
}

template <typename T>
void Tree<T>::postOrderTraverse2()
{
    set<node<T> *> se;
    stack< node<T>*> s;
    node <T> *p = t;
    if(p == NULL) return;
   
    while(!s.empty() || p){
        if(p){
            s.push(p);
            se.insert(p);
            p = p->lchild;
        }else{
            p = s.top();
            s.pop();
            cout << p->data ;
        }
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
    t.createTree();//采用先根遍历的方法输入这个树
    t.postOrderTraverse();
    return 0;
}

