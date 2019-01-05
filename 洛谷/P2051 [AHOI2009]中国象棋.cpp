// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 110;
const int p = 9999973;


int n, m, ans;
int f[maxn][maxn][maxn];
ll inv2;

ll inv(ll x) {
	if (x == 0 || x == 1) return 1;
	return (p - p / x) * inv(p % x) % p;
}

int C(int x) {
	return inv2 * x % p * (x - 1) % p;
}
#undef int
int main() {
#define int long long
	inv2 = inv(2);
	n = read(), m = read();
	f[0][0][0] = 1;
	for (int k = 0; k <= n; k++)
		for (int i = 0; i <= m; i++)
			for (int j = 0; i + j <= m; j++) {
//				if (f[k][i][j] < 0) printf("!!");
				(f[k + 1][i][j] += f[k][i][j]) %= p;
				if (m - i - j >= 1) (f[k + 1][i + 1][j] += 1LL * f[k][i][j] * (m - i - j)) %= p;
				if (m - i - j >= 2) (f[k + 1][i + 2][j] += 1LL * f[k][i][j] * C(m - i - j)) %= p;
				if (m - i - j >= 1 && i >= 1) (f[k + 1][i][j + 1] += 1LL * f[k][i][j] * (m - i - j) % p * i) %= p;
				if (i >= 1) (f[k + 1][i - 1][j + 1] += 1LL * f[k][i][j] * i) %= p;
				if (i >= 2) (f[k + 1][i - 2][j + 2] += 1LL * f[k][i][j] * C(i)) %= p;
//				printf("%d %d %d\n", f[k][i][j], f[k + 1][i + 1][j], m - i - j);
			}
//	for (int i = 0; i <= m; i++) {
//		for (int j = 0; i + j <= m; j++)
//			printf("%d ", f[n][i][j]);
//		puts("");
//	}
//	puts("");
	for (int i = 0; i <= m; i++)
		for (int j = 0; i + j <= m; j++)
			(ans += f[n][i][j]) %= p;
	printf("%lld\n", ans);
	return 0;
}
