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

const int maxn = 60;
int n, m, u, v;
int f[maxn][maxn], g[maxn][maxn][maxn];

int main() {
	memset(f, 63, sizeof(f));
	
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read();
		f[u][v] = g[u][v][0] = 1;
	}
	
	for (int t = 1; t <= n; t++)
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++) {
					g[i][j][t] |= g[i][k][t - 1] & g[k][j][t - 1];
					if (g[i][j][t]) f[i][j] = 1;
				}
//	for (int t = 0; t <= n; t++) {
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++)
//				printf("%d ", g[i][j][t]);
//			puts("");
//		}
//		puts("");
//	}
	for (int t = 1; t <= n; t++)
		f[t][t] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			printf("%d ", f[i][j]);
//		puts("");
//	}
	printf("%d\n", f[1][n]);
	
	return 0;
}