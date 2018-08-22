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

const int maxn = 1e6 + 10;
int n, m, l, r, i, x, opt;
ll a[maxn], s[maxn];

#define lowbit(x) ((x)&(-(x)))

void add(int i, ll x) {
	for (; i <= n; i += lowbit(i))
		s[i] += x;
}

ll ask(int i) {
	ll ans = 0;
	for (; i; i -= lowbit(i))
		ans += s[i];
	return ans;
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read(), add(i, a[i]);

	for (int i = 1; i <= m; i++) {
		opt = read();
		if (opt == 1) {
			l = read(), x = read();
			add(l, x);
		} else {
			l = read(), r = read();
			printf("%lld\n", ask(r) - ask(l - 1));
		}
	}

	return 0;
}