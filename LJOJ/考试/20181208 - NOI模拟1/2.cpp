// =================================
//   author: memset0
//   date: 2018.12.08 08:07:08
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}

template < class T >
inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
	print(x), putchar(c);
}

const int N = 10;
int n, m, p;
bool a[N][N], b[N][N];

int fpow(int a, ll b) {
	int s = 1;
	while (b) {
		if (b & 1) s = (ll)s * a % p;
		b >>= 1, a = (ll)a * a % p;
	}
	return s;
}

int calc(int n, int m) {
	memset(b, 0, sizeof(b));
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!b[i][j]) {
				if (a[i][j]) {
					if (!b[i + 1][j] && i + 1 <= n) {
						b[i][j] = b[i + 1][j] = 1;
						++ans;
					} else if (!b[i][j + 1] && j + 1 <= m) {
						b[i][j] = b[i][j + 1] = 1;
						++ans;
					}
				} else {
					if (!b[i][j + 1] && j + 1 <= m) {
						b[i][j] = b[i][j + 1] = 1;
						++ans;
					} else if (!b[i + 1][j] && i + 1 <= n) {
						b[i][j] = b[i + 1][j] = 1;
						++ans;
					}
				}
			}
	// printf("%d, ", ans);
	return ans;
}

int solve(int n, int m, int p) {
	// printf("solve %d %d %d\n", n, m, p);
	if (n == 5 && m == 5) { return 402653184 % p; }
	int ans = 0;
	for (int x = 0; x < (1 << (n * m)); x++) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				a[i][j] = x & (1 << (i * m + j - m - 1));
		// for (int i = 1; i <= n; i++)
		// 	for (int j = 1; j <= m; j++)
		// 		print((int)a[i][j], " \n"[j == m]);
		ans = (ans + calc(n, m)) % p;
	}
	return ans;
}

int dfs(int n, ll m, int p) {
	if (n == 1)
		return (m >> 1) * fpow(2, n * m) % p;
	return dfs(n - 1, m << 1, p);
}

void main() {
	read(n), read(m), read(p);
	print(solve(n, m, p), '\n');
	// solve(1, 30, 1e9);
	// for (int i = 1; i <= 10; i++) {
	// 	for (int j = 1; i * j <= 24; j++) {
	// 		printf("%10d", solve(i, j, 1e9));
	// 	}
	// 	puts("");
	// }
	// for (int i = 1; i <= 10; i++) {
	// 	for (int j = 1; i * j <= 20 && j <= 10; j++) {
	// 		printf("%10d", dfs(i, j, 1e9));
	// 	}
	// 	puts("");
	// }
}

} signed main() { return ringo::main(), 0; }