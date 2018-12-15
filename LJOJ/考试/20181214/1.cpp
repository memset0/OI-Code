// =================================
//   author: memset0
//   date: 2018.12.14 08:07:29
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

const int N = 15e4 + 10;
const ll inf = 1e18;
int n, m, k, u, v, pos;
int p[N], son[N], siz[N], dep[N], id[N], wid[N], top[N], fa[N];
ll dis[N];
int tot = 2, hed[N], nxt[N << 1], to[N << 1], val[N << 1];

inline void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
}

void dfs(int u) {
	siz[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u]) {
			fa[v] = u, dep[v] = dep[u] + 1, dis[v] = dis[u] + p[v];
			dfs(v), siz[u] += siz[v];
			if (siz[v] > siz[son[u]]) son[u] = v;
		}
}

void dfs(int u, int toppoint) {
	top[u] = toppoint, id[u] = ++pos, wid[id[u]] = u;
	if (siz[u] == 1) return;
	dfs(son[u], toppoint);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u] && v != son[u])
			dfs(v, v);
}

inline int lca(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) std::swap(u, v);
		v = fa[top[v]];
	}
	return dep[u] > dep[v] ? v : u;
}

ll solve1() {
	ll ans = -inf;
	for (int u = 1, t; u <= n; u++)
		for (int v = 1; v <= n; v++) {
			t = lca(u, v);
			if (dep[u] + dep[v] - (dep[t] << 1) + 1 < k) continue;
			maxd(ans, dis[u] + dis[v] - (dis[t] << 1) + p[t]);
		}
	return ans;
}

ll solve2() {
	ll ans = 0;
	std::sort(p + 1, p + n + 1);
	for (int i = n - m + 1; i <= n; i++)
		ans += p[i];
	return ans;
}

void main() {
	read(n), read(m), read(k);
	for (int i = 1; i <= n; i++) read(p[i]);
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		add_edge(u, v);
	}
	dfs(1), dfs(1, 1);
	if (m == 1 && n <= 5000) { print(solve1(), '\n'); return; }
	print(solve2(), '\n');
}

} signed main() { return ringo::main(), 0; }