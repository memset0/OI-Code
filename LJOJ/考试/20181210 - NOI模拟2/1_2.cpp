#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;

int n,m,ux[100005],uy[100005],uw[100005];
long long dis[305][305],adj[305][305],ans[305],val[100005];
bool ok[100005],vis[305];
int edgenum,nex[100005],vet[100005],head[305];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >Q;


void addedge(int u,int v,long long w)
{
    edgenum++;
    vet[edgenum]=v;
    nex[edgenum]=head[u];
    val[edgenum]=w;
    head[u]=edgenum;
}
void dijkstra(int s)
{
    for (int i=1;i<=n;i++)
        dis[s][i]=1000000000000000000ll,vis[i]=false;
    dis[s][s]=0;
    Q.push(make_pair(0,s));
    while (!Q.empty())
    {
        pair<long long,int> t=Q.top();
        Q.pop();
        int u=t.second;
        if (vis[u]==true) continue;
        vis[u]=true;
        for (int i=head[u];i!=0;i=nex[i])
            if (ok[i]==false && dis[s][u]+val[i]<dis[s][vet[i]])
            {
                dis[s][vet[i]]=dis[s][u]+val[i];
                Q.push(make_pair(dis[s][vet[i]],vet[i]));
            }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        ans[i]=1000000000000000000ll;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            adj[i][j]=1000000000000000000ll;
    while (m--)
    {
        int x,y;long long z;
        scanf("%d%d%lld",&x,&y,&z);
        if (x==y) ans[x]=min(ans[x],z),ans[y]=min(ans[y],z);
        ans[x]=min(ans[x],adj[x][y]+z),ans[y]=min(ans[y],adj[x][y]+z);
        adj[x][y]=min(z,adj[x][y]);
        adj[y][x]=min(z,adj[y][x]);
    }
    m=0;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if (adj[i][j]!=1000000000000000000ll)
            {
                m++,ux[m]=i,uy[m]=j,uw[m]=adj[i][j];
                addedge(i,j,adj[i][j]),addedge(j,i,adj[i][j]);
            }
    if (n<=100)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
                for (int k=1;k<=n;k++)
                {
                    if (j==i || k==i) dis[j][k]=1000000000000000000ll;
                    else dis[j][k]=adj[j][k];
                }
            for(int k=1;k<=n;k++)
                for(int x=1;x<=n;x++)
                    for (int y=1;y<=n;y++)
                        dis[x][y]=min(dis[x][y],dis[x][k]+dis[k][y]);

            for (int x=1;x<=n;x++)
                for (int y=x+1;y<=n;y++)
                    ans[i]=min(ans[i],adj[i][x]+adj[i][y]+dis[x][y]);
        }
    }
    else
    {
        for (int i=1;i<=m;i++)
        {
            ok[i+i-1]=ok[i+i]=true;
            dijkstra(ux[i]),dijkstra(uy[i]);
            for (int j=1;j<=n;j++)
            {
                if (j==ux[i] || j==uy[i]) continue;
                ans[ux[i]]=min(ans[ux[i]],dis[ux[i]][j]+dis[uy[i]][j]+uw[i]);
                ans[uy[i]]=min(ans[uy[i]],dis[ux[i]][j]+dis[uy[i]][j]+uw[i]);
            }
            ok[i+i-1]=ok[i+i]=false;
        }
    }

    for (int i=1;i<=n;i++)
        if (ans[i]==1000000000000000000ll) ans[i]=-1;

    for (int i=1;i<=n;i++)
        printf("%lld ",ans[i]);
    printf("\n");
    return 0;
}