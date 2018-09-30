#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,a[100010],b[100010],p,q;
inline void dfs(int l,int r,int n,int t)
{
       if(n==0)
         {
          if(t>p)
            {
             p=t;
             q=0;
            }
          if(t==p)
            q++;
          return;
         }
       int i;
       for(i=l;i<=r;i++)
         if(a[i]&n)
           break;
       if(i==l || i==r+1)
         dfs(l,r,n>>1,t+n);
       else
         {
          dfs(l,i-1,n>>1,t);
          dfs(i,r,n>>1,t);
         }
}
int main()
{
//    freopen("big.in","r",stdin);
//    freopen("big.out","w",stdout);
	freopen("3.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
      {
       scanf("%d",&a[i]);
       b[i]=b[i-1]^(a[i]*2/(1<<n)+a[i]*2%(1<<n));
      }
    for(i=m-1;i>0;i--)
      a[i]^=a[i+1];
    for(i=0;i<m;i++)
      a[i]=a[i+1]^b[i];
    a[m]=b[m];
    sort(a,a+m+1);
    dfs(0,m,n==0?0:(1<<(n-1)),0);
    printf("%d\n%d\n",p,q);
    return 0;
}
