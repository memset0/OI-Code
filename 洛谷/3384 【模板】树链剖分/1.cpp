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
int n, m, r, u, v, x, y, z, opt, mod, w[maxn];
int pos, wt[maxn], dep[maxn], fa[maxn], siz[maxn], son[maxn], id[maxn], top[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

void print_arr(string name, int *arr, int length)  {
	if (name != "") cout << name << " ";
	for (int i = 1; i <= length; i++)
		printf("%d ", arr[i]);
	puts("");
}

struct node {
	int l, r, mid, val, lazy;
} p[maxn << 2];

void pushup(int u, int w) {
	p[u].val = (p[u].val + w * (p[u].r - p[u].l + 1)) % mod;
	p[u].lazy = (p[u].lazy + w) % mod;
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
//	printf("BUILD %d %d %d\n", u, l, r);
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	p[u].val = p[u].lazy = 0;
	if (l == r) {
		p[u].val = wt[l] % mod;
		return;
	}
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].val = (p[u << 1].val + p[u << 1 | 1].val) % mod;
}

void update(int u, int l, int r, int w) {
//	printf("UPDATE %d %d %d %d\n", u, l, r, w);
	pushdown(u);
	if (p[u].l == l && p[u].r == r) {
		pushup(u, w);
		return;
	}
	if (r <= p[u].mid) update(u << 1, l, r, w);
	else if (l > p[u].mid) update(u << 1 | 1, l, r, w);
	else update(u << 1, l, p[u].mid, w), update(u << 1 | 1, p[u].mid + 1, r, w);
	p[u].val = (p[u << 1].val + p[u << 1 | 1].val) % mod;
}

int query(int u, int l, int r) {
//	printf("QUERY %d %d %d\n", u, l, r);
	pushdown(u);
	if (p[u].l == l && p[u].r == r) {
		return p[u].val;
	}
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else return (query(u << 1, l, p[u].mid) + query(u << 1 | 1, p[u].mid + 1, r)) % mod;
}

void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
}

void dfs1(int u, int father, int depth) {
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
void dfs2(int u, int toppoint) {
	id[u] = ++pos, top[u] = toppoint, wt[id[u]] = w[u];
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u] && to[i] != son[u])
			dfs2(to[i], to[i]);
}

int queryRange(int u, int v)  {
//	printf("QUERY RANGE %d %d\n", u, v);
	int ret = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) swap(u, v);
		ret = (ret + query(1, id[top[v]], id[v])) % mod;
		v = fa[top[v]];
	}
	if (dep[u] > dep[v]) swap(u, v);
	ret = (ret + query(1, id[u], id[v])) % mod;
	return ret;
}

void updateRange(int u, int v, int w) {
//	printf("UPDATE RANGE %d %d %d\n", u, v, w);
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) swap(u, v);
		update(1, id[top[v]], id[v], w);
		v = fa[top[v]];
	}
//	printf("%d %d %d %d\n", u, v, id[u], id[v]);
	if (dep[u] > dep[v]) swap(u, v);
	update(1, id[u], id[v], w);
}

int queryTree(int u) {
	return query(1, id[u], id[u] + siz[u] - 1);
}

void updateTree(int u, int w) {
	update(1, id[u], id[u] + siz[u] - 1, w);
}

void init() {
	dfs1(r, 0, 1);
	dfs2(r, r);
	build(1, 1, n);
//	print_arr("dep", dep, n);
//	print_arr(" id",  id, n);
//	print_arr("top", top, n);
//	print_arr("siz", siz, n);
//	print_arr("son", son, n);
//	printf("  p ");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", query(1, i, i));
//	puts("");
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("data.txt", "r", stdin);
	n = read(), m = read(), r = read(), mod = read();
	for (int i = 1; i <= n; i++) w[i] = read();
	for (int i = 1; i < n; i++) u = read(), v = read(), add_edge(u, v);
	init();
	for (int i = 1; i <= m; i++) {
		opt = read();
		if (opt == 1) {
			x = read(), y = read(), z = read();
			updateRange(x, y, z);
		} else if (opt == 2) {
			x = read(), y = read();
			printf("%d\n", queryRange(x, y));
		} else if (opt == 3) {
			x = read(), z = read();
			updateTree(x, z);
		} else {
			x = read();
			printf("%d\n", queryTree(x));
		}
	}
	return 0;
}
