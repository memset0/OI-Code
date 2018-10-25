#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, m, x, y, z, ans = 2 << 30, g[maxn][maxn], f[maxn][maxn];
int main() {
	memset(g, 63, sizeof(g));
	memset(f, 63, sizeof(f));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		g[x][y] = min(g[x][y], z);
		g[y][x] = min(g[y][x], z);
	}
	for (int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				ans = min(ans, f[i][j] + g[i][k] + g[k][j]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	}
	printf("%d", ans);
	return 0;
}
