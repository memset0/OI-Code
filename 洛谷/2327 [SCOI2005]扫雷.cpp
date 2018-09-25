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
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}	

const int maxn = 10010;

int n, ans;
int a[maxn], b[maxn];

int check() {
	for (int i = 2; i <= n; i++) {
		b[i] = a[i - 1] - b[i - 1] - b[i - 2];
		if (b[i] < 0 || b[i] > 1) return 0;
	}
	if (a[n] != b[n] + b[n - 1]) return 0;
	return 1;
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);

	ans += check();
	b[1] = 1;
	ans += check();
	print(ans);

	return 0;
}
