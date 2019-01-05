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

const int maxn = 110, maxm = 15;
const int inf = 1000000000;

int n, m, p, nxt, ans = -inf;
int a[maxn][3], s[maxn][3], f[maxn][maxm][maxm];

inline void update(int u, int &v, int k) {
	if (k == 1) u += a[nxt][1];
	else if (k == 2) u += a[nxt][2];
	else if (k == 3) u += a[nxt][1] + a[nxt][2];
	v = std::max(v, u);
}

int main() {
	// freopen("1.in", "r", stdin);

	read(n), read(m), read(p);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(a[i][j]);
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++)
			s[i][j] = s[i - 1][j] + a[i][j]; 
	}
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxm; j++)
			for (int k = 0; k < maxm; k++)
				f[i][j][k] = -inf;
	if (m == 1) {
		f[1][0][0] = 0, f[1][1][1] = a[1][1];
		for (int i = 2; i <= n; i++) {
			for (int k = 0; k <= p; k++) {
				f[i][k][0] = std::max(f[i - 1][k][0], f[i - 1][k][1]);
				f[i][k][1] = std::max(f[i - 1][k][1], k ? f[i - 1][k - 1][0] : -inf) + a[i][1];
			}
		}
		for (int i = 0; i <= p; i++)
			ans = std::max(ans, std::max(f[n][i][0], f[n][i][1]));
		print(ans, '\n');
	} else {
		f[0][0][0] = 0;
		for (int i = 0; i <= n; i++) {
			for (int k = 0; k <= p; k++) {
				nxt = i + 1;
				f[i][k][5] = std::max(f[i][k][0],
						std::max(f[i][k][1],
						std::max(f[i][k][2],
						std::max(f[i][k][3],
						f[i][k][4]))));
				update(f[i][k][5], f[i + 1][k][0], 0);
				update(f[i][k][5], f[i + 1][k + 1][1], 1);
				update(f[i][k][5], f[i + 1][k + 1][2], 2);
				update(f[i][k][5], f[i + 1][k + 2][3], 3);
				update(f[i][k][5], f[i + 1][k + 1][4], 3);
				update(f[i][k][1], f[i + 1][k][1], 1);
				update(f[i][k][3], f[i + 1][k][1], 1);
				update(f[i][k][2], f[i + 1][k][2], 2);
				update(f[i][k][3], f[i + 1][k][2], 2);
				update(f[i][k][1], f[i + 1][k + 1][3], 3);
				update(f[i][k][2], f[i + 1][k + 1][3], 3);
				update(f[i][k][3], f[i + 1][k][3], 3);
				update(f[i][k][4], f[i + 1][k][4], 3);
			}
		}
		// for (int i = 1; i <= n; i++) {
		// 	for (int j = 0; j <= p; j++)
		// 		printf("(%d %d %d %d %d %d) ", f[i][j][0], f[i][j][1], f[i][j][2], f[i][j][3], f[i][j][4], f[i][j][5]);
		// 	puts("");
		// }
		for (int i = 0; i <= p; i++)
			ans = std::max(ans, f[n][i][5]);
		print(ans, '\n');
	}

	return 0;
}

// 00 => 0
// 10 => 1
// 01 => 2
// 12 => 3
// 11 => 4