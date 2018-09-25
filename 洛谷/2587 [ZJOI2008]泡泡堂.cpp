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

const int maxn = 100010;

int n, al, ar, bl, br, ans;
int a[maxn], b[maxn];

int solve() {
	al = bl = 1, ar = br = n, ans = 0;
//	for (int i = al; i <= ar; i++)
//		print(a[i], ' ');
//	putc('\n');
//	for (int i = bl; i <= br; i++)
//		print(b[i], ' ');
//	putc('\n');
	while (al <= ar) {
		while (al <= ar && a[al] > b[bl]) ++al, ++bl, ans += 2;
		while (al <= ar && a[ar] > b[br]) --ar, --br, ans += 2;
		if (al <= ar) {
			if (a[al] ==  b[br]) ans += 1;
			++al, --br;
		}
	}
	return ans;
}

int main() {

	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		read(b[i]);
	std::sort(a + 1, a + n + 1);
	std::sort(b + 1, b + n + 1);
	
	print(solve(), ' ');
	std::swap(a, b);
	print((n << 1) - solve());
	
	return 0;
}
