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
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int N = 200010, M = 500010, E = N * 40;

int n, m, p, u, v, w, t, x, k, cnt, pos, ord;
int fa[N], id[N], wid[N], val[N], siz[N];
int f[N][20], g[N][20];
int lc[E], rc[E], sum[E], root[N];

struct edge {
	int u, v, w;
} e[M];
bool operator < (const edge &a, const edge &b) {
	return a.w < b.w;
}

int tot = 2, hed[N], nxt[N << 1], to[N << 1];
inline void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
//	printf("add edge %d %d\n", u, v);
}

int find(int u) {
	if (fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}

void dfs(int u) {
	siz[u] = 1, id[u] = ++pos, wid[id[u]] = u;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ f[u][0]) {
			f[v][0] = u;
			g[v][0] = (u <= n ? 0 : val[u]);
			dfs(v);
			siz[u] += siz[v];
		}
}

void build(int &u, int v, int l, int r, int k) {
	u = ++ord, lc[u] = lc[v], rc[u] = rc[v], sum[u] = sum[v] + 1;
//	printf("build(%d %d %d %d %d %d)\n", u, v, l, r, sum[u], k);
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (k <= mid) build(lc[u], lc[v], l, mid, k);
	else build(rc[u], rc[v], mid + 1, r, k);
}

int query(int u, int v, int l, int r, int k) {
	if (l == r) return (k <= (sum[v] - sum[u]) ? l : -1);
	if (l == r) return l;
	int mid = (l + r) >> 1, tmp;
//	printf("query(%d %d %d %d %d %d %d)\n", u, v, l, r, k, sum[rc[v]] - sum[rc[u]]);
	tmp = sum[rc[v]] - sum[rc[u]];
	if (k <= tmp)
		return query(rc[u], rc[v], mid + 1, r, k);
	else
		return query(lc[u], lc[v], l, mid, k - tmp);
}

int main() {
//	freopen("INPUT", "r", stdin);

	read(n), read(m), read(p);
	for (int i = 1; i <= n; i++)
		read(val[i]);
	for (int i = 1; i <= m; i++)
		read(e[i].u), read(e[i].v), read(e[i].w);
	
	std::sort(e + 1, e + m + 1);
	for (int i = 1; i < (n << 1); i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++) {
		u = e[i].u, v = e[i].v, w = e[i].w;
		if  (find(u) ^ find(v)) {
			t = n + (++cnt);
			u = find(u), v = find(v);
//			printf("== %d %d %d ==\n", u, v, w);
			fa[u] = fa[v] = t;
			add_edge(u, t);
			add_edge(v, t);
			val[t] = w;
		}
	}
	
	dfs((n << 1) - 1);
	for (int i = 1; i < (n << 1); i++)
		if (wid[i] <= n)
			build(root[i], root[i - 1], 1, 1e9, val[wid[i]]);
		else
			root[i] = root[i - 1];
	for (int i = 1; i <= 19; i++)
		for (int j = 1; j < (n << 1); j++) {
			f[j][i] = f[f[j][i - 1]][i - 1];
			g[j][i] = std::max(g[j][i - 1], g[f[j][i - 1]][i - 1]);
		}
	
	for (int i = 1; i <= p; i++) {
		read(u), read(x), read(k);	
//		printf("%d %d %d\n", u, x, k);
		for (int i = 19; i >= 0; i--)
			if (x >= g[u][i] && f[u][i]) {
//				printf("%d -> %d %d\n", u, f[u][i], g[u][i]);
				u = f[u][i];
			}
//		printf("=> %d %d %d\n", u, val[u], x);
		printf("%d\n", query(root[id[u] - 1], root[id[u] + siz[u] - 1], 1, 1e9, k));
	}
//	for (int i = 1; i < (n << 1); i++) print(id[i]); putc('\n');
//	for (int i = 1; i < (n << 1); i++) print(id[i] + siz[i] - 1); putc('\n');

	return 0;
}