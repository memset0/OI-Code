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

#define locate(x, y, k) ((k) * n * n + ((x) - 1) * n + (y))

const int maxn = 110, max_point = 110010, max_edge = max_point * 20;
int n, m, a, b, c, l, r, s, u, ans, inq[max_point], dis[max_point], g[maxn][maxn], q[1000010];
int tot = 2, hed[max_point], nxt[max_edge], to[max_edge], val[max_edge];

void add_edge(int u, int v, int w) {
	// printf("%d -> %d : %d\n", u, v, w);
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
}

void add_way(int ux, int uy, int vx, int vy, int uk, int cst) {
	if (vx < 1 || vy < 1 || vx > n || vy > n) return;
	if (g[vx][vy]) add_edge(locate(ux, uy, uk), locate(vx, vy, m), cst + a);
	else {
		add_edge(locate(ux, uy, uk), locate(vx, vy, uk - 1), cst);
		add_edge(locate(ux, uy, uk), locate(vx, vy, m), cst + a + c);
	}
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);
	memset(dis, 0x3f, sizeof(dis));

	n = read(), m = read(), a = read(), b = read(), c = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			g[i][j] = read();

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			for (int k = m; k > 0; k--) {
				add_way(i, j, i + 1, j, k, 0);
				add_way(i, j, i, j + 1, k, 0);
				add_way(i, j, i - 1, j, k, b);
				add_way(i, j, i, j - 1, k, b);
			}
		}

	s = locate(1, 1, m);
	l = r = 1, q[1] = s, dis[s] = 0, inq[s] = 1;
	while (l <= r) {
		u = q[l++], inq[u] = 0;
		for (int i = hed[u]; i; i = nxt[i])
			if (dis[to[i]] > dis[u] + val[i]) {
				// printf("%d -> %d : %d\n", u, to[i], val[i]);
				dis[to[i]] = dis[u] + val[i];
				if (!inq[to[i]]) {
					inq[to[i]] = 1;
					q[++r] = to[i];
				}
			}
	}

	ans = 0x3f3f3f3f;
	for (int i = 0; i <= m; i++)
		ans = min(ans, dis[locate(n, n, i)]);
	printf("%d\n", ans);

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		int ans = 0x3f3f3f3f;
	// 		for (int k = 0; k <= m; k++)
	// 			ans = min(ans, dis[locate(i, j, k)]);
	// 		printf("%d ", ans);
	// 	}
	// 	puts("");
	// }

	return 0;
}