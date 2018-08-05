#include <bits/stdc++.h>
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 100010;
int n, m, u, v, w, s[maxn], f[maxn][20], dep[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1];

void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	hed[u] = tot++;
}

void dfs(int u) {
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != f[u][0]) {
			f[to[i]][0] = u;
			dep[to[i]] = dep[u] + 1;
			s[to[i]] = s[u] ^ val[i];
			dfs(to[i]);
		}
}

int lca(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = 19; i >= 0; i--)
		if (dep[f[v][i]] >= dep[u])
			v = f[v][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--)
		if (f[u][i] != f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}

int main() {
	n = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read(), w = read();
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	dep[1] = 1, dfs(1);
	m = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read();
		printf("%d\n", s[u] ^ s[v]);
	}
	return 0;
}