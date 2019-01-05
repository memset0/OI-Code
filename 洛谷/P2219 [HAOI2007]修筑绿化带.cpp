// luogu-judger-enable-o2
// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
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

int n, m, a, b, c, d, x, ll, rr, ans;
int l[maxn], r[maxn];

typedef int matrix[maxn][maxn];
matrix s, f1, f2;

struct pair {
	int v, k;
} q[maxn][maxn], qq[maxn];

inline int calc(int a, int b, int c, int d) { return s[c][d] + s[a - 1][b - 1] - s[c][b - 1] - s[a - 1][d]; }

int main() {
	// freopen("1.in", "r", stdin);

	read(n), read(m), read(a), read(b), read(c), read(d);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			read(x);
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
		}
	for (int i = 1; i + a - 1 <= n; i++)
		for (int j = 1; j + b - 1 <= m; j++)
			f1[i][j] = calc(i, j, i + a - 1, j + b - 1);
	c += 2, d += 2;
	for (int i = 1; i + c - 1 <= n; i++)
		for (int j = 1; j + d - 1 <= m; j++)
			f2[i][j] = calc(i + 1, j + 1, i + c - 2, j + d - 2);
	for (int i = 1; i + c - 1 <= n; i++)
		l[i] = 1;
	for (int j = m + 1 - d; j >= 1; j--) {
		for (int i = n + 1 - c; i >= 1; i--) {
			while (l[i] <= r[i] && q[i][r[i]].v >= f2[i][j]) --r[i];
			q[i][++r[i]] = pair{f2[i][j], j};
			while (l[i] <= r[i] && q[i][l[i]].k - j >= b - d + 1) ++l[i];
		}
		if (j <= m + 1 - b) {
			ll = 1, rr = 0;
			for (int i = n + 1 - c; i >= 1; i--) {
				while (ll <= rr && qq[rr].v >= q[i][l[i]].v) --rr;
				qq[++rr] = pair{q[i][l[i]].v, i};
				while (ll <= rr && qq[ll].k - i >= a - c + 1) ++ll;
				if (i <= n + 1 - a) ans = std::max(ans, f1[i][j] - qq[ll].v);
				// printf("%d %d | %d %d %d | %d %d %d %d \n", i, j, f1[i][j] - qq[ll].v, f1[i][j], qq[ll].v, ll, rr, l[i], r[i]);
			}
		}
	}
	print(ans, '\n');

	return 0;
}