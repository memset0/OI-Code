// luogu-judger-enable-o2
// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void readc(T &x) {
	while (x = getc(), !islower(x) && !isupper(x));
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 300010;
int n, m, u, v, k, opt, cnt, pos;
int id[maxn], wid[maxn], son[maxn], dep[maxn], fa[maxn], siz[maxn], top[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

struct war {
	int u, v;
} w[maxn];

void dfs1(int u) {
	// printf("dfs1 %d\n", u);
	siz[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ fa[u]) {
			fa[v] = u;
			dep[v] = dep[u] + 1;
			dfs1(v);
			siz[u] += siz[v];
			if (siz[v] > siz[son[u]])
				son[u] = v;
		}
}

void dfs2(int u, int toppoint) {
	// printf("dfs2 %d %d\n", u, toppoint);
	top[u] = toppoint, id[u] = ++pos, wid[id[u]] = u;
	if (siz[u] == 1) return;
	dfs2(son[u], top[u]);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ fa[u] && v ^ son[u])
			dfs2(v, v);
}

struct node {
	int l, r, mid;
	int flag, tag;
} p[maxn << 2];

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) return;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}

void modify(int u, int k, int v) {
	if (p[u].l == p[u].r)
		return (void)(p[u].tag = v);
	modify(u << 1 | (k <= p[u].mid ? 0 : 1), k, v);
	p[u].tag = p[u << 1].tag | p[u << 1 | 1].tag;
}

bool query(int u, int l, int r) {
	// printf("query %d %d %d\n", u, l, r);
	if (p[u].l == l && p[u].r == r)
		return p[u].tag;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else return query(u << 1, l, p[u].mid) |
		query(u << 1 | 1, p[u].mid + 1, r);
}

int lca(int u, int v) {
	while (top[u] ^ top[v]) {
		if (dep[top[u]] > dep[top[v]])
			std::swap(u, v);
		v = fa[top[v]];
	}
	return dep[u] < dep[v] ? u : v;
}

bool jump(int u, int v) {
	while (top[u] ^ top[v]) {
		if (query(1, id[top[u]], id[u]))
			return true;
		u = fa[top[u]];
	}
	if (u == v)
		return false;
	if (query(1, id[v] + 1, id[u]))
		return true;
	return false;
}

bool query(int u, int v) {
	int t = lca(u, v);
	// printf("lca(%d %d) = %d\n", u, v, t);
	if (jump(u, t))
		return true;
	if (jump(v, t))
		return true;
	return false;
}

int main() {
	// freopen("1.in", "r", stdin);
	read(n), read(m);
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
	dfs1(1), dfs2(1, 1);
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		readc(opt);
		// printf(">>> %d %c\n", i, opt);
		if (opt == 'Q') {
			read(u), read(v);
			puts(query(u, v) ? "No" : "Yes");
		} else if (opt == 'C') {
			read(u), read(v);
			if (dep[u] > dep[v])
				std::swap(u, v);
			w[++cnt] = war{u, v};
			modify(1, id[v], 1);
		} else {
			read(k), u = w[k].u, v = w[k].v;
			modify(1, id[v], 0);
		}
	}
	return 0;
}
