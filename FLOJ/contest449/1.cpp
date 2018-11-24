#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

const int maxn = 2010;
int n, a, b, q;
typedef int arr[maxn]; arr k, c, y, z, h, s;
std::vector < int > G[maxn];

void dfs(int u, char c) {
	s[u] = c;
	for (auto v : G[u]) if (s[v] != c) dfs(v, c);
}

void main() {
	read(n), read(a), read(b), read(q), y[b + 1] = n + 1;
	for (int i = 1; i <= a; i++) read(k[i]), c[i] = getc();
	for (int i = 1; i <= b; i++) read(y[i]), read(h[i]);
	for (int i = 1; i <= q; i++) read(z[i]);
	for (int i = 1; i <= b; i++) {
		if (!h[i]) continue;
//		printf("===== %d %d (%d) =====\n", y[i], h[i], y[i + 1]);
		for (int p = y[i], q = h[i]; p < y[i + 1] && q < h[i] + y[i + 1] - y[i]; ++p, ++q)
//			printf("%d <-> %d\n", p, q), 
			G[p].push_back(q), G[q].push_back(p);
	}
	for (int i = 1; i <= a; i++) dfs(k[i], c[i]);
	for (int i = 1; i <= q; i++) putc(s[z[i]] ? s[z[i]] : '?');
	putc('\n');
}

} int main() { return ringo::main(), 0; }
