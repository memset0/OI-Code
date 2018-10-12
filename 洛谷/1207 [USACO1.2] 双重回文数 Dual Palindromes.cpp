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

int n, s, ans, cnt, top;
int a[1000];

int check(int x, int c) {
	top = 0;
	while (x) {
		a[++top] = x % c;
		x /= c;
	}
	for (int i = 1; i <= top; i++)
		if (a[i] != a[top + 1 - i])
			return 0;
	return 1;
}

int main() {
	
	read(n), read(s);
	for (int i = s + 1; ans < n; i++) {
		cnt = 0;
		for (int j = 2; j <= 10; j++)
			cnt += check(i, j);
		if (cnt >= 2) {
			ans++;
			print(i, '\n');
		}
	}

	return 0;
}

