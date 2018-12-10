// =================================
//   author: memset0
//   date: 2018.12.10 09:26:57
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

const int N = 1e3 + 10, P = 998244353;
int T, n;
ll a[N], f[N << 1], g[N << 1];

void main() {
	for (read(T); T--; ) {
		read(n);
		for (int i = 1; i <= n; i++) read(a[i]);
		if (n == 1) {
			if (a[1] == 0) printf("%d %d %d \n", 0, 0, 0);
			else if (a[1] == 1) printf("%d %d %d \n", 0, 0, 1);
			else printf("%lld %d %d \n", a[1] - 2, 2, 0);
			continue;
		}
		memset(f, 0, sizeof(f));
		if (a[1] == 1) f[2] = 1;
		else f[0] = a[1] - 2, f[1] = 2;
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <= n << 1; j++) g[j] = f[j];
			w(f, 0, sizeof(f));
			if (a[i] == 0) { memset(f, 0, sizeof(f)); break; }
			if (a[i] == 1) {
				for (int j = 0; j <= n << 1; j++)
					(f[j + 2] += g[j]) %= P;
			} else {
				for (int j = 0; j <= n << 1; j++) {
					(f[j + 1] += g[j] << 1) %= P;
					f[j] = (f[j] + (ll)g[j] * (a[i] - 2)) % P;
				}
			}
		}
		for (int j = 0; j <= n << 1; j++)
			print(f[j], ' '); puts("");
	}
}

} signed main() { return ringo::main(), 0; }