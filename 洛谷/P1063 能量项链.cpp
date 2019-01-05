// luogu-judger-enable-o2
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

const int maxn = 210;
int n, ans;
int a[maxn], f[maxn][maxn];

void main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]), a[n + i] = a[i];
	// for (int i = 1; i <= n * 2; i++)
	// 	print(a[i]), putc(i == n * 2 ? '\n' : ' ');
	for (int len = 3; len <= n + 1; len++)
		for (int l = 1, r = len; r <= n * 2; l++, r++)
			for (int i = l + 1; i <= r - 1; i++) {
				// printf("%d %d %d : %d %d %d : %d\n", l, i, r, a[l], a[i], a[r], f[l][i] + f[i][r] + a[l] * a[i] * a[r]);
				f[l][r] = std::max(f[l][r], f[l][i] + f[i][r] + a[l] * a[i] * a[r]);
			}
	// for (int i = 1; i <= n * 2; i++) {
	// 	for (int j = 1; j <= n * 2; j++) 
	// 		printf("%4d", f[i][j]);
	// 	puts("");
	// }
	for (int l = 1, r = n + 1; r <= n * 2; l++, r++)
		ans = std::max(ans, f[l][r]);
	print(ans), putc('\n');
}

} int main() { return ringo::main(), 0; }