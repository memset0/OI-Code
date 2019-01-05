// =================================
//   author: memset0
//   date: 2018.12.25 22:11:27
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

const int N = 1e5 + 10;
int n, m, a[N], b[N];
char s[N];

void main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		switch (s[i]) {
			case 'b': a[i] = 0; break;
			case 'p': a[i] = 1; break;
			case 'd': a[i] = 2; break;
			case 'q': a[i] = 3; break;
		}
	for (int i = 1; i <= n; i++) b[i] = a[i];
	std::reverse(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) b[i] = (b[i] + 2) % 4;
	for (int i = 1; i <= n; i++)
		if (a[i] != b[i]) {
			puts("No");
			return;
		}
	puts("Yes");
}

} signed main() { return ringo::main(), 0; }