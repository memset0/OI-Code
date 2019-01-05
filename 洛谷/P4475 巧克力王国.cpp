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

#define lc e[u].ch[0]
#define rc e[u].ch[1]

int n, m, a, b, c, x, y, z, rt, top, cnt, FG;
int stk[maxn];

struct point {
	int a[2], v;
	point () {}
	point (int x, int y, int z) {
		a[0] = x, a[1] = y, v = z;
	}
} p[maxn];
bool operator < (const point &a, const point &b) {
	return a.a[FG] < b.a[FG];
}

struct node {
	int min[2], max[2], ch[2], cnt;
	ll sum; point x;
} e[maxn];

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
	lc = rc = 0, e[u].x = x;
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
	FG = flag, std::nth_element(p + l, p + mid, p + r + 1);
	int u = newnode(p[mid]);
	lc = build(l, mid - 1, flag ^ 1);
	rc = build(mid + 1, r, flag ^ 1);
	return update(u), u;
}

void check(int &u, int flag) {
	static double ratio = 0.70;
	if (e[lc].cnt > e[u].cnt * ratio || e[rc].cnt > e[u].cnt * ratio)
		pia(u, 1), u = build(1, e[u].cnt, flag);
}

void insert(int &u, const point &x, int flag) {
	if (!u) { u = newnode(x); return; }
	insert(e[u].ch[e[u].x.a[flag] <= x.a[flag] ? 0 : 1], x, flag ^ 1);
	update(u), check(u, flag);
}

bool in(ll a, ll b, ll c, int x, int y, int p, int q) {
	return (a * x + b * y < c) && (a * p + b * q < c) &&
		(a * x + b * q < c) && (a * p + b * y < c);
}

bool out(ll a, ll b, ll c, int x, int y, int p, int q) {
	return (a * x + b * y >= c) && (a * p + b * q >= c) &&
		(a * x + b * q >= c) && (a * p + b * y >= c);
}

ll query(int u, ll a, ll b, ll c) {
	if (!u) return 0;
//	std::cerr << e[lc].cnt << ' ' << e[rc].cnt << endl;
//	printf("query %d %d %d %d %d %d %d %d\n", u, a, b, c, e[u].min[0], e[u].min[1], e[u].max[0], e[u].max[1]);
	if (in(a, b, c, e[u].min[0], e[u].min[1], e[u].max[0], e[u].max[1])) return e[u].sum;
	if (out(a, b, c, e[u].min[0], e[u].min[1], e[u].max[0], e[u].max[1])) return 0;
	return (a * e[u].x.a[0] + b * e[u].x.a[1] < c ? e[u].x.v : 0) +
		query(lc, a, b, c) + query(rc, a, b, c);
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);

	read(n), read(m);
//	std::cerr << std::clock() << endl;
	for (int i = 1; i <= n; i++) {
		read(x), read(y), read(z);
		p[i] = point(x, y, z);
	}
	rt = build(1, n, 0);
//	for (int i = 1; i <= n; i++) {
//		read(x), read(y), read(z);
//		insert(rt, point(x, y, z), 0);
//	}
//	std::cerr << std::clock() << endl;
	for (int i = 1; i <= m; i++) {
		read(a), read(b), read(c);
//		query(rt, a, b, c);
		print(query(rt, a, b, c), endl);
	}
//	std::cerr << std::clock() << endl;

	return 0;
}