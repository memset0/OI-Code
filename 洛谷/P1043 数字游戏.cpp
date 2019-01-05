#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

const int maxn = 110, maxm = 10;
int n, m, ans1, ans2;
int a[maxn], s[maxn];
int f[maxn][maxn][maxm], g[maxn][maxn][maxm];

int calc(int l, int r) {
	return ((s[r] - s[l - 1]) % 10 + 10) % 10;
}

void main() {
	memset(f, -1, sizeof(f));
	memset(g, -1, sizeof(g));

	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]), a[n + i] = a[i];
	for (int i = 1; i <= (n << 1); i++)
		s[i] = s[i - 1] + a[i];
	// for (int i = 1; i <= (n << 1); i++)
	// 	printf("%d ", s[i]);
	// puts("");
	for (int len = 1; len <= n; len++)
		for (int l = 1, r = len; r <= (n << 1); l++, r++) {
			f[l][r][1] = g[l][r][1] = calc(l, r);
			for (int k = l; k < r; k++)
				for (int i = 1; i <= m; i++)
					for (int j = 1; i + j <= m; j++) {
						f[l][r][i + j] = std::max(f[l][r][i + j], f[l][k][i] * f[k + 1][r][j]);
						if (g[l][k][i] == -1 || g[k + 1][r][j] == -1) continue;
						if (g[l][r][i + j] == -1) g[l][r][i + j] = g[l][k][i] * g[k + 1][r][j];
						else g[l][r][i + j] = std::min(g[l][r][i + j], g[l][k][i] * g[k + 1][r][j]);
					}
		}
	ans1 = ans2 = -1;
	for (int i = 1; i <= n; i++) {
		ans1 = std::max(f[i][i + n - 1][m], ans1);
		if (ans2 == -1) ans2 = g[i][i + n - 1][m];
		else ans2 = std::min(g[i][i + n - 1][m], ans2);
	}
	// for (int i = 1; i <= (n << 1); i++) {
	// 	for (int j = 1; j <= (n << 1); j++)
	// 		printf("(%d %d) ", calc(i, j), s[j] - s[i - 1]);
	// 	puts("");
	// }
	// puts("");
	// for (int k = 1; k <= m; k++) {
	// 	for (int i = 1; i <= (n << 1); i++) {
	// 		for (int j = 1; j <= (n << 1); j++)
	// 			printf("(%d %d) ", f[i][j][k], g[i][j][k] >= g[0][0][0] ? -1 : g[i][j][k]);
	// 		puts("");
	// 	}
	// 	puts("");
	// }
	print(ans2), putc('\n');
	print(ans1), putc('\n');
}

} int main() { return ringo::main(), 0; }