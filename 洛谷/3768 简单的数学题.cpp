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
int MAX = 8000000; 
#define MAXN 8000000
#define ll long long
inline ll read()
{
    ll x = 0, t = 1; char ch = getchar(); 
    while((ch<'0'||ch>'9') && ch! = '-')ch = getchar(); 
    if(ch =  = '-')t = -1, ch = getchar(); 
    while(ch<= '9' && ch> = '0')x = x*10 + ch-48, ch = getchar(); 
    return x*t; 
}
ll p, n, inv6, inv2; 
int pri[MAXN], tot; 
ll phi[MAXN + 10]; 
bool zs[MAXN + 10]; 
map<ll, ll> M; 
ll fpow(ll a, ll b)
{
    ll s = 1; 
    while(b){if(b&1)s = s*a % p; a = a*a % p; b>> = 1; }
    return s; 
}
void pre()
{
    zs[1] = true; phi[1] = 1; 
    for(int i = 2; i<= MAX;  ++ i)
    {
        if(!zs[i])pri[ ++ tot] = i, phi[i] = i-1; 
        for(int j = 1; j<= tot && i*pri[j]<= MAX;  ++ j)
        {
            zs[i*pri[j]] = true; 
            if(i % pri[j])phi[i*pri[j]] = 1ll*phi[i]*phi[pri[j]] % p; 
            else{phi[i*pri[j]] = 1ll*phi[i]*pri[j] % p; break; }
        }
    }
    for(int i = 1; i<= MAX;  ++ i)phi[i] = (phi[i-1] + 1ll*phi[i]*i % p*i % p) % p; 
}
ll Sum(ll x){x %  = p; return x*(x + 1) % p*inv2 % p; }
ll Sump(ll x){x %  = p; return x*(x + 1) % p*(x + x + 1) % p*inv6 % p; }
ll SF(ll x)
{
    if(x<= MAX)return phi[x]; 
    if(M[x])return M[x]; 
    ll ret = Sum(x); ret = ret*ret % p; 
    for(ll i = 2, j; i<= x; i = j + 1)
    {
        j = x/(x/i); 
        ll tt = (Sump(j)-Sump(i-1)) % p; 
        ret- = SF(x/i)*tt % p; 
        ret %  = p; 
    }
    return M[x] = (ret + p) % p; 
}
int main()
{
	freopen("INPUT",  "r",  stdin); 
    p = read(); n = read(); 
    MAX = min(1ll*MAX, n); 
    inv2 = fpow(2, p-2); 
    inv6 = fpow(6, p-2); 
    pre(); 
    ll ans = 0; 
    for(ll i = 1, j; i<= n; i = j + 1)
    {
        j = n/(n/i); 
        ll tt = Sum(n/i); tt = tt*tt % p; 
        ll gg = (SF(j)-SF(i-1)) % p; 
        ans +  = gg*tt % p; 
        ans %  = p; 
        if (ans < 0) printf(" % lld\n",  ans); 
    }
    printf(" % lld\n", (ans + p) % p); 
    return 0; 
}