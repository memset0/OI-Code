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

const int maxn = 100010, maxm = 200010;
int n, m, u, v, t, x, ans, opt;
int pos, siz[maxn], son[maxn], fa[maxn], dep[maxn], top[maxn], id[maxn];
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
	id[u] = ++pos, top[u] = toppoint;
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u] && to[i] != son[u])
			dfs2(to[i], to[i]);
}

struct heap {
	priority_queue < int > ins, del;
	void push(int x, int opt) {
		if (opt) del.push(x);
		else ins.push(x);
	}
	int top() {
		while (!ins.empty() && !del.empty() && ins.top() == del.top())
			ins.pop(), del.pop();
		if (ins.empty()) return -1;
		return ins.top();
	}
};

struct node {
	int l, r, mid;
	heap q;
} p[maxn << 2];

void build(int l, int r, int u = 1) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) return;
	build(l, p[u].mid, u << 1);
	build(p[u].mid + 1, r, u << 1 | 1);
}

void modify(int l, int r, int x, int opt, int u = 1) {
	// printf("modify %d %d %d %d %d\n", u, l, r, x, opt);
	if (l > r) return;
	if (p[u].l == l && p[u].r == r) {
		p[u].q.push(x, opt);
		return;
	}
	if (r <= p[u].mid) modify(l, r, x, opt, u << 1);
	else if (l > p[u].mid) modify(l, r, x, opt, u << 1 | 1);
	else modify(l, p[u].mid, x, opt, u << 1), modify(p[u].mid + 1, r, x, opt, u << 1 | 1);
}

int query(int k, int u = 1) {
	// printf("query %d %d\n", k, u);
	if (p[u].l == p[u].r) return p[u].q.top();
	if (k <= p[u].mid) return max(p[u].q.top(), query(k, u << 1));
	else return max(p[u].q.top(), query(k, u << 1 | 1));
}

struct history {
	int u, v, x;
} h[maxm];

struct link {
	int l, r;
	bool operator < (const link &b) const {
		return l < b.l;
	}
	void set(int a, int b) {
		l = a, r = b;
	}
} l[maxn];
int lenl;

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		add_edge(u, v);
		add_edge(v, u);
	}

	dep[1] = 1;
	dfs1(1);
	dfs2(1, 1);
	build(1, n);
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", id[i]);
	// puts("");
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", dep[i]);
	// puts("");
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", top[i]);
	// puts("");

	for (int i = 1; i <= m; i++) {
		opt = read();
		// printf(">>> %d\n", opt);
		if (opt == 0) {
			u = read(), v = read(), x = read();
			h[i].u = u, h[i].v = v, h[i].x = x;
			lenl = 0;
			while (top[u] != top[v]) {
				if (dep[top[u]] > dep[top[v]]) swap(u, v);
				l[++lenl].set(id[top[v]], id[v]);
				v = fa[top[v]];
			}
			if (dep[u] > dep[v]) swap(u, v);
			l[++lenl].set(id[u], id[v]);
			l[++lenl].set(0, 0);
			l[++lenl].set(n + 1, n + 1);
			sort(l + 1, l + lenl + 1);
			// for (int i = 1; i <= lenl; i++)
			// 	printf("]]] %d %d\n", l[i].l, l[i].r);
			for (int i = 2; i <= lenl; i++)
				modify(l[i - 1].r + 1, l[i].l - 1, x, 0);
		} else if (opt == 1) {
			t = read(), ans = -1;
			u = h[t].u, v = h[t].v, x = h[t].x;
			lenl = 0;
			while (top[u] != top[v]) {
				if (dep[top[u]] > dep[top[v]]) swap(u, v);
				l[++lenl].set(id[top[v]], id[v]);
				v = fa[top[v]];
			}
			if (dep[u] > dep[v]) swap(u, v);
			l[++lenl].set(id[u], id[v]);
			l[++lenl].set(0, 0);
			l[++lenl].set(n + 1, n + 1);
			sort(l + 1, l + lenl + 1);
			for (int i = 2; i <= lenl; i++)
				modify(l[i - 1].r + 1, l[i].l - 1, x, 1);
		} else if (opt == 2) {
			x = read();
			printf("%d\n", query(id[x]));
		}
	}

	return 0;
}