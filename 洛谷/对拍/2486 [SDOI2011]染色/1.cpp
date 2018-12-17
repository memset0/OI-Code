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
int n, m, x, y, z, u, v, opt;
int pos, siz[maxn], id[maxn], fa[maxn], son[maxn], wt[maxn], wa[maxn], dep[maxn], top[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
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
	id[u] = ++pos, top[u] = toppoint, wt[id[u]] = wa[u];
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u] && to[i] != son[u])
			dfs2(to[i], to[i]);
}

struct answer {
	int lc, rc, cnt;
	void print() {
		printf("(%d, %d, %d)\n", lc, rc, cnt);
	}
	answer(int _lc = 0, int _rc = 0, int _cnt = 0) {
		lc = _lc, rc = _rc, cnt = _cnt;
	}
	answer operator + (const answer & b) const {
		if (rc == b.lc) return answer(lc, b.rc, cnt + b.cnt - 1);
		else return answer(lc, b.rc, cnt + b.cnt);
	}
};

struct node {
	int l, r, mid, lazy;
	answer x;
} p[maxn << 2];

inline answer flip(answer a) {
	return answer(a.rc, a.lc, a.cnt);
}

inline void pushup(int u, int w) {
	p[u].x = answer(w, w, 1);
	p[u].lazy = w;
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

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1, p[u].lazy = 0;
	if (l == r) { p[u].x = answer(wt[l], wt[l], 1); return; }
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].x = p[u << 1].x + p[u << 1 | 1].x;
}

void update(int u, int l, int r, int w) {
	pushdown(u);
	// printf("UPDATE %d %d %d %d\n", u, l, r, w);
	if (p[u].l == l && p[u].r == r) { pushup(u, w); return; }
	if (r <= p[u].mid) update(u << 1, l, r, w);
	else if (l > p[u].mid) update(u << 1 | 1, l, r, w);
	else update(u << 1, l, p[u].mid, w), update(u << 1 | 1, p[u].mid + 1, r, w);
	p[u].x = p[u << 1].x + p[u << 1 | 1].x;
}

answer query(int u, int l, int r) {
	pushdown(u);
	// printf("QUERY %d %d %d\n", u, l, r);
	if (p[u].l == l && p[u].r == r) return p[u].x;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1| 1, l, r);
	else return query(u << 1, l, p[u].mid) + query(u << 1 | 1, p[u].mid + 1, r);
}

int main() {
	// freopen("data.txt", "r", stdin);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) wa[i] = read();
	for (int i = 1; i < n; i++) u = read(), v = read(), add_edge(u, v);
	dfs1(1, 0, 1), dfs2(1, 1), build(1, 1, n);
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", id[i]);
	// puts("");
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", top[i]);
	// puts("");
	for (int i = 1; i <= m; i++) {
		opt = readc();
		if (opt == 'C') {
			x = read(), y = read(), z = read();
			// printf(">>> C %d %d %d\n", x, y, z);
			while (top[x] != top[y]) {
				if (dep[top[x]] > dep[top[y]]) swap(x, y);
				update(1, id[top[y]], id[y], z);
				y = fa[top[y]];
			}
			if (dep[x] > dep[y]) swap(x, y);
			update(1, id[x], id[y], z);
			// printf("=== TREE ===\n");
			// for (int i = 1; i <= (n << 2); i++)
			// 	if (p[i].mid)
			// 		printf("%d %d %d | %d %d %d | %d\n", i, p[i].l, p[i].r, p[i].x.lc, p[i].x.rc, p[i].x.cnt, p[i].lazy);
			// printf("=== END  ===\n");
		} else {
			x = read(), y = read();
			// printf(">>> Q %d %d\n", x, y);
			answer ansx, ansy;
			while (top[x] != top[y]) {
				if (dep[top[x]] > dep[top[y]]) swap(x, y), swap(ansx, ansy);
				if (ansy.cnt) ansy = query(1, id[top[y]], id[y]) + ansy;
				else ansy = query(1, id[top[y]], id[y]);
				y = fa[top[y]];
			}
			if (dep[x] > dep[y]) swap(x, y), swap(ansx, ansy);
			if (ansy.cnt) ansy = query(1, id[x], id[y]) + ansy;
			else ansy = query(1, id[x], id[y]);
			answer ans = flip(ansx) + ansy;
			// printf(">> %d %d %d %d %d %d %d %d %d\n", ans.lc, ans.rc, ans.cnt, ansx.lc, ansx.rc, ansx.cnt, ansy.lc, ansy.rc, ansy.cnt);
			printf("%d\n", ans.cnt);
		}
	}
	return 0;
}