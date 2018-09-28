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

#define lc e[u].ch[0]
#define rc e[u].ch[1]

int n, m, ;

struct point {
	int a[2], v;
	point () {}
	point (int x, int y, int z) {
		a[0] = x, a[1] = y, v = z;
	}
};

struct node {
	int min[2], max[2], ch[2];
	int sum, cnt;
	point x;
};

void update(int u) {
	for (int i = 0; i ^ 2; i++) {
		e[u].min[i] = e[u].max[i] = e[u].x.a[i];
		if (lc) e[u].min[i] = std::min(e[u].min[i], e[lc].min[i]);
		if (rc) e[u].min[i] = std::min(e[u].min[i], e[rc].min[i]);
		if (lc) e[u].max[i] = std::max(e[u].max[i], e[lc].max[i]);
		if (rc) e[u].max[i] = std::max(e[u].max[i], e[rc].max[i]);
	}
	e[u].sum = e[lc].sum + e[rc].sum + e[u].x.v;
	e[u].cnt = e[lc].cnt + e[rc].cnt + 1;
}

int newnode(const point &x) {
	int u = top ? stk[top--] : ++cnt;
	memset(e[u], 0, sizeof(e[u])), e[u].x = x;
	return update(u), u;
}

void pia(int u, int k) {
	if (lc) pia(lc, k);
	p[k + e[lc].cnt] = e[u].x, stk[++top] = u;
	if (rc) pia(rc, e[lc].cnt + k + 1);
}

int build(int l, int r, int flag) {
	if (l > r) return 0;
	int mid = (l + r) >> 1;
	FG = flag, nth_element(p + l, p + mid, p + r + 1);
	int u = newnode(p[mid]);
	lc = build(l, mid - 1, flag ^ 1);
	rc = build(mid + 1, r, flag ^ 1);
	return update(u), u;
}

void check(int &u, int flag) {
	static double ratio = 0.66;
	if (e[lc].cnt > e[u].cnt * ratio || e[rc].cnt * ratio > e[u].cnt * ratio)
		pia(u, 1), u = build(1, e[u].siz, flag);
}

void insert(int &u, const point &x, int flag) {
	if (!u) { u = newnode(x); return; }
	insert(e[u].ch[e[u].x.a[flag] <= x.a[flag] ? 0 : 1], x, flag ^ 1)
	update(u), check(u, flag);
}

int query(int u, int a, int b, int c) {
	if (!u) return 0;
	if (a * e[u].max[0] + b * e[u].max[1] < c) return e[u].sum;
	if (a * e[u].min[0] + b * e[u].min[1] >= c) return 0;
	return (a * e[u].x.a[0] + b * e[u].x.a[1] < c ? e[u].x.v : 0) +
		query(lc, a, b, c), query(rc, a, b, c);
}

int main() {

	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(x), read(y), read(z);
		insert(rt, point(x, y, z), 0);
	}
	for (int i = 1; i <= m; i++) {
		read(a), read(b), read(c);
		print(query(rt, a, b, c), endl);
	}

	return 0;
}
