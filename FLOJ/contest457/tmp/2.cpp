#include <bits/stdc++.h>
// #pragma comment(linker, "/STACK:102400000,102400000")
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

const int maxn = 3e5 + 10;
int n, m, l, r, u, v, ur, ans, pos;
bool tag[maxn];

typedef int arr[maxn];
arr fa, top, siz, dep, id, wid, son, final_ans;
std::vector < int > G[maxn];


struct query { int l, r, i; } q[maxn];
bool cmp(const query &a, const query &b) { return a.l == b.l ? a.r < b.r : a.l < b.l; }

struct node { int l, r, mid, rit; bool tag; } p[maxn << 2];

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) return;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}

void clear(int u) {
	p[u].rit = p[u].tag = 0;
	if (p[u].l == l && p[u].r == r) return;
	clear(u << 1), clear(u << 1 | 1);
}

void modify(int u, int l, int r) {
//	printf("modify %d %d %d : %d %d %d %d\n", u, l, r, p[u].l, p[u].r, p[u].rit, p[u].tag);
	if (p[u].tag) return;
	if (p[u].l == l && p[u].r == r) { p[u].tag = 1, p[u].rit = p[u].r; return; }
	if (r <= p[u].mid) modify(u << 1, l, r);
	else if (l > p[u].mid) modify(u << 1 | 1, l, r);
	else modify(u << 1, l, p[u].mid), modify(u << 1 | 1, p[u].mid + 1, r);
	p[u].rit = std::max(p[u << 1].rit, p[u << 1 | 1].rit);
}

int query(int u, int l, int r) {
	if (p[u].tag) return r;
	if (p[u].l == l && p[u].r == r) return p[u].rit;
	if (r <= p[u].mid) return query(u << 1, l, r);
	if (l > p[u].mid) return query(u << 1 | 1, l, r);
	return std::max(query(u << 1, l, p[u].mid), query(u << 1 | 1, p[u].mid + 1, r));
}

void dfs1(int u) {
	siz[u] = 1;
	for (auto v : G[u]) if (v != fa[u]) {
		fa[v] = u, dep[v] = dep[u] + 1, dfs1(v), siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}

void dfs2(int u, int toppoint) {
	top[u] = toppoint, id[u] = ++pos, wid[id[u]] = u;
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (auto v : G[u]) if (v != fa[u] && v != son[u])
		dfs2(v, v);
}

int lca(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) std::swap(u, v);
		v = fa[top[v]];
	}
	if (dep[u] > dep[v]) std::swap(u, v);
	return u;
}

void insert(int u) {
//	printf("--- %d ---\n", u);
	int bak = u, lca = 0;
	while (top[u]) {
//		printf("> %d : %d %d\n", u, id[top[u]], id[u]);
		lca = wid[query(1, id[top[u]], id[u])];
		if (lca) break;
		u = fa[top[u]];
	}
	u = bak;
//	printf(">>> %d : %d\n", u, lca);
	while (top[u] != top[lca]) modify(1, id[top[u]], id[u]), u = fa[top[u]];
	if (lca != u) modify(1, id[lca] + 1, id[u]);
	u = bak;
	ans += (tag[u] ^ 1), tag[u] = 1;
	if (lca) ans += tag[lca] ^ 1, tag[lca] = 1;
}

void main() {
	read(n), read(m);
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1), dfs2(1, 1), build(1, 1, n);
	for (int i = 1; i <= m; i++) read(q[i].l), read(q[i].r), q[i].i = i;
	std::sort(q + 1, q + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
//		printf("=== %d %d %d ===\n", q[i].i, q[i].l, q[i].r);
		if (q[i].l != q[i - 1].l) ans = 0, ur = q[i].l - 1, clear(1), memset(tag, 0, sizeof(tag));
		while (ur < q[i].r) insert(++ur);
		final_ans[q[i].i] = ans;
//		printf(">>>>> %d\n", ans);
	}
	for (int i = 1; i <= m; i++) print(final_ans[i]), putc('\n');
}

} int main() { return ringo::main(), 0; }
