#include <iostream>

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

public:
    void createTree(node <T> *&p);
    void createTree();
    void preOrderTraverse();
    void preOrderTraverse(node <T> *p);
    void inOrderTraverse();
    void inOrderTraverse(node <T> *p);
    void postOrderTraverse();
    void postOrderTraverse(node <T> *p);
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
    std::cout << p->data ;
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
    std::cout << p->data ;
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
    t.preOrderTraverse();//先序遍历的结果
    std::cout << "\n"; 
    t.inOrderTraverse();
    std::cout << "\n";
    t.postOrderTraverse();
    std::cout << "\n";
    return 0;
}

