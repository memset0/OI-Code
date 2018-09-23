// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 1000000, maxm = 110, maxk = 510;
const ll inf = 1e18;

int n, m, k, t, x;
int p[maxn], cnt[maxm];
ll a[maxm][maxk], f[maxm][maxk];

ll s(ll x) {
	return ((x) * (x + 1)) >> 1LL;
}

int main() {
//	freopen("noise.in", "r", stdin);
//	freopen("noise.out", "w", stdout);
//	freopen("3.txt", "r", stdin);
//	freopen("1.txt", "w", stdout);

	n = read(), m = read(), k = read() ;
	for (int i = 1; i <= n; i++) {
		p[i] = read();
		cnt[p[i]]++;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < cnt[i] && j <= k; j++) {
			ll k = (cnt[i] - 1) / (j + 1) + 1;
			a[i][j] = s(k) * (cnt[i] - k * j - k + j + 1) + s(k - 1) * (k * j + k - cnt[i]);
		}
		for (int j = cnt[i]; j <= k; j++)
			a[i][j] = cnt[i];
	}
	
//	for (int i = 1; i <= m; i++)
//		printf("%d ", cnt[i]);
//	puts("");puts("");
		
	for (int i = 1; i <= m; i++)
		for (int j = 0; j <= k; j++) {
			f[i][j] = inf;
			for (int t = 0; t <= j; t++)
				f[i][j] = std::min(f[i][j], f[i - 1][t] + a[i][j - t]);
		}
//	for (int i = 1; i <= m; i++) {
//		for (int j = 0; j <= k; j++)
//			printf("%lld ", a[i][j]);
//		puts("");
//	}
//	puts("");
//	for (int i = 1; i <= m; i++) {
//		for (int j = 0; j <= k; j++)
//			printf("%lld ", f[i][j]);
//		puts("");
//	}
//	puts("");
		
	printf("%lld\n", f[m][k]);

	return 0;
}
