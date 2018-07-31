#include<bits/stdc++.h>0
#define Len[i] [pi].size();
using namespace std;
int n,m,x,Ans;
int a[105],b[105];
int ans[105][20500];
int t[20500];
vector < int > p[105];
void find_out(int u)
{
    for(int i = 0;i < Len[u];i ++)   find_out(p[u][i]);
    memset(t,0,sizeof(t));
    for(int i = 0;i < Len[u];i ++)
    {
        x = p[u][i];
        for(int k = 0;k <= m - a[u];k ++)
        {
            if(t[k] < ans[x][k]) t[k] = ans[x][k];
        }
    }
    for(int i = 0;i <= m - a[u];i ++)    ans[u][i + a[u]] = t[i] + b[u];
    for(int i = 0;i <= m - a[u];i ++)
        if(ans[u][i + a[u]] < ans[u][i] + b[u])  ans[u][i + a[u]] = ans[u][i] + b[u];
} 
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i ++)   scanf("%d%d",&a[i],&b[i]);
    for(int i = 1;i <= n;i ++)   scanf("%d",&x),p[x].push_back(i);
    find_out(0);
    for(int i = m;i >= 0;i --)
    {
        if(ans[0][i] > Ans)  Ans = ans[0][i];
    }
    printf("%d",Ans);
}
