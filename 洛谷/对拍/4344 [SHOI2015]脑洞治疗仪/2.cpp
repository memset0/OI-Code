# include<iostream>
# include<cstring>
# include<cstdio>
# include<algorithm>
# define tl (k<<1)
# define tr (k<<1|1)
# define mid (((l)+(r))>>1)
using namespace std;
const int MAX=2e5+1;
struct p{
    int Sum,l,r,sum,lazy;
    p(){lazy=-1;}
}s[MAX<<2];
int n,m,tot,TOT;
int read()
{
    int x=0;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar());
    for(;isdigit(ch);x=x*10+ch-48,ch=getchar());
    return x;
}
p pus(int dis,p a,p b,int l,int r)
{
    p c;
    c.l=c.r=c.sum=c.Sum=0,c.lazy=dis;
    c.Sum=a.Sum+b.Sum;
    c.l=a.l,c.r=b.r;
    if(a.l==mid-l+1) c.l+=b.l;
    if(b.r==r-mid) c.r+=a.r;
    c.sum=a.r+b.l;
    c.sum=max(c.sum,max(a.sum,b.sum));
    c.sum=max(c.l,max(c.r,c.sum));
    return c;
}
void down(int l,int r,int k)
{
    int dis=s[k].lazy;
    s[k].lazy=-1;
    if(dis==-1) return;
    s[tl].Sum=dis*(mid-l+1),s[tl].sum=s[tl].l=s[tl].r=(dis==0)*(mid-l+1),s[tl].lazy=dis;
    s[tr].Sum=dis*(r-mid),s[tr].sum=s[tr].l=s[tr].r=(dis==0)*(r-mid),s[tr].lazy=dis;
}
void change1(int l,int r,int k,int L,int R)
{
    if(l==L&&r==R)
    {
        s[k].Sum=0,s[k].sum=s[k].l=s[k].r=r-l+1,s[k].lazy=0;
        return;
    }
    down(l,r,k);
    if(R<=mid) change1(l,mid,tl,L,R);
    else if(L>mid) change1(mid+1,r,tr,L,R);
    else change1(l,mid,tl,L,mid),change1(mid+1,r,tr,mid+1,R);
    s[k]=pus(s[k].lazy,s[tl],s[tr],l,r);
}
void change3(int l,int r,int k)
{
    if(!TOT) return;
    if(s[k].Sum==r-l+1) return;
    if(!s[k].Sum&&TOT>=r-l+1)
    {
        s[k].Sum=r-l+1,s[k].sum=s[k].l=s[k].r=0,s[k].lazy=1;
        TOT-=r-l+1,tot+=r-l+1;
        return;
    }
    if(l>=r) return;
    down(l,r,k);
    change3(l,mid,tl),change3(mid+1,r,tr);
    s[k]=pus(s[k].lazy,s[tl],s[tr],l,r);
}
void change2(int l,int r,int k,int L,int R,int dis)
{
    if(tot>=dis) return;
    if(l==L&&r==R)
    {
        TOT=dis-tot,change3(l,r,k);
        return;
    }
    down(l,r,k);
    if(R<=mid) change2(l,mid,tl,L,R,dis);
    else if(L>mid) change2(mid+1,r,tr,L,R,dis);
    else change2(l,mid,tl,L,mid,dis),change2(mid+1,r,tr,mid+1,R,dis);
    s[k]=pus(s[k].lazy,s[tl],s[tr],l,r);
}
int ask1(int l,int r,int k,int L,int R)
{
    if(l==L&&r==R) return s[k].Sum;
    down(l,r,k);
    if(R<=mid) return ask1(l,mid,tl,L,R);
    if(L>mid) return ask1(mid+1,r,tr,L,R);
    return ask1(l,mid,tl,L,mid)+ask1(mid+1,r,tr,mid+1,R);
}
p ask2(int l,int r,int k,int L,int R)
{
    if(l==L&&r==R) return s[k];
    down(l,r,k);
    if(R<=mid) return ask2(l,mid,tl,L,R);
    if(L>mid) return ask2(mid+1,r,tr,L,R);
    p LL=ask2(l,mid,tl,L,mid),RR=ask2(mid+1,r,tr,mid+1,R);
    return pus(-1,LL,RR,l,r);
}
int Ask(int l,int r)
{
    int ans=ask1(1,n,1,l,r);
    change1(1,n,1,l,r);
    return ans;
}
int main()
{
    n=read(),m=read();
    s[1].lazy=1,s[1].Sum=n;
    for(int i=1;i<=m;++i)
      {
        int op=read(),l=read(),r=read(),l1,r1;
        if(!op) change1(1,n,1,l,r);
        else if(op==1)
        {
            l1=read(),r1=read();
            int dis=Ask(l,r);
            if(dis) tot=TOT=0,change2(1,n,1,l1,r1,dis);
        }
        else if(op==2) printf("%d\n",ask2(1,n,1,l,r).sum);
      }
    return 0;
}