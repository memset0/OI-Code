
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define ll long long
#define pb push_back
#define MAXN 2000
#define MAXM 800000 
#define INF 1073741823 
using namespace std;
    int n,m,tmp,s,t,sz=1,yans,sum,rem,num,ulen,cou;
    int val[MAXN],cost[MAXN],H[MAXN],gap[MAXN],cur[MAXN],pre[MAXM],to[MAXM],v[MAXM],las[MAXN],yv[MAXM];
    vector <int> req[MAXN];
    bool canuse1[MAXN],canuse2[MAXN];
    char c[10010];
void ins(int x,int y,int z)
{
    sz++;to[sz]=y;v[sz]=z;pre[sz]=las[x];las[x]=sz;
    sz++;to[sz]=x;v[sz]=0;pre[sz]=las[y];las[y]=sz;
}
void init()
{
    s=1,t=2+n+m;
    for (int i=1;i<=n;i++)
    {
        ins(s,i+1,val[i]);
        for (int j=0;j<req[i].size();j++)
            ins(i+1,1+n+req[i][j],INF);
    }
    for (int i=1;i<=m;i++)
        ins(i+n+1,t,cost[i]);
}
void bfs()
{
    memset(gap,0,sizeof(gap));
    memset(H,-1,sizeof(H));
    H[t]=0,gap[0]=1;
    queue<int> q;
    q.push(t);
    while (!q.empty())
    {
        tmp=q.front();
        q.pop();
        for (int i=las[tmp];i;i=pre[i])
        if (H[to[i]]==-1)
        {
            H[to[i]]=H[tmp]+1;
            gap[H[to[i]]]++;
            q.push(to[i]);
        }
    }
}
int dfs(int x,int F)
{
    if (x==t) return F;
    int used=0,w;
    for (int i=cur[x];i;i=pre[i])
    if (v[i]>0&&H[to[i]]+1==H[x])
    {
        w=min(v[i],F-used);
        w=dfs(to[i],w);
        v[i]-=w,v[i^1]+=w,used+=w;
        if (v[i]>0) cur[x]=i;
        if (F==used) return F;
    }
    gap[H[x]]--;
    if (!gap[H[x]]) H[s]=t+2;
    cur[x]=las[x];
    gap[++H[x]]++;
    return used;
}
int SAP()
{
    int ans=0;
    for (int i=s;i<=t;i++)
        cur[i]=las[i];
    while (H[s]<t+2)
        ans+=dfs(s,INF);
    return ans; 
}
int main()
{
    freopen("INPUT", "r", stdin);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&val[i]);
        sum+=val[i];
        memset(c,0,sizeof(c));
        cin.getline(c,10000);
        ulen=0;
        while (sscanf(c+ulen,"%d",&num)==1)
        {
            req[i].pb(num);
            if (num==0) ulen++;
            else while (num)
            {
                num/=10;
                ulen++;
            }
            ulen++;
        }
    }
    for (int i=1;i<=m;i++)
        scanf("%d",&cost[i]);
    init();
    memcpy(yv,v,sizeof(v));
    bfs();
    yans=SAP();
    for (int i=las[t];i;i=pre[i])
    {
        memcpy(v,yv,sizeof(yv));
        rem=v[i^1];
        v[i^1]=0;
        bfs();
        tmp=SAP();
        if (yans-tmp==rem) canuse1[to[i]-n-1]=true;
        v[i^1]=rem;
    }
    for (int i=1;i<=n;i++)
    {
        canuse2[i]=true;
        for (int j=0;j<req[i].size();j++)
            if (!canuse1[req[i][j]])
            {
                canuse2[i]=false;
                break;
            }
    }
    for (int i=1;i<=n;i++)
        if (canuse2[i]) printf("%d ",i);
    putchar('\n');
    for (int i=1;i<=m;i++)
        if (canuse1[i]) printf("%d ",i);
    putchar('\n');
    printf("%d",sum-yans);
    return 0;
}