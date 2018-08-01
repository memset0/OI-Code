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

const int maxn = 300010, M = 998244353;
int n, m, u, v, w, t, _u, _v;
int dep[maxn], f[maxn][20];
ll ans, mul[maxn][51], g[maxn][51];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];
inline void add_edge(int u, int v) {
	nxt[tot] = hed[u];
	to[tot] = v;
	hed[u] = tot++;
}
inline int lca(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = 19; i >= 0; i--)
		if (dep[f[v][i]] >= dep[u] && f[v][i])
			v = f[v][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--)
		if (f[u][i] != f[v][i] && f[u][i] && f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}
void init_dfs(int u) {
	mul[u][1] = dep[u];
	for (int i = 2; i <= 50; i++)
		mul[u][i] = (mul[u][i - 1] * dep[u]) % M;
	for (int i = 1; i <= 50; i++)
		g[u][i] = (g[u][i] + mul[u][i]) % M;
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != f[u][0]) {
			dep[to[i]] = dep[u] + 1;
			f[to[i]][0] = u;
			for (int k = 1; k <= 50; k++)
				g[to[i]][k] = g[u][k];
			init_dfs(to[i]);
		}
}
inline void init(void) {
	dep[1] = 0, init_dfs(1);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++)
			f[j][i] = f[f[j][i - 1]][i - 1];
}
int main() {
	n = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		add_edge(u, v);
		add_edge(v, u);
	}
	init();
	m = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), w = read(), t = lca(u, v);
		ans = (g[u][w] + g[v][w] - g[t][w] - g[f[t][0]][w] + M + M) % M;
		printf("%lld\n", ans);
	}
	return 0;
}

