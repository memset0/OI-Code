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

int n, m, p, x, y, c, d, tn;
int b[maxn * 5], s[maxn * 5], ans[maxn];

struct node {
	int x, y, k;
} a[maxn * 5];

inline bool operator < (const node &a, const node &b) {
	if (a.x ^ b.x) return a.x < b.x;
	if (a.y ^ b.y) return a.y < b.y;
	return abs(a.k) < abs(b.k);
}

void insert(int k) {
	for (int i = k; i <= tn; i += i & -i)
		++s[i];
}

int query(int k) {
	int ret = 0;
	for (int i = k; i >= 1; i -= i & -i)
		ret += s[i];
	return ret;
}

int main() {
	// freopen("1.in", "r", stdin);
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(x), read(y);
		a[++p] = {x, y, 0};
	}
	for (int i = 1; i <= m; i++) {
		read(x), read(y), read(c), read(d);
		a[++p] = node{c, d, i};
		if (x) a[++p] = node{x - 1, d, -i};
		if (y) a[++p] = node{c, y - 1, -i};
		if (x && y) a[++p] = node{x - 1, y - 1, i};
	}
	std::sort(a + 1, a + p + 1);
	for (int i = 1; i <= p; i++)
		b[++tn] = a[i].y;
	std::sort(b + 1, b + tn + 1);
	tn = std::unique(b + 1, b + tn + 1) - b - 1;
	for (int i = 1; i <= p; i++)
		a[i].y = std::lower_bound(b + 1, b + tn + 1, a[i].y) - b;
	for (int i = 1; i <= p; i++) {
		// printf("> %d %d %d\n", a[i].x, a[i].y, a[i].k);
		if (a[i].k) {
			ans[abs(a[i].k)] += (a[i].k < 0 ? -1 : 1) * query(a[i].y);
		} else {
			insert(a[i].y);
		}
 	}
 	for (int i = 1; i <= m; i++)
 		print(ans[i], '\n');
	return 0;
}