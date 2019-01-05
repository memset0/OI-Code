#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}

template < class T >
inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
	print(x), putchar(c);
}

const int N = 1e5 + 10, inf = 1e9;
int n, m, u, v, w, t, pos;
int a[N], id[N], fa[N], wid[N], top[N], son[N], siz[N], dep[N];
int tot = 2, hed[N], to[N << 1], nxt[N << 1], val[N << 1];

typedef std::pair < int, int > pair;
pair ans;

struct node {
	int l, r, mid;
	pair x;
} p[N << 2];

void dfs1(int u) {
	// printf("dfs1 %d\n", u);
	siz[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u]) {
			fa[v] = u, dep[v] = dep[u] + 1, dfs1(v), siz[u] += siz[v], a[v] = val[i];
			if (siz[v] > siz[son[u]]) son[u] = v;
		}
}

void dfs2(int u, int toppoint) {
	// printf("dfs2 %d %d\n", u, toppoint);
	id[u] = ++pos, wid[id[u]] = u, top[u] = toppoint;
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u] && v != son[u])
			dfs2(v, v);
}

inline int lca(int u,int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) std::swap(u, v);
		v = fa[top[v]];
	}
	return dep[u] < dep[v] ? u : v;
}

inline pair merge(const pair &a, const pair &b) {
	return std::make_pair(std::min(a.first, b.first), std::max(a.second, b.second));
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) { p[u].x = std::make_pair(a[wid[l]], a[wid[l]]); return; }
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].x = merge(p[u << 1].x, p[u << 1 | 1].x);
}

pair query(int u, int l, int r) {
	if (p[u].l == l && p[u].r == r) return p[u].x;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else return merge(query(u << 1, l, p[u].mid), query(u << 1 | 1, p[u].mid + 1, r));
}

pair jump(int u, int v) {
	pair ans = std::make_pair(inf, -inf);
	while (top[u] != top[v]) {
		ans = merge(ans, query(1, id[top[u]], id[u]));
		u = fa[top[u]];
	}
	if (u != v) ans = merge(ans, query(1, id[v] + 1, id[u]));
	return ans;
}

void main() {
	read(n);
	for (int i = 1; i < n; i++) {
		read(u), read(v), read(w);
		nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, val[tot] = w, hed[v] = tot++;
	}
	dfs1(1), dfs2(1, 1), build(1, 1, n);
	read(m);
	for (int i = 1; i <= m; i++) {
		read(u), read(v), t = lca(u, v);
		ans = merge(jump(u, t), jump(v, t));
		print(ans.first, ' '), print(ans.second, '\n');
	}
}

} signed main() { return ringo::main(), 0; }