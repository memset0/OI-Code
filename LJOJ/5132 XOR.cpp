// =================================
//   author: memset0
//   date: 2018.12.11 15:58:09
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define int long long
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

const int N = 1e5 + 10, M = 2e5 + 10;
int n, m, u, v, w, ans, f[N];

struct node {
	int w, v, i;
	inline bool operator < (const node &other) const {
		return w > other.w;
	}
} a[N];

bool check(int x) {
	for (int i = 62; i >= 0; i--)
		if (x & (1 << i)) {
			if (!f[i]) return false;
			x ^= f[i];
		}
	return true;
}

void insert(int x) {
	for (int i = 62; i >= 0; i--)
		if (x & (1 << i)) {
			if (f[i]) x ^= f[i];
			else { f[i] = x; return; }
		}
}

void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i].w), a[i].i = i;
	for (int i = 1; i <= m; i++) {
		read(u), read(v), read(w);
		a[u].v ^= w, a[v].v ^= w;
	}
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		if (check(a[i].v)) ans -= a[i].w;
		else ans += a[i].w, insert(a[i].v);
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }	
