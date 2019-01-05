#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

const int maxn = 500010;
int n, m, l, r, op;
int a[maxn];

struct pair {
	int sum, ans, suml, sumr;
};

pair create(int x) {
	pair u;
	u.sum = u.ans = u.suml = u.sumr = x;
	return u;
}

pair merge(const pair &a, const pair &b) {
	pair u;
	u.sum = a.sum + b.sum;
	u.ans = std::max(a.sumr + b.suml, std::max(a.ans, b.ans));
	u.suml = std::max(a.sum + b.suml, a.suml);
	u.sumr = std::max(b.sum + a.sumr, b.sumr);
	return u;
}

struct node {
	int l, r, mid;
	pair x;
} p[maxn << 2];

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) { p[u].x = create(a[l]); return; }
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].x = merge(p[u << 1].x, p[u << 1 | 1].x);
}

void modify(int u, int k, int s) {
	if (p[u].l == p[u].r) { p[u].x = create(s); return; }
	if (k <= p[u].mid) modify(u << 1, k, s);
	else modify(u << 1 | 1, k, s);
	p[u].x = merge(p[u << 1].x, p[u << 1 | 1].x);
}

pair query(int u, int l, int r) {
	if (p[u].l == l && p[u].r == r) return p[u].x;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else return merge(query(u << 1, l, p[u].mid), query(u << 1 | 1, p[u].mid + 1, r));
}

void main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		read(op), read(l), read(r);
		if (op == 1) {
			if (l > r) std::swap(l, r);
			print(query(1, l, r).ans), putc('\n');
		} else {
			modify(1, l, r);
		}
	}
}

} int main() { return ringo::main(), 0; }