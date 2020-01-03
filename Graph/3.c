#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mp[100][100];
int visit[100];
void dfs(int x,int n)
{
   int i;
   visit[x]=1;
   for(i=1;i<=n;i++)
   {
       if(!visit[i]&&mp[x][i])
       {
          dfs(i,n);
       }
   }
}
int main()
{
    int T,n,m,u,v,i,count;
    scanf("%d",&T);
    while(T--)
    {  count=0;
       scanf("%d%d",&n,&m);
       memset(mp,0,sizeof(mp));
       memset(visit,0,sizeof(visit));
       for(i=0;i<=m-1;i++)
       {
           scanf("%d%d",&u,&v);
           mp[u][v]=mp[v][u]=1;
       }
       for(i=1;i<=n;i++)
       {
           if(!visit[i])
           {
              dfs(i,n);
              count++;//每有一个新的未被标记的点就有了一个新的分支
           }
       }
       printf("%d\n",count);
    }
    return 0;
}
