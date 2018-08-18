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
int n, m, u, v, opt, k;
int pos, siz[maxn], id[maxn], top[maxn], son[maxn], fa[maxn], dep[maxn], wid[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

void add_edge(int u, int v) {
	nxt[tot] = hed[u];
	to[tot] = v;
	hed[u] = tot++;
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
	id[u] = ++pos, wid[id[u]] = u, top[u] = toppoint;
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u] && to[i] != son[u])
			dfs2(to[i], to[i]);
}

struct node {
	int l, r, mid, v;
	void print(int u) {
		printf("node[%d] -> %d %d %d\n", u, l, r, v);
	}
} p[maxn << 2];

int better(int a, int b) {
	if (dep[a] < dep[b]) return a;
	else return b;
}

void build(int l, int r, int u = 1) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	p[u].v = 0;
	if (l == r) return;
	build(l, p[u].mid, u << 1);
	build(p[u].mid + 1, r, u << 1 | 1);
}

void modify(int k, int u = 1) {
	if (p[u].l == p[u].r) {
		p[u].v = p[u].v ? 0 : wid[p[u].l];
		return;
	}
	if (k <= p[u].mid) modify(k, u << 1);
	else modify(k, u << 1 | 1);
	p[u].v = better(p[u << 1].v, p[u << 1 | 1].v);
}

int query(int l, int r, int u = 1) {
	// printf("query %d %d %d\n", u, l, r);
	if (p[u].l == l && p[u].r == r)
		return p[u].v;
	if (r <= p[u].mid) return query(l, r, u << 1);
	if (l > p[u].mid) return query(l, r, u << 1 | 1);
	return better(query(l, p[u].mid, u << 1), query(p[u].mid + 1, r, u << 1 | 1));
}

void print(int a[], string s) {
	cout << s << " ";
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	puts("");
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		add_edge(u, v);
		add_edge(v, u);
	}

	dep[0] = 0x3f3f3f3f;
	dep[1] = 1;
	dfs1(1);
	dfs2(1, 1);
	build(1, n);
	// print(dep, "dep");


	for (int i = 1; i <= m; i++) {
		opt = read();
		if (opt == 0) {
			k = read();
			modify(id[k]);
			// for (int i = 1; i <= (n << 2); i++)
			// 	if (p[i].mid)
			// 		p[i].print(i);
		} else {
			u = read();
			int ans = 0;
			while (top[u] != 1) {
				ans = better(ans, query(id[top[u]], id[u]));
				u = fa[top[u]];
			}
			ans = better(ans, query(1, id[u]));
			printf("%d\n", ans ? ans : -1);
		}
	}

	return 0;
}