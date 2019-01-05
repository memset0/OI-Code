// luogu-judger-enable-o2
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

const int N = 5e4 + 10, M = 2e2 + 10, mod = 1e9 + 7;
int n, m, a, b, t, ans;
int c[M][M], s[N][M];

void main() {
	s[1][1] = 1;
	for (int i = 0; i <= 200; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}
	for (int i = 2; i <= 50000; i++) {
		for (int j = 1; j <= i && j <= 200; j++)
			s[i][j] = ((ll)(i - 1) * s[i - 1][j] + s[i - 1][j - 1]) % mod;
	}
	for (read(t); t--;) {
		read(n), read(a), read(b);
		if (n == 1 && a == 1 && b == 1) { puts("1"); continue; }
		// printf("%d %d\n", s[n - 1][a + b - 2], c[a + b - 2][a - 1]);
		print((ll)s[n - 1][a + b - 2] * c[a + b - 2][a - 1] % mod, '\n');
	}
}

} signed main() { return ringo::main(), 0; }