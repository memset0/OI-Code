#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
const int inf=1e9;

queue <int> q;
int m,n,x,y,z,maxflow,head[5000],num_edge=-1;
int cur[5000],deep[5000],last[5000],num[5000];
//cur当前弧优化； last该点的上一条边； num桶 用来GAP优化 
struct Edge{
    int next,to,dis;
}edge[500];

void add_edge(int from,int to,int dis,bool flag)
{
    edge[++num_edge].next=head[from];
    edge[num_edge].to=to;
    edge[num_edge].dis=dis;
    head[from]=num_edge;
}

//bfs仅用于更新deep 
void bfs(int t)
{
    while (!q.empty()) q.pop();
    for (int i=0; i<=m; i++) cur[i]=head[i];
    for (int i=1; i<=n; i++) deep[i]=n;
    deep[t]=0;
    q.push(t);

    while (!q.empty())
    {
        int now=q.front(); q.pop();
        for (int i=head[now]; i!=-1; i=edge[i].next)
        {
            if (deep[edge[i].to]==n && edge[i^1].dis)//i^1是为了找反边 
            {
                deep[edge[i].to]=deep[now]+1;
                q.push(edge[i].to);
            }
        }
    }
}

int add_flow(int s,int t)
{
    int ans=inf,now=t;
    while (now!=s)
    {
        ans=min(ans,edge[last[now]].dis);
        now=edge[last[now]^1].to;
    }
    now=t;
    while (now!=s)
    {
        edge[last[now]].dis-=ans;
        edge[last[now]^1].dis+=ans;
        now=edge[last[now]^1].to;
    }
    return ans;
}

void isap(int s,int t)
{
    int now=s;
    bfs(t);//搜出一条增广路
    for (int i=1; i<=n; i++) num[deep[i]]++;

    while (deep[s]<n)
    {
        if (now==t)
        {//如果到达汇点就直接增广，重新回到源点进行下一轮增广 
            maxflow+=add_flow(s,t);
            now=s;//回到源点 
        }

        bool has_find=0;
        for (int i=cur[now]; i!=-1; i=edge[i].next)
        {
            if (deep[now]==deep[edge[i].to]+1 && edge[i].dis)//找到一条增广路 
            {
                has_find=true;
                cur[now]=i;//当前弧优化
                now=edge[i].to;
                last[edge[i].to]=i;
                break;
            }
        }

        if (!has_find)//没有找到出边，重新编号 
        {
            int minn=n-1;
            for (int i=head[now]; i!=-1; i=edge[i].next)//回头找路径 
                if (edge[i].dis)
                    minn=min(minn,deep[edge[i].to]);
            if ((--num[deep[now]])==0) break;//GAP优化 出现了断层 
            num[deep[now]=minn+1]++;
            cur[now]=head[now];
            if (now!=s)
                now=edge[last[now]^1].to;
        }
    }
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d",&m,&n);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z,1); add_edge(y,x,z,0); 
    }
    isap(1,n);
    printf("%d",maxflow);
    return 0;

}