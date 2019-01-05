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
char readc() {
	char c = getchar();
	while (!('A' <= c && c <= 'Z')) c = getchar();
	return c;
}

const int maxn = 100010, inf = 2e9 + 10;
int n, m, u, v, w, x, y, z, opt, wa[maxn];
int pos, id[maxn], son[maxn], fa[maxn], dep[maxn], wt[maxn], top[maxn], siz[maxn];
int tot = 2, hed[maxn], to[maxn << 1], nxt[maxn << 1], val[maxn << 1];

void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
}

struct edge {
	int u, v, w;
} g[maxn];

struct node {
	int l, r, mid;
	int max, min, sum;
	int lazy;
} p[maxn << 2];

void pushup(int u) {
	p[u].lazy *= w;
	int tmp = p[u].max;
	p[u].max = -p[u].min;
	p[u].min = -tmp;
	p[u].sum = -p[u].sum;
}

void pushdown(int u) {
	if (p[u].lazy == -1) {
		if (p[u].l != p[u].r) {
			pushup(u << 1);
			pushup(u << 1 | 1);
		}
		p[u].lazy = 1;
	}
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1, p[u].lazy = 1;
	if (l == r) { p[u].max = p[u].min = p[u].sum = wt[l]; return; }
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].max = max(p[u << 1].max, p[u << 1 | 1].max);
	p[u].min = min(p[u << 1].min, p[u << 1 | 1].min);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
}

void update_num(int u, int k, int w) {
	pushdown(u);
//	printf("UPDATE NUM %d %d %d\n", u, k, w);
	if (p[u].l == p[u].r) { p[u].sum = p[u].max = p[u].min = w; return; }
	if (k <= p[u].mid) update_num(u << 1, k, w);
	else update_num(u << 1 | 1, k, w);
	p[u].max = max(p[u << 1].max, p[u << 1 | 1].max);
	p[u].min = min(p[u << 1].min, p[u << 1 | 1].min);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
}

void update(int u, int l, int r) {
	pushdown(u);
	if (l > r) return;
	if (p[u].l == l && p[u].r == r) { pushup(u); return; }
	if (r <= p[u].mid) update(u << 1, l, r);
	else if (l > p[u].mid) update(u << 1 | 1, l, r);
	else update(u << 1, l, p[u].mid), update(u << 1 | 1, p[u].mid + 1, r);
	p[u].max = max(p[u << 1].max, p[u << 1 | 1].max);
	p[u].min = min(p[u << 1].min, p[u << 1 | 1].min);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
}

int query_sum(int u, int l, int r) {
	pushdown(u);
	if (l > r) return 0;
	if (p[u].l == l && p[u].r == r) return p[u].sum;
	if (r <= p[u].mid) return query_sum(u << 1, l, r);
	else if (l > p[u].mid) return query_sum(u << 1 | 1, l, r);
	else return query_sum(u << 1, l, p[u].mid) + query_sum(u << 1 | 1, p[u].mid + 1, r);
}

int query_max(int u, int l, int r) {
	pushdown(u);
//	printf("QUERY MAX %d %d %d\n", u, l, r);
	if (l > r) return -inf;
	if (p[u].l == l && p[u].r == r) return p[u].max;
	if (r <= p[u].mid) return query_max(u << 1, l, r);
	else if (l > p[u].mid) return query_max(u << 1 | 1, l, r);
	else return max(query_max(u << 1, l, p[u].mid), query_max(u << 1 | 1, p[u].mid + 1, r));
}

int query_min(int u, int l, int r) {
	pushdown(u);
//	printf("QUERY MIN %d %d %d\n", u, l, r);
	if (l > r) return inf;
	if (p[u].l == l && p[u].r == r) return p[u].min;
	if (r <= p[u].mid) return query_min(u << 1, l, r);
	else if (l > p[u].mid) return query_min(u << 1 | 1, l, r);
	else return min(query_min(u << 1, l, p[u].mid), query_min(u << 1 | 1, p[u].mid + 1, r));
}

