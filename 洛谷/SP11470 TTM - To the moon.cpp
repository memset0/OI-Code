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

const int N = 1e5 + 10, M = N * 40;
int n, m, l, r, w, op, tim, cnt;
int a[N], rt[N], lc[M], rc[M], sum[M], tag[M];

void build(int &u, int l, int r) {
	u = ++cnt;
	if (l == r) { sum[u] = a[l]; return; }
	int mid = (l + r) >> 1;
	build(lc[u], l, mid);
	build(rc[u], mid + 1, r);
	sum[u] = sum[lc[u]] + sum[rc[u]];
}

void modify(int &u, int v, int ql, int qr, int w, int l, int r) {
	u = ++cnt, lc[u] = lc[v], rc[u] = rc[v];
	sum[u] = sum[v] + (qr - ql + 1) * w, tag[u] = tag[v];
	// printf("modify %d %d %d %d %d %d %d : %d %d\n", u, v, ql, qr, w, l, r, sum[u], tag[u]);
	if (ql == l && qr == r) { tag[u] += w; return; }
	int mid = (l + r) >> 1;
	if (qr <= mid) modify(lc[u], lc[v], ql, qr, w, l, mid);
	else if (ql > mid) modify(rc[u], rc[v], ql, qr, w, mid + 1, r);
	else modify(lc[u], lc[v], ql, mid, w, l, mid), modify(rc[u], rc[v], mid + 1, qr, w, mid + 1, r);
}

int query(int u, int ql, int qr, int l, int r) {
	// printf("query %d %d %d %d %d : %d %d\n", u, ql, qr, l, r, sum[u], tag[u]);
	if (ql == l && qr == r) return sum[u];
	int mid = (l + r) >> 1, ret = tag[u] * (qr - ql + 1);
	if (qr <= mid) return ret + query(lc[u], ql, qr, l, mid);
	if (ql > mid) return ret + query(rc[u], ql, qr, mid + 1, r);
	return ret + query(lc[u], ql, mid, l, mid) + query(rc[u], mid + 1, qr, mid + 1, r);
}

void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) read(a[i]);
	build(rt[0], 1, n);
	for (int i = 1; i <= m; i++) {
		while (op = getchar(), !isupper(op));
		// printf(">>> %c : %d\n", op, tim);
		switch (op) {
			case 'C':
				read(l), read(r), read(w);
				modify(rt[tim + 1], rt[tim], l, r, w, 1, n), ++tim;
				break;
			case 'Q':
				read(l), read(r);
				print(query(rt[tim], l, r, 1, n), '\n');
				break;
			case 'H':
				read(l), read(r), read(w);
				print(query(rt[w], l, r, 1, n), '\n');
				break;
			case 'B':
				read(w), tim = w;
				break;
		}
	}
}

} signed main() { return ringo::main(), 0; }