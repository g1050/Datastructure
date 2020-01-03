#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
template <typename  T> 
struct node
{
    node<T> *lchild;
    node<T> *rchild;
    T data;
};

struct inode
{
	char data;
	int dep;	
};

template <typename T>
class Tree
{
private:
    node<T> *t;
	map <int,int > mp;
	vector <inode> vec;
public:
    void createTree(node <T> *&p);
    void createTree();
    void preOrderTraverse();
    void preOrderTraverse(node <T> *p,int level);
    void inOrderTraverse();
    void inOrderTraverse(node <T> *p);
    void postOrderTraverse();
    void postOrderTraverse(node <T> *p);
    int getLeaves(int k);
    void dfs();
    void dfs(node <T> * p,int level);
    void debug();
    char gerAncestor(char a,char b);
};

bool cmp(inode a,inode b)
{
	
	return a.dep < b.dep;
}
template <typename T>
char Tree<T>::gerAncestor(char a,char b)
{
	vector <inode>::iterator st,ed;
	bool flag1 = true,flag2 = true;
	for(vector <inode>::iterator it = vec.begin();it != vec.end();it++){
		if(it->data == a  && flag1){
			st = it;
			flag1 = false;
		}
		if(it->data == b  && flag2){
			ed = it;
			flag2 = false;
		}
	}
	
	if(st > ed) swap(st,ed);
	inode res = *min_element(st,ed,cmp);
	return res.data;
}

template <typename T>
void Tree<T>::debug()
{
	for(vector <inode>::iterator it = vec.begin();it != vec.end();it++){
		cout << it->data << " " << it->dep << endl;
	}
	return;
}

template <typename T>
void Tree<T>::dfs()
{
	dfs(t,1);
	return ;	
}

template <typename T>
void Tree<T>::dfs(node <T> * p,int level)
{
	if(p == NULL) return;
	

		inode tmp;
		tmp.data = p->data;
		tmp.dep = level;
		vec.push_back(tmp); 

	
	
	dfs(p->lchild,level+1);
	
	if(p->rchild){
		inode tmp2;
		tmp2.data = p->data;
		tmp2.dep = level;
		vec.push_back(tmp2);
	}
	
	 
	dfs(p->rchild,level+1);
	return ;	
}

template <typename T>
int Tree<T>::getLeaves(int k)
{
	if(mp.count(k)){
		return mp[k];
	}else return 0;
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
    std::cout << p->data ;
    return ;
}

    template <typename T>
void Tree<T>::preOrderTraverse()
{
    this->preOrderTraverse(t,1);
    return ;
}

    template <typename T>
void Tree<T>::preOrderTraverse(node <T> *p,int level)
{
    if(p == NULL) return ;
    std::cout << p->data ;
    //std::cout << "(" << p->data << "," << level << ")";
    if(!p->lchild && !p->rchild){
    	mp[level]++;
    }
    preOrderTraverse(p->lchild,level+1);
    preOrderTraverse(p->rchild,level+1);
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
    t.createTree();//采用先根遍历的方法输入这个树
    t.dfs();
    //t.debug();
    char a,b;
    cin >> a >> b;
    cout << t.gerAncestor(a,b);
    return 0;
}

