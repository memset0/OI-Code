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

const int maxn = 50010;

int n, m, u, v, w, t, pos;
int siz[maxn], id[maxn], wid[maxn], top[maxn], fa[maxn], son[maxn], dep[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

struct edge {
	int u, v, w;
	inline edge () {}
	inline edge (int a, int b, int c = 0) { u = a, v = b, w = c; }
} e[maxn], g[maxn];

inline int min(int a, int b) {
	if (!~a) return b;
	if (!~b) return a;
	return std::min(a, b);
}

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

struct seg_node {
	int l, r, mid;
	int min, lazy;
} p[maxn << 2];

inline void pushup(int u, int x) {
	p[u].min = min(p[u].min, x);
	p[u].lazy = min(p[u].lazy, x);
}
inline void pushdown(int u)  {
	if (~p[u].lazy) {
		if (p[u].l ^ p[u].r) {
			pushup(u << 1, p[u].lazy);
			pushup(u << 1 | 1, p[u].lazy);
		}
		p[u].lazy = -1;
	}
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	p[u].min = p[u].lazy = -1;
	if (l == r) return;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}

void modify(int u, int l, int r, int x) {
	if (l > r) return; pushdown(u);
//	printf("modify %d %d %d %d %d %d\n", u, l, r, p[u].l, p[u].r, x);
	if (p[u].l == l && p[u].r == r) { pushup(u, x); return; }
	if (r <= p[u].mid) modify(u << 1, l, r, x);
	else if (l > p[u].mid) modify(u << 1 | 1, l, r, x);
	else modify(u << 1, l, p[u].mid, x), modify(u << 1 | 1, p[u].mid + 1, r, x);
	p[u].min = min(p[u << 1].min, p[u << 1 | 1].min);
}

int query(int u, int l, int r) {
	if (l > r) return -1; pushdown(u);
	if (p[u].l == l && p[u].r == r) return p[u].min;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else return min(query(u << 1, l, p[u].mid), query(u << 1 | 1, p[u].mid + 1, r));
}
int query(int u, int k) {
	pushdown(u);
	if (p[u].l == p[u].r) return p[u].min;
	if (k <= p[u].mid) return query(u << 1, k);
	else return query(u << 1 | 1, k);
}

int lca(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) std::swap(u, v);
		v = fa[top[v]];
	}
	if (dep[u] > dep[v]) std::swap(u, v);
	return u;
}

void update_path(int u, int v, int x) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) std::swap(u, v);
		modify(1, id[top[v]], id[v], x);
		v = fa[top[v]];
	}
	if (dep[u] > dep[v]) std::swap(u, v);
	modify(1, id[son[u]], id[v], x);
}

int main() {
	
	n = read(), m = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		g[i] = edge(u, v);
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), w = read();
		e[i] = edge(u, v, w);
	}
	
	dfs1(1);
	dfs2(1, 1);
	build(1, 1, n);
	
	for (int i = 1; i <= m; i++) {
		u = e[i].u, v = e[i].v, w = e[i].w;
		t = lca(u, v);
		update_path(u, t, w);
		update_path(v, t, w);
	}
	
//	for (int i = 1; i <= n; i++)
//		printf("%d ", dep[i]);
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", query(1, i));
//	puts("");
	for (int i = 1; i < n; i++) {
		u = g[i].u, v = g[i].v;
		if (dep[u] > dep[v]) std::swap(u, v);
//		printf(">> %d %d >> ", u, v);
		printf("%d\n", query(1, id[v], id[v]));
	}

	return 0;
}