void dfs1(int u, int father, int depth, int value) {
//	printf(">>> %d %d\n", u, value);
	dep[u] = depth, fa[u] = father, siz[u] = 1, wa[u] = value;
	int maxson = -1;
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u]) {
			dfs1(to[i], u, dep[u] + 1, val[i]);
			siz[u] += siz[to[i]];
			if (siz[to[i]] > maxson) {
				maxson = siz[to[i]];
				son[u] = to[i];
			}
		}
}

void dfs2(int u, int toppoint) {
	id[u] = ++pos, top[u] = toppoint, wt[id[u]] = wa[u];
//	printf("%d %d %d\n", u, id[u], wa[u]);
	if (siz[u] == 1) return;
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u] && to[i] != son[i])
			dfs2(to[i], to[i]);
}

int main() {
//	freopen("data.txt", "r", stdin);
	n = read();
	for (int i = 1; i < n; i++) {
		u = read() + 1, v = read() + 1, w = read();
		add_edge(u, v, w);
		add_edge(v, u, w);
		g[i] = {u, v, w};
	}
	dfs1(1, 0, 1, 0);
	dfs2(1, 1);
	build(1, 1, n);
//	for (int i = 1; i <= (n << 2); i++)
//		if (p[i].mid)
//			printf(">>> %d %d %d %d %d %d\n", i, p[i].l, p[i].r, p[i].min, p[i].max, p[i].sum);
	for (int i = 1; i < n; i++)
		if (dep[g[i].u] > dep[g[i].v]) swap(g[i].u, g[i].v);
	m = read();
	for (int i = 1; i <= m; i++) {
		opt = readc();
		if (opt == 'C') {
			x = read(), z = read();
			update_num(1, id[g[x].v], z);
//			for (int i = 1; i <= (n << 2); i++)
//				if (p[i].mid)
//					printf(">>> %d %d %d %d %d %d\n", i, p[i].l, p[i].r, p[i].min, p[i].max, p[i].sum);
		} else if (opt == 'N') {
			x = read() + 1, y = read() + 1;
			while (top[x] != top[y]) {
				if (dep[top[x]] > dep[top[y]]) swap(x, y);
				update(1, id[top[y]], id[y]);
				y = fa[top[y]];
			}
			if (dep[x] > dep[y]) swap(x, y);
			update(1, id[x] + 1, id[y]);
//			for (int i = 1; i <= (n << 2); i++)
//				if (p[i].mid)
//					printf(">>> %d %d %d %d %d %d\n", i, p[i].l, p[i].r, p[i].min, p[i].max, p[i].sum);
		} else if (opt == 'S') {
			x = read() + 1, y = read() + 1;
			int ans = 0;
			while (top[x] != top[y]) {
				if (dep[top[x]] > dep[top[y]]) swap(x, y);
				ans += query_sum(1, id[top[y]], id[y]);
				y = fa[top[y]];
			}
			if (dep[x] > dep[y]) swap(x, y);
			ans += query_sum(1, id[x] + 1, id[y]);
			printf("%d\n", ans);
		} else {
			opt = readc();
			if (opt == 'A') {
				x = read() + 1, y = read() + 1;
				int ans = -inf;
				while (top[x] != top[y]) {
					if (dep[top[x]] > dep[top[y]]) swap(x, y);
					ans = max(ans, query_max(1, id[top[y]], id[y]));
					y = fa[top[y]];
				}
				if (dep[x] > dep[y]) swap(x, y);
				ans = max(ans, query_max(1, id[x] + 1, id[y]));
				printf("%d\n", ans);			
			} else {
				x = read() + 1, y = read() + 1;
				int ans = inf;
				while (top[x] != top[y]) {
					if (dep[top[x]] > dep[top[y]]) swap(x, y);
					ans = min(ans, query_min(1, id[top[y]], id[y]));
					y = fa[top[y]];
				}
				if (dep[x] > dep[y]) swap(x, y);
				ans = min(ans, query_min(1, id[x] + 1, id[y]));
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}