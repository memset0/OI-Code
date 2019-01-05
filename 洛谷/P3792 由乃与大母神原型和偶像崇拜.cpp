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
const int mod1 = 19260817;
const int mod2 = 20040301;

int n, m, l, r, x, y, opt;
bool updAns;
int a[maxn];

struct node {
	int l, r, mid;
	int min, max;
	int sum21, sum31, sum22, sum32;
} ans, p[maxn << 2];

inline void update(int u) {
	p[u].min = std::min(p[u << 1].min, p[u << 1 | 1].min);
	p[u].max = std::max(p[u << 1].max, p[u << 1 | 1].max);
	p[u].sum21 = (p[u << 1].sum21 + p[u << 1 | 1].sum21) % mod1;
	p[u].sum31 = (p[u << 1].sum31 + p[u << 1 | 1].sum31) % mod1;
	p[u].sum22 = (p[u << 1].sum22 + p[u << 1 | 1].sum22) % mod2;
	p[u].sum32 = (p[u << 1].sum32 + p[u << 1 | 1].sum32) % mod2;
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) {
		p[u].min = p[u].max = a[l];
		p[u].sum21 = 1ll * a[l] % mod1 * a[l] % mod1;
		p[u].sum31 = 1ll * a[l] % mod1 * a[l] % mod1 * a[l] % mod1;
		p[u].sum22 = 1ll * a[l] % mod2 * a[l] % mod2;
		p[u].sum32 = 1ll * a[l] % mod2 * a[l] % mod2 * a[l] % mod2;
		return;
	}
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	update(u);
}

void modify(int u, int k, int x) {
	if (p[u].l == p[u].r) {
		p[u].min = p[u].max = x;
		p[u].sum21 = 1ll * x * x % mod1;
		p[u].sum31 = 1ll * x * x % mod1 * x % mod1;
		p[u].sum22 = 1ll * x * x % mod2;
		p[u].sum32 = 1ll * x * x % mod2 * x % mod2;
		return;
	}
	modify(u << 1 | (k <= p[u].mid ? 0 : 1), k, x);
	update(u);
}

void query(int u, int l, int r) {
	if (p[u].l == l && p[u].r == r) {
		// printf("query to and %d %d %d %d %d %d <= %d\n", l, r, p[u].min, p[u].max, ans.min, ans.max, u);
		if (!updAns) {
			ans.min = p[u].min;
			ans.max = p[u].max;
			ans.sum21 = p[u].sum21;
			ans.sum22 = p[u].sum22;
			ans.sum31 = p[u].sum31;
			ans.sum32 = p[u].sum32;
			updAns = true;
		} else {
			ans.min = std::min(ans.min, p[u].min);
			ans.max = std::max(ans.max, p[u].max);
			ans.sum21 = (ans.sum21 + p[u].sum21) % mod1;
			ans.sum31 = (ans.sum31 + p[u].sum31) % mod1;
			ans.sum22 = (ans.sum22 + p[u].sum22) % mod2;
			ans.sum32 = (ans.sum32 + p[u].sum32) % mod2;
		}
		return;
	}
	if (r <= p[u].mid) query(u << 1, l, r);
	else if (l > p[u].mid) query(u << 1 | 1, l, r);
	else {
		query(u << 1, l, p[u].mid);
		query(u << 1 | 1, p[u].mid + 1, r);
	}
}

inline ll calcSum1(ll n, ll mod) {
	return n * (n + 1) / 2 % mod;
}
inline ll calcSum2(ll n, ll mod) {
	ll a = n, b = n + 1, c = n * 2 + 1;
	if (a % 2 == 0) a /= 2;
	else if (b % 2 == 0) b /= 2;
	else c /= 2;
	if (a % 3 == 0) a /= 3;
	else if (b % 3 == 0) b /= 3;
	else c /= 3;
	return a % mod * b % mod * c % mod;
}
inline ll calcSum3(ll n, ll mod) {
	return calcSum1(n, mod) * calcSum1(n, mod) % mod;
}

inline bool check() {
	// printf("%d %d %d %d %d %d\n", ans.min, ans.max, ans.max - ans.min, l, r, r - l);
	if (ans.max - ans.min != r - l)
		return false;
	int sum21 = calcSum2(ans.max, mod1) - calcSum2(ans.min - 1, mod1);
	sum21 = (sum21 % mod1 + mod1) % mod1;
	// printf("sum21 : %d %d\n", sum21, ans.sum21);
	if (sum21 != ans.sum21) return false;
	int sum22 = calcSum2(ans.max, mod2) - calcSum2(ans.min - 1, mod2);
	sum22 = (sum22 % mod2 + mod2) % mod2;
	// printf("sum22 : %d %d\n", sum22, ans.sum22);
	if (sum22 != ans.sum22) return false;
	int sum31 = calcSum3(ans.max, mod1) - calcSum3(ans.min - 1, mod1);
	sum31 = (sum31 % mod1 + mod1) % mod1;
	// printf("sum31 : %d %d\n", sum31, ans.sum31);
	if (sum31 != ans.sum31) return false;
	int sum32 = calcSum3(ans.max, mod2) - calcSum3(ans.min - 1, mod2);
	sum32 = (sum32 % mod2 + mod2) % mod2;
	// printf("sum32 : %d %d\n", sum32, ans.sum32);
	if (sum32 != ans.sum32) return false;
	return true;
}

int main() {
	// freopen("1.in", "r", stdin);
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		read(opt);
		if (opt == 1) {
			read(x), read(y);
			modify(1, x, y);
		} else {
			read(l), read(r);
			updAns = false;
			query(1, l, r);
			// printf("%d %d %d %d %d %d\n", ans.min, ans.max, ans.sum21, ans.sum22, ans.sum31, ans.sum32);
			puts(check() ? "damushen" : "yuanxing");
		}
	}
	return 0;
}