// =================================
//   author: memset0
//   date: 2018.12.11 08:10:25
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef __int128 ll;

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

const int N = 2e3 + 10, p = 1e9 + 7;
int n, m, ans;
int a[N];
ll f[1 << 20];
short lg2[1 << 20];

template < class T >
inline T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

template < class T >
inline T lcm(T a, T b) {
	return a / gcd(a, b) * b;
}

void main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) lg2[1 << (i - 1)] = i;
	f[0] = 1;
	for (int i = 1; i < (1 << n); i++) {
		f[i] = lcm(f[i - (i & -i)], (ll)a[lg2[i & -i]]);
		ans = (ans + f[i]) % p;
	}
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }