// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long

inline int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 100010;

int n, m, u, v, t, pos, opt, sum;
int dep[maxn], siz[maxn], fa[maxn], id[maxn], wid[maxn], son[maxn], top[maxn];

int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];
inline void add_edge(int u, int v) { nxt[tot] = hed[u], to[tot] = v; hed[u] = tot++; }

void dfs1(int u) {
	siz[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u]) {
			fa[v] = u, dep[v] = dep[u] + 1, dfs1(v), siz[u] += siz[v];
			if (siz[v] > siz[son[u]]) son[u] = v;
		}
}

void dfs2(int u, int toppoint) {
	id[u] = ++pos, wid[id[u]] = u, top[u] = toppoint;
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u] && v != son[u])
			dfs2(v, v);
}

struct seg_node {
	int l, r, mid;
	int max, sum, tag;
	bool flag;
} p[maxn << 2];

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) { p[u].sum = p[u].max = dep[wid[l]] - 1; return; }
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
	p[u].max = std::max(p[u << 1].max, p[u << 1 | 1].max);
}

inline void pushup_sum(int u, int x) {
	p[u].tag += x;
	p[u].max += x;
	p[u].sum += x * (p[u].r - p[u].l + 1);
}
inline void pushup_to_zero(int u) {
	p[u].tag = p[u].sum = p[u].max = 0;
	p[u].flag = 1;
}

inline void pushdown(int u) {
	if (p[u].l == p[u].r) return;
	if (p[u].flag) {
		pushup_to_zero(u << 1);
		pushup_to_zero(u << 1 | 1);
	}
	if (p[u].tag) {
		pushup_sum(u << 1, p[u].tag);
		pushup_sum(u << 1 | 1, p[u].tag);
	}
}

void modify_sum(int u, int l, int r, int x) {
	if (l > r) return; pushdown(u);
//	printf("modify sum %d %d %d %d\n", u, l, r, x);
	if (p[u].l == l && p[u].r == r) { pushup_sum(u, x); return; }
	if (r <= p[u].mid) modify_sum(u << 1, l, r, x);
	else if (l > p[u].mid) modify_sum(u << 1 | 1, l, r, x);
	else modify_sum(u << 1, l, p[u].mid, x), modify_sum(u << 1 | 1, p[u].mid + 1, r, x);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
	p[u].max = std::max(p[u << 1].max, p[u << 1 | 1].max);
}

void modify_to_zero(int u, int l, int r) {
	if (l > r) return; pushdown(u);
//	printf("modify to zero %d %d %d\n", u, l, r);
	if (p[u].l == l && p[u].r == r) { pushup_to_zero(u); return; }
	if (r <= p[u].mid) modify_to_zero(u << 1, l, r);
	else if (l > p[u].mid) modify_to_zero(u << 1 | 1, l, r);
	else modify_to_zero(u << 1, l, p[u].mid), modify_to_zero(u << 1 | 1, p[u].mid + 1, r);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
	p[u].max = std::max(p[u << 1].max, p[u << 1 | 1].max);
}

int query_sum(int u, int l, int r) {
	if (l > r) return 0; pushdown(u);
	if (p[u].l == l && p[u].r == r) return p[u].sum;
	if (r <= p[u].mid) return query_sum(u << 1, l, r);
	else if (l > p[u].mid) return query_sum(u << 1 | 1, l, r);
	else return query_sum(u << 1, l, p[u].mid) + query_sum(u << 1 | 1, p[u].mid + 1, r);
}

int query_max(int u, int l, int r) {
	if (l > r) return -1; pushdown(u);
	if (p[u].l == l && p[u].r == r) return p[u].max;
	if (r <= p[u].mid) return query_max(u << 1, l, r);
	else if (l > p[u].mid) return query_max(u << 1 | 1, l, r);
	else return std::max(query_max(u << 1, l, p[u].mid), query_max(u << 1 | 1, p[u].mid + 1, r));
}

int lca(int u, int v) {
	while (top[u] ^ top[v]) {
		if (dep[top[u]] > dep[top[v]]) std::swap(u, v);
		v = fa[top[v]];
	}
	if (dep[u] > dep[v]) std::swap(u, v);
	return u;
}

int main() {

	n = read(), m = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		add_edge(u, v);
		add_edge(v, u);
	}
	
	dep[1] = 1;
	dfs1(1);
	dfs2(1, 1);
	build(1, 1, n);
	
//	for (int i = 1; i <= n; i++)
//		printf("%d ", id[i]);
//	puts("");
	
	for (int i = 1; i <= m; i++) {
		opt = read();
//		printf(">> %d\n", opt);
		if (opt == 1) {
//			for (int i = 1; i <= n; i++)
//				printf("%d ", query_sum(1, id[i], id[i]));
//			puts("");
			t = u = read(), sum = 0;
			while (top[u] ^ 1) {
				sum += query_sum(1, id[top[u]], id[u]);
				modify_to_zero(1, id[top[u]], id[u]);
				u = fa[top[u]];
			}
			sum += query_sum(1, 1, id[u]);
			modify_to_zero(1, 1, id[u]);
			modify_sum(1, id[t] + 1, id[t] + siz[t] - 1, 1 - sum);
//			for (int i = 1; i <= n; i++)
//				printf("%d ", query_sum(1, id[i], id[i]));
//			puts("");
		} else if (opt == 2) {
			u = read(), v = read(), t = lca(u, v);
			printf("%d\n", query_sum(1, id[u], id[u]) + query_sum(1, id[v], id[v])
					- (query_sum(1, id[t], id[t]) << 1) + 1);
		} else {
			u = read();
			printf("%d\n", query_max(1, id[u], id[u] + siz[u] - 1) + 1);
		}
	}
	
	return 0;
}

