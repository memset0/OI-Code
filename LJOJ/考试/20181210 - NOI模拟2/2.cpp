// =================================
//   author: memset0
//   date: 2018.12.10 08:34:33
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

const int P = 1e9 + 7;
int T, n, m, k, ans;

int inv(int x) {
	if (!x || x == 1) return 1;
	return (ll)(P - P / x) * inv(P % x) % P;
}

void main() {
	for (read(T); T--; ) {
		read(n), read(m), read(k);
		ans = (ll)n * inv(m) % P * inv(k) % P;
		print(ans, '\n');
	}
}

} signed main() { return ringo::main(), 0; }