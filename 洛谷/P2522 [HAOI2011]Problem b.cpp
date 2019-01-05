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

const int maxn = 50000;

int t, a, b, c, d, k;

int vis[50000], pri[50000], sum[50000], miu[50000];

void init() {

	miu[1] = 1;

	for (int i = 2; i <= 50000; i++) {
		if (!vis[i]) {
			miu[i] = -1;
			pri[++pri[0]] = i;
		}
		for (int j = 1; j <= pri[0] && i * pri[j] <= 50000; j++) {
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
		 	miu[i * pri[j]] = -miu[i];
		}
	}

	for (int i = 1; i <= 50000; i++)
		sum[i] = sum[i - 1] + miu[i];

}

ll calc(int n, int m) {

	ll ans = 0;

	if (n > m) swap(n, m);
	n /= k, m /= k;

	for (int l = 1, r; l <= n; l = r + 1) {
		r = min(n / (n / l), m / (m / l));
		ans = ans + 1LL * (n / l) * (m / l) * (sum[r] - sum[l - 1]);
	}

	// printf("%d %d %lld\n", n, m, ans);

	return ans;

}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	init();

	t = read();
	while (t--) {

		a = read(), b = read();
		c = read(), d = read();
		k = read();

		printf("%lld\n", calc(b, d)
				- calc(a - 1, d)
				- calc(b, c - 1)
				+ calc(a - 1, c - 1));

	}

	return 0;
}