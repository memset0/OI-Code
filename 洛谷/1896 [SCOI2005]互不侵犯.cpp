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

int n, m, flag;
ll ans, f[10][1024][100];

int main() {
	
	read(n), read(m);
	f[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int x = 0; x < (1 << n); x++) {
			flag = 0;
			for (int j = 1; j < n; j++)
				if ((x & (1 << (j - 1)) && (x & (1 << j)))) {
					flag = 1;
					break;
				}
			if (flag) continue;
			for (int y = 0; y < (1 << n); y++) {
				flag = x & y;
				for (int j = 1; j < n && !flag; j++)
					if (((x & (1 << (j - 1))) || (y & (1 << (j - 1)))) && ((x & (1 << j)) || (y & (1 << j))))
						flag = 1;
				if (flag) continue;
				int cnt = __builtin_popcount(y);
				for (int j = cnt; j <= m; j++) {
					f[i][y][j] += f[i - 1][x][j - cnt];
//					if (f[i - 1][x][j - cnt]) {
////						printf("%d %d %d %d %d\n", i, j, x, y, cnt);
//						printf("f[%d][%d][%d](%d) += f[%d][%d][%d](%d)\n",
//							i, y, j, f[i][y][j],
//							i - 1, x, j - cnt, f[i - 1][x][j - cnt]
//							);
//					}
				}
			}
		}
	} 
	for (int i = 0; i < (1 << n); i++)
		ans += f[n][i][m];
	printf("%lld\n", ans);
	
	return 0;
}
