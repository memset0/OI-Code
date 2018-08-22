// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

#define lowbit(i) ((i)&(-(i)))

const int maxn = 1000010;
int n, m, l, r, x, opt, a[maxn];
ll s[maxn], c[2][maxn];

void modify(int k, ll x) {
	for (int i = k; i <= n; i += lowbit(i))
		c[0][i] += x, c[1][i] += x * (k + 1);
}

ll query(int k) {
	ll ans = 0;
	for (ll i = k; i > 0; i -= lowbit(i))
		ans += c[0][i] * (k + 1) - c[1][i];
	return ans;
}

int main() {
	freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read(), s[i] = s[i - 1] + a[i];

	for (int i = 1; i <= m; i++) {
		opt = read();
		if (opt == 1) {
			l = read(), r = read(), x = read();
			modify(l, x), modify(r + 1, -x);
		} else {
			l = read(), r = read();
			printf("%lld\n", query(r + 1) - query(l) + s[r] - s[l - 1]);
		}
	}

	return 0;
}