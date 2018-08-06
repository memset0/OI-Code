#include<bits/stdc++.h>
using namespace std;
int n;
struct Pair{long long x,y;};
long long f,t,k,p,ansf,anst,Mod;
inline long long read()
{
    long long num=0; char g=getchar();
    while(g<48||57<g) g=getchar();
    while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar();
    return num;
}
long long Max(long long a,long long b) {if(a>b) return a; return b;}
long long Min(long long a,long long b) {if(a<b) return a; return b;}
long long Cross(long long a,long long b,long long c)//龟速乘 a*b对c取模 
{
    a=(a+c)%c,b=(b+c)%c;
    long long sum=0,u=1,t=a;
    while(b>0) {if(b&u) sum=(sum+t)%c,b=b-u; u=(u<<1),t=(t<<1)%c; }
    return sum;
}
Pair Exgcd(long long a,long long b)
{
    Pair h,r; if(b==0) {r.x=1,r.y=0; return r;}
    h=Exgcd(b,a%b); r.x=h.y,r.y=(h.x-Cross((a/b),h.y,Mod)+Mod)%Mod; return r;  
}
long long gcd(long long a,long long b) {if(b==0) return a; return gcd(b,a%b);}
long long inv(long long a,long long b)
{
    Pair p=Exgcd(Max(a,b),Min(a,b));
    if(a>b) return p.x; return p.y;
}
void Get_ans()
{
    k=gcd(Max(anst,t),Min(anst,t)),Mod=(t/k)*anst,p=inv(anst/k,t/k);
    ansf=(Cross(Cross(anst,p,Mod),(f-ansf)/k,Mod)+ansf+Mod)%Mod,anst=(anst/k)*t;
	printf("%lld %lld\n", anst, ansf);
}
int main() 
{
	freopen("INPUT","r",stdin);
    n=read();
    anst=read(),ansf=read();
    for(int i=1;i<n;i++) t=read(),f=read(),Get_ans(); 
    ansf=ansf%anst;
    long long Ans=(ansf+anst)%anst;
    printf("%lld\n",Ans);
    return 0;
}
//3
//11 6
//25 9
//33 17