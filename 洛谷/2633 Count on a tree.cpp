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
template <typename T> inline void print(T x, char c = '\n') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 100010, maxe = maxn * 40;

int n, m, u, v, l, r, k, t, tn, pos, mid, ans, now, lastans;
int val[maxn], tmp[maxn], root[maxn], dep[maxn];
int f[maxn][20];
int sum[maxe], lc[maxe], rc[maxe];

int tot = 2, hed[maxn], to[maxn << 1], nxt[maxn << 1];

inline void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v;
	hed[u] = tot++;
}

void build(int &u, int l = 1, int r = tn) {
	u = ++pos;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(lc[u], l, mid);
	build(rc[u], mid + 1, r);
}

void modify(int &u, int v, int k, int l = 1, int r = tn) {
	u = ++pos;
	lc[u] = lc[v], rc[u] = rc[v], sum[u] = sum[v] + 1;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (k <= mid) modify(lc[u], lc[v], k, l, mid);
	else modify(rc[u], rc[v], k, mid + 1, r);
}

int query(int a, int b, int c, int d, int k, int l = 1, int r = tn) {
	if (l == r) return l;
	int now = sum[lc[a]] + sum[lc[b]] - sum[lc[c]] - sum[lc[d]];
	int mid = (l + r) >> 1;
	if (k <= now) return query(lc[a], lc[b], lc[c], lc[d], k, l, mid);
	else return query(rc[a], rc[b], rc[c], rc[d], k - now, mid + 1, r);
}

void dfs(int u) {
	modify(root[u], root[f[u][0]], val[u]);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ f[u][0])  {
			f[v][0] = u;
			dep[v] = dep[u] + 1;
			dfs(v);
		}
}

int lca(int u, int v) {
	if (dep[u] > dep[v])
		 std::swap(u, v);
	for (int i = 19; i >= 0; i--)
		if (dep[f[v][i]] >= dep[u])
			v = f[v][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--)
		if (f[u][i] ^ f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(val[i]);
		tmp[i] = val[i];
	}
	std::sort(tmp + 1, tmp + n + 1);
	tn = std::unique(tmp + 1, tmp + n + 1) - tmp - 1;
	for (int i = 1; i <= n; i++)
		val[i] = std::lower_bound(tmp + 1, tmp + tn + 1, val[i]) - tmp;
//	for (int i = 1; i <= n; i++)
//		print(val[i], ' ');
//	putc('\n');
//	for (int i = 1; i <= tn; i++)
//		print(tmp[i], ' ');
//	putc('\n');
		
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		add_edge(u, v);
		add_edge(v, u);
	}
	
	build(root[0]);
	dep[1] = 1, dfs(1);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++)
			f[j][i] = f[f[j][i - 1]][i - 1];
	
	for (int i = 1; i <= m; i++) {
		read(u), read(v), read(k);
		u ^= lastans, t = lca(u, v);
		print(lastans = tmp[query(root[u], root[v], root[t], root[f[t][0]], k)]);
	}

	return 0;
}
