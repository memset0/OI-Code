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
template <typename T> inline void read1d(T &x) {
	while (x = getc(), !isdigit(x));
	x -= '0';
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 300010;

int n, m, l, r, opt;
int a[maxn];

struct matrix {
	int x[2][2];
};
matrix simple0, simple1;

struct seg_node {
	int l, r, mid;
	matrix x; 
} p[maxn << 2];

inline matrix operator * (const matrix &a, const matrix &b) {
	return matrix {{{
		std::min(a.x[0][0] + b.x[0][0], a.x[1][0] + b.x[0][1]),
		std::min(a.x[0][1] + b.x[0][0], a.x[1][1] + b.x[0][1])},{
		std::min(a.x[0][0] + b.x[1][0], a.x[1][0] + b.x[1][1]),
		std::min(a.x[0][1] + b.x[1][0], a.x[1][1] + b.x[1][1])}
	}};
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) {
		p[u].x = a[l] ? simple1 : simple0;
		return;
	}
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].x = p[u << 1].x * p[u << 1 | 1].x;
}

void modify(int u, int k, int c) {
	if (p[u].l == p[u].r) {
		p[u].x = c ? simple1 : simple0;
		return;
	}
	if (k <= p[u].mid) modify(u << 1, k, c);
	else modify(u << 1 | 1, k, c);
	p[u].x = p[u << 1].x * p[u << 1 | 1].x;
}

matrix query(int u, int l, int r) {
	if (p[u].l == l && p[u].r == r)
		return p[u].x;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else return query(u << 1, l, p[u].mid) *
		query(u << 1 | 1, p[u].mid + 1, r);
}

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	simple0 = matrix{{{0, 2}, {1, 1}}};
	simple1 = matrix{{{1, 2}, {0, 0}}};
	read(n);
	for (int i = 1; i <= n; i++)
		read1d(a[i]);
	build(1, 1, n);
	read(m);
	for (int i = 1; i <= m; i++) {
		read(opt), read(l), read(r);
		if (opt == 1) {
			print(query(1, l, r).x[0][0], '\n');
		} else {
			modify(1, l, r);
		}
	}
	return 0;
}