#include <bits/stdc++.h>
#define il inline
#define rg register
#define int long long
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T >
il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}
template < class T >
il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}
template < class T >
il void print(T x, char c) {
	print(x), putc(c);
}

const int N = 5e4 + 10;
int n, m, l, r, a[N];

struct status {
	int lmax, rmax, max, sum;
};

struct node {
	int l, r, mid;
	status x;
} p[N << 2];

il status new_status(int x) {
	return (status) { x, x, x, x };
}

il status merge(const status &a, const status &b) {
	return (status) {
		std::max(a.lmax, a.sum + b.lmax),
		std::max(b.rmax, b.sum + a.rmax),
		std::max(a.rmax + b.lmax, std::max(a.max, b.max)),
		a.sum + b.sum
	};
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) { p[u].x = new_status(a[l]); return; }
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].x = merge(p[u << 1].x, p[u << 1 | 1].x);
}

status query(int u, int l, int r) {
	if (p[u].l == l && p[u].r == r) return p[u].x;
	if (r <= p[u].mid) return query(u << 1, l, r);
	if (l > p[u].mid) return query(u << 1 | 1, l, r);
	return merge(query(u << 1, l, p[u].mid), query(u << 1 | 1, p[u].mid + 1, r));
}

void main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	build(1, 1, n);
	read(m);
	for (int i = 1; i <= m; i++) {
		read(l), read(r);
		print(query(1, l, r).max, '\n');
	}
}

} signed main() { return ringo::main(), 0; }