// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define ull unsigned long long
#define y1 this_is_not_y1
#define y2 this_is_not_y2
#define sqr ((x)*(x))
#define lowbit(x) ((x)&(-x))
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 100, maxm = 10000;
int n, m, u, v, w, f[maxn][maxn], g[maxn][maxn];
long long sum, ans = -1;
int tot, hed[maxn], nxt[maxm], to[maxm], val[maxm];

int main() {
//	freopen("castle.in", "r", stdin);
//	freopen("castle.out", "w", stdout);
	memset(f, 63, sizeof(f));
	
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), w = read();
		f[u][v] = f[v][u] = w;
	}
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	
	for (int x = 1; x <= n; x++)
		for (int y = x + 1; y <= n; y++) {
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					g[i][j] = f[i][j];
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					g[i][j] = min(g[i][j], min(g[i][x], g[i][y]) + min(g[x][j], g[y][j]));
			sum = 0;
			for (int i = 1; i <= n; i++)
				for (int j = i + 1; j <= n; j++)
					sum += g[i][j];
			ans = ((sum < ans) || (ans == -1)) ? sum : ans;
//			for (int i = 1; i <= n; i++) {
//				for (int j = 1; j <= n; j++)
//					printf("%d ", g[i][j]);
//				puts("");
//			}
//			printf("(%d, %d): %lld\n", x, y, sum);
		}

	printf("%lld\n", ans);

	return 0;
}
