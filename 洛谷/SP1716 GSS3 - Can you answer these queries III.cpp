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

const int N = 50010;
int n, m, l, r, i, op;
int a[N];

struct status {
	int lmax, rmax, max, sum;
};

inline status new_status(int x) {
	return (status) { x, x, x, x };
}

inline status merge(const status &a, const status &b) {
	return (status) {
		std::max(a.lmax, a.sum + b.lmax),
		std::max(b.rmax, b.sum + a.rmax),
		std::max(a.rmax + b.lmax, std::max(a.max, b.max)),
		a.sum + b.sum
	};
}

struct node {
	int l, r, mid;
	status x;
} p[N << 2];

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) { p[u].x = new_status(a[l]); return; }
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].x = merge(p[u << 1].x, p[u << 1 | 1].x);
}

void modify(int u, int k, int x) {
	if (p[u].l == p[u].r) { p[u].x = new_status(x); return; }
	modify(k <= p[u].mid ? u << 1 : u << 1 | 1, k, x);
	p[u].x = merge(p[u << 1].x, p[u << 1 | 1].x);
}

status query(int u, int l, int r) {
	if (p[u].l == l && p[u].r == r) return p[u].x;
	if (r <= p[u].mid) return query(u << 1, l, r);
	if (l > p[u].mid) return query(u << 1 | 1, l, r);
	return merge(query(u << 1, l, p[u].mid), query(u << 1 | 1, p[u].mid + 1, r));
}

void main() {
	for (read(n), i = 1; i <= n; i++) read(a[i]);
	build(1, 1, n);
	for (read(m), i = 1; i <= m; i++)
		if (read(op), read(l), read(r), op)
			print(query(1, l, r).max, '\n');
		else
			modify(1, l, r);
}

} signed main() { return ringo::main(), 0; }