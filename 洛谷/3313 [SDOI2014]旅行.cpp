// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

int readc() {
	char c = getchar();
	while (c != 'Q' && c != 'C') c = getchar();
	if (c == 'C') {
		c = getchar();
		if (c == 'C') return 1;
		return 2;
	} else {
		c = getchar();
		if (c == 'S') return 3;
		return 4;
	}
}

const int maxn = 100010, maxm = maxn * 20;

int n, m, u, v, x, y, cnt, ans, opt;
int w[maxn], c[maxn];
int tot = 2, hed[maxn], to[maxn << 1], nxt[maxn << 1];
int son[maxn], siz[maxn], fa[maxn], dep[maxn], id[maxn], pos[maxn], top[maxn];
int root[maxn], lc[maxm], rc[maxm], sum[maxm], max[maxm];

void dfs1(int u) {
	siz[u] = 1;
	for (int i = hed[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v != fa[u]) {
			fa[v] = u;
			dep[v] = dep[u] + 1;
			dfs1(v);
			siz[u] += siz[v];
			if (siz[v] > siz[son[u]])
				son[u] = v;
		}
	}
}

void dfs2(int u, int toppoint) {
//	printf(">>> %d %d\n", u, toppoint);
	id[u] = ++cnt, pos[id[u]] = u;
	top[u] = toppoint;
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = hed[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v != fa[u] && v != son[u])
			dfs2(v, v);
	}
}

void update(int u) {
	sum[u] = sum[lc[u]] + sum[rc[u]];
	max[u] = std::max(max[lc[u]], max[rc[u]]);
}

void modify(int &u, int k, int v, int l = 1, int r = 100000) {
	if (!u) u = ++cnt;
//	printf("modify %d %d %d %d %d\n", u, k, v, l, r);
	if (l == r)  {
		max[u] = sum[u] = v;
		return;
	}
	int mid = (l + r) >> 1;
	if (k <= mid) modify(lc[u], k, v, l, mid);
	else modify(rc[u], k, v, mid + 1, r);
	update(u);
}

int query_sum(int u, int ql, int qr, int l = 1, int r = 100000) {
	if (!u) return 0;
//	printf("query sum %d %d %d %d %d\n", u, ql, qr, l, r);
	if (ql == l && qr == r)
		return sum[u];
	int mid = (l + r) >> 1;
	if (qr <= mid) return query_sum(lc[u], ql, qr, l, mid);
	if (ql > mid) return query_sum(rc[u], ql, qr, mid + 1, r);
	return query_sum(lc[u], ql, mid, l, mid) +
		query_sum(rc[u], mid + 1, qr, mid + 1, r);
}

int query_max(int u, int ql, int qr, int l = 1, int r = 100000) {
	if (!u) return 0;
//	printf("query max %d %d %d %d %d %d\n", u, ql, qr, l, r, max[u]);
	if (ql == l && qr == r)
		return max[u];
	int mid = (l + r) >> 1;
	if (qr <= mid) return query_max(lc[u], ql, qr, l, mid);
	if (ql > mid) return query_max(rc[u], ql, qr, mid + 1, r);
	return std::max(query_max(lc[u], ql, mid, l, mid), 
		query_max(rc[u], mid + 1, qr, mid + 1, r));
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		w[i] = read(), c[i] = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}

	dep[1] = 1;
	dfs1(1);
	dfs2(1, 1);
	for (int i = 1; i <= n; i++)
		modify(root[c[i]], id[i], w[i]);
	
	for (int i = 1; i <= m; i++) {
		opt = readc();
//		printf("> %d\n", opt);
		switch (opt) {
			case 1:
				x = read(), y = read();
				modify(root[c[x]], id[x], 0);
				c[x] = y;
				modify(root[c[x]], id[x], w[x]);
				break;
			case 2:
				x = read(), y = read();
				w[x] = y;
				modify(root[c[x]], id[x], w[x]);
				break;
			case 3:
				u = read(), v = read();
				ans = 0, x = c[u];
				while (top[u] != top[v]) {
					if (dep[top[u]] > dep[top[v]])
						std::swap(u, v);
					ans += query_sum(root[x], id[top[v]], id[v]);
					v = fa[top[v]];
				}
				if (dep[u] > dep[v])
					std::swap(u, v);
				ans += query_sum(root[x], id[u], id[v]);
				printf("%d\n", ans);
				break;
			case 4:
				u = read(), v = read();
				ans = 0, x = c[u];
				while (top[u] != top[v]) {
					if (dep[top[u]] > dep[top[v]])
						std::swap(u, v);
					ans = std::max(ans, query_max(root[x], id[top[v]], id[v]));
					v = fa[top[v]];
				}
				if (dep[u] > dep[v])
					std::swap(u, v);
				ans = std::max(ans, query_max(root[x], id[u], id[v]));
				printf("%d\n", ans);
				break;
		}
	}

	return 0;
}
