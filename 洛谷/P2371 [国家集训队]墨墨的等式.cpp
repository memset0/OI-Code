// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.07 22:10:52
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

const int N = 15, M = 5e5 + 10;
int n, m, b, l, r, u, v, c;
int a[N], dis[M], q[N * M * 2];
bool inq[M];
ll L, R, ans;

void spfa() {
	memset(dis, -1, sizeof(dis));
	dis[0] = 0, q[l = r = 1] = 0;
	while (l <= r) {
		u = q[l++], inq[u] = 0;
		for (int i = 1; i <= n; i++) {
			v = (u + a[i]) % b, c = (u + a[i]) / b;
			if (dis[v] == -1 || dis[v] > dis[u] + c) {
				dis[v] = dis[u] + c;
				if (!inq[v]) q[++r] = v, inq[v] = 1;
			}
		}
	}
}

ll solve(ll limit) {
	ll ans = 0;
	// printf("===== solve %lld =====\n", limit);
	for (int i = 0; i < b; i++)
		if (~dis[i] && limit >= (ll)dis[i] * b + i) {
			ans += (limit - i) / b + 1 - dis[i];
		}
	// printf(">>> %lld\n", ans);
	return ans;
}

void main() {
	read(n), read(L), read(R);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	std::sort(a + 1, a + n + 1);
	n = std::unique(a + 1, a + n + 1) - a - 1;
	b = a[n--];
	spfa();
	ans = solve(R) - solve(L - 1);
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }