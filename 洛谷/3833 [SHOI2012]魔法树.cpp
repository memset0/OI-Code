#include <bits/stdc++.h>
#define int long long
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}

template < class T >
inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
	print(x), putchar(c);
}

const int N = 1e5 + 10;
int n, m, u, v, w, op, pos;
int siz[N], top[N], dep[N], fa[N], son[N], id[N], wid[N];
int tot = 2, hed[N], nxt[N], to[N];

struct node {
	int l, r, mid;
	int sum, tag;
} p[N << 2];

void dfs1(int u) {
	siz[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
		fa[v] = u, dep[v] = dep[u] + 1, dfs1(v), siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}

void dfs2(int u, int tp) {
	top[u] = tp, id[u] = ++pos, wid[id[u]] = u;
	if (siz[u] == 1) return;
	dfs2(son[u], tp);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != son[u]) dfs2(v, v);
}

inline void pushup(int u, int x) {
	p[u].tag += x, p[u].sum += (p[u].r - p[u].l + 1) * x;
}	

inline void pushdown(int u) {
	if (p[u].l == p[u].r || !p[u].tag) return;
	pushup(u << 1, p[u].tag);
	pushup(u << 1 | 1, p[u].tag);
	p[u].tag = 0;
}

void build(int u, int l, int r) {
	// printf("build %d %d %d\n", u, l, r);
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) return;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}

void modify(int u, int l, int r, int x) {
	pushdown(u);
	// printf("modify %d %d %d %d\n", u, l, r, x);
	if (p[u].l == l && p[u].r == r) { pushup(u, x); return; }
	if (r <= p[u].mid) modify(u << 1, l, r, x);
	else if (l > p[u].mid) modify(u << 1 | 1, l, r, x);
	else modify(u << 1, l, p[u].mid, x), modify(u << 1 | 1, p[u].mid + 1, r, x);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
}

int query(int u, int l, int r) {
	pushdown(u);
	// printf("query %d %d %d\n", u, l, r);
	if (p[u].l == l && p[u].r == r) return p[u].sum;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else return query(u << 1, l, p[u].mid) + query(u << 1 | 1, p[u].mid + 1, r);
}

void main() {
	read(n);
	for (int i = 1; i < n; i++) {
		read(u), read(v), ++u, ++v;
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	}
	dfs1(1), dfs2(1, 1), build(1, 1, n);
	read(m);
	for (int i = 1; i <= m; i++) {
		while (op = getchar(), op != 'A' && op != 'Q');
		if (op == 'A') {
			read(u), read(v), read(w), ++u, ++v;
			while (top[u] != top[v]) {
				if (dep[top[u]] > dep[top[v]]) std::swap(u, v);
				modify(1, id[top[v]], id[v], w);
				v = fa[top[v]];
			}
			if (dep[u] > dep[v]) std::swap(u, v);
			modify(1, id[u], id[v], w);
		} else {
			read(u), ++u;
			print(query(1, id[u], id[u] + siz[u] - 1), '\n');
		}
	}
}

} signed main() { return ringo::main(), 0; }