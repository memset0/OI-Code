//fhq-treap
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;
const int N=100010;
struct trnode
{
    int son[2],v,rnd,size;
}tr[N]; int tot=0,root=0;
void update(int x)
{
    tr[x].size=tr[tr[x].son[0]].size+tr[tr[x].son[1]].size+1;   
}
int new_code(int v)
{
    tot++;
    tr[tot].size=1; tr[tot].v=v; tr[tot].rnd=rand();
    return tot;
}
int merge(int x,int y)//默认x<y 
{
    if(!x || !y) return x+y;
    if(tr[x].rnd<tr[y].rnd)//用rand值来维护堆进而维护平衡性 
    {
        tr[x].son[1]=merge(tr[x].son[1],y);
        update(x);
        return x;
    }
    else
    {
        tr[y].son[0]=merge(x,tr[y].son[0]);
        update(y);
        return y;   
    }
}
void split(int now,int k,int &x,int &y)//以权值k分离now树成x,y 
{
    if(!now) x=y=0;
    else
    {
        if(tr[now].v<=k) //把所有小于k的权值的节点分到一棵树中
            x=now,split(tr[now].son[1],k,tr[now].son[1],y);
        else
            y=now,split(tr[now].son[0],k,x,tr[now].son[0]);
        update(now);
    }
}
int kth(int now,int k)
{
    while(1)
    {
        if(k<=tr[tr[now].son[0]].size) 
            now=tr[now].son[0];
        else
        {
            if(k==tr[tr[now].son[0]].size+1) return now;
            else 
            {
                k-=tr[tr[now].son[0]].size+1;
                now=tr[now].son[1];
            }
        }
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int T; int flag,x,y,z,a,b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&flag,&a);
        if(flag==1)
        {
            split(root,a,x,y);
            root=merge(merge(x,new_code(a)),y);
        }
        else if(flag==2)
        {
            split(root,a,x,z);
            split(x,a-1,x,y);
            y=merge(tr[y].son[0],tr[y].son[1]);
            root=merge(merge(x,y),z);
        }
        else if(flag==3)
        {
            split(root,a-1,x,y);
            printf("%d\n",tr[x].size+1);
            root=merge(x,y);
        }
        else if(flag==4)
            printf("%d\n",tr[kth(root,a)].v);
        else if(flag==5)
        {
            split(root,a-1,x,y);
            printf("%d\n",tr[kth(x,tr[x].size)].v);
            root=merge(x,y);
        }
        else if(flag==6)
        {
            split(root,a,x,y);
            printf("%d\n",tr[kth(y,1)].v); 
            root=merge(x,y);
        }
    }
    return 0;
}
