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

const int maxn = 202, maxm = 10006;
int n, m, x, y, fl, ans, sum;
int a[maxn][5], b[maxn][5], f[2][maxm][5][5];

inline void max(int &a, int b) {
	a = std::max(a, b);
}

int main() {
	// freopen("1.in", "r", stdin);
	memset(f, -1, sizeof(f));
	read(n);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 5; j++)
			read(a[i][j]);
	read(m);
	for (int i = 1; i <= m; i++) {
		read(x), read(y), --y;
		b[x][y] = 1;
		// printf("%d %d\n", x, y);
	}
	sum = 4, f[1][4][2][2] = 0;
	for (int t = 1; t <= n; t++) {
		fl ^= 1;
		for (int i = 0; i < 5; i++)
			if (a[t][i] > 0)
				sum += a[t][i];
		// for (int i = sum; i >= 0; i--)
		// 	for (int k = 0; k < 5; k++)
		// 		if (~f[fl][i][k][k])
		// 			printf("%d %d %d => %d %d\n", t, k, k, i, f[fl][i][k][k]);
		for (int len = 2; len <= 5; len++)
			for (int l = 0, r = l + len - 1; r < 5; l++, r++)
				for (int i = sum; i >= 0; i--) {
					for (int x = 0; x ^ 2; x++) {
						if (x && b[t][l]) { continue; }
						if (!x && b[t][r - 1]) { continue; }
						int val = x ? a[t][l] : a[t][r];
						if (i - val < 0) continue;
						int &from = (x ? f[fl][i - val][l + 1][r] : f[fl][i - val][l][r - 1]);
						if (!~from) continue;
						if (val == 0) {
							max(f[fl][i][l][r], from);
						} else if (val > 0) {
							max(f[fl][i][l][r], from);
						} else {
							max(f[fl][i][l][r], from - val);
							max(ans, from - val);
						}
					}
					// if (~f[fl][i][l][r])
					// 	printf("%d %d %d => %d %d\n", t, l, r, i, f[fl][i][l][r]);
				}
		memset(f[fl ^ 1], -1, sizeof(f[fl ^ 1]));
		if (t == n) break;
		for (int len = 1; len <= 5; len++)
			for (int l = 0, r = l + len - 1; r < 5; l++, r++)
				for (int i = 0; i <= sum; i++)
					if (~f[fl][i][l][r]) {
						for (int k = l; k <= r; k++) {
							int val = a[t + 1][k];
							if (val == 0) {
								max(f[fl ^ 1][i][k][k], f[fl][i][l][r]);
							} else if (val < 0) {
								if (i + val < 0) continue;
								max(f[fl ^ 1][i + val][k][k], f[fl][i][l][r] - val);
								max(ans, f[fl ^ 1][i + val][k][k]);
							} else {
								max(f[fl ^ 1][i + val][k][k], f[fl][i][l][r]);
							}
						}
					}
		// printf(">>> %d\n", ans);
		// for (int i = 0; i <= sum; i++) {
		// 	for (int l = 0; l < 5; l++)
		// 		for (int r = l; r < 5; r++)
		// 			print(f[fl][i][l][r]);
		// 	putc('\n');
		// }
	}
	print(ans, '\n');
	return 0;
}