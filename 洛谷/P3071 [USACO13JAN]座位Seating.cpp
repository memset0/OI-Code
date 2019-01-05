// luogu-judger-enable-o2
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
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 500010;

int n, m, l, r, k, x, ans;
char opt;

#define lc (u<<1)
#define rc (u<<1|1)

struct node {
	int l, r, mid;
	int sl, sr, sm;
	int tag;
} p[maxn << 2];

bool full(int u) {
	return p[u].sm == p[u].r - p[u].l + 1;
}

void pushup(int u, int x) {
	p[u].sl = p[u].sr = p[u].sm = x ? 0 : p[u].r - p[u].l + 1;
	p[u].tag = x;
}

void pushdown(int u) {
	if (~p[u].tag) {
		if (p[u].l ^ p[u].r) {
			pushup(lc, p[u].tag);
			pushup(rc, p[u].tag);
		}
		p[u].tag = -1;
	}
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	p[u].sl = p[u].sr = p[u].sm = r - l + 1;
	p[u].tag = -1;
	if (l == r) return;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}

void update(int u) {
	p[u].sl = full(lc) ? p[lc].sm + p[rc].sl : p[lc].sl;
	p[u].sr = full(rc) ? p[rc].sm + p[lc].sr : p[rc].sr;
	p[u].sm = std::max(p[lc].sr + p[rc].sl, std::max(p[lc].sm, p[rc].sm));
}

void clear(int u, int l, int r) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) {
		pushup(u, 0);
		return;
	}
	if (r <= p[u].mid) clear(lc, l, r);
	else if (l > p[u].mid) clear(rc, l, r);
	else clear(lc, l, p[u].mid), clear(rc, p[u].mid + 1, r);
	update(u);
}

void fill(int u, int l, int r) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) {
		pushup(u, 1);
		return;
	}
	if (r <= p[u].mid) fill(lc, l, r);
	else if (l > p[u].mid) fill(rc, l, r);
	else fill(lc, l, p[u].mid), fill(rc, p[u].mid + 1, r);
	update(u);
}

int query(int u, int s) {
	if (!s) return u;
	pushdown(u);
	if (p[u].l == p[u].r) return p[u].l;
	if (full(u)) return p[u].l;
	if (p[lc].sm >= s) return query(lc, s);
	if (p[lc].sr + p[rc].sl >= s) return p[lc].r - p[lc].sr + 1;
	return query(rc, s);
}

int main() {
	// freopen("1.in", "r", stdin);
	read(n), read(m);
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		readc(opt);
		if (opt == 'A') {
			read(x);
			if (p[1].sm < x)
				++ans;
			else {
				k = query(1, x);
				fill(1, k, k + x - 1);
			}
		} else {
			read(l), read(r);
			clear(1, l, r);
		}
	}
	print(ans, '\n');
	return 0;
}