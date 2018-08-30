// luogu-judger-enable-o2
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=100005;

int N,M,L,R;
map <int,int> H;

struct Node{
    int v,s;
    Node *l,*r;
    Node(){
        v=0,s=0;
        l=NULL,r=NULL;
    }
} POOL[MAXN<<6],*ROOT;
int SIZE;

template <typename T>
inline void read(T &x){
    bool fl=0; char ch;
    while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
    while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
    if (fl) x=-x;
}

#define mid ((l+r)>>1)

inline int mdf(Node *&u,int l,int r,int pos,int val){
    if (u==NULL){
        u=&POOL[++SIZE];
        u->s=max(0,min(r,N)-max(l,1)+1);
    }
    if (l==r){ u->v=val; return 0; }
    if (mid>=pos){
        return mdf(u->l,l,mid,pos,val);
    }
    else{
        return mdf(u->r,mid+1,r,pos,val)+(u->l!=NULL?u->l->s:max(0,min(mid,N)-max(l,1)+1));
    }
}

inline int upd(Node *&u,int l,int r,int pos,int val,int id){
    if (u==NULL){
        u=&POOL[++SIZE];
        u->s=max(0,min(r,N)-max(l,1)+1);
        if (l==r) u->v=l;
    }
    u->s+=val;
    if (l==r){ if (id!=-1) u->v=id; return 0; }
    if (mid>=pos){
        return upd(u->l,l,mid,pos,val,id);
    }
    else{
        return upd(u->r,mid+1,r,pos,val,id)+(u->l!=NULL?u->l->s:max(0,min(mid,N)-max(l,1)+1));
    }
}

inline int qry(Node *&u,int l,int r,int k){
    if (u==NULL){
        u=&POOL[++SIZE];
        u->s=max(0,min(r,N)-max(l,1)+1);
        if (l==r) u->v=l;
    }
    if (l==r) return u->v;
    int t=u->l!=NULL?u->l->s:max(0,min(mid,N)-max(l,1)+1);
    if (t>=k){
        return qry(u->l,l,mid,k);
    }
    else{
        return qry(u->r,mid+1,r,k-t);
    }
}

int main(){
    read(N),read(M);
    L=1,R=N;
    for (int i=1,ans=0,t,x,y;i<=M;i++){
        read(t),read(x);
        switch (t){
            case 1 :
                read(y);
                printf("%d\n",ans=mdf(ROOT,-M,N+M,H[y]=(H.find(x)==H.end()?x:H[x]),y)+1);
                break;
            case 2 :
                printf("%d\n",ans=upd(ROOT,-M,N+M,H.find(x)==H.end()?x:H[x],-1,-1)+1);
                upd(ROOT,-M,N+M,H[x]=--L,1,x);
                break;
            case 3 :
                printf("%d\n",ans=upd(ROOT,-M,N+M,H.find(x)==H.end()?x:H[x],-1,-1)+1);
                upd(ROOT,-M,N+M,H[x]=++R,1,x);
                break;
            case 4 :
                printf("%d\n",ans=qry(ROOT,-M,N+M,x));
                break;
        }
    }
    return 0;
}

