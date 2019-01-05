// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
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

const int maxn = 1000010;

int n, ans;
int a[maxn];
int f[maxn][3];

int min(int a, int b) {
	if (!~a) return b;
	if (!~b) return a;
	return std::min(a, b);
}

int main() {
	memset(f, -1, sizeof(f));

	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	
	f[1][a[1] + 1] = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] == -1) {
			f[i][0] = f[i - 1][0];
//			f[i][1] = ~f[i - 1][2] ? f[i - 1][2] + 1 : -1;
			f[i][2] = ~f[i - 1][2] ? f[i - 1][2] + 2 : -1;
		} else if (a[i] == 0) {
			f[i][0] = ~f[i - 1][0] ? f[i - 1][0] + 1 : -1;
			f[i][1] = min(f[i - 1][0], f[i - 1][1]);
			f[i][2] = ~f[i - 1][2] ? f[i - 1][2] + 1 : -1;
		} else {
			f[i][0] = ~f[i - 1][0] ? f[i - 1][0] + 2 : -1;
			f[i][1] = ~f[i - 1][0] ? f[i - 1][0] + 1 : -1;
			f[i][2] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2]));
		}
	}
	
//	for (int i = 1; i <= n; i++)
//		printf("%d %d %d\n", f[i][0], f[i][1], f[i][2]);
	ans = min(f[n][0], min(f[n][1], f[n][2]));
	if (~ans) print(ans, endl);
	else puts("BRAK");

	return 0;
}