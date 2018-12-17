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

int n = 10, m = 4;

int brand() {
	return (rand() << 16) + (rand() << 1) + (rand() & 1);
}

int r() {
	return brand() % n + 1;
}

int main() {
	srand(GetTickCount());
	
	printf("%d\n", 10);
	for (int i = 1; i <= m; i++) {
		int opt = rand() % 2 + 1;
		if (opt == 1) {
			int x = r(), y = r(), v = brand() % 100 + 1;
			printf("1 %d %d %d\n", x, y, v);
		} else {
			int x1 = r(), y1 = r(), x2 = r(), y2 = r();
			printf("2 %d %d %d %d\n", x1, y1, x2, y2);
		}
	}
	printf("3\n");

	return 0;
}
