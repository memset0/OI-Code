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

const int maxn = 30010, maxm = 210;
const int M = 13131;

int n, m, t, val, ans, tmp;
int a[maxm]; char s[maxm];

unsigned long long now, mul[maxm], l[maxm], r[maxm];
unsigned long long f[maxm][maxn];

typedef std::map < int, int > mapType;
typedef mapType::iterator mapIterator;
mapType map[maxm];

int change(char c) {
	if ('a' <= c && c <= 'z') return c - 'a' + 1;
	if ('A' <= c && c <= 'Z') return c - 'A' + 27;
	if ('0' <= c && c <= '9') return c - '0' + 53;
	if (c == '_') return 63;
	if (c == '@') return 64;
}

int inv(int x, int p) {
	if (x == 0 || x == 1) return 1;
	return 1ll * (p - p / x) * inv(p % x, p) % p;
}

int main() {
	// freopen("1.in", "r", stdin);

	read(n), read(m), read(t);

	for (int k = 1; k <= n; k++) {
		scanf("%s", s + 1);
		for (int i = 1; i <= m; i++)
			a[i] = change(s[i]);
		for (int i = 1; i <= m; i++)
			l[i] = l[i - 1] * M + a[i];
		for (int i = m; i >= 1; i--)
			r[i] = r[i + 1] * M + a[i];
		for (int i = 1; i <= m; i++)
			f[i][k] = l[i - 1] * 137 + r[i + 1] * 129;
	}
	for (int i = 1; i <= m; i++) {
		std::sort(f[i] + 1, f[i] + n + 1);
		tmp = 0;
		for (int j = 2; j <= n; j++)
			if (f[i][j] == f[i][j - 1]) {
				ans += ++tmp;
			} else {
				tmp = 0;
			}
	}
	print(ans, '\n');

	return 0;
}