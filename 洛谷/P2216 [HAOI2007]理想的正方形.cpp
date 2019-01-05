// luogu-judger-enable-o2
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

const int maxn = 1010;

int n, m, p, ans, min, max;
int a[maxn][maxn], gmin[maxn][maxn], gmax[maxn][maxn];

int main() {
	// freopen("1.in", "r", stdin);

	read(n), read(m), read(p);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j + p - 1 <= m; j++) {
			gmin[i][j] = gmax[i][j] = a[i][j];
			for (int k = j + 1; k <= j + p - 1; k++) {
				gmin[i][j] = std::min(gmin[i][j], a[i][k]);
				gmax[i][j] = std::max(gmax[i][j], a[i][k]);
			}
		}
	ans = -1;
	for (int i = 1; i + p - 1 <= n; i++)
		for (int j = 1; j + p - 1 <= m; j++) {
			min = gmin[i][j], max = gmax[i][j];
			for (int k = i + 1; k <= i + p - 1; k++) {
				min = std::min(min, gmin[k][j]);
				max = std::max(max, gmax[k][j]);
			}
			ans = ~ans && ans < (max - min) ? ans : max - min;
		}
	// for (int i = 1; i + p - 1 <= n; i++) {
	// 	for (int j = 1; j + p - 1 <= m; j++)
	// 		printf("(%d %d) ", gmin[i][j], gmax[i][j]);
	// 	putc('\n');
	// }
	print(ans, '\n');

	return 0;
}