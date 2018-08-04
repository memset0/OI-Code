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

const int maxn = 100010;
int n, m, u, v, x, y, opt;
int pos, id[maxn], fa[maxn], son[maxn], top[maxn], siz[maxn], dep[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

void add_edge(int u, int v) {
	nxt[tot] = hed[u];
	to[tot] = v;
	hed[u] = tot++;
}

void dfs1(int u, int father, int depth) {
	dep[u] = depth, fa[u] = father, siz[u] = 1;
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
	id[u] = ++pos, top[u] = toppoint;
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u] && to[i] != son[u])
			dfs2(to[i], to[i]);
}

struct node {
	int l, r, mid, sum, lazy;
} p[maxn << 2];

void pushup(int u, int w) {
	p[u].sum += w * (p[u].r - p[u].l + 1);
	p[u].lazy += w;
}

void pushdown(int u) {
	if (p[u].lazy) {
		if (p[u].l != p[u].r) {
			pushup(u << 1, p[u].lazy);
			pushup(u << 1 | 1, p[u].lazy);
		}
		p[u].lazy = 0;
	}
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) return;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}

void update(int u, int l, int r) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) { pushup(u, 1); return; }
	if (r <= p[u].mid) update(u << 1, l, r);
	else if (l > p[u].mid) update(u << 1 | 1, l, r);
	else update(u << 1, l, p[u].mid), update(u << 1 | 1, p[u].mid + 1, r);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
}

int query(int u, int l, int r) {
	pushdown(u);
	// printf("QUERY %d %d %d\n", u, l, r);
	if (p[u].l == l && p[u].r == r) return p[u].sum;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else return query(u << 1, l, p[u].mid) + query(u << 1 | 1, p[u].mid + 1, r);
}

int main() {
	n = read(), m = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		add_edge(u, v);
		add_edge(v, u);
	}
	dfs1(1, 0, 1);
	dfs2(1, 1);
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		opt = readc();
		if (opt == 'P') {
			x = read(), y = read();
			while (top[x] != top[y]) {
				if (dep[top[x]] > dep[top[y]]) swap(x, y);
				update(1, id[top[y]], id[y]);
				y = fa[top[y]];
			}
			if (dep[x] > dep[y]) swap(x, y);
			if (id[x] + 1 <= id[y]) update(1, id[x] + 1, id[y]);
		} else {
			x = read(), y = read();
			int ans = 0;
			while (top[x] != top[y]) {
				if (dep[top[x]] > dep[top[y]]) swap(x, y);
				ans += query(1, id[top[y]], id[y]);
				y = fa[top[y]];
			}
			if (dep[x] > dep[y]) swap(x, y);
			if (id[x] + 1 <= id[y]) ans += query(1, id[x] + 1, id[y]);
			printf("%d\n", ans);
		}
	}
	return 0;
}