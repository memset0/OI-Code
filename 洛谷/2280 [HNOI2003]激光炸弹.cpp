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
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 5010;

int n, m, x, y, z, mx, my, ans;
int s[maxn][maxn];

int main() {
//	freopen("INPUT", "r", stdin);
	
	read(n), read(m);
	mx = my = m;
	for (int i = 1; i <= n; i++) {
		read(x), read(y), read(z);
		++x, ++y; 
		s[x][y] += z;
		mx = std::max(mx, x);
		my = std::max(my, y);
	}
	for (int i = 1; i <= mx; i++)
		for (int j = 1; j <= my; j++)
			s[i][j] = s[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
	for (int i = m; i <= mx; i++)
		for (int j = m; j <= my; j++) {
			ans = std::max(ans, s[i][j] - s[i][j - m] - s[i - m][j] + s[i - m][j - m]);
//			printf("%d %d -> %d\n", i, j, s[i][j] - s[0][j - m] - s[i - m][0] + s[i - m][j - m]);
		}
//	for (int i = 0; i <= mx; i++) { 
//		for (int j = 0; j <= my; j++)
//			printf("%d ", s[i][j]);
//		puts("");
//	}
	printf("%d\n", ans);

	return 0;
}

