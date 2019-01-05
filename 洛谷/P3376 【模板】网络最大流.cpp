#include <cstdio>
#include <cstring>

#define MAXN 10005
#define MAXE 200005
const int Inf=0X7FFFFFFF;

int N,E,S,T,Ans;
int Pre[MAXN],Gap[MAXN],Dep[MAXN];
int Tot,Lnk[MAXN],Cur[MAXN],Son[MAXE],Nxt[MAXE],Cap[MAXE],Flow[MAXE];

inline void AddEdge(int x,int y,int z){
    Son[Tot]=y;
    Cap[Tot]=z;
    Flow[Tot]=0;
    Nxt[Tot]=Lnk[x];
    Lnk[x]=Tot++;
}

template <typename T>
inline void Read(T &x){
    int Fl=0,ch;
    while (ch=getchar(),ch<48 || 57<ch) Fl^=!(ch^45); x=(ch&15);
    while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
    if (Fl) x=-x;
}

inline void Sap(){
    int u=S;
    Pre[u]=-1;
    Gap[0]=N;
    Ans=0;
    while (Dep[S]<N){
        if (u==T){
            int Min=Inf;
            for (int i=Pre[u];~i;i=Pre[Son[i^1]])
                if (Cap[i]-Flow[i]<Min) Min=Cap[i]-Flow[i];
            for (int i=Pre[u];~i;i=Pre[Son[i^1]]){
                Flow[i]+=Min;
                Flow[i^1]-=Min;
            }
            u=S;
            Ans+=Min;
            continue;
        }
        bool Flag=0;
        int v;
        for (int i=Cur[u];~i;i=Nxt[i]){
            v=Son[i];
            if (Cap[i]!=Flow[i] && Dep[v]+1==Dep[u]){
                Flag=1;
                Pre[v]=i;
                break;
            }
        }
        if (Flag){
            u=v;
            continue;
        }
        int Min=N;
        for (int i=Lnk[u];~i;i=Nxt[i])
            if (Cap[i]!=Flow[i] && Dep[Son[i]]<Min){
                Min=Dep[Son[i]];
                Cur[u]=i;
            }
        if (!--Gap[Dep[u]]) break;
        Dep[u]=Min+1;
        Gap[Dep[u]]++;
        if (u!=S) u=Son[Pre[u]^1];
    }
}

int main(){
    memset(Lnk,-1,sizeof(Lnk)); 
    Read(N),Read(E),Read(S),Read(T);
    for (int i=1,u,v,w;i<=E;i++){
        Read(u),Read(v),Read(w);
        AddEdge(u,v,w);
        AddEdge(v,u,0);
    }
    Sap();
    printf("%d\n",Ans);
    return 0;
}