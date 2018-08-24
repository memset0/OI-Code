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

int t, a, b, d, ans, sum[maxn], miu[maxn], f[maxn], pri[maxn];

void init() {
	miu[1] = 1, f[0] = f[1] = 1;
	for (int i = 2; i <= 50000; i++) {
		if (!f[i]) {
			miu[i] = -1;
			pri[++pri[0]] = i;
		}
		for (int j = 1; j <= pri[0] && i * pri[j] <= 50000; j++) {
			f[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
			miu[i * pri[j]] = -miu[i];
		}
	}
	for (int i = 1; i <= 50000; i++)
		sum[i] = sum[i - 1] + miu[i];
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	init();

	t = read();
	while (t--) {
		ans = 0;

		a = read(), b = read(), d = read();
		if (a > b) swap(a, b);
		a /= d, b /= d;

		// cout << a << " " << b << endl;

		for (int l = 1, r; l <= a; l = r + 1) {
			r = min(a / (a / l), b / (b / l));
			ans = ans + (a / l) * (b / l) * (sum[r] - sum[l - 1]);
		}

		printf("%d\n", ans);

	}

	return 0;
}