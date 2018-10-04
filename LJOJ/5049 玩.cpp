// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

#define int long long

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

const int maxn = 500010;

int m, c, x, h, l, r, opt, pos, now, lastans;

struct node {
	int l, r, mid;
	int sum, max;
	int lq, rq;
} p[maxn << 2];

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) return;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}

void insert(int u, int k, int x, int h) {
	if (p[u].l == p[u].r) {
		p[u].sum = p[u].lq = p[u].rq = x;
		p[u].max = h;
		return;
	}
	insert(k <= p[u].mid ? u << 1 : u << 1 | 1, k, x, h);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
	p[u].max = std::max(p[u << 1].max, p[u << 1 | 1].max);
}

void erase(int u, int k) {
	if (p[u].l == p[u].r) {
		p[u].sum = p[u].lq = p[u].rq = 0;
		p[u].max = 0;
		return;
	}
	erase(k <= p[u].mid ? u << 1 : u << 1 | 1, k);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
	p[u].max = std::max(p[u << 1].max, p[u << 1 | 1].max);
}

void query(int u, int l, int r) {
//	printf("query %d %d %d %d %d\n", u, l, r, p[u].sum, p[u].max);
	if (p[u].max <= now || l > r) return;
	if ((l <= p[u].lq && r >= p[u].sum - p[u].rq) || (p[u].l == p[u].r)) {
		now = std::max(p[u].max, now);
		return;
	}
	int siz = p[u << 1].sum;
	if (l < siz && r < siz) query(u << 1, l, r);
	else if (l > siz && r > siz) query(u << 1 | 1, l - siz, r - siz);
	else {
		query(u << 1, l, siz);
		query(u << 1 | 1, 0, r - siz);
	}
}

signed main() {
//	freopen("play1.in", "r", stdin);
//	freopen("play.out", "w", stdout);
//	freopen("3.txt", "r", stdin);
//	freopen("1.txt", "w", stdout);

	read(m), read(c);
	build(1, 1, m);
	for (int i = 1; i <= m; i++) {
		read(opt);
//		printf(">>> %d\n", opt);
		if (opt == 1) {
			read(x), read(h);
			if (c) {
				x = (x * 2333ll + lastans * 666ll) % 100000007 + 1;
				h = (h * 2333ll + lastans * 666ll) % 100000007 + 1;
			}
			insert(1, ++pos, x, h);
		} else if (opt == 2) {
			read(x);
			erase(1, x);
		} else {
			read(l), read(r);
			now = 0;
			query(1, l, r);
			print(now, '\n');
			lastans = now;
		}
	}


	return 0;
}
