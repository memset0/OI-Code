// =================================
//   author: memset0
//   date: 2018.12.10 10:50:00
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

const int n = 300, m = 2000, lim = 1000000000;

int rand(int x) { return ::rand() % x + 1; }

void main() {
	srand(time(0) + clock());
	printf("%d %d\n", n, m);
	for (int i = 1; i <= m; i++)
		printf("%d %d %d\n", rand(n), rand(n), rand(lim));
}

} signed main() { return ringo::main(), 0; }