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

const int maxn = 50010;

int n, m, l, r, opt;

struct node {
	int l, r, mid;
	int min, sum;
}; 

void init() {
	
}

int calc(int x, int p) {
	
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) return;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}

void modify(int u, int l, int r) {
	if (p[u].min > maxp) return;
	if (p[u].l == l && p[u].r == r) {
		p[u].min++;
		p[u].sum = calc(a[l], p[u].min);
		return;
	}
	if (r <= p[u].mid) modify(u << 1, l, r);
	else if (l > p[u].mid) modify(u << 1 | 1, l, r);
	else {
		modify(u << 1, l, p[u].mid);
		modify(u << 1 | 1, p[u].mid + 1, r);
	}
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
	p[u].min = std::min(p[u << 1].min, p[u << 1 | 1].min);
}

int query(int u, int l, int r) {
	if (p[u].l == l && p[u].r == r)
		return p[u].sum;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else return query(u << 1, l, p[u].mid) +
		query(u << 1 | 1, p[u].mid + 1, r);
}

int main() {
	read(n), read(m), read(p), read(c);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	init();
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		read(opt), read(l), read(r);
		if (opt) {
			print(query(1, l, r), endl);
		} else {
			modify(1, l, r);
		}
	}
	return 0;
}
