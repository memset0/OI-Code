// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

const int maxn = 50010, inf = 1e9;
int n, m, u, v, w, t, tu, tv, pos;
int a[maxn], fa[maxn], top[maxn], siz[maxn], son[maxn], id[maxn], wid[maxn], dep[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

struct status {
	int ans, rev, max, min;
	il status () {}
	il status (int a, int b, int c, int d) { ans = a, rev = b, max = c, min = d; }
	il void print() { printf("%d %d %d %d\n", ans, rev, max, min); }
	il status reverse() { return status(rev, ans, max, min); }
	il status operator + (const status &other) const {
		return status(std::max(ans, std::max(other.ans, other.max - min)),
			std::max(rev, std::max(other.rev, max - other.min)),
			std::max(max, other.max), std::min(min, other.min));
	}
} ans, lft, rit;

struct node {
	int l, r, mid, tag;
	status x;
} p[maxn << 2];

void dfs1(int u) {
	siz[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u]) {
			fa[v] = u, dep[v] = dep[u] + 1;
			dfs1(v);
			siz[u] += siz[v];
			if (siz[v] > siz[son[u]])
				son[u] = v;
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

int lca(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) std::swap(u, v);
		v = fa[top[v]];
	}
	return dep[u] < dep[v] ? u : v;
}

il void pushup(int u, int w) {
	// printf("pushup %d %d : %d %d\n", u, w, p[u].l, p[u].r);
	p[u].x.max += w, p[u].x.min += w;
	p[u].tag += w;
}

il void pushdown(int u) {
	if (p[u].tag) {
		if (p[u].l != p[u].r) {
			pushup(u << 1, p[u].tag);
			pushup(u << 1 | 1, p[u].tag);
		}
		p[u].tag = 0;
	}
}

void build(int u, int l, int r) {
	// printf("build %d %d %d\n", u, l, r);
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) { p[u].x = status(-inf, -inf, a[wid[l]], a[wid[l]]); return; }
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].x = p[u << 1].x + p[u << 1 | 1].x;
}

void modify(int u, int l, int r, int w) {
	// printf("modify %d %d %d %d\n", u, l, r, w);
	pushdown(u);
	if (p[u].l == l && p[u].r == r) { pushup(u, w); return; }
	if (r <= p[u].mid) modify(u << 1, l, r, w);
	else if (l > p[u].mid) modify(u << 1 | 1, l, r, w);
	else modify(u << 1, l, p[u].mid, w), modify(u << 1 | 1, p[u].mid + 1, r, w);
	p[u].x = p[u << 1].x + p[u << 1 | 1].x;
}

status query(int u, int l, int r) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) return p[u].x;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else return query(u << 1, l, p[u].mid) + query(u << 1 | 1, p[u].mid + 1, r);
}

void dfs_seg(int u) {
	pushdown(u);
	if (p[u].l == p[u].r) {
		printf("%d : ", u), p[u].x.print();
		return;
	}
	dfs_seg(u << 1);
	dfs_seg(u << 1 | 1);
}

void main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
	read(m);
	dfs1(1), dfs2(1, 1), build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		read(u), read(v), read(w), tu = u, tv = v, t = lca(u, v);
		// printf("=== %d %d %d : %d ===\n", u, v, w, t);
		// === query ===
		lft = rit = (status){-inf, -inf, -inf, inf};
		while (top[u] != top[t]) lft = lft + query(1, id[top[u]], id[u]).reverse(), u = fa[top[u]];
		lft = lft + query(1, id[t], id[u]).reverse();
		while (top[v] != top[t]) rit = query(1, id[top[v]], id[v]) + rit, v = fa[top[v]];
		if (id[t] != id[v]) rit = query(1, id[t] + 1, id[v]) + rit;
		ans = lft + rit;
		print(std::max(0, ans.ans)), putc('\n');
		// === modify ===
		u = tu, v = tv;
		while (top[u] != top[t]) modify(1, id[top[u]], id[u], w), u = fa[top[u]];
		modify(1, id[t], id[u], w);
		while (top[v] != top[t]) modify(1, id[top[v]], id[v], w), v = fa[top[v]];
		if (id[t] != id[v]) modify(1, id[t] + 1, id[v], w);
		// === dfs ===
		// dfs_seg(1);
	}
}

} int main() { return ringo::main(), 0; }
