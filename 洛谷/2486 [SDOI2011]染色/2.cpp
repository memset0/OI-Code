#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<queue>  
#include<set>  
#include<map>  
#include<vector>  
#include<stack>  
#include<cmath>  
#include<string>  
#include<algorithm>  
using namespace std;  
typedef long long ll;  
const int sigma_size=26;  
const int N=100+50;  
const int MAXN=100000+50;  
const int inf=0x3fffffff;  
const double eps=1e-8;  
const int mod=100000000+7;  
#define L(x) (x<<1)  
#define R(x) (x<<1|1)  
#define PII pair<int, int>  
#define mk(x,y) make_pair((x),(y))  
int n,m,edge_cnt,cnt,Lc,Rc;  
char str[N];  
int col[MAXN],head[MAXN],sz[MAXN],dep[MAXN],fa[MAXN],son[MAXN],top[MAXN],pos[MAXN];  
struct Edge{  
    int u,v,next;  
}edge[MAXN<<1];  
struct node{  
    int l,r;  
    int num,tag,lc,rc;  
}segtree[MAXN<<2];  
void init(){  
    edge_cnt=cnt=0;  
    memset(head,-1,sizeof(head));  
}  
void addedge(int u,int v){  
    edge[edge_cnt].u=u; edge[edge_cnt].v=v;  
    edge[edge_cnt].next=head[u]; head[u]=edge_cnt++;  
}  
void dfs1(int u,int pre,int depth){  
    sz[u]=1; fa[u]=pre; son[u]=0; dep[u]=depth;  
    for(int i=head[u];i!=-1;i=edge[i].next){  
        int v=edge[i].v;  
        if(v == pre)  
            continue;  
        dfs1(v,u,depth+1);  
        sz[u]+=sz[v];  
        if(sz[son[u]]<sz[v])  
            son[u]=v;  
    }  
}  
void dfs2(int u,int tp){  
    pos[u]=++cnt; top[u]=tp;  
    if(son[u]!=0)  
        dfs2(son[u],top[u]);  
    for(int i=head[u];i!=-1;i=edge[i].next){  
        int v=edge[i].v;  
        if(v == fa[u] || v == son[u])  
            continue;  
        dfs2(v,v);  
    }  
}  
void push_down(int rt){  
    if(segtree[rt].tag){  
        segtree[L(rt)].tag=segtree[R(rt)].tag=segtree[rt].tag;  
        segtree[L(rt)].num=segtree[R(rt)].num=1;  
        segtree[L(rt)].lc=segtree[L(rt)].rc=segtree[rt].lc;  
        segtree[R(rt)].lc=segtree[R(rt)].rc=segtree[rt].lc;  
        segtree[rt].tag=0;  
    }  
}  
void push_up(int rt){  
    segtree[rt].lc=segtree[L(rt)].lc; segtree[rt].rc=segtree[R(rt)].rc;  
    int ans=segtree[L(rt)].num+segtree[R(rt)].num;  
    if(segtree[L(rt)].rc == segtree[R(rt)].lc)  
        ans--;  
    segtree[rt].num=ans;  
}  
void build(int rt,int l,int r){  
    segtree[rt].l=l; segtree[rt].r=r; segtree[rt].num=0;  
    if(l == r)  
        return ;  
    int mid=(l+r)>>1;  
    build(L(rt),l,mid); build(R(rt),mid+1,r);  
}  
void update(int rt,int l,int r,int x){  
    if(segtree[rt].l == l && segtree[rt].r == r){  
        segtree[rt].num=segtree[rt].tag=1;  
        segtree[rt].lc=segtree[rt].rc=x;  
        return ;  
    }  
    push_down(rt);  
    int mid=(segtree[rt].l+segtree[rt].r)>>1;  
    if(r<=mid)  
        update(L(rt),l,r,x);  
    else if(l>mid)  
        update(R(rt),l,r,x);  
    else {  
        update(L(rt),l,mid,x); update(R(rt),mid+1,r,x);  
    }  
    push_up(rt);  
}  
int query(int rt,int l,int r,int L,int R){  
    if(segtree[rt].l == L)  
        Lc=segtree[rt].lc;  
    if(segtree[rt].r == R)  
        Rc=segtree[rt].rc;  
    if(segtree[rt].l == l && segtree[rt].r == r)  
        return segtree[rt].num;  
    push_down(rt);  
    int mid=(segtree[rt].l+segtree[rt].r)>>1;  
    if(r<=mid)  
        return query(L(rt),l,r,L,R);  
    else if(l>mid)  
        return query(R(rt),l,r,L,R);  
    else{  
        int ans=query(L(rt),l,mid,L,R)+query(R(rt),mid+1,r,L,R);  
        if(segtree[L(rt)].rc == segtree[R(rt)].lc)  
            ans--;  
        return ans;  
    }  
    push_up(rt);  
}  
int solve(int u,int v,int id,int c){  
    int ans=0;  
    if(id == 1){  
        while(top[u]!=top[v]){  
            if(dep[top[u]]<dep[top[v]])  
                swap(u,v);  
            update(1,pos[top[u]],pos[u],c);  
            u=fa[top[u]];  
        }  
        if(dep[u]>dep[v])  
            swap(u,v);  
        update(1,pos[u],pos[v],c);  
    }  
    else{  
        //printf("u=%d v=%d pos[u]=%d pos[v]=%d\n",u,v,pos[u],pos[v]);  
        int ans1=-1,ans2=-1; //记录上次链的左端的颜色  
        while(top[u]!=top[v]){  
            if(dep[top[u]]<dep[top[v]]){  
                swap(u,v); swap(ans1,ans2);  
            }  
            ans+=query(1,pos[top[u]],pos[u],pos[top[u]],pos[u]);  
            if(Rc == ans1)  
                ans--;  
           // printf("u=%d top[u]=%d Lc=%d Rc=%d ans=%d\n",u,top[u],Lc,Rc,ans);  
            ans1=Lc; u=fa[top[u]];  
        }  
        if(dep[u]<dep[v]){  
            swap(u,v); swap(ans1,ans2);  
        }  
        ans+=query(1,pos[v],pos[u],pos[v],pos[u]);  
        if(Rc == ans1)  
            ans--;  
        if(Lc == ans2)  
            ans--;  
        //printf("u=%d v=%d Lc=%d Rc=%d ans=%d\n",u,v,Lc,Rc,ans);  
    }  
    return ans;  
}  
int main(){  
    //freopen("in.txt","r",stdin);  
    while(~scanf("%d%d",&n,&m)){  
        init();  
        for(int i=1;i<=n;i++)  
            scanf("%d",&col[i]);  
        for(int i=1;i<n;i++){  
            int u,v;  
            scanf("%d%d",&u,&v);  
            addedge(u,v); addedge(v,u);  
        }  
        dfs1(1,1,1); dfs2(1,1); build(1,1,n);  
        //<F9>printf("%d %d\n",son[1],son[2]);  
        /*for(int i=1;i<=n;i++) 
            printf("top[i]=%d pos[i]%d\n",top[i],pos[i]); 
        printf("---------------------------------------\n"); 
        printf("\n");*/  
        for(int i=1;i<=n;i++)  
            update(1,pos[i],pos[i],col[i]);  
        while(m--){  
            scanf("%s",str);  
            int u,v;  
            if(str[0] == 'C'){  
                int c;  
                scanf("%d%d%d",&u,&v,&c);  
                solve(u,v,1,c);  
            }  
            else{  
                int u,v;  
                scanf("%d%d",&u,&v);  
                printf("%d\n",solve(u,v,2,0));  
                //printf("--------------------------------------\n");  
            }  
        }  
    }  
    return 0;  
}