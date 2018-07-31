#include <bits/stdc++.h>
#define INF 1917483645
using namespace std;
const int maxn = 20, maxm = 1010;
int n, m, dis[maxn], a[maxn][maxn];
void DFS(int u, int k, int cnt, int val) {
	if (cnt == n) {
		ans = min(ans, val);
		return ;
	}
	for (int v = 1; v <= n; v++)
		if (dis[u] + a[u][v] * k < dis[v]) {
			dis[v] = dis[u] + a[u][v] * k;
		}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = INF;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		a[x][y] = min(a[x][y], z);
		a[y][x] = min(a[y][x], z);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			dis[j] = INF;
		dis[i] = 0;
		DFS(i, 1, 1, 0);
	}
}
