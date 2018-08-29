#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int MAX=8000000;
#define MAXN 8000000
#define ll long long
inline ll read()
{
    ll x=0,t=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}
ll MOD,n,inv6,inv2;
int pri[MAXN],tot;
ll phi[MAXN+10];
bool zs[MAXN+10];
map<ll,ll> M;
ll fpow(ll a,ll b)
{
    ll s=1;
    while(b){if(b&1)s=s*a%MOD;a=a*a%MOD;b>>=1;}
    return s;
}
void pre()
{
    zs[1]=true;phi[1]=1;
    for(int i=2;i<=MAX;++i)
    {
        if(!zs[i])pri[++tot]=i,phi[i]=i-1;
        for(int j=1;j<=tot&&i*pri[j]<=MAX;++j)
        {
            zs[i*pri[j]]=true;
            if(i%pri[j])phi[i*pri[j]]=1ll*phi[i]*phi[pri[j]]%MOD;
            else{phi[i*pri[j]]=1ll*phi[i]*pri[j]%MOD;break;}
        }
    }
    for(int i=1;i<=MAX;++i)phi[i]=(phi[i-1]+1ll*phi[i]*i%MOD*i%MOD)%MOD;
}
ll Sum(ll x){x%=MOD;return x*(x+1)%MOD*inv2%MOD;}
ll Sump(ll x){x%=MOD;return x*(x+1)%MOD*(x+x+1)%MOD*inv6%MOD;}
ll SF(ll x)
{
    if(x<=MAX)return phi[x];
    if(M[x])return M[x];
    ll ret=Sum(x);ret=ret*ret%MOD;
    for(ll i=2,j;i<=x;i=j+1)
    {
        j=x/(x/i);
        ll tt=(Sump(j)-Sump(i-1))%MOD;
        ret-=SF(x/i)*tt%MOD;
        ret%=MOD;
    }
    return M[x]=(ret+MOD)%MOD;
}
int main()
{
    MOD=read();n=read();
    MAX=min(1ll*MAX,n);
    inv2=fpow(2,MOD-2);
    inv6=fpow(6,MOD-2);
    pre();
    printf("%lld\n",SF(1196575702));
    return 0;
}