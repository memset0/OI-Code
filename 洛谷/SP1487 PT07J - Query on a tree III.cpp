#include <bits/stdc++.h>
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

const int N = 1e5 + 10, P = N * 20;
int n, m, x, k, u, v, pos, cnt;
int a[N], b[N], rt[N], id[N], wid[N], siz[N], col[N];
int lc[P], rc[P], sum[P];
int tot = 2, hed[N], to[N << 1], nxt[N << 1];

void dfs(int u, int father) {
	siz[u] = 1, id[u] = ++pos, wid[id[u]] = u;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != father)
			dfs(v, u), siz[u] += siz[v];
}

void build(int &u, int l, int r) {
	u = ++cnt;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(lc[u], l, mid);
	build(rc[u], mid + 1, r);
}

void modify(int &u, int v, int k, int l, int r) {
	u = ++cnt, lc[u] = lc[v], rc[u] = rc[v], sum[u] = sum[v] + 1;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (k <= mid) modify(lc[u], lc[v], k, l, mid);
	else modify(rc[u], rc[v], k, mid + 1, r);
}

int query(int u, int v, int k, int l, int r) {
	// printf("query %d %d %d %d %d\n", u, v, k, l, r);
	if (l == r) return col[l];
	int mid = (l + r) >> 1, siz = sum[lc[v]] - sum[lc[u]];
	if (k <= siz) return query(lc[u], lc[v], k, l, mid);
	else return query(rc[u], rc[v], k - siz, mid + 1, r);
}

void main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]), b[i] = a[i];
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
	dfs(1, 0);
	std::sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) {
		a[i] = std::lower_bound(b + 1, b + n + 1, a[i]) - b;
		col[a[i]] = i;
	}
	// for (int i = 1; i <= n; i++)
	// 	print(col[i], " \n"[i == n]);
	build(rt[0], 1, n);
	for (int i = 1; i <= n; i++)
		modify(rt[i], rt[i - 1], a[wid[i]], 1, n);
	read(m);
	for (int i = 1; i <= m; i++) {
		read(x), read(k);
		// printf("%d %d : %d\n", id[x], id[x] + siz[x] - 1, k);
		print(query(rt[id[x] - 1], rt[id[x] + siz[x] - 1], k, 1, n), '\n');
	}
}

} signed main() { return ringo::main(), 0; }