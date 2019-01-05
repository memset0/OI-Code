// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.16 14:30:19
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

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

const int p = 1e9 + 7;
int w;
ll n, k;

int fpow(int a, ll b) {
	int s = 1;
	while (b) {
		if (b & 1) s = (ll)s * a % p;
		b >>= 1, a = (ll)a * a % p;
	}
	return s;
}

void main() {
	read(w), read(n), read(k);
	print((ll)w * fpow(5e8 + 4, k) % p, '\n');
}

} signed main() { return ringo::main(), 0; }