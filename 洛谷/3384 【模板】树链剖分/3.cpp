#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=2*1e6+10;
#define ls k<<1
#define rs k<<1|1
inline char nc()
{
    static char buf[MAXN],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,MAXN,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
    char c=nc();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=nc();}
    while(c>='0'&&c<='9'){x=x*10+c-'0',c=nc();}
    return x*f;
}
struct node
{
    int u,v,nxt;
}edge[MAXN];
int head[MAXN];
int num=1;
struct Tree
{
    int l,r,w,siz,f;
}T[MAXN];
int N,M,root,MOD,cnt=0,a[MAXN],b[MAXN];
inline void AddEdge(int x,int y)
{
    edge[num].u=x;
    edge[num].v=y;
    edge[num].nxt=head[x];
    head[x]=num++;
}
int deep[MAXN],fa[MAXN],son[MAXN],tot[MAXN],top[MAXN],idx[MAXN];
int dfs1(int now,int f,int dep)
{
    deep[now]=dep;
    fa[now]=f;
    tot[now]=1;
    int maxson=-1;
    for(int i=head[now];i!=-1;i=edge[i].nxt)
    {
        if(edge[i].v==f) continue;
        tot[now]+=dfs1(edge[i].v,now,dep+1);
        if(tot[edge[i].v]>maxson) maxson=tot[edge[i].v],son[now]=edge[i].v;
    }
    return tot[now];
}
void update(int k)
{
    T[k].w=(T[ls].w+T[rs].w+MOD)%MOD;
}
void Build(int k,int ll,int rr)
{
    T[k].l=ll;T[k].r=rr;T[k].siz=rr-ll+1;
    if(ll==rr)
    {
        T[k].w=a[ll];
        return ;
    }
    int mid=(ll+rr)>>1;
    Build(ls,ll,mid);
    Build(rs,mid+1,rr);
    update(k);
}
void dfs2(int now,int topf)
{
    idx[now]=++cnt;
    a[cnt]=b[now];
    top[now]=topf;
    if(!son[now]) return ;
    dfs2(son[now],topf);
    for(int i=head[now];i!=-1;i=edge[i].nxt)
        if(!idx[edge[i].v])
            dfs2(edge[i].v,edge[i].v);
}
void pushdown(int k)
{
    if(!T[k].f) return ;
    T[ls].w=(T[ls].w+T[ls].siz*T[k].f)%MOD;
    T[rs].w=(T[rs].w+T[rs].siz*T[k].f)%MOD;
    T[ls].f=(T[ls].f+T[k].f)%MOD;
    T[rs].f=(T[rs].f+T[k].f)%MOD;
    T[k].f=0;
}
void IntervalAdd(int k,int ll,int rr,int val)
{
    if(ll<=T[k].l&&T[k].r<=rr)
    {
        T[k].w+=T[k].siz*val;
        T[k].f+=val;
        return ;
    }
    pushdown(k);
    int mid=(T[k].l+T[k].r)>>1;
    if(ll<=mid)    IntervalAdd(ls,ll,rr,val);
    if(rr>mid)    IntervalAdd(rs,ll,rr,val);
    update(k);
}
void TreeAdd(int x,int y,int val)
{
    while(top[x]!=top[y])
    {
        if(deep[top[x]]<deep[top[y]]) swap(x,y);
        IntervalAdd(1,idx[ top[x] ],idx[x],val);
        x=fa[ top[x] ];
    }
    if(deep[x]>deep[y])    swap(x,y);
    IntervalAdd(1,idx[x],idx[y],val);
}
int IntervalSum(int k,int ll,int rr)
{
    int ans=0;
    if(ll<=T[k].l&&T[k].r<=rr)
        return T[k].w;
    pushdown(k);
    int mid=(T[k].l+T[k].r)>>1;
    if(ll<=mid) ans=(ans+IntervalSum(ls,ll,rr))%MOD;
    if(rr>mid)  ans=(ans+IntervalSum(rs,ll,rr))%MOD;
    return ans;
}
void TreeSum(int x,int y)
{
    int ans=0;
    while(top[x]!=top[y])
    {
        if(deep[top[x]]<deep[top[y]]) swap(x,y);
        ans=(ans+IntervalSum(1,idx[ top[x] ],idx[x]))%MOD;
        x=fa[ top[x] ];
    }
    if(deep[x]>deep[y]) swap(x,y);
    ans=(ans+IntervalSum(1,idx[x],idx[y]))%MOD;
    printf("%d\n",ans);
}
int main()
{
    memset(head,-1,sizeof(head));
    N=read();M=read();root=read();MOD=read();
    for(int i=1;i<=N;i++) b[i]=read();
    for(int i=1;i<=N-1;i++)
    {
        int x=read(),y=read();
        AddEdge(x,y);AddEdge(y,x);
    }
    dfs1(root,0,1);
    dfs2(root,root);
    Build(1,1,N);
    while(M--)
    {
        int opt=read(),x,y,z;
        if(opt==1)
        {    
            x=read();y=read();z=read();z=z%MOD;
            TreeAdd(x,y,z);
        }
        else if(opt==2)
        {
            x=read();y=read();
            TreeSum(x,y);
        }
        else if(opt==3)
        {
            x=read(),z=read();
            IntervalAdd(1,idx[x],idx[x]+tot[x]-1,z%MOD);
        }
        else if(opt==4)
        {
            x=read();
            printf("%d\n",IntervalSum(1,idx[x],idx[x]+tot[x]-1));
        }
    }
    return 0;
}
