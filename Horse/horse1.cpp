#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX = 8;
 
struct spot
{
    int x;
    int y;
    int d;
};
 
int dir[9][2] = { {0,0},
    {-2,1},{-1,2},{1,2},{2,1},
    {2,-1},{1,-2},{-1,-2},{-2,-1}
};
 
class Board
{
public:
    Board(int x,int y);
    void setNum();
    bool inRange(spot &next);
    void nextStep(spot &cur,spot &next);
    void printAns();
private:
    int mp[10][10];
    int vis[10][10];
    int stx;
    int sty;
    int step;
    stack <spot> s;
};
 
void Board::printAns()
{
    for(int i = 1;i<=8;i++){
        for(int j = 1;j<=8;j++){
            printf("%2d ",mp[i][j]);
        }
        printf("\n");
    }
             
    return ;
}
Board::Board(int x,int y)
{
    memset(mp,0,sizeof(mp));
    memset(vis,0,sizeof(vis));//0认为没有走过
    mp[x][y] = 1;
    vis[x][y] = 1;
    stx = x;
    sty = y;
    step = 0;
    return ;
}
 
void Board::nextStep(spot &cur,spot &next)
{
    if(cur.d > 8) return ;
    //向下一个方向试探
    next.x = cur.x+dir[cur.d][0];
    next.y = cur.y+dir[cur.d][1];
    return ;
}
bool Board::inRange(spot &next)
{
    if(next.x >= 1 && next.x <= MAX && next.y >= 1 && next.y <= 8 
       && vis[next.x][next.y] == 0){
            return true;
    }else{
        return false;
    }
}
 
void Board::setNum()
{
    //初始位置为(stx,sty)
     
    //spot记录每次走的位置信息，并且压入栈中
    spot cur,nextt;//分别记录当前位置和下一位置
     
    //初始化cur
    cur.x = stx;
    cur.y = sty;
    cur.d = 1;//0表示还未进行试探
    nextt.d = 1;
 
    while(step < 64){
        int i ;
        int flag = 0;
        for(i = cur.d;i <= 8;i++){//向8个方向进行试探
            nextt.x = cur.x+dir[i][0];
            nextt.y = cur.y+dir[i][1];
           if(inRange(nextt) && cur.d <= 8){//合法
               cur.d = i+1;
               s.push(cur);
               vis[cur.x][cur.y] = 1;
               mp[cur.x][cur.y] = ++step;
               cur = nextt;//改变当前位置
               flag = 1;
 
               if(step == 63){
                    mp[nextt.x][nextt.y] = ++step;
               }
 
               break;//不在继续向下试探
           }
            
        }
 
        if(!s.empty() && !flag){//回退上一步
                    cur = s.top();
                    s.pop();
                    step--;
                    vis[cur.x][cur.y] = 0;
                    mp[cur.x][cur.y] = 0;
                    /* cur.d++; */
                
           }
    }
 
    return ; 
}
 
int main()
{
    int x,y;
    cin >> x >> y;
    Board b(x,y);
    b.setNum();
    b.printAns();
    return 0;
}
 
 
/**************************************************************
    Problem: 1841
    User: 04183102
    Language: C++
    Result: 正确
    Time:9087 ms
    Memory:1688 kb
****************************************************************/
