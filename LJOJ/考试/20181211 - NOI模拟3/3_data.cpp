// =================================
//   author: memset0
//   date: 2018.12.11 09:26:16
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

const int n = 1000, p = 1000;
int m, cnt, a[n + 1], b[n + 1], t[n + 1];
std::set < int > set;

inline int rand(int x) { return ::rand() % x + 1; }

void main() {
	srand(time(0) + clock());
	printf("%d %d\n", n, p);
	for (int i = 1, op, k, v, flag; i <= p; i++) {
		if (!m) op = 1;
		else if (cnt == n) op = 2;
		else op = ::rand() % 4 ? 1 : 2;
		print(op, ' ');
		if (op == 1) {
			do {
				k = rand(n);
			} while (t[k]);
			do {
				v = rand(10);
			} while (set.count(v - i));
			++cnt, set.insert(v - i), t[k] = 1, b[++m] = k;
			print(k, ' '), print(v, '\n');
		} else {
			print(k = rand(m), '\n');
			std::swap(b[k], b[m]), --m;
		}
	}
}

} signed main() { return ringo::main(), 0; }