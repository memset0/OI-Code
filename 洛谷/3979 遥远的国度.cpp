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

const int maxn = 100010, inf = 2e9 + 10;
int n, m, u, v, x, t, opt, ans, root, a[maxn];
int pos, id[maxn], son[maxn], top[maxn], fa[maxn], wa[maxn], siz[maxn], dep[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
}

void dfs1(int u) {
	siz[u] = 1;
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u]) {
			fa[to[i]] = u;
			dep[to[i]] = dep[u] + 1;
			dfs1(to[i]);
			siz[u] += siz[to[i]];
			if (siz[to[i]] > siz[son[u]])
				son[u] = to[i];
		}
}

void dfs2(int u, int toppoint) {
	// printf("dfs2 %d %d\n", u, toppoint);
	id[u] = ++pos, wa[id[u]] = a[u], top[u] = toppoint;
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u] && to[i] != son[u])
			dfs2(to[i], to[i]);
}

struct node {
	int l, r, mid, lazy, min;
} p[maxn << 2];

void pushup(int u, int x) {
	p[u].min = x;
	p[u].lazy = x;
}

void pushdown(int u) {
	if (p[u].lazy != inf) {
		if (p[u].l != p[u].r) {
			pushup(u << 1    , p[u].lazy);
			pushup(u << 1 | 1, p[u].lazy);
		}
		p[u].lazy = inf;
	}
}

void build(int l, int r, int u = 1) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	p[u].min = p[u].lazy = inf;
	if (l == r) {
		p[u].min = wa[l];
		return;
	}
	build(l, p[u].mid, u << 1);
	build(p[u].mid + 1, r, u << 1 | 1);
	p[u].min = min(p[u << 1].min, p[u << 1 | 1].min);
}

void modify(int l, int r, int x, int u = 1) {
	// printf("modify %d %d %d %d : %d %d %d\n", u, l, r, x, p[u].l, p[u].mid, p[u].r);
	pushdown(u);
	if (p[u].l == l && p[u].r == r) {
		pushup(u, x);
		return;
	}
	if (r <= p[u].mid) modify(l, r, x, u << 1);
	else if (l > p[u].mid) modify(l, r, x, u << 1 | 1);
	else modify(l, p[u].mid, x, u << 1), modify(p[u].mid + 1, r, x, u << 1 | 1);
	p[u].min = min(p[u << 1].min, p[u << 1 | 1].min);
}

int query(int l, int r, int u = 1) {
	if (l > r) return inf;
	pushdown(u);
	// printf("query %d %d %d\n", u, l, r);
	if (p[u].l == l && p[u].r == r) {
		return p[u].min;
	}
	if (r <= p[u].mid) return query(l, r, u << 1);
	else if (l > p[u].mid) return query(l, r, u << 1 | 1);
	else return min(query(l, p[u].mid, u << 1), query(p[u].mid + 1, r, u << 1 | 1));
}

int lca(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) swap(u, v);
		v = fa[top[v]];
	}
	if (dep[u] > dep[v]) swap(u, v);
	return u;
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		add_edge(u, v), add_edge(v, u);
	}
	for (int i = 1; i <= n; i++)
		a[i] = read();
	root = read();

	dep[1] = 1;
	dfs1(1), dfs2(1, 1);
	build(1, n);
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", id[i]);
	// puts("");
	// for (int i = hed[1]; i; i = nxt[i])
	// 	printf("%d %d\n", i, to[i]);

	for (int i = 1; i <= m; i++) {
		opt = read();
		// printf(">>> %d\n", opt);
		if (opt == 1) {
			root = read();
		} else if (opt == 2) {
			u = read(), v = read(), x = read();
			while (top[u] != top[v]) {
				if (dep[top[u]] > dep[top[v]]) swap(u, v);
				modify(id[top[v]], id[v], x);
				v = fa[top[v]];
			}
			if (dep[u] > dep[v]) swap(u, v);
			modify(id[u], id[v], x);
		} else if (opt == 3) {
			u = read(), t = lca(root, u);
			if (u == root) {
				printf("%d\n", query(1, n));
			} else if (t != u) {
				// printf("pay attention %d %d\n", id[u], id[u] + siz[u] - 1);
				printf("%d\n", query(id[u], id[u] + siz[u] - 1));
			} else {
				t = root, v = 0;
				while (top[t] != top[u]) {
					if (fa[t] == u) {
						v = t;
						break;
					} else t = fa[t];
					t = top[t];
				}
				if (!v) v = son[u];
				// printf("%d %d\n", u, v);
				printf("%d\n", min(query(1, id[v] - 1), query(id[v] + siz[v], n)));
			}
		}
	}

    return 0;
}