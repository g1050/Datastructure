#include <iostream>
#include <memory>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
const int LEN = 1000;

class ENode{//表示邻接表的链表中的节点 
	public:
		int vex;//下一个节点的编号
		ENode *nextEdge;//指向邻接表中下一个节点的指针域 
};

class VNode{
	public:
		char data;//定点的值
		ENode *firstEdge;//指向链表中的第一个节点 
};

class Graph{
public :int ans;
	private:
		int n,e;
		VNode mVexs[LEN];
		int Degree[LEN][2];
		bool vis[LEN];
		queue<int> q;
		int getNodeIndex(char ch){
			for(int i = 0;i<n;i++){
				if(mVexs[i].data == ch){
					return i;
				}
			}
			return -1;
		}
		
		void insertLast(ENode *p,int start){
			
			ENode *tmp = mVexs[start].firstEdge;
			if(!tmp){
				mVexs[start].firstEdge = p;
			}else{
				while(tmp->nextEdge){
					tmp = tmp->nextEdge;
				}
				tmp->nextEdge = p;
			}
			return ;
		}
		
	public:
		Graph(){
			memset(Degree,0,sizeof(Degree));
			memset(vis,0,sizeof(vis));
		}
		
		void input(){
			cin >> n;
			cin >> e;
			
			for(int i = 0;i<n;i++){
				cin >> mVexs[i].data;
				mVexs[i].firstEdge = NULL;//初始化为空 
			} 
			
			for(int i = 0;i<e;i++){//生成ｅ条边 
				char ch1,ch2;
				cin >> ch1 >> ch2; 
				int start = getNodeIndex(ch1);
				int end = getNodeIndex(ch2);
				
				ENode* p = new ENode();
				p->vex = end;
				p->nextEdge = NULL;
				
				insertLast(p,start);
			} 
		}
		
		void print(){
			for(int i = 0;i<n;i++){
				//cout << mVexs[i].data;
				ENode *tmp = mVexs[i].firstEdge;
				while(tmp){
					Degree[i][0]++;
					//cout << "->" << tmp->vex;
					Degree[tmp->vex][1]++;
					tmp = tmp->nextEdge;
				}
				//cout << endl;
			}
			
		}
		
		void printDegree(){
			for(int i = 0;i<n;i++){
				cout << mVexs[i].data << " " << Degree[i][0]
				<< " " << Degree[i][1] << " "<< 
				Degree[i][0]+Degree[i][1] << endl;
			}
		}
		void dfs(){
            ans = 0;
			for(int i = 0;i<n;i++){
                if(!vis[i]){
                    ans++;
					dfs(0);
                }
                    
			}
		}
		
		void dfs(int index){
			ENode *p = mVexs[index].firstEdge;
			vis[index] = true;
	
			/* cout << mVexs[index].data; */	
			
			while(p){
				if(!vis[p->vex]){
					dfs(p->vex);
				}
				p = p->nextEdge;
			}
		}
		
		void bfs(){
			memset(vis,0,sizeof(vis));
			for(int i = 0;i<n;i++){
				if(!vis[i]){
					vis[i] = true;
					cout << mVexs[i].data;
					
					q.push(i);
					
					while(!q.empty()){
						int index = q.front();
						q.pop();
						
						ENode *p = mVexs[index].firstEdge;
						while(p){
							if(!vis[p->vex]){
								vis[p->vex] = true;
								cout << mVexs[p->vex].data;
								q.push(p->vex);
							}
							p = p->nextEdge;
						}
						
					}

				}
			}
		}
		
		
};
int main()
{
	//cout << "Hello World!" << endl;
	Graph g;
	g.input();

	g.print();
	g.printDegree();
	g.dfs();
    /* cout << g.ans << endl; */
	cout << "\n";
	g.bfs();
    cout << "\n";

	return 0;
}
