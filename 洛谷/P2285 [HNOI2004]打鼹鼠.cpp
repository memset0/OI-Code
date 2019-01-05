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

const int maxn = 10010;

int n, m, ans;
int f[maxn];

struct node {
	int x, y, t;
} a[maxn];

inline bool operator < (const node &a, const node &b) {
	return a.t < b.t;
}

inline int dis(int i, int j) {
	return abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
}

int main() {
	// freopen("1.in", "r", stdin);
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(a[i].t);
		read(a[i].x);
		read(a[i].y);
	}
	std::sort(a + 1, a + m + 1);
	for (int i = 1; i <= m; i++) {
		f[i] = 1;
		for (int j = 1; j < i; j++)
			if (dis(i, j) <= a[i].t - a[j].t)
				f[i] = std::max(f[i], f[j] + 1);
	}
	for (int i = 1; i <= m; i++)
		ans = std::max(ans, f[i]);
	print(ans, '\n');
	return 0;
}