// ==============================
//  author: memset0
//  website: https://memset0.cn
//  note: _rqy 又强又可爱
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
template <typename T> inline void print(T x, char c = '\n') {
	static int buf[40];
	if (x < 0) putc('-'), x = -x; else if (x == 0) putc('0');
	else {
		for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
		while (buf[0]) putc((char) buf[buf[0]--]);
	} putc(c);
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			scanf("%1d", &a[i][j]);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			scanf("%1d", &b[i][j]);
	

	return 0;
}
