#include<bits/stdc++.h>
using namespace std;
int n,m;
inline int read()
{
    int num=0; char t='+',g=getchar();
    while(g<48||57<g) t=g,g=getchar();
    while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar();
    if(t=='-') return 0-num; return num;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n>=m) {for(int x=m;x<=n;x++) printf("%d ",x); printf("\n");}
        else if(m%(n+1)==0) printf("You are loser\n");
        else printf("%d\n",m%(n+1));
    }
    return 0;
}
