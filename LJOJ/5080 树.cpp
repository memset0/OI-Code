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

const int maxn = 100010;

int n, m, u, v, c, s, e;
int val[maxn], dep[maxn], ans[maxn], f[maxn][20];

struct max_pair {
	int v, k;
	inline bool operator < (const max_pair &other) {
		if (v == other.v) {
			return dep[k] > dep[other.k];
		} else {
			return v < other.v;
		}
	}
} ret, g[maxn][20];

int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];
inline void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
}

void dfs1(int u) {
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != f[u][0]) {
			f[v][0] = u;
			g[v][0] = max_pair{val[u], u};
			dep[v] = dep[u] + 1;
			dfs1(v);
		}
}

int jump(int u, int c) {
	if (c < val[u]) return u;
	for (int i = 19; i >= 0; i--)
		if (g[u][i].v <= c && f[u][i]) {
			u = f[u][i];
		}
	return f[u][0];
}

int find(int u, int v) {
	ret = max_pair{val[u], u};
	for (int i = 19; i >= 0; i--)
		if (dep[f[u][i]] >= dep[v]) {
			ret = ret < g[u][i] ? g[u][i] : ret;
			u = f[u][i];
		}
	return ret.k;
}

void dfs2(int u) {
	ans[u] = ans[jump(u, val[u])] + 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != f[u][0]) {
			dfs2(v);
		}
}

int main() {
	// freopen("tree.in", "r", stdin);
	// freopen("tree.out", "w", stdout);
//	freopen("3.txt", "r", stdin);
//	freopen("1.txt", "w", stdout);
	
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(val[i]);
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		add_edge(u, v);
		add_edge(v, u);
	}
	dfs1(1);
	for (int i = 1; i <= 19; i++)
		for (int j = 1; j <= n; j++) {
			f[j][i] = f[f[j][i - 1]][i - 1];
			g[j][i] = g[f[j][i - 1]][i - 1] < g[j][i - 1] ? g[j][i - 1] : g[f[j][i - 1]][i - 1];
		}
	dfs2(1);
//	for (int i = 1; i <= n; i++)
//		printf("%d ", ans[i]);
//	putc('\n');
	for (int i = 1; i <= m; i++) {
		read(u), read(v), read(c);
		s = jump(u, c);
		e = find(u, v);
//		printf("%d %d\n", s, e);
		print(dep[s] >= dep[e] ? ans[s] - ans[e] + 1 : 0, '\n');
	}

	return 0;
}
