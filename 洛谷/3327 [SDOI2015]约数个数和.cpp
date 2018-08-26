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

const int maxn = 50010;

int t, n, m;

ll ans;

int miu[maxn], vis[maxn], pri[maxn], sum[maxn], g[maxn];

void init() {

	int N = 50000;
	miu[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (!vis[i]) {
			miu[i] = -1;
			pri[++pri[0]] = i;
		}
		for (int j = 1; j <= pri[0] && i * pri[j] <= N; j++) {
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
			miu[i * pri[j]] = -miu[i];
		}
	}

	for (int i = 1; i <= N; i++)
		sum[i] = sum[i - 1] + miu[i];

	for (int n = 1; n <= N; n++) {

		for (int l = 1, r; l <= n; l = r + 1) {
			r = n / (n / l);
			g[n] += (n / l) * (r - l + 1);
		}

	}

}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	init();

	t = read();
	while (t--) {

		ans = 0;

		n = read(), m = read();
		if (n > m) swap(n, m);

		for (int l = 1, r; l <= n; l = r + 1) {
			r = min(n / (n / l), m / (m / l));
			ans += 1LL * (sum[r] - sum[l - 1]) * g[n / l] * g[m / l];
		}

		printf("%lld\n", ans);

	}

	return 0;
}