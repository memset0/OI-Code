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

const int maxn = 2010;
int n, m, ans1, ans2;
typedef int matrix[maxn][maxn];
matrix a, pl, pr, up;

void print(const matrix &a) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)	
			print(a[i][j]);
		puts("");
	}
}

int main() {
	// freopen("1.in", "r", stdin);
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(a[i][j]);
	for (int i = 1; i <= n; i++)
		pl[i][1] = pr[i][m] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 2; j <= m; j++)
			pl[i][j] = a[i][j] == a[i][j - 1] ? 1 : pl[i][j - 1] + 1;
	for (int i = 1; i <= n; i++)
		for (int j = m - 1; j >= 1; j--)
			pr[i][j] = a[i][j] == a[i][j + 1] ? 1 : pr[i][j + 1] + 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (a[i][j] ^ a[i - 1][j] && i ^ 1) {
				pl[i][j] = std::min(pl[i][j], pl[i - 1][j]);
				pr[i][j] = std::min(pr[i][j], pr[i - 1][j]);
				up[i][j] = up[i - 1][j] + 1;
			} else {
				up[i][j] = 1;
			}
			int a = up[i][j], b = pl[i][j] + pr[i][j] - 1;
			ans2 = std::max(ans2, a * b);
			a = std::min(a, b);
			ans1 = std::max(ans1, a * a);
		}
	// print(a), print(up), print(pl), print(pr);
	print(ans1, '\n'), print(ans2, '\n');
	return 0;
}