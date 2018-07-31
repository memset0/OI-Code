#include<bits/stdc++.h>
#define N 2005
#define next chr01
#define point chr02
#define ans chr03
using namespace std;
int n,m,x,y,tot;
int next[N*N*2],point[N],v[N*N*2],ans[N];
bool b[N],k;
void f(int x,int y,int i)
{
    v[i] = y; next[i] = point[x]; point[x]=i;
}
  
void dfs(int x)
{
    b[x] = 1;
    if (x == n){
        k = 1; return;
    }
    for (int i = point[x]; i > 0;i = next[i])
      if (!b[v[i]]){
        dfs(v[i]);
        if(k > 0)
            return;
      }
}
int main()
{
    cin >> n >> m;
    for (int i=1;i<=m;++i)
    {
        scanf("%d%d",&x,&y);
        f(x,y,i * 2);
        f(y,x,i * 2|1);
    }
    for (int i = 2;i < n;++i)
    {
        k = 0;
        memset(b,0,sizeof(b));
        b[i] = 1;
        dfs(1);
        if (!k) ans[++tot]=i;
    }
  
    printf("%d\n",tot);
    for (int i=1;i < tot;++i)
      printf("%d ",ans[i]);
    printf("%d\n",ans[tot]);
    return 0;
}