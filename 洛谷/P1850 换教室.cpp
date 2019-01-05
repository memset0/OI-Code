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

const int maxn = 2010;

int n, m, u, v, w, e, t;
int c1, c2, c3, c4;

int p[maxn][maxn], c[maxn], d[maxn];

double ans, k[maxn], f[maxn][maxn][2];

int main() {
//	freopen("INPUT", "r", stdin);
	memset(p, 63, sizeof(p));
	
	n = read(), m = read(), t = read(), e = read();
	for (int i = 1; i <= n; i++)
		c[i] = read();
	for (int i = 1; i <= n; i++)
		d[i] = read();
	for (int i = 1; i <= n; i++)
		scanf("%lf", &k[i]);
	for (int i = 1; i <= e; i++) {
		u = read(), v = read(), w = read();
		p[u][v] = p[v][u] = min(p[u][v], w);
	}
	
	for (int k = 1; k <= t; k++)
		for (int i = 1; i <= t; i++)
			for (int j = 1; j <= t; j++)
				p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
	for (int i = 1; i <= t; i++)
		p[i][i] = p[i][0] = p[0][i] = 0;
	
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			f[i][j][0] = f[i][j][1] = 1e10 + 10;
	f[1][0][0] = f[1][1][1] = 0;
	for (int i = 2; i <= n; i++) {
		f[i][0][0] = f[i - 1][0][0] + p[c[i - 1]][c[i]];
		for (int j = 1; j <= i; j++) {
			c1 = c[i - 1], c2 = d[i - 1], c3 = c[i], c4 = d[i];
			f[i][j][0] = min(
				f[i - 1][j][0]
					+ p[c1][c3],
				f[i - 1][j][1]
					+ p[c2][c3] * k[i - 1]
					+ p[c1][c3] * (1 - k[i - 1])
				);
			f[i][j][1] = min(
				f[i - 1][j - 1][0]
					+ p[c1][c4] * k[i]
					+ p[c1][c3] * (1 - k[i]), 
				f[i - 1][j - 1][1]
					+ p[c2][c4] * k[i - 1] * k[i]
					+ p[c1][c4] * (1 - k[i - 1]) * k[i]
					+ p[c2][c3] * k[i - 1] * (1 - k[i])
					+ p[c1][c3] * (1 - k[i - 1]) * (1 - k[i])
				);
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= m; j++)
//			printf("(%.2lf %.2lf)", f[i][j][0] > 1e10 ? -1 : f[i][j][0], f[i][j][1] > 1e10 ? -1 : f[i][j][1]);
//		puts("");
//	}
	ans = f[n][0][0];
	for (int i = 0; i <= m; i++)
		ans = min(ans, min(f[n][i][0], f[n][i][1]));
	printf("%.2lf\n", ans);
	return 0;
}
