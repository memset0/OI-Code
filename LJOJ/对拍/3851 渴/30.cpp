#include <cstdio>

#define MAXN 200005
#define MAXE 400005
#define INF 0X3F3F3F3F

int n,m;
int tot,ans,Q[MAXN],dis[MAXN],lnk[MAXN],son[MAXE],nxt[MAXE];

template <typename T>
inline void read(T &x){
	int fl=0,ch;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

inline void AddEdge(int x,int y){
	son[++tot]=y;
	nxt[tot]=lnk[x];
	lnk[x]=tot;
}

inline void bfs(int s){
	int H=0,T=1;
	Q[T]=s,dis[s]=0;
	while (H!=T){
		int x=Q[++H];
		for (int j=lnk[x];j;j=nxt[j])
			if (dis[x]+1<dis[son[j]]){
				dis[son[j]]=dis[x]+1;
				Q[++T]=son[j]; 
			}
	}
}

int main(){
//	freopen("thirst.in","r",stdin);
//	freopen("thirst.out","w",stdout);
	read(n);
	for (int i=1,u,v;i^n;i++){
		read(u),read(v);
		AddEdge(u,v);
		AddEdge(v,u);
	}
	read(m);
	for (int i=1,u,v;i<=m;i++){
		for (int j=1;j<=n;j++) dis[j]=INF; ans=0;
		read(u),read(v);
		bfs(u),bfs(v);
		for (int j=1;j<=n;j++)
			if (ans<dis[j]) ans=dis[j];
		printf("%d\n",ans);
	}
	return 0;
}
