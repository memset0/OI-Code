// luogu-judger-enable-o2
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

const int N = 1e4 + 10, mod = 1e9 + 7;
int n, m, x, u, v, rt, ans[N], siz[N];
int tot = 2, hed[N], to[N << 1], nxt[N << 1];

void dfs(int u, int father) {
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != father) {
			// printf("%d -> %d\n", u, v);
			dfs(v, u);
			ans[u] += (ll)siz[u] * siz[v] % mod;
			siz[u] += siz[v];
		}
	++siz[u], ans[u] <<= 1, ans[u] += (siz[u] << 1) - 1;
}

void main() {
	read(n), read(rt), read(m);
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
	dfs(rt, 0);
	// for (int i = 1; i <= n; i++) print(siz[i], " \n"[i == n]);
	// for (int i = 1; i <= n; i++) print(ans[i], " \n"[i == n]);
	for (int i = 1; i <= m; i++)
		print(ans[read(x), x], '\n');
}

} signed main() { return ringo::main(), 0; }