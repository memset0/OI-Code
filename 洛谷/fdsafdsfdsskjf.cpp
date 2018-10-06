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


const int maxn = 2010;

#define lowbit(x) ((x)&(-(x)))

int n, m, p, q, a, b, c, d;
ll ans, s[4][maxn][maxn];
char opt;

void modify(int a, int b, int x) {
	for (int i = a; i <= n; i += lowbit(i))
		for (int j = b; j <= m; j += lowbit(j)) {
			s[0][i][j] += x;
			s[1][i][j] += x * a;
			s[2][i][j] += x * b;
			s[3][i][j] += x * a * b;
		}
}

ll query(int a, int b) {
	ll ans = 0;
	for (int i = a; i; i -= lowbit(i))
		for (int j = b; j; j -= lowbit(j)) {
			ans += s[0][i][j] * a * b;
			ans -= s[1][i][j] * b;
			ans -= s[2][i][j] * a;
			ans += s[3][i][j];
		}
	return ans;
}

int main() {

	read(n), read(m), read(p), read(q);
	for (int i = 1; i <= p; i++) {
		read(a), read(b), read(c), read(d);
		modify(a, b, 1);
		modify(a, d + 1, -1);
		modify(c + 1, b, -1);
		modify(c + 1, d + 1, 1);
	}
	for (int i = 1; i <= q; i++) {
		read(a), read(b), read(c), read(d);
		ans = 0;
		ans += query(a, b);
		ans -= query(a, d + 1);
		ans -= query(c + 1, b);
		ans += query(c + 1, d + 1);
		print(ans, '\n');
	}

	return 0;
}
