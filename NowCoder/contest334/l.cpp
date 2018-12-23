#include<bits/stdc++.h>
using namespace std;
int ans,cnt,siz,ch[6],cha[6],e[20]; bool flag;
inline int read()
{
    int num=0; char t='+',g=getchar();
    while(g<48||57<g) t=g,g=getchar();
    while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar();
    if(t=='-') return 0-num; return num;
}
inline void check()
{
//  if(ch[1]==ch[2]&&ch[2]==ch[3]&&ch[3]==ch[4]&&ch[4]==ch[5]) return;
    flag=false,siz++;
    for(int x=1;x<=5;x++) if(ch[x]>=5) flag=true;
    if(ch[1]+ch[2]+ch[3]+ch[4]+ch[5]>10) flag=true;
    if(!flag) {cnt+=60; return;}
    flag=false;
//  cout<<ch[1]<<' '<<ch[2]<<' '<<ch[3]<<' '<<ch[4]<<' '<<ch[5]<<"ioi"<<endl;
    for(int x=1;x<=5;x++) if(ch[x]<=10) flag=true;
    if(!flag) {cnt+=50; return;}
     
     
    if(ch[1]==ch[2]&&ch[2]==ch[3]&&ch[3]==ch[4])
    {
        cnt+=40; return;
    }
    if(ch[1]==ch[2]&&ch[2]==ch[3]&&ch[3]==ch[5])
    {
        cnt+=40; return;
    }
    if(ch[1]==ch[2]&&ch[2]==ch[4]&&ch[5]==ch[4])
    {
        cnt+=40; return;
    }
    if(ch[1]==ch[3]&&ch[4]==ch[3]&&ch[5]==ch[4])
    {
        cnt+=40; return;
    }
    if(ch[5]==ch[2]&&ch[2]==ch[3]&&ch[3]==ch[4])
    {
        cnt+=40; return;
    }
    for(int x=1;x<=5;x++) if(ch[x]>10) ch[x]=10;
    int sum=ch[1]+ch[2]+ch[3]+ch[4]+ch[5];
    sum=sum%10;
    if(!((ch[1]+ch[2]+ch[3])%10))
    {
            if(sum==0) cnt+=30;
    else if(sum>=7) cnt=cnt+sum+sum;
    else cnt=cnt+sum; return;
    }
    if(!((ch[1]+ch[2]+ch[4])%10))
    {
            if(sum==0) cnt+=30;
    else if(sum>=7) cnt=cnt+sum+sum;
    else cnt=cnt+sum; return;
    }
    if(!((ch[1]+ch[2]+ch[5])%10))
    {
            if(sum==0) cnt+=30;
    else if(sum>=7) cnt=cnt+sum+sum;
    else cnt=cnt+sum; return;
    }
    if(!((ch[1]+ch[3]+ch[5])%10))
    {
            if(sum==0) cnt+=30;
    else if(sum>=7) cnt=cnt+sum+sum;
    else cnt=cnt+sum; return;
    }
    if(!((ch[1]+ch[3]+ch[4])%10))
    {
            if(sum==0) cnt+=30;
    else if(sum>=7) cnt=cnt+sum+sum;
    else cnt=cnt+sum; return;
    }
    if(!((ch[1]+ch[4]+ch[5])%10))
    {
            if(sum==0) cnt+=30;
    else if(sum>=7) cnt=cnt+sum+sum;
    else cnt=cnt+sum; return;
    }
    if(!((ch[2]+ch[3]+ch[4])%10))
    {
            if(sum==0) cnt+=30;
    else if(sum>=7) cnt=cnt+sum+sum;
    else cnt=cnt+sum; return;
    }
    if(!((ch[2]+ch[3]+ch[5])%10))
    {
            if(sum==0) cnt+=30;
    else if(sum>=7) cnt=cnt+sum+sum;
    else cnt=cnt+sum; return;
    }
    if(!((ch[2]+ch[4]+ch[5])%10))
    {
            if(sum==0) cnt+=30;
    else if(sum>=7) cnt=cnt+sum+sum;
    else cnt=cnt+sum; return;
    }
    if(!((ch[3]+ch[4]+ch[5])%10))
    {
            if(sum==0) cnt+=30;
    else if(sum>=7) cnt=cnt+sum+sum;
    else cnt=cnt+sum; return;
    }
}
int main()
{
    int t=read();
    while(t--)
    {
        memset(e,0,sizeof(e)),cnt=0,siz=0;
        for(int x=1;x<=4;x++) cha[x]=read(),e[cha[x]]++;
        for(int x=1;x<=13;x++)
        {
//          for(int t=1;t<=4-e[x];t++)
//          {
                for(int u=1;u<=4;u++) ch[u]=cha[u];
                ch[5]=x,check();
//              cout<<x<<endl;
//              cout<<x<<' '<<cnt<<' '<<siz<<"ioi"<<endl;
//          }
        }
//      for(int x=0;x<=60;x++) if(e[x]) ans++;
//      cout<<cnt<<' '<<siz<<endl;
        printf("%d\n",(int)(cnt/(double)siz+0.5));
    }
    return 0;
}
 
 
/*
1 60 1ioi
2 120 2ioi
3 180 3ioi
4 240 4ioi
5 300 5ioi
6 340 6ioi
7 380 7ioi
8 420 8ioi
9 460 9ioi
10 500 10ioi
11 540 11ioi
12 580 12ioi
13 620 13ioi
48
 
*/
