#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
using namespace std;
struct Edge
{
    int left;
    int right;
    int height;
    int flag;
}e[10005];
struct Tree
{
    int sum;
    int num;
    int len;
    bool lflag;
    bool rflag;
}tree[100005];
int n,mx=-2147483647,mn=2147483647,edgenum,ans,last;
void add_edge(int l,int r,int h,int f)
{
    e[++edgenum].left=l;
    e[edgenum].right=r;
    e[edgenum].height=h;
    e[edgenum].flag=f;
}
bool cmp(Edge a,Edge b)
{
    return a.height<b.height||(a.height==b.height&&a.flag>b.flag);
}
void pushup(int o,int l,int r)
{
    if(tree[o].sum)
    {
        // tree[o].num=1;
        tree[o].len=r-l+1;
        tree[o].lflag=tree[o].rflag=1;
    }
    else if(l==r)
    {
        tree[o].len=0;
        // tree[o].num=0;
        tree[o].lflag=tree[o].rflag=0;
    }
    else
    {
        tree[o].len=tree[lson].len+tree[rson].len;
        // tree[o].num=tree[lson].num+tree[rson].num;
        // if(tree[lson].rflag&&tree[rson].lflag)tree[o].num--;
        tree[o].lflag=tree[lson].lflag;
        tree[o].rflag=tree[rson].rflag;
    }
}
void add(int o,int l,int r,int from,int to,int value)
{
    if(l>=from&&r<=to)
    {
        tree[o].sum+=value;
        pushup(o,l,r);
        return;
    }
    if(from<=mid)add(lson,l,mid,from,to,value);
    if(to>mid)add(rson,mid+1,r,from,to,value);
    pushup(o,l,r);
}
int main()
{
    freopen("INPUT", "r", stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        mx=max(mx,max(x1,x2));
        mn=min(mn,min(x1,x2));
        add_edge(x1,x2,y1,1);
        add_edge(x1,x2,y2,-1);
    }
    if(mn<=0)
    {
        for(int i=1;i<=edgenum;i++)
        {
            e[i].left+=-mn+1;
            e[i].right+=-mn+1;
        }
        mx-=mn;
    }
    sort(e+1,e+edgenum+1,cmp);
    for(int i=1;i<=edgenum;i++)
    {
        add(1,1,mx,e[i].left,e[i].right-1,e[i].flag);//注意这里！！！加边有学问！！！
        while(e[i].height==e[i+1].height&&e[i].flag==e[i+1].flag)
        {
            i++;
            add(1,1,mx,e[i].left,e[i].right-1,e[i].flag);
        }
        ans+=abs(tree[1].len-last);
        last=tree[1].len;
        ans+=tree[1].num*2*(e[i+1].height-e[i].height);
    }
    printf("%d\n",ans);
    return 0;
}