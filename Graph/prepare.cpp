#include <iostream>
#include <queue>
#include <string>
#include <memory.h>

const int MAXN = 0xffff; 
const int MAXSIZE = 100;

struct Coordinate{
    int x;
    int y;
};

/* 边的结构 */
struct EdgeNode{
    EdgeNode(){
        next = NULL;
        weight = 1;
    }
    int adjvex;//与表头节点相连的节点存储的下标位置
    int weight;//改边的权重,后期可提升为数组
    EdgeNode *next;
};

/* 顶点结构 */
struct AdjList{
    std::string data;//数据域
    Coordinate coordinate;
    EdgeNode *firstEdge;
};

/* 用来存储每个节点的到源点的最短路径 */
struct Node{
    int pos; //该节点的位置
    int minWeight; //该节点与源定点的距离
    /* 重载运算符，以使最小Node节点出队 */
    friend bool operator<(Node a,Node b){
        return a.minWeight > b.minWeight;
    }
};

//定义临接表结构
struct GraphAdjList{
private:
    int parent[MAXSIZE];//记录寻找最短路径时每个节点的父节点
    AdjList adjlist[MAXSIZE];
    bool visit[MAXSIZE];
    Node node[MAXSIZE];
    std::priority_queue<Node> q;//优先队列
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
            std::cout << "Please input the " << i+1 << " vertex: " ;    
            std::cin >> adjlist[i].data;
            std::cout << "Please input the coordinate ";
            std::cin >> adjlist[i].coordinate.x >> adjlist[i].coordinate.y;
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
            std::cout << "(" << adjlist[i].coordinate.x << "," << adjlist[i].coordinate.y << ")";
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
        memset(visit,false,sizeof(visit));
    }
        
    void destroyGraph(){
        EdgeNode* p = NULL;

        for(int i = 0;i<numVertex;i++){
            p = adjlist[i].firstEdge;
            while(p){
                EdgeNode *tmp = p;
                p = p->next;
                delete tmp;
            }
            adjlist[i].firstEdge = NULL;
        }
        return ;
    }
    
    void Dijkstrta(int st){
        
        /* 每次调用该函数都要初始化 */
        for(int i = 0;i<numEdge;i++){
            node[i].pos = i;
            node[i].minWeight = MAXN;//初始状态每个点到源点的距离无限大
            parent[i] = -1; //每个节点都没有父亲节点
            visit[i] = false;
        }

        node[st].minWeight = 0;//到自己的最短距离就是0
        q.push(node[st]);

        while(!q.empty()){
            
            Node tp = q.top();
            q.pop();
            int pos = tp.pos;//获取队首元素的值

            if(visit[pos])  continue;
            visit[pos] = true;
            EdgeNode *p = adjlist[pos].firstEdge ;
            while(p){//遍历所有与p相连的节点
                int cur = p->adjvex;//获取当前节点的位置
                if(!visit[cur] && node[cur].minWeight > node[pos].minWeight + p->weight){//整个算法的核心的
                    node[cur].minWeight = node[pos].minWeight + p->weight;//更新值
                    parent[cur] = pos;
                    q.push(node[cur]);
                }
                p = p->next;
            }

        }
    }

    void printShortestPath(int ed){

        std::cout << "(" << adjlist[ed].coordinate.x << "," << adjlist[ed].coordinate.y << ")" << std::endl;

        int q = parent[ed];
        while(q != -1){
            std::cout << "(" << adjlist[q].coordinate.x << "," << adjlist[q].coordinate.y << ")" << std::endl;
            /* 向上一节点转移 */
            q = parent[q];
        }

        if(node[ed].minWeight != MAXN){
            std::cout << "The shortest path is " << node[ed].minWeight << std::endl;;
        }else{
            std::cout << "Not find." << std::endl;
        }
   
        return ;
    }
};


int main()
{
    GraphAdjList *g = new GraphAdjList(5,5);
    int st,ed;

    g->createGraph();
    g->print();
    /* g->DFS(); */
    /* g->BFS(); */

    std::cout << "Please input the begin: ";
    std::cin >> st; 
    std::cout << "Please input the end ";
    std::cin >> ed;

    g->Dijkstrta(st);
    g->printShortestPath(ed);

    g->destroyGraph();
    return 0;
}

