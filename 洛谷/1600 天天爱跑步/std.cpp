#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define LL long long int
using namespace std;
const int maxn=700005,maxm=2000100,INF=2000000000,P=1000000007;
//快速读入
inline int read(){
    int out=0,flag=1;char c=getchar();
    while(c<48||c>57) {if(c=='-') flag=-1;c=getchar();}
    while(c>=48&&c<=57){out=out*10+c-48;c=getchar();}
    return out*flag;
}
//边信息建立
int head[maxn],nedge=0;
struct EDGE{
    int to,next;
}edge[maxm];
inline void build(int a,int b){
    edge[nedge]=(EDGE){b,head[a]};
    head[a]=nedge++;
    edge[nedge]=(EDGE){a,head[b]};
    head[b]=nedge++;
}
//lca询问信息建立
int Head[maxn],nlca=0;
struct LCA{
    int to,flag,next;
}Lca[maxm];
inline void link(int a,int b){
    Lca[nlca]=(LCA){b,0,Head[a]};
    Head[a]=nlca++;
    Lca[nlca]=(LCA){a,0,Head[b]};
    Head[b]=nlca++;
}
int N,M,w[maxn],rt=0,Siz[maxn],disrt=INF;
//数据读入
void init(){
    fill(head,head+maxn,-1);
    fill(Head,Head+maxn,-1);
    N=read();M=read();
    int a,b;
    for(int i=1;i<N;i++) build(read(),read());
    for(int i=1;i<=N;i++) w[i]=read();
    for(int i=1;i<=M;i++){a=read();b=read();link(a,b);}
}
//重心为根
void dfs1(int u,int f){
    int to,Min=INF,Max=-INF;
    Siz[u]=1;
    for(int k=head[u];k!=-1;k=edge[k].next)
        if((to=edge[k].to)!=f){
            dfs1(to,u);
            Siz[u]+=Siz[to];
            if(Siz[to]<Min) Min=Siz[to];
            if(Siz[to]>Max) Max=Siz[to];
        }
    if(Min==INF) return;
    if(N-Siz[u]<Min&&f) Min=N-Siz[u];
    if(N-Siz[u]>Max) Max=N-Siz[u];
    if(Max-Min<disrt){disrt=Max-Min;rt=u;}
}
void focus(){
    dfs1(1,0);
    if(!rt) rt=1;
    //cout<<rt<<endl;
}
vector<int> Su[maxn],Sd[maxn],Tu[maxn],Td[maxn];
int pre[maxn],dep[maxn],dis[maxn],S[maxn],T[maxn],pret[maxn],pathi=0,temp;
int lca0[maxn];
bool vis[maxn];
inline int find(int u){
    return u==pre[u] ? u:pre[u]=find(pre[u]);
}
//tarjan_lca算法割路径
void dfs2(int u,int f){
    int to;
    pre[u]=u;
    dep[u]=dep[f]+1;
    vis[u]=true;
    for(int k=head[u];k!=-1;k=edge[k].next){
        if((to=edge[k].to)!=f){
            dfs2(to,u);
            pre[to]=u;
        }
    }
    for(int k=Head[u];k!=-1;k=Lca[k].next){
        if(!Lca[k].flag&&vis[to=Lca[k].to]){
            Lca[k].flag=Lca[k^1].flag=true;
            int flag=0,m=find(to);
            if(!(k&1)) {flag=1;to^=u^=to^=u;}
            pathi++;
            if(to==m){
                S[pathi]=to;T[pathi]=u;dis[pathi]=dep[u]-dep[to];
                pret[pathi]=0;
                Sd[to].push_back(pathi);Tu[u].push_back(pathi);
            }else if(u==m){
                S[pathi]=to;T[pathi]=u;dis[pathi]=dep[to]-dep[u];
                Td[u].push_back(pathi);Su[to].push_back(pathi);
            }else{
                lca0[pathi]=m;
                S[pathi]=to;T[pathi]=m;dis[pathi]=dep[to]-dep[m];
                Su[to].push_back(pathi);Td[m].push_back(pathi);
                S[++pathi]=m;T[pathi]=u;dis[pathi]=dep[u]-dep[m];
                pret[pathi]=dep[to]-dep[m];
                Sd[m].push_back(pathi);Tu[u].push_back(pathi);
            }
            if(flag) u=to;
        }
    }
}
void tarjan_lca(){
    dfs2(rt,0);
    /*for(int i=1;i<=pathi;i++){
        printf("%d %d %d\n",S[i],T[i],dis[i]);
    }*/
}
int cntS[maxm],cntT[maxm],ans[maxn];
//树上统计
void dfs(int u,int f){
    int dS=dep[u]+w[u]+maxn,oriS=cntS[dS],dT=dep[u]-w[u]+maxn,oriT=cntT[dT],to;
    for(unsigned i=0;i<Su[u].size();i++){
        cntS[dep[S[Su[u][i]]]+maxn]++;
    }
    for(unsigned i=0;i<Tu[u].size();i++){
        cntT[dep[T[Tu[u][i]]]-dis[Tu[u][i]]-pret[Tu[u][i]]+maxn]++;
    }
    for(int k=head[u];k!=-1;k=edge[k].next){
        if((to=edge[k].to)!=f){
            dfs(to,u);
        }
    }
    ans[u]=cntS[dS]-oriS+cntT[dT]-oriT;
    for(unsigned i=0;i<Td[u].size();i++){
        cntS[dep[S[Td[u][i]]]+maxn]--;
        //if(u==2) cout<<"lca:"<<lca0[Td[u][i]]<<endl;
        if(lca0[Td[u][i]]==u&&dep[S[Td[u][i]]]+maxn==dS) ans[u]--;
    }
    for(unsigned i=0;i<Sd[u].size();i++){
        cntT[dep[T[Sd[u][i]]]-dis[Sd[u][i]]-pret[Sd[u][i]]+maxn]--;
    }
}
//打印答案
void print(){
    for(int i=1;i<=N;i++) printf("%d ",ans[i]);
    printf("\n");
}
int main(){
	freopen("data.txt", "r", stdin);
    init();
    focus();
    tarjan_lca();
    dfs(rt,0);
    print();
    return 0;
}
