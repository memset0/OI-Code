// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 210;

int n, ans, sum[maxn], f[maxn][maxn * maxn];
struct node {
	int a, b;
} a[maxn];
bool operator < (const node &a, const node &b) {
	return a.b > b.b;
}

inline int min(int a, int b) {
	if (!~a) return b;
	if (!~b) return a;
	return std::min(a, b);
}

int main() {
	memset(f, -1, sizeof(f));
	n = read();
	for (int i = 1; i <= n; i++)
		a[i].a = read(), a[i].b = read();
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i].a;
	f[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= 40000 - a[i + 1].a; j++)
			if (~f[i][j]) {
				f[i + 1][j + a[i + 1].a] = min(f[i + 1][j + a[i + 1].a], std::max(f[i][j], j + a[i + 1].a + a[i + 1].b));
				f[i + 1][j] = min(f[i + 1][j], std::max(f[i][j], sum[i + 1] - j + a[i + 1].b));
//				printf("f[%d][%d] -> %d\n", i, j, f[i][j]);
			}
	ans = -1;
	for (int i = 0; i <= 40000; i++)
		ans = min(ans, f[n][i]);
	printf("%d\n", ans);
	return 0;
}
