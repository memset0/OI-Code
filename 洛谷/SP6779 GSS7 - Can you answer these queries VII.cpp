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

const int N = 1e5 + 10;
int n, m, u, v, w, t, op, pos;
int a[N], fa[N], id[N], wid[N], top[N], dep[N], son[N], siz[N];
int tot = 2, hed[N], to[N << 1], nxt[N << 1];

struct status {
	int lmax, rmax, max, sum;
	inline status reverse() {
		return (status) { rmax, lmax, max, sum };
	}
} lft, rit, ans;

struct node {
	int l, r, mid, tag, flag;
	status x;
} p[N << 2];

inline status new_status(int x) {
	return (status) { x, x, x, x };
}

inline status merge(const status &a, const status &b) {
	return (status) {
		std::max(a.lmax, a.sum + b.lmax),
		std::max(b.rmax, b.sum + a.rmax),
		std::max(a.rmax + b.lmax, std::max(a.max, b.max)),
		a.sum + b.sum
	};
}

void dfs1(int u) {
	siz[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u]) {
			fa[v] = u, dep[v] = dep[u] + 1, dfs1(v), siz[u] += siz[v];
			if (siz[v] > siz[son[u]]) son[u] = v;
		}
}

void dfs2(int u, int toppoint) {
	top[u] = toppoint, id[u] = ++pos, wid[id[u]] = u;
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u] && v != son[u])
			dfs2(v, v);
}

void pushup(int u, int x) {
	p[u].tag = x, p[u].flag = 1;
	p[u].x = new_status((p[u].r - p[u].l + 1) * x);
}

void pushdown(int u) {
	if (p[u].flag && p[u].l != p[u].r) {
		pushup(u << 1, p[u].tag);
		pushup(u << 1 | 1, p[u].tag);
		p[u].flag = 0;
	}
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) { p[u].x = new_status(a[wid[l]]); return; }
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].x = merge(p[u << 1].x, p[u << 1 | 1].x);
}

void modify(int u, int l, int r, int x) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) { pushup(u, x); return; }
	if (r <= p[u].mid) modify(u << 1, l, r, x);
	else if (l > p[u].mid) modify(u << 1 | 1, l, r, x);
	else modify(u << 1, l, p[u].mid, x), modify(u << 1 | 1, p[u].mid + 1, r, x);
	p[u].x = merge(p[u << 1].x, p[u << 1 | 1].x);
}

status query(int u, int l, int r) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) return p[u].x;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else return merge(query(u << 1, l, p[u].mid), query(u << 1 | 1, p[u].mid + 1, r));
}

void modify_link(int u, int v, int w) {
	while (top[u] != top[v]) {
		modify(1, id[top[u]], id[u], w);
		u = fa[top[u]];
	}
	modify(1, id[v], id[u], w);
}

inline int lca(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) std::swap(u, v);
		v = fa[top[v]];
	}
	return dep[u] < dep[v] ? u : v;
}

void debug(int l, int r) {
	status x = query(1, l, r);
	printf("%d %d : %d %d %d %d\n", l, r, x.lmax, x.rmax, x.max, x.sum);
}

void main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
	dfs1(1), dfs2(1, 1), build(1, 1, n);
	// for (int i = 1; i <= n; i++) print(id[i], " \n"[i == n]);
	read(m);
	for (int i = 1; i <= m; i++)
		if (read(op), op == 1) {
			read(u), read(v), t = lca(u, v);
			// printf("1 : %d %d\n", u, v);
			lft = rit = new_status(0);
			while (top[u] != top[t]) {
				lft = merge(lft, query(1, id[top[u]], id[u]).reverse());
				// debug(id[top[u]], id[u]);
				u = fa[top[u]];
			}
			lft = merge(lft, query(1, id[t], id[u]).reverse());
			// debug(id[t], id[u]);
			// puts("----");
			while (top[v] != top[t]) {
				rit = merge(query(1, id[top[v]], id[v]), rit);
				// debug(id[top[v]], id[v]);
				v = fa[top[v]];
			}
			if (v != t) rit = merge(query(1, id[t] + 1, id[v]), rit);
			// if (v != t) debug(id[t] + 1, id[v]);
			ans = merge(lft, rit);
			// printf(">>> %d %d %d %d\n", lft.lmax, lft.rmax, lft.max, lft.sum);
			// printf(">>> %d %d %d %d\n", rit.lmax, rit.rmax, rit.max, rit.sum);
			// printf(">>> %d %d %d %d\n", ans.lmax, ans.rmax, ans.max, ans.sum);
			print(std::max(0, ans.max), '\n');
		} else {
			read(u), read(v), read(w), t = lca(u, v);
			modify_link(u, t, w), modify_link(v, t, w);
		}
}

} signed main() { return ringo::main(), 0; }