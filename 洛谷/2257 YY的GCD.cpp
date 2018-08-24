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

const int maxn = 10000010;

int t, n, m;

int miu[maxn], sum[maxn], pri[maxn], fun[maxn];
bool vis[maxn];
ll ans;

void init() {
	miu[1] = 1;
	for (int i = 2; i <= 10000000; i++) {
		if (!vis[i]) {
			miu[i] = -1;
			pri[++pri[0]] = i;
		}
		for (int j = 1; j <= pri[0] && i * pri[j] <= 10000000; j++) {
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
			miu[i * pri[j]] = miu[i] * -1;
		}
	}
	for (int i = 1; i <= pri[0]; i++)
		for (int j = 1; j * pri[i] <= 10000000; j++)
			fun[j * pri[i]] += miu[j];
	for (int i = 1; i <= 10000000; i++)
		sum[i] = sum[i - 1] + fun[i];
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
			// cout << l << " " << r << " " << sum[l - 1] << " " << sum[r] << endl;
			ans = ans + 1LL * (n / l) * (m / l) * (sum[r] - sum[l - 1]);
		}

		printf("%lld\n", ans);

	}

	return 0;
}