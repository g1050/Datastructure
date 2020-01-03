#include <iostream>
#include <queue>
#include <string>
#include <memory.h>

const int MAXN = 100;

/* 边的结构 */
struct EdgeNode{
    EdgeNode(){
        next = NULL;
    }
    int adjvex;//存储临界点的位置
    EdgeNode *next;
};

/* 定点结构 */
struct AdjList{
    std::string data;//数据域
    EdgeNode *firstEdge;
};

//定义临接表结构
struct GraphAdjList{
private:
    AdjList adjlist[MAXN];
    bool visit[MAXN];
    int numVertex,numEdge;

public:

    GraphAdjList(int numVertex,int numEdge){
        memset(visit,false,sizeof(visit));
        this->numVertex = numVertex;
        this->numEdge = numEdge;
    }

    /* 查找某个定点所在的位置 */
    int local(std::string val){
        for(int i = 0;i<numVertex;i++){
            if(adjlist[i].data == val){
                return i;
            }
        }
        return -1;
    }

    bool createGraph(){

        /* 首先输入定点信息 */
        for(int i = 0;i<numVertex;i++){
            std::cout << "Please the " << i+1 << " vertex: " ;    
            std::cin >> adjlist[i].data;
            adjlist->firstEdge = NULL;//初始化每个点的next指向空
        }

        /* 其次输入边的信息 */
        for(int k = 0;k<numEdge;k++){
            std::string v1,v2;
            std::cout << "Please input edge(v1,v2)" ;
            std::cin >> v1 >> v2;
            int i = local(v1);
            int j = local(v2);

            if(i == -1 || j == -1){
                std::cout << i << " " << j << std::endl;
                std::cout << "Input error" << std::endl;
                return false;
            }

            /* 最后把边对应的两个定点加入到图中 */
            if(adjlist[i].firstEdge == NULL){//对应孤立节点的情况，没有与任何点相连接
                //申请新节点，直接插入就可以
                EdgeNode *e = new EdgeNode();
                e->adjvex = j;
                adjlist[i].firstEdge = e;
            }else{//对应已经加入图中的节点
                //指针后移，将新节点插入最后
                EdgeNode *p = adjlist[i].firstEdge;
                while(p->next != NULL){
                    p = p->next;
                }
                EdgeNode *e = new EdgeNode();
                e->adjvex = j;
                p->next = e;
            }
            if(adjlist[j].firstEdge == NULL){//对应孤立节点的情况，没有与任何点相连接
                //申请新节点，直接插入就可以
                EdgeNode *e = new EdgeNode();
                e->adjvex = i;
                adjlist[j].firstEdge = e;
            }else{//对应已经加入图中的节点
                //指针后移，将新节点插入最后
                EdgeNode *p = adjlist[j].firstEdge;
                while(p->next != NULL){
                    p = p->next;
                }
                EdgeNode *e = new EdgeNode();
                e->adjvex = i;
                p->next = e;
            }

        }
        return true;
    }

    void print(){

        for(int i = 0;i<numVertex;i++){
            std::cout << adjlist[i].data;
            EdgeNode *p = adjlist[i].firstEdge;
            while(p){
                std::cout << "->" << p->adjvex;
                p = p->next;
            }
            std::cout << std::endl;
        }
    }

    void DFS(int i){//i表示遍历的起点
        visit[i] = true;
        std::cout << adjlist[i].data << " ";
        EdgeNode *p = adjlist[i].firstEdge;
        while(p){
            if(!visit[p->adjvex]){//没走过的可以进入
                DFS(p->adjvex);
            }
            p = p->next;
        }
        return ;
    }

    void DFS(){

        for(int i = 0;i < numVertex;i++){
            if(!visit[i]){
                DFS(i);
            }
        }
        std::cout << std::endl;
        memset(visit,false,sizeof(visit));
        return ;
    }

    void BFS(){
        std::queue<int> q;
        for(int i = 0;i<numVertex;i++){
            if(!visit[i]){//某走过的地方
               visit[i] = true; 
               std::cout << adjlist[i].data << " ";
               q.push(i);

               while(!q.empty()){
                    int index = q.front();
                    q.pop();
                    EdgeNode *p = adjlist[index].firstEdge;
                    while(p){
                        if(!visit[p->adjvex]){
                            visit[p->adjvex] = true;
                            std::cout << adjlist[p->adjvex].data << " ";
                            q.push(p->adjvex);
                        }
                        p = p->next;
                    }
               }

            }

        }
        std::cout << std::endl;
    }
        
    

};


int main()
{
    GraphAdjList *g = new GraphAdjList(5,6);
    g->createGraph();
    g->print();
    g->DFS();
    g->BFS();
    return 0;
}

