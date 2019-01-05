// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll read() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const ll p = 10000007;

ll n, t, ans = 1;
ll f[60], g[60];

ll qpow(ll x, ll i) {
	// printf("%lld %lld =>", x, i);
	ll ans = 1;
	while (i) {
		if (i & 1) ans = ans * x % p;
		x = x * x % p;
		i >>= 1;
	}
	// printf(" %lld\n", ans);
	return ans;
}

ll inv(ll x) {
	if (x == 0 || x == 1) return 1;
	return (p - p / x) * inv(p % x) % p;
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read();
	for (int i = 60; i >= 0; i--)
		if (n & (1LL << i)) {
			g[1] = i;
			for (int j = 2; j <= i; j++)
				g[j] = g[j - 1] * (i + 1 - j) / j;
			// for (int j = 0; j <= i; j++)
			// 	printf("%lld ", g[j]);
			// puts("");
			for (int j = 0; j <= i; j++)
				f[j + t] = f[j + t] + g[j];
			f[1 + t] = f[1 + t] + 1;
			t++;
		}

	// for (int i = 1; i < 60; i++)
	// 	cout << f[i] << endl;
	for (int i = 1; i < 60; i++)
		ans = ans * qpow(i, f[i]) % p;

	printf("%lld\n", ans);

	return 0;
}