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
	while (!('a' <= c && c <= 'z')) c = getchar();
	return c;
}

const int maxn = 100010;
int n, m, pri, x, opt;
int pos, id[maxn], siz[maxn], fa[maxn], son[maxn], dep[maxn], top[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn];

void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
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
	id[u] = ++pos, top[u] = toppoint;
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u] && to[i] != son[u])
			dfs2(to[i], to[i]);
}

struct node {
	int l, r, mid, cnt, lazy;
} p[maxn << 2];

void pushup(int u, int w) {
	p[u].cnt = w * (p[u].r - p[u].l + 1);
	p[u].lazy = w;
}

void pushdown(int u) {
	if (p[u].lazy != -1) {
		// printf(">>> %d\n", p[u].lazy);
		if (p[u].l != p[u].r) {
			pushup(u << 1, p[u].lazy);
			pushup(u << 1 | 1, p[u].lazy);
		}
		p[u].lazy = -1;
	}
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1, p[u].lazy = -1, p[u].cnt = 0;
	if (l == r) return;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}

void update(int u, int l, int r, int w) {
	pushdown(u);
	if (l == p[u].l && r == p[u].r) { pushup(u, w); return; }
	if (r <= p[u].mid) update(u << 1, l, r, w);
	else if (l > p[u].mid) update(u << 1 | 1, l, r, w);
	else update(u << 1, l, p[u].mid, w), update(u << 1 | 1, p[u].mid + 1, r, w);
	p[u].cnt = p[u << 1].cnt + p[u << 1 | 1].cnt;
}

// int query(int u, int l, int r) {
// 	pushdown(u);
// 	if (l == p[u].l && r == p[u].r) return p[u].cnt;
// 	if (r <= p[u].mid) return query(u << 1, l, r);
// 	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
// 	else return query(u << 1, l, p[u].mid) + query(u << 1 | 1, p[u].mid + 1, r);
// }

int main() {
	// freopen("INPUT", "r", stdin);
	n = read();
	for (int i = 2; i <= n; i++)
		add_edge(i, read() + 1);
	dfs1(1, 0, 1);
	dfs2(1, 1);
	build(1, 1, n);
	m = read();
	for (int i = 1; i <= m; i++) {
		opt = readc(), x = read() + 1;
		if (opt == 'i') {
			// printf("INSTALL >> %d\n", x);
			pri = p[1].cnt;
			while (x) {
				update(1, id[top[x]], id[x], 1);
				x = fa[top[x]];
			}
			// printf("%d %d\n", pri, p[1].cnt);
			printf("%d\n", p[1].cnt - pri);
		} else {
			pri = p[1].cnt;
			update(1, id[x], id[x] + siz[x] - 1, 0);
			printf("%d\n", pri - p[1].cnt);
		}
	}
	return 0;
}