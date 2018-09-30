// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)
#define endl ('\n')

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

const int maxn = 100010, inf = 2e9;

int n, m, u, x, rt, opt, pos, tmp, a[maxn];
int dep[maxn], fa[maxn], siz[maxn], top[maxn], id[maxn], wid[maxn], son[maxn];

int tot = 2, hed[maxn], to[maxn << 1], nxt[maxn << 1];

inline void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
}

void dfs(int u) {
	siz[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ fa[u]) {
			fa[v] = u;
			dep[v] = dep[u] + 1;
			dfs(v);
			siz[u] += siz[v];
			if (siz[v] > siz[son[u]])
				son[u] = v;
		}
}

void dfs(int u, int toppoint) {
	top[u] = toppoint, id[u] = ++pos, wid[id[u]] = u;
	if (siz[u] == 1)
		return;
	dfs(son[u], toppoint);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ fa[u] && v ^ son[u])
			dfs(v, v);
}

int lca(int u, int v) {
	while (top[u] ^ top[v]) {
		if (dep[top[u]] > dep[top[v]])
			std::swap(u, v);
		v = fa[top[v]];
	}
	if (dep[u] > dep[v])
		std::swap(u, v);
	return u;
}

struct node {
	int l, r, mid;
	int min;
} p[maxn << 2];

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) {
		p[u].min = a[wid[l]];
		return;
	}
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].min = std::min(p[u << 1].min, p[u << 1 | 1].min);
}

void modify(int u, int k, int x) {
	if (p[u].l == p[u].r) {
		p[u].min = x;
		return;
	}
	if (k <= p[u].mid) modify(u << 1, k, x);
	else modify(u << 1 | 1, k, x);
	p[u].min = std::min(p[u << 1].min, p[u << 1 | 1].min);
}

int query(int u, int l, int r) {
	if (l > r) return inf;
//	if (tmp == m) printf("query %d %d %d %d %d %d\n", u, l, r, p[u].l, p[u].r, p[u].min);
	if (p[u].l == l && p[u].r == r)
		return p[u].min;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else return std::min(query(u << 1, l, p[u].mid),
		query(u << 1 | 1, p[u].mid + 1, r));
}

int query(int u) {
//	if (u == 1) printf(">>> %d %d %d %d %d %d %d\n", u, rt, lca(u, rt), 1, id[u] - 1, id[u] + siz[u], n);
	if (u == rt)
		return query(1, 1, n);
	else if (lca(u, rt) != u)
		return query(1, id[u], id[u] + siz[u] - 1);
	else {
		int v = rt;
		while (top[u] ^ top[v]) {
			if (fa[v] == u) break;
			v = fa[top[v]];
		}
		if (fa[v] ^ u) v = son[u];
		return std::min(query(1, 1, id[v] - 1), query(1, id[v] + siz[v], n));
	}
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
	
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(u), read(a[i]);
		if (!u) rt = i;
		else add_edge(u, i);
	}
	dep[1] = 1, dfs(1), dfs(1, 1);
	build(1, 1, n);
	
	int qcnt = 0;
	for (int i = 1; i <= m; i++) {
		readc(opt);
		switch (opt) {
			case 'V':
				read(u), read(x);
				modify(1, id[u], x);
				break;
			case 'E':
				read(u);
				rt = u;
				break;
			case 'Q':
				read(u);
//				if (u == 1)
				print(query(u), endl);
//				else query(u);
//				if (++qcnt == 22311) {
//					std::cerr << i << endl;
//					return 0;
//				}
				break;
		}
	}

	return 0;
}
