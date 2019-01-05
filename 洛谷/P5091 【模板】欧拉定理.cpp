// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.19 16:17:36
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
namespace ringo {
typedef long long ll;
typedef unsigned long long ull;
template <class T> inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void maxd(T &a, T b) { if (b > a) a = b; }
template <class T> inline void mind(T &a, T b) { if (b < a) a = b; }
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline T abs(const T &a) { if (a < 0) return -a; return a; }

int a, m, b, s, c, i, t, flag;

void main() {
	read(a), read(m);
	for (i = 2, t = s = m; i * i <= t; i++)
		if (t % i == 0) {
			s = s - s / i;
			while (t % i == 0)
				t /= i;
		}
	if (t != 1) s = s - s / t;
	while (true) {
		c = getchar();
		while (!isdigit(c)) {
			c = getchar();
			if (c == EOF) break;
		}
		if (c == EOF) break;
		b = b * 10 + c - '0';
		if (b >= s) b %= s, flag = true;
	}
	if (s != m - 1 && flag) b += s;
	s = 1;
	while (b) {
		if (b & 1) s = (ll)s * a % m;
		a = (ll)a * a % m, b >>= 1;
	}
	print(s, '\n');
}

} signed main() { return ringo::main(), 0; }