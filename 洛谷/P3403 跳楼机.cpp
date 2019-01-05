// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.07 20:31:35
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

const int N = 1e5 + 10;
int x, y, z, u, v, l, r;
int q[N * 16], dis[N];
bool inq[N];
ll h, ans;

void main() {
	memset(dis, -1, sizeof dis);
	read(h), read(x), read(y), read(z);
	if (x < y) std::swap(x, y);
	if (x < z) std::swap(x, z);
	if (y < z) std::swap(y, z);
	dis[1] = 0, q[r++] = 1;
	while (l < r) {
		u = q[l++], inq[u] = 0;
		if (y != x) {
			if (u + y < x) {
				v = u + y;
				if (dis[v] == -1 || dis[v] > dis[u]) {
					dis[v] = dis[u];
					// printf("%d[%d] -> %d[%d]\n", u, dis[u], v, d	is[v]);
					if (!inq[v]) q[r++] = v, inq[v] = 1;
				}
			} else {
				v = u + y - x;
				if (dis[v] == -1 || dis[v] > dis[u] + 1) {
					dis[v] = dis[u] + 1;
					// printf("%d[%d] -> %d[%d]\n", u, dis[u], v, dis[v]);
					if (!inq[v]) q[r++] = v, inq[v] = 1;
				}
			}
		}
		if (z != x) {
			if (u + z < x) {
				v = u + z;
				if (dis[v] == -1 || dis[v] > dis[u]) {
					dis[v] = dis[u];
					// printf("%d[%d] -> %d[%d]\n", u, dis[u], v, dis[v]);
					if (!inq[v]) q[r++] = v, inq[v] = 1;
				}
			} else {
				v = u + z - x;
				if (dis[v] == -1 || dis[v] > dis[u] + 1) {
					dis[v] = dis[u] + 1;
					// printf("%d[%d] -> %d[%d]\n", u, dis[u], v, dis[v]);
					if (!inq[v]) q[r++] = v, inq[v] = 1;
				}
			}
		}
	}
	for (int i = 0; i < x; i++)
		if (~dis[i] && h >= (ll)dis[i] * x + i) {
			// printf("> %d %d : %lld\n", i, dis[i], (h - i) / x + 1);
			ans += std::max(0ll, (h - i) / x + 1 - dis[i]);
		}
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }