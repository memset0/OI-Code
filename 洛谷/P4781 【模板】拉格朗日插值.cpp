// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define ull unsigned long long
#define y1 this_is_not_y1
#define y2 this_is_not_y2
#define sqr ((x)*(x))
#define lowbit(x) ((x)&(-x))
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

ll readll() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 2010, Mod = 998244353;
int n, k;
ll s1, s2, ans;
ll x[maxn], y[maxn];

ll inv(ll x) {
	if (x < 0) return inv((x % Mod + Mod) % Mod);
	if (x == 0 || x == 1) return 1;
	return (Mod - Mod / x) * inv(Mod % x) % Mod;
}

int main() {
//	freopen("INPUT", "r", stdin);	
	
	n = read(), k = read();
	for (int i = 1; i <= n; i++)
		x[i] = read(), y[i] = read();
	ans = 0;
	for (int i = 1; i <= n; i++) {
		s1 = 1, s2 = 1;
		for (int j = 1; j <= n; j++)
			if (i != j) {
				s1 = (s1 * (k - x[j])) % Mod;
				s2 = (s2 * (x[i] - x[j])) % Mod;
			}
//		printf("%lld %lld(%lld) %lld\n", s1, s2, inv(s2), s1 % Mod * inv(s2) % Mod);
		ans = (ans + s1 * inv(s2) % Mod * y[i] % Mod + Mod) % Mod;
	}
	printf("%lld\n", ans);
	
	return 0;
}
