#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 10010;
const int inf = 0x3f3f3f3f;
ll last[maxn],in[maxn],out[maxn];
struct Node{
    ll t,b,e;
}e[maxn];
ll n, m, k, ssw[maxn],d[maxn],sum[maxn], tim[maxn],rang[maxn];
int main() {
	scanf("%lld%lld%lld", &n, &m, &k); 
    ll ans = 0;
    for(ll i = 1; i < n; i++)
        scanf("%lld", &d[i]);
    for(ll i = 1; i <= m; i++) {
    	scanf("%lld%lld%lld", &e[i].t, &e[i].b, &e[i].e);
        last[e[i].b] = max(e[i].t, last[e[i].b]);
        ++in[e[i].b];
        ++out[e[i].e];
    }
    last[n] = inf;
    for(ll i = 1; i < n; i++) {
        ssw[i] = ssw[i - 1] + in[i] - out[i];
        tim[i + 1] = max(tim[i] + d[i], last[i] + d[i]);
    }
    for(ll i = 1; i <= m; i++)
		ans += tim[e[i].e]-e[i].t;
    for(ll i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + out[i];
    while(k--) {
        ll tn = 0, flag;
		rang[n - 1]=n;
        for (ll i = 1; i < n; i++) {
            if (d[i] && sum[rang[i]] - sum[i] > tn) {
				flag=i;
                tn = sum[rang[i]] - sum[i];
            }
        }
        for (ll i = n - 2; i != 0; i--) {
            if(tim[i + 1] > last[i+1]) rang[i] = rang[i + 1];
            else rang[i] = i + 1;
        }
        if (tn == 0)
			break;
        ans -= tn;
        d[flag] -= 1;
        tim[1] = 0;
        for(ll i = 1; i < n; i++)
			tim[i+1] = max(tim[i], last[i]) + d[i];
    }
    printf("%d\n", ans);
    return 0;
}
