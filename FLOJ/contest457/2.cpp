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

const int N = 45, M = 105, mod = 1e9 + 7;
int n, m, i, ans, len, lim;
int a[N], per[N], C[M + N][N];

int calc(int x) {
	if (x < 0) return 0;
	if (x == 0) return 1;
	// printf(">> %d : %d %d : %d\n", x, x + n, n, C[x + n][n]);
	return C[x + n][n];
}

void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) read(a[i]);
	std::sort(a + 1, a + n + 1);
	for (int i = 0; i <= m + n; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= std::min(i, n); j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	for (lim = 1, i = 1; i <= n; i++) per[i] = i, lim *= i;
	while (lim--) {
		len = 0;
		for (int i = 1; i < n; i++)
			len += std::max(a[per[i]], a[per[i + 1]]);
		ans = (ans + calc(m - len - 1)) % mod;
		std::next_permutation(per + 1, per + n + 1);
	}
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }