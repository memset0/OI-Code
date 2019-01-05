// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.13 23:55:39
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template <class T> inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void maxd(T &a, T b) { if (b > a) a = b; }
template <class T> inline void mind(T &a, T b) { if (b < a) a = b; }
template <class T> inline void print(T x, char c) { print(x), putchar(c); }

const int N = 1e6 + 10;
int n, m, u, v, w, t, tot, pos, tim, hed;
typedef int R1[N]; R1 siz, son, fa, dep, top, low, dfn, ins, stk, id, wid;

struct graph {
	int tot, hed[N], nxt[N << 1], to[N << 1];
	graph () { tot = 2; }
	inline void add_edge(int u, int v) {
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
} G1, G2;

void tarjan(int u, int father) {
	dfn[u] = low[u] = ++tim, ins[u] = 1, stk[++hed] = u;
	for (int i = G1.hed[u], v = G1.to[i]; i; i = G1.nxt[i], v = G1.to[i])
		if (v != father) {
			if (!dfn[v]) {
				tarjan(v, u), low[u] = std::min(low[u], low[v]);
				if (low[v] >= dfn[u]) {
					G2.add_edge(u, ++tot);
					int x; do {
						x = stk[hed--];
						ins[x] = false, G2.add_edge(x, tot);
					} while (x != v);
				}
			} else if (ins[v]) low[u] = std::min(low[u], dfn[v]);
		}
}

inline int lca(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) std::swap(u, v);
		v = fa[top[v]];
	}
	return dep[u] < dep[v] ? u : v;
}

void dfs(int u) {
	siz[u] = 1;
	for (int i = G2.hed[u], v = G2.to[i]; i; i = G2.nxt[i], v = G2.to[i])
		if (v != fa[u]) {
			fa[v] = u, dep[v] = dep[u] + 1, dfs(v), siz[u] += siz[v];
			if (siz[v] > siz[son[u]]) son[u] = v;
		}
}

void dfs(int u, int toppoint) {
	top[u] = toppoint, id[u] = ++pos, wid[id[u]] = u;
	if (siz[u] == 1) return;
	dfs(son[u], toppoint);
	for (int i = G2.hed[u], v = G2.to[i]; i; i = G2.nxt[i], v = G2.to[i])
		if (v != fa[u] && v != son[u])
			dfs(v, v);
}

void main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(u), read(v);
		G1.add_edge(u, v);
	}
	tot = n;
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) {
			tarjan(i, 0), dep[i] = 1;
			dfs(i), dfs(i, i);
		}
	read(m);
	for (int i = 1; i <= m; i++) {
		read(u), read(v), t = lca(u, v);
		w = dep[u] + dep[v] - (dep[t] << 1) + 1;
		print((w + 1) >> 1, '\n');
	}
}

} signed main() { return ringo::main(), 0; }