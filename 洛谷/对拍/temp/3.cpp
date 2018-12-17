// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#include <windows.h>
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

int n, m, lim;

int brand() {
	return ((rand() << 16) + (rand() << 1) + (rand() & 1)) % lim;
}

int main() {
	srand(GetTickCount());
	freopen("3.txt", "w", stdout);

	n = m = 10, lim = 10;
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++)
		print(brand());
	putc('\n');
	for (int i = 1; i <= m; i++) {
		int opt = (rand() & 1) + 1;
		printf("%d ", opt);
		if (opt == 1) {
			int l = rand() % n + 1;
			int r = rand() % n + 1;
			if (l > r) std::swap(l, r);
			printf("%d %d %d\n", l, r, brand());
		}
		else
			putc('\n');
	}

	return 0;
}

