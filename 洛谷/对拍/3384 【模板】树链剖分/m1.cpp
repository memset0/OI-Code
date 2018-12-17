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
int n, m, r, mod, opt, u, v, x, y, z, w[maxn];
int pos, id[maxn], dep[maxn], top[maxn], siz[maxn], wt[maxn], fa[maxn], son[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

inline void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
}

struct node {
	int l, r, mid, val, lazy;
} p[maxn << 2];
inline void pushup(int u, int w) {
	p[u].val = (p[u].val + w * (p[u].r - p[u].l + 1)) % mod;
	p[u].lazy = (p[u].lazy + w) % mod;
}
inline void pushdown(int u) {
	if (p[u].lazy) {
		if (p[u].l != p[u].r) {
			pushup(u << 1, p[u].lazy);
			pushup(u << 1 | 1, p[u].lazy);
		}
		p[u].lazy = 0;
	}
}
inline void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) {
		p[u].val = wt[l] % mod;
		return;
	}
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].val = (p[u << 1].val + p[u << 1 | 1].val) % mod;
}
inline void update(int u, int l, int r, int w) {
	pushdown(u);
	if (l == p[u].l && r == p[u].r) {
		pushup(u, w);
		return;
	}
	if (r <= p[u].mid) update(u << 1, l, r, w);
	else if (l > p[u].mid) update(u << 1 | 1, l, r, w);
	else update(u << 1, l, p[u].mid, w), update(u << 1 | 1, p[u].mid + 1, r, w);
	p[u].val = (p[u << 1].val + p[u << 1 | 1].val) % mod;
}
inline int query(int u, int l, int r) {
	pushdown(u);
	if (l == p[u].l && r == p[u].r) return p[u].val;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else return (query(u << 1, l, p[u].mid) + query(u << 1 | 1, p[u].mid + 1, r)) % mod;
}

inline void dfs1(int u, int father, int depth) {
	dep[u] = depth, fa[u] = father, siz[u] = 1;
	int maxsiz = -1;
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != father) {
			dfs1(to[i], u, depth + 1);
			siz[u] += siz[to[i]];
			if (siz[to[i]] > maxsiz) {
				maxsiz = siz[to[i]];
				son[u] = to[i];
			}
		}
}
inline void dfs2(int u, int toppoint) {
	id[u] = ++pos, top[u] = toppoint, wt[id[u]] = w[u];
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u] && to[i] != son[u])
			dfs2(to[i], to[i]);
}

inline void init() {
	dfs1(r, 0, 1);
	dfs2(r, r);
	build(1, 1, n);
//	for (int i = 1; i <= n; i++)
//		printf("%d ", id[i]);
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", siz[i]);
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", top[i]);
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", query(1, id[i], id[i]));
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", query(1, id[i], id[i] + siz[i] - 1));
//	puts("");
}

int main() {
//	freopen("data.txt", "r", stdin);
	n = read(), m = read(), r = read(), mod = read();
	for (int i = 1; i <= n; i++)
		w[i] = read();
	for (int i = 1; i < n; i++)
		u = read(), v = read(), add_edge(u, v);
	init();
	for (int i = 1; i <= m; i++) {
		opt = read();
		if (opt == 1) {
			x = read(), y = read(), z = read();
			while (top[x] != top[y]) {
				if (dep[top[x]] > dep[top[y]]) swap(x, y);
				update(1, id[top[y]], id[y], z);
				y = fa[top[y]];
			}
			if (dep[x] > dep[y]) swap(x, y);
			update(1, id[x], id[y], z);
		} else if (opt == 2) {
			x = read(), y = read();
			int ans = 0;
			while (top[x] != top[y]) {
				if (dep[top[x]] > dep[top[y]]) swap(x, y);
				ans = (query(1, id[top[y]], id[y]) + ans) % mod;
				y = fa[top[y]];
			}
			if (dep[x] > dep[y]) swap(x, y);
			ans = (query(1, id[x], id[y]) + ans) % mod;
			printf("%d\n", ans);
		} else if (opt == 3) {
			x = read(), z = read();
			update(1, id[x], id[x] + siz[x] - 1, z);
		} else {
			x = read();
			printf("%d\n", query(1, id[x], id[x] + siz[x] - 1) % mod);
		}
	}
	return 0;
}

