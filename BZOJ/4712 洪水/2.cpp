#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define inf 1000000007
#define ll long long
#define N 200010
inline int rd()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int lj[N],fro[N<<1],to[N<<1],cnt;
void add(int a,int b){fro[++cnt]=lj[a];to[cnt]=b;lj[a]=cnt;}
int n,T;
ll w[N];
int fa[N],son[N],sz[N],top[N],tid[N],tim,rk[N];
ll h[N],dp[N];
void dfs1(int x,int f)
{
	fa[x]=f;sz[x]=1;
	for(int i=lj[x];i;i=fro[i])
	{
		if(to[i]==f) continue;
		dfs1(to[i],x);
		h[x]+=dp[to[i]];sz[x]+=sz[to[i]];
		if(sz[son[x]]<sz[to[i]]) son[x]=to[i];
	}
	if(!son[x]) h[x]=inf;
	dp[x]=min(w[x],h[x]);
}
void dfs2(int x,int tp)
{
	tid[x]=++tim;
	rk[tim]=x;top[x]=tp;
	if(!son[x]) return;
	dfs2(son[x],tp);
	for(int i=lj[x];i;i=fro[i])
	{
		if(to[i]==son[x]||to[i]==fa[x]) continue;
		dfs2(to[i],to[i]);
	}
}
#define ls p<<1
#define rs p<<1|1
ll mn[N<<2],tg[N<<2];
void build(int p,int l,int r)
{
	if(l==r){mn[p]=w[rk[l]]-h[rk[l]];tg[p]=h[rk[l]];return;}
	int mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	mn[p]=min(mn[ls],mn[rs]);
}
inline void pd(int p)
{
	if(!tg[p]) return;
	mn[ls]-=tg[p];mn[rs]-=tg[p];
	tg[ls]+=tg[p];tg[rs]+=tg[p];
	tg[p]=0;
}
ll fd(int p,int l,int r,int x)
{
	if(l==r) return tg[p];
	pd(p);
	int mid=l+r>>1;
	return x<=mid?fd(ls,l,mid,x):fd(rs,mid+1,r,x);
}
ll ask(int x){return min(w[x],fd(1,1,n,tid[x]));}
void xg(int p,int l,int r,int x)
{
	if(l==r){mn[p]=w[rk[l]]-tg[p];return;}
	int mid=l+r>>1;
	if(x<=mid) xg(ls,l,mid,x);
	else xg(rs,mid+1,r,x);
	mn[p]=min(mn[ls],mn[rs]);
}
void xg(int p,int l,int r,int L,int R,ll v)
{
	if(l==L&&R==r){mn[p]-=v;tg[p]+=v;return;}
	pd(p);
	int mid=l+r>>1;
	if(R<=mid) xg(ls,l,mid,L,R,v);
	else if(L>mid) xg(rs,mid+1,r,L,R,v);
	else xg(ls,l,mid,L,mid,v),xg(rs,mid+1,r,mid+1,R,v);
	mn[p]=min(mn[ls],mn[rs]);
}
void chg(int x,int y,ll v)
{
	while(top[x]!=top[y]) xg(1,1,n,tid[top[x]],tid[x],v),x=fa[top[x]];
	xg(1,1,n,tid[y],tid[x],v);
}
int fd(int p,int l,int r,int L,int R,ll v)
{
	if(L<=l&&r<=R)
	{
		if(mn[p]>=v) return l;
		if(l==r) return 0;
	}
	pd(p);
	int mid=l+r>>1,tp;
	if(R<=mid) return fd(ls,l,mid,L,R,v);
	if(L>mid) return fd(rs,mid+1,r,L,R,v);
	tp=fd(rs,mid+1,r,L,R,v);
	if(!tp||tp>mid+1) return tp;
	tp=fd(ls,l,mid,L,R,v);
	return tp?tp:mid+1;
}
int gety(int x,ll v)
{
	int t=x,tp;x=fa[x];
	while(x)
	{
		tp=fd(1,1,n,tid[top[x]],tid[x],v);
		if(!tp) break;
		if(tp>tid[top[x]]) return rk[tp];
		t=top[x];x=fa[t]; 
	}
	return t;
}
void cg(int x,ll v)
{
	int tp=ask(x);
	ll d;
	w[x]+=v;
	xg(1,1,n,tid[x]);
	d=ask(x)-tp;
	if(!d) return;
	while(fa[x])
	{
		int y=gety(x,d);
		if(x!=y) chg(fa[x],y,d);
		x=fa[y];
		if(!x) return;
		tp=ask(x);
		chg(x,x,d);
		d=ask(x)-tp;
		if(!d) return;
	}
}
int main()
{
	freopen("3.txt","r",stdin);
	freopen("2.txt","w",stdout);
	n=rd();
	for(int i=1;i<=n;i++) w[i]=rd();
	int x,y;
	for(int i=1;i<n;i++)
	{
		x=rd();y=rd();
		add(x,y);add(y,x);
	}
	dfs1(1,0);dfs2(1,1);
	build(1,1,n);
	T=rd();
	char op[2];
	while(T--)
	{
		scanf("%s",op);x=rd();
		if(op[0]=='Q') printf("%lld\n",ask(x));
		else{y=rd();cg(x,y);}
	}
	return 0;
}
