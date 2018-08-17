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

const int maxn = 500010;
int n, m, u, v, x, y, z, xy, yz, xz, ans, sum;
int dep[maxn], f[maxn][21];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

void add_edge(int u, int v) {
	nxt[tot] = hed[u];
	to[tot] = v;
	hed[u] = tot++;
}

void dfs(int u) {
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != f[u][0]) {
			f[to[i]][0] = u;
			dep[to[i]] = dep[u] + 1;
			dfs(to[i]);
		}
}

int lca(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = 20; i >= 0; i--)
		if (dep[f[v][i]] >= dep[u])
			v = f[v][i];
	if (u == v) return u;
	for (int i = 20; i >= 0; i--)
		if (f[u][i] != f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}

int dis(int u, int v) {
	return dep[u] + dep[v] - (dep[lca(u, v)] << 1);
}

int maxdep(int a, int b, int c) {
	int ans = a;
	if (dep[b] > dep[ans]) ans = b;
	if (dep[c] > dep[ans]) ans = c;
	return ans;
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		add_edge(u, v);
		add_edge(v, u);
	}

	dep[1] = 1;
	dfs(1);
	for (int i = 1; i < 21; i++)
		for (int j = 1; j <= n; j++)
			f[j][i] = f[f[j][i - 1]][i - 1];

	for (int i = 1; i <= m; i++) {
		x = read(), y = read(), z = read();
		xy = lca(x, y), xz = lca(x, z), yz = lca(y, z);
		// printf("%d %d %d %d %d %d\n", x, y, z, xy, yz, xz);
		ans = maxdep(xy, xz, yz);
		if (ans == xy) {
			sum = dep[x] + dep[y] + dep[z] - dep[xy] - (dep[xz] << 1);
		} else if (ans == xz) {
			sum = dep[x] + dep[z] + dep[y] - dep[xz] - (dep[yz] << 1);
		} else {
			sum = dep[y] + dep[z] + dep[x] - dep[yz] - (dep[xy] << 1);
		}
		printf("%d %d\n", ans, sum);
	}

	return 0;
}