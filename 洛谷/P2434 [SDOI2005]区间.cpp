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
template <typename T> inline void print(T x, char c = '\n') {
	static int buf[40];
	if (x == 0) { putc('0'); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 50010, maxm = 1000010;

int n, m = 1e6, l, r, cnt;
int a[maxm], b[maxm];

int main() {
	
	read(n);
	for (int i = 1; i <= n; i++) {
		read(l), read(r);
		a[l]++, b[r]++;
	}
	
	for (int i = 1; i <= m; i++) {
		if (!cnt && a[i]) printf("%d ", i);
		cnt += a[i] - b[i];
		if (!cnt && b[i]) printf("%d\n", i);
	}
	
	return 0;
}