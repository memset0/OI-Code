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

const int maxn = 100010, maxm = 300010;

int n, m, u, v, t, pos;
int fa[maxn], id[maxn], top[maxn], wid[maxn], son[maxn], siz[maxn], dep[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

typedef std::vector < int > vector;
typedef vector ::iterator iterator;
vector ans;

struct query {
	int u, v, t;
} q[maxm];
inline bool cmp(const query &a, const query &b) {
	return dep[a.t] > dep[b.t];
}

struct node {
	int l, r, mid;
	bool tag;
} p[maxn << 2];

void dfs1(int u) {
	siz[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ fa[u]) {
			fa[v] = u, dep[v] = dep[u] + 1;
			dfs1(v);
			siz[u] += siz[v];
			if (siz[v] > siz[son[u]])
				son[u] = v;
		}
}

void dfs2(int u, int toppoint) {
	top[u] = toppoint, id[u] = ++pos, wid[id[u]] = u;
	if (siz[u] == 1) return;
	dfs2(son[u], top[u]);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ fa[u] && v ^ son[u])
			dfs2(v, v);
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

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) return;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}

void modify(int u, int k) {
	p[u].tag = true;
	if (p[u].l == p[u].r) return;
	modify(k <= p[u].mid ? u << 1 : u << 1 | 1, k);
}

bool query(int u, int l, int r) {
	if (p[u].l == l && p[u].r == r) return p[u].tag;
	if (r <= p[u].mid) return query(u << 1, l, r);
	if (l > p[u].mid) return query(u << 1 | 1, l, r);
	return query(u << 1, l, p[u].mid) | query(u << 1 | 1, p[u].mid + 1, r);
}

bool jump(int u, int v) {
	while (top[u] ^ top[v]) {
		if (query(1, id[top[u]], id[u]))
			return true;
		u = fa[top[u]];
	}
	return query(1, id[v], id[u]);
}

int main() {
	// freopen("1.in", "r", stdin);
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(u), read(v);
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
	dep[1] = 1, dfs1(1), dfs2(1, 1), build(1, 1, n);
	read(m);
	for (int i = 1; i <= m; i++) {
		read(q[i].u), read(q[i].v);
		q[i].t = lca(q[i].u, q[i].v);
	}
	std::sort(q + 1, q + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		u = q[i].u, v = q[i].v, t = q[i].t;
		if (!jump(u, t) && !jump(v, t)) {
			ans.push_back(t);
			modify(1, id[t]);
		}
	}
	print(ans.size(), '\n');
	for (iterator it = ans.begin(); it != ans.end(); it++)
		print(*it);
	putc('\n');
	return 0;
}