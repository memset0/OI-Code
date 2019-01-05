#include <bits/stdc++.h>

#define ls d[p].l
#define rs d[p].r
#define N 100007
#define inf 2000000010
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if (ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}

int n,sz,rt,ans;
struct Node
{
    int l,r,val,siz,rnd,ct;//记录左儿子，右儿子，点值，该子树大小，随机的值，该点值出现的次数。 
}d[N];//最多多少个节点，就开多少空间 

inline int rand(){
    static int seed = 2333;
    return seed = (int)((((seed ^ 998244353) + 19260817ll) * 19890604ll) % 1000000007);
}
inline void update(int p)
{
    d[p].siz=d[ls].siz+d[rs].siz+d[p].ct;
}
void lturn(int &p)
{
    int t=d[p].r;d[p].r=d[t].l;d[t].l=p;
    d[t].siz=d[p].siz;update(p);p=t;
}
void rturn(int &p)
{
    int t=d[p].l;d[p].l=d[t].r;d[t].r=p;
    d[t].siz=d[p].siz;update(p);p=t;
}
void ins(int &p,int x)
{
    if (p==0)
    {
        d[p=++sz].siz=d[p].ct=1,d[p].val=x,d[p].rnd=rand();
        return;
    }
    d[p].siz++;
    if (d[p].val==x) d[p].ct++;
    else if (x>d[p].val)
    {
        ins(d[p].r,x);
        if (d[rs].rnd<d[p].rnd) lturn(p);
    }else
    {
        ins(d[p].l,x);
        if (d[ls].rnd<d[p].rnd) rturn(p);
    }
}
void del(int &p,int x)
{
    if (p==0) return;
    if (d[p].val==x)
    {
        if (d[p].ct>1) d[p].ct--,d[p].siz--;//如果有多个直接减一即可。
        else
        {
            if (ls==0||rs==0) p=ls+rs;//单节点或者空的话直接儿子移上来或者删去即可。
            else if (d[ls].rnd<d[rs].rnd) rturn(p),del(p,x);
            else lturn(p),del(p,x); 
        }
    }
    else if (x>d[p].val) d[p].siz--,del(rs,x);
    else d[p].siz--,del(ls,x);
}
int find_pm(int p,int x)
{
    if (p==0) return 0;
    if (d[p].val==x) return d[ls].siz+1;
    if (x>d[p].val) return d[ls].siz+d[p].ct+find_pm(rs,x);
    else return find_pm(ls,x);
}
int find_sz(int p,int x)
{
    if (p==0) return 0;
    if (x<=d[ls].siz) return find_sz(ls,x);
    x-=d[ls].siz;
    if (x<=d[p].ct) return d[p].val;
    x-=d[p].ct;
    return find_sz(rs,x);
}
int find_qq(int p,int x)
{
    if (p==0) return -inf;
    if (d[p].val<x) return max(d[p].val,find_qq(rs,x));
    else if (d[p].val>=x) return find_qq(ls,x);
}
int find_hj(int p,int x)
{
    if (p==0) return inf;
    if (d[p].val<=x) return find_hj(rs,x);
    else return min(d[p].val,find_hj(ls,x));
}
int main()
{
    n=read();
    for (int i=1;i<=n;i++)
    {
        int flag=read(),x=read();
        if (flag==1) ins(rt,x);
        if (flag==2) del(rt,x);
        if (flag==3) printf("%d\n",find_pm(rt,x));//寻找x的排名
        if (flag==4) printf("%d\n",find_sz(rt,x));//寻找排名为x的数字 
        if (flag==5) printf("%d\n",find_qq(rt,x));
        if (flag==6) printf("%d\n",find_hj(rt,x));
    }
}