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

const int maxn = 310;

int n, s, m, l, r, u, v, w, ans, max, now;
int dis[maxn], cst[maxn], sum[maxn], q[maxn], pre[maxn], f[maxn][maxn], pnt[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1];

void add_edge(int u, int v, int w)  {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
	hed[u] = tot++;
}

void bfs(int s) {
	memset(dis, 0, sizeof(dis));
	memset(pre, 0, sizeof(pre));
	l = r = 1, q[1] = s, dis[s] = 1;
	while (l <= r) {
		u = q[l++];
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (!dis[v]) {
				dis[v] = dis[u] + val[i];
				pre[v] = i;
				q[++r] = v;
			}
	}
}

int main() {
	memset(f, 63, sizeof(f));
	n = read(), s = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read(), w = read();
		add_edge(u, v, w), add_edge(v, u, w);
		f[u][v] = f[v][u] = w;
	}
	bfs(1);
	for (int i = 1; i <= n; i++)
		if (dis[i] > dis[max])
			max = i;
	bfs(max);
	max = 0;
	for (int i = 1; i <= n; i++)
		if (dis[i] > dis[max])
			max = i;
	pnt[0] = max;
	for (int i = pre[max]; i; i = pre[to[i ^ 1]]) {
		cst[++m] = val[i];
		pnt[m] = to[i ^ 1];
	}
	for (int i = 1; i <= m; i++)
		sum[i] = sum[i - 1] + cst[i];
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
	ans = f[0][0];
	for (int i = 1, j = 0; i <= m; i++) {
		s += cst[i - 1];
		while (j <= m && s >= cst[j]) s -= cst[j++];
		max = 0;
		for (int t = 1; t <= n; t++) {
			now = f[0][0];
			for (int k = i - 1; k < j; k++)
				now = std::min(now, f[t][pnt[k]]);
			max = std::max(max, now);
		}
//		printf(">>> %d\n", max);
		ans = std::min(ans, max);
	}
	printf("%d\n", ans);
	
	return 0;
}
