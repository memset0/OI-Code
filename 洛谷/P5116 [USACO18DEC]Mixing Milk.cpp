// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.24 13:05:28
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

std::pair <int, int> a[3];

void solve(std::pair <int, int> &x, std::pair <int, int> &y) {
	int dta = std::min(y.first - y.second, x.second);
	x.second -= dta, y.second += dta;
}

void main() {
	for (int i = 0; i < 3; i++) read(a[i].first), read(a[i].second);
	for (int t = 0; t < 33; t++) solve(a[0], a[1]), solve(a[1], a[2]), solve(a[2], a[0]);
	solve(a[0], a[1]);
	for (int i = 0; i < 3; i++) print(a[i].second, '\n');
}

} signed main() { return ringo::main(), 0; }