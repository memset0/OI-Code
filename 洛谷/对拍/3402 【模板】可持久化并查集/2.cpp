#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#define rg register int
#define ll long long
#define RG register
#define il inline
using namespace std;

il int gi() 
{
    rg x=0,o=0;RG char ch=getchar();
    while(ch!='-'&&(ch<'0'||'9'<ch)) ch=getchar();
    if(ch=='-') o=1,ch=getchar();
    while('0'<=ch&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    return o?-x:x;
}

#define SZ 200010
int n,m,fa[SZ*30],deep[SZ*30];
// deep 存最大深度
// fa 存 一个点在某个版本的父亲

struct Tree {
  int l,r;
}tr[SZ*30];
#define lson tr[rt].l
#define rson tr[rt].r
int Ed[SZ],tot; 
// Ed 是版本号 ， tot是节点总数（这些就是主席树啦）

void build(int &rt,rg l,rg r)
{
    rt=++tot;
    if(l==r)
    {
        fa[rt]=l;  // 初始版本 ： 父亲是自己
        // 就像并查集初始化每个点的父亲是它自己
        return;
    }
    rg mid=l+r>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
}

// 主席树维护的是 每一个版本 每一个点的父亲是谁
void update(int &rt,rg last,rg l,rg r,rg pos,rg ff) //把pos的父亲改成ff
{
    rt=++tot;
    if(l==r)
    {
        fa[rt]=ff;
        deep[rt]=deep[last];  // deep 用于 启发式合并
        return;
    }
    lson=tr[last].l;rson=tr[last].r;
    rg mid=l+r>>1;
    if(pos<=mid) update(lson,tr[last].l,l,mid,pos,ff);
    else update(rson,tr[last].r,mid+1,r,pos,ff);
}

int query(rg rt,rg l,rg r,rg pos) // 询问某一个版本的一个点的父亲
{
    if(l==r) return rt;
    rg mid=l+r>>1;
    if(pos<=mid) return query(lson,l,mid,pos);
    else return query(rson,mid+1,r,pos);
}

void add(rg rt,rg l,rg r,rg pos) // 把某一个并查集联通块中每一个点的深度加一
{
    if(l==r) 
    {
        ++deep[rt];
        return;    
    }
    rg mid=l+r>>1;
    if(pos<=mid) add(lson,l,mid,pos);
    else add(rson,mid+1,r,pos);
}

int find_fa(rg ed,rg x) // ed 版本编号
{ 
    rg ff=query(ed,1,n,x);  // 查询在这一版本里 一个点的父亲
    if(x==fa[ff]) return ff;
    return find_fa(ed,fa[ff]);  // 不带路径压缩的并查集
}

int main() 
{
	freopen("3.txt","r",stdin);
	freopen("2.txt","w",stdout);
    n=gi(),m=gi();
    build(Ed[0],1,n);
//init
    for(rg opt,k,a,b,i=1;i<=m;++i) 
    {
        opt=gi();
        if(opt==1) 
        {
            Ed[i]=Ed[i-1];
            a=gi(),b=gi();
            rg f1=find_fa(Ed[i],a);
            rg f2=find_fa(Ed[i],b);
            if(fa[f1]==fa[f2]) continue;
            if(deep[f1]>deep[f2]) swap(f1,f2); 
            // 把大的往小的 并，保证f1儿子节点数一定是小于等于f2
            update(Ed[i],Ed[i-1],1,n,fa[f1],fa[f2]);   // 把f1 
            if(deep[f1]==deep[f2]) add(Ed[i],1,n,fa[f2]);
          // 因为f2 并到了 f1 所以f1的深度要加1
          //我们用 启发式合并 来保证 病查集合并的复杂度
        }
        if(opt==2) 
        {
            k=gi();
            Ed[i]=Ed[k];
        }
        if(opt==3) 
        {
            Ed[i]=Ed[i-1];
            a=gi(),b=gi();
            rg f1=find_fa(Ed[i],a);
            rg f2=find_fa(Ed[i],b);
            if(fa[f1]==fa[f2]) puts("1");
            else puts("0");
        }
    }
  return 0;
}
