#include<algorithm>
#include<iostream>
using namespace std;
int a,b,c,n,sum,max_,min_;
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)
    max_=max(a,c),min_=min(b,c);
    if(a<b)
    max_=max(b,c),min_=min(a,c);
    for(int i=1;i<=min_/3+1;i++)
    if(max_%i==0&&min_%i==0)
    max_/=i,min_/=i;
    printf("%d/%d",min_,max_); 
    return 0;
}
