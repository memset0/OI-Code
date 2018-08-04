#include <bits/stdc++.h>
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

char readc() {
	char c = getchar();
	while (!('A' <= c && c <= 'Z')) c = getchar();
	return c;
}

const int maxn = 30010, inf = 2e9 + 10;
int n, m, x, y, z, u, v, opt, w[maxn];
int pos, id[maxn], fa[maxn], top[maxn], siz[maxn], son[maxn], wt[maxn], dep[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

void add_edge(int u, int v) {
	nxt[tot] = hed[u];
	to[tot] = v;
	hed[u] = tot++;
}

void dfs1(int u, int father, int depth) {
	fa[u] = father, dep[u] = depth, siz[u] = 1;
	int maxson = -1;
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u]) {
			dfs1(to[i], u, dep[u] + 1);
			siz[u] += siz[to[i]];
			if (siz[to[i]] > maxson) {
				maxson = siz[to[i]];
				son[u] = to[i];
			}
		}
}

void dfs2(int u, int toppoint) {
	id[u] = ++pos, top[u] = toppoint, wt[id[u]] = w[u];
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u] && to[i] != son[u])
			dfs2(to[i], to[i]);
}

struct node {
	int l, r, mid, max, sum;
} p[maxn << 2];

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) { p[u].max = p[u].sum = wt[l]; return; }
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].max = max(p[u << 1].max, p[u << 1 | 1].max);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
}

void update(int u, int k, int w) {
	if (p[u].l == p[u].r) { p[u].sum = p[u].max = w; return; }
	if (k <= p[u].mid) update(u << 1, k, w);
	else update(u << 1 | 1, k, w);
	p[u].max = max(p[u << 1].max, p[u << 1 | 1].max);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
}

int query_max(int u, int l, int r) {
	// printf("QUERY MAX %d %d %d\n", u, l, r);
	if (l == p[u].l && r == p[u].r) return p[u].max;
	if (r <= p[u].mid) return query_max(u << 1, l, r);
	else if (l > p[u].mid) return query_max(u << 1 | 1, l, r);
	else return max(query_max(u << 1, l, p[u].mid), query_max(u << 1 | 1, p[u].mid + 1, r));
}

int query_sum(int u, int l, int r) {
	if (l == p[u].l && r == p[u].r) return p[u].sum;
	if (r <= p[u].mid) return query_sum(u << 1, l, r);
	else if (l > p[u].mid) return query_sum(u << 1 | 1, l, r);
	else return query_sum(u << 1, l, p[u].mid) + query_sum(u << 1 | 1, p[u].mid + 1, r);
}

int main() {
	n = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		add_edge(u, v);
		add_edge(v, u);
	}
	for (int i = 1; i <= n; i++)
		w[i] = read();
	dfs1(1, 0, 1);
	dfs2(1, 1);
	build(1, 1, n);
	// for (int i = 1; i <= (n << 2); i++)
	// 	if (p[i].mid)
	// 		printf("%d %d %d %d %d\n", i, p[i].l, p[i].r, p[i].max, p[i].sum);
	m = read();
	for (int i = 1; i <= m; i++) {
		opt = readc();
		if (opt == 'C') {
			x = read(), z = read();
			update(1, id[x], z);
		} else {
			opt = readc();
			if (opt == 'M') {
				x = read(), y = read();
				int ans = -inf;
				while (top[x] != top[y]) {
					if (dep[top[x]] > dep[top[y]]) swap(x, y);
					ans = max(ans, query_max(1, id[top[y]], id[y]));
					y = fa[top[y]];
				}
				if (dep[x] > dep[y]) swap(x, y);
				ans = max(ans, query_max(1, id[x], id[y]));
				printf("%d\n", ans);
			} else {
				x = read(), y = read();
				int ans = 0;
				while (top[x] != top[y]) {
					if (dep[top[x]] > dep[top[y]]) swap(x, y);
					ans += query_sum(1, id[top[y]], id[y]);
					y = fa[top[y]];
				}
				if (dep[x] > dep[y]) swap(x, y);
				ans += query_sum(1, id[x], id[y]);
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}