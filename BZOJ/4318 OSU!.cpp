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

int n;
double p, len1, len2, ans;

int main() {
	// freopen("1.in", "r", stdin);f

	read(n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &p);
		ans += (3 * len2 + 3 * len1 + 1) * p;
		len2 = (len2 + 2 * len1 + 1) * p;
		len1 = (len1 + 1) * p;
	}
	printf("%.1lf\n", ans);

	return 0;
}

//   a ^ 3 - b ^ 3
// = (a - b)(a ^ 2 + a * b + b ^ 2)
// = (i - i + 1)(i ^ 2 + i * (i - 1) + (i - 1) ^ 2)
// = i ^ 2 + i ^ 2 - i + i ^ 2 + 2 * i + 1
// = 3 * i ^ 2 + 3 * i + 1

//   a ^ 2 - b ^ 2
// = (a + b)(a - b)
// = i * 2 - 1