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

const int maxn = 100010;
const int mod = 998244353;

int n, m, l, r, v, opt, ans;
int a[maxn];

struct node {
	int l, r, mid;
	int sum, tag;
	int len, len1, len2, lenv;
} p[maxn << 2];

inline void pushup(int u, int x) {
	p[u].tag = (p[u].tag + x) % mod;
	p[u].sum = (p[u].sum + 1ll * x * p[u].len) % mod;
	p[u].lenv = (p[u << 1].lenv + p[u << 1 | 1].lenv + 1ll * p[u].len1 * p[u].sum) % mod;
}

inline void pushdown(int u) {
	if (p[u].tag) {
		if (p[u].l ^ p[u].r) {
			pushup(u << 1, p[u].tag);
			pushup(u << 1 | 1, p[u].tag);
		}
		p[u].tag = 0;
	}
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r;
	p[u].mid = (l + r) >> 1;
	p[u].len = r - l + 1;
//	printf("build %d %d %d\n", u, l, r);
	if (l == r) {
		p[u].sum = a[l];
		p[u].len1 = 1;
		p[u].len2 = 1;
		p[u].lenv = a[l];
	} else {
		build(u << 1, l, p[u].mid);
		build(u << 1 | 1, p[u].mid + 1, r);
		p[u].sum = (p[u << 1].sum + p[u << 1 | 1].sum) % mod;
		p[u].lenv = (p[u << 1].lenv + p[u << 1 | 1].lenv + 1ll * p[u].sum * p[u].len) % mod;
		p[u].len1 = (p[u << 1].len1 + p[u << 1 | 1].len1 + p[u].len) % mod;
		p[u].len2 = (p[u << 1].len2 + p[u << 1 | 1].len2 + 1ll * p[u].len * p[u].len) % mod;
	}
	ans = (ans + 1ll * p[u].sum * p[u].sum) % mod;
}

void modify(int u, int l, int r, int x) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) {
//		printf(">>> (%d %d %d %d) %d", p[u].l, p[u].r, p[u].lenv, p[u].len2, ans);
		ans = (ans + 1ll * x * x % mod * p[u].len2) % mod;
//		printf(" %d", ans);
		ans = (ans + 2ll * x * p[u].lenv) % mod;
//		printf(" %d\n", ans);
		pushup(u, x);
		return;
	}
	if (r <= p[u].mid) modify(u << 1, l, r, x);
	else if (l > p[u].mid) modify(u << 1 | 1, l, r, x);
	else {
		modify(u << 1, l, p[u].mid, x);
		modify(u << 1 | 1, p[u].mid + 1, r, x);
	}
	int old = p[u].sum;
	p[u].sum = (p[u << 1].sum + p[u << 1 | 1].sum) % mod;
	ans = (ans + 1ll * p[u].sum * p[u].sum - 1ll * old * old + mod) % mod;
}

ll inv(ll x) {
	if (x == 0 || x == 1) return 1;
	return (mod - mod / x) * inv(mod % x) % mod;
}

int main() {
	freopen("3.txt", "r", stdin);
	freopen("1.txt", "w", stdout);

	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	ans = 0;
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		read(opt);
//		print(ans, '\n');
		if (opt == 1) {
			read(l), read(r), read(v);
			modify(1, l, r, v);
		} else {
//			print(ans, '\n');
			print(1ll * ans * inv(p[1].sum) % mod, '\n');
		}
	}

	return 0;
}

