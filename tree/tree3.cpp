#include <iostream>
#include <stack>
using namespace std;
template <typename  T> 
struct node
{
    node<T> *lchild;
    node<T> *rchild;
    bool ltag ;
    bool rtag ;
    bool mtag ;
    T data;
};

template <typename T>
class Tree
{
private:
    node<T> *t;
    stack <node<T> > s;
public:
    void createTree(node <T> *&p);
    void createTree();
    void preOrderTraverse();
    void preOrderTraverse(node <T> *p);
    void inOrderTraverse();
    void inOrderTraverse(node <T> *p);
    void postOrderTraverse();
    void postOrderTraverse(node <T> *p);
    void preOrderTraverse2();
    void inOrderTraverse2();
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
    std::cout << p->data << " ";
    return ;
}

template <typename T>
void Tree<T>::preOrderTraverse2()
{
    if(t != NULL){
        cout << t->data ;
        s.push(*t);//将根节点入栈
    }
   while(!s.empty()){
       node<T> tmp = s.top();
       if(tmp.lchild != NULL && tmp.ltag){
           tmp.ltag = false;
           s.pop();s.push(tmp);
           s.push(*(tmp.lchild));
           cout << tmp.lchild->data;
       }
       else if(tmp.rchild != NULL && tmp.rtag){
           tmp.rtag = false;
           s.pop();s.push(tmp);
           s.push(*(tmp.rchild));
           cout << tmp.rchild->data;
       }else if(tmp.lchild == NULL && tmp.rchild == NULL){
           s.pop();
       }else{
           s.pop();
       }
   }
   cout << "\n";

   return ;
}

template <typename  T>
void Tree<T>::inOrderTraverse2()
{
    stack <node<T> *> s;
    node <T> *p;
    p = t;
    if(p == NULL)   return;
    while(!s.empty() || p){
        if(p){
            s.push(p);
            p = p->lchild;
        }else{
            p = s.top();
            s.pop();
            cout << p->data ;
            p = p->rchild;
        }
    }
    cout << "\n";
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
            exit(1);
        }
        /* std::cout << "p = " << p << std::endl; */
        p->data = tmp;
        /* std::cout << p->data << std::endl; */
        p->ltag = true;
        p->rtag = true;
        p->mtag = true;
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
    t.createTree();//采用先根遍历的方法输入这个树
    t.preOrderTraverse2();
    t.inOrderTraverse2();
    return 0;
}

