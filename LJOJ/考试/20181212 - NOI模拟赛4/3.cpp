// =================================
//   author: memset0
//   date: 2018.12.13 12:54:05
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T > inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template < class T > inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template < class T > inline void maxd(T &a, T b) { if (b > a) a = b; }
template < class T > inline void mind(T &a, T b) { if (b < a) a = b; }
template < class T > inline void print(T x, char c) { print(x), putchar(c); }

int p, n, m;

void output(int n) {
	printf("%d\n", n);
	if (n < 200) {
		for (int i = 1; i <= n; i++)
			print(i, " \n"[i == n]);
	} else {
		for (int i = 1; i <= 100; i++)
			print(i, ' ');
		for (int i = n - 100 + 1; i <= n; i++)
			print(i, " \n"[i == n]);
	}
}

void main() {
	read(p), read(n), read(m);
	if (p == 0) {
		puts("0.000000");
		output(n);
	} else if (p == 100) {
		puts("1.000000");
		output(m - n);
	}
}

} signed main() { return ringo::main(), 0; }