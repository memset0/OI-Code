// luogu-judger-enable-o2
// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long

ll read() {
	ll x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

ll a, b, p, m, u, t, stp, cnt, ans;
std::map < ll, ll > hash;

ll bsgs(int a, int b, int p) {
	a %= p, b %= p;
	if (b == 1) return 0;
	t = 1, cnt = 0;
	for (int g = std::__gcd(a, p); g != 1; g = std::__gcd(a, p)) {
		if (b % g) return -1;
		b /= g, p /= g, t = t * a / g % p; 
		++cnt;
		if (b == t) return cnt;
	}
	hash.clear();
	m = sqrt(p) + 1, u = b;
	for (int i = 0; i < m; i++) {
		hash[u] = i;
		u = u * a % p;
	}
	stp = 1, u = t;
	for (int i = 1; i <= m; i++)
		stp = stp * a % p;
	for (int i = 1; i <= m + 1; i++) {
		u = u * stp % p;
		if (hash.count(u)) {
//			printf("%d %lld %d %lld %lld\n", i, m, hash[u], cnt, u);
			return i * m - hash[u] + cnt;
		}
	}
	return -1;
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
	while ((a = read()) + (p = read()) + (b = read())) {
		~(ans = bsgs(a, b, p)) ? printf("%lld\n", ans) : puts("No Solution");
	}
	return 0;
}