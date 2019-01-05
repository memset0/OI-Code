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

const int N = 3e4 + 10, M = 2e5 + 10, T = N * 20;
int n, m, l, r, k, tn, tot;
int a[N], b[N], rt[N], lc[T], rc[T], sum[T];

void build(int &u, int l, int r) {
	u = ++tot;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(lc[u], l, mid);
	build(rc[u], mid + 1, r);
}

void modify(int &u, int v, int k, int l, int r) {
	u = ++tot, lc[u] = lc[v], rc[u] = rc[v], sum[u] = sum[v] + 1;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (k <= mid) modify(lc[u], lc[v], k, l, mid);
	else modify(rc[u], rc[v], k, mid + 1, r);
}

int query(int u, int v, int ql, int qr, int l, int r) {
	if (ql > qr) return 0;
	if (ql == l && qr == r) return sum[v] - sum[u];
	int mid = (l + r) >> 1;
	if (qr <= mid) return query(lc[u], lc[v], ql, qr, l, mid);
	if (ql > mid) return query(rc[u], rc[v], ql, qr, mid + 1, r);
	return query(lc[u], lc[v], ql, mid, l, mid) + query(rc[u], rc[v], mid + 1, qr, mid + 1, r);
}

void main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]), b[i] = a[i];
	std::sort(b + 1, b + n + 1);
	tn = std::unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++)
		a[i] = std::lower_bound(b + 1, b + tn + 1, a[i]) - b;
	build(rt[0], 1, tn);
	for (int i = 1; i <= n; i++)
		modify(rt[i], rt[i - 1], a[i], 1, tn);
	read(m);
	for (int i = 1; i <= m; i++) {
		read(l), read(r), read(k);
		k = std::upper_bound(b + 1, b + tn + 1, k) - b;
		print(query(rt[l - 1], rt[r], k, tn, 1, tn), '\n');
	}
}

} signed main() { return ringo::main(), 0; }