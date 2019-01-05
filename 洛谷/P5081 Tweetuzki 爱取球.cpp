// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.10 23:40:18
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

const int N = 1e7 + 10, p = 20040313;
int n, inv[N];

void main() {
	read(n), inv[1] = 1;
	for (int i = 2; i <= n; i++) inv[i] = (ll)(p - p / i) * inv[p % i] % p;
	for (int i = 2; i <= n; i++) inv[i] = (inv[i] + inv[i - 1]) % p;
	print((ll)inv[n] * n % p, '\n');
}

} signed main() { return ringo::main(), 0; }