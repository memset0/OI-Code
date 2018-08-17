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

const int maxn = 100010;
int n, m, u, v, x, opt, root, a[maxn];
int pos, wa[maxn], siz[maxn], fa[maxn], dep[maxn], son[maxn], id[maxn], top[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];
ll ans;

void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
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
	id[u] = ++pos, top[u] = toppoint, wa[id[u]] = a[u];
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u] && to[i] != son[u])
			dfs2(to[i], to[i]);
}

struct node {
	int l, r, mid;
	ll sum, lazy;
} p[maxn << 2];

void pushup(int u, int x) {
	p[u].sum += x * (p[u].r - p[u].l + 1);
	p[u].lazy += x;
}

void pushdown(int u) {
	if (p[u].lazy) {
		if (p[u].l != p[u].r) {
			pushup(u << 1    , p[u].lazy);
			pushup(u << 1 | 1, p[u].lazy);
		}
		p[u].lazy = 0;
	}
}

void build(int l, int r, int u = 1) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	p[u].sum = p[u].lazy = 0;
	if (l == r) {
		p[u].sum = wa[l];
		return;
	}
	build(l, p[u].mid, u << 1);
	build(p[u].mid + 1, r, u << 1 | 1);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
}

void modify(int l, int r, int x, int u = 1) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) {
		pushup(u, x);
		return;
	}
	if (r <= p[u].mid) modify(l, r, x, u << 1);
	else if (l > p[u].mid) modify(l, r, x, u << 1 | 1);
	else modify(l, p[u].mid, x, u << 1), modify(p[u].mid + 1, r, x, u << 1 | 1);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
}

ll query(int l, int r, int u = 1) {
	pushdown(u);
	// printf("query %d %d\n", l, r);
	if (p[u].l == l && p[u].r == r) {
		return p[u].sum;
	}
	if (r <= p[u].mid) return query(l, r, u << 1);
	else if (l > p[u].mid) return query(l, r, u << 1 | 1);
	else return query(l, p[u].mid, u << 1) + query(p[u].mid + 1, r, u << 1 | 1);
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
	
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 2; i <= n; i++)
		add_edge(i, read());

	dep[1] = root = 1;
	dfs1(1), dfs2(1, 1);
	build(1, n);
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", id[i]);
	// puts("");
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", top[i]);
	// puts("");

	m = read();
	while (m--) {
		opt = read();
		// printf(">>> opt = %d\n", opt);
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
			u = read(), x = read();
			int t = lca(root, u);
			if (u == root) {
				modify(1, n, x);
			} else if (t != u) {
				modify(id[u], id[u] + siz[u] - 1, x);
			} else {
				int v = root;
				while (dep[v] > dep[u]) {
					if (fa[top[v]] == u) {
						v = top[v];
						break;
					}
					v = fa[top[v]];
				}
				if (dep[v] <= dep[u])
					v = son[u];
				// printf("%d %d\n", u, v);
				modify(1, n, x);
				modify(id[v], id[v] + siz[v] - 1, -x);
			}
		} else if (opt == 4) {
			u = read(), v = read(), ans = 0;
			while (top[u] != top[v]) {
				if (dep[top[u]] > dep[top[v]]) swap(u, v);
				ans += query(id[top[v]], id[v]);
				v = fa[top[v]];
			}
			if (dep[u] > dep[v]) swap(u, v);
			// printf(">>> %d %d %d\n", u, v, ans);
			ans += query(id[u], id[v]);
			printf("%lld\n", ans);
		} else if (opt == 5) {
			u = read(), ans = 0;
			int t = lca(root, u);
			if (u == root) {
				ans += query(1, n);
			} else if (t != u) {
				ans += query(id[u], id[u] + siz[u] - 1);
			} else {
				int v = root;
				while (dep[v] > dep[u]) {
					if (fa[top[v]] == u) {
						v = top[v];
						break;
					}
					v = fa[top[v]];
				}
				if (dep[v] <= dep[u])
					v = son[u];
				ans += query(1, n);
				ans -= query(id[v], id[v] + siz[v] - 1);
			}
			printf("%lld\n", ans);
		}
	}
	
	return 0;
}