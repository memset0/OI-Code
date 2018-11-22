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

const int maxn = 1010;
int n, t, x;
bool tag[maxn][maxn], G[maxn][maxn];

std::vector < int > f[maxn];

void main() {
	read(n);
	for (int i = 1; i <= n; i++)
		for (read(t); t--; ) read(x), p[i].push_back(x);
	for (int u = 1; u <= n; u++) for (auto v : p[u]) tag[u][v] = 1;
	for (int i = 1; i <= n; i++) {
		for (auto u : f[i]) {
			if (u == i) continue;
			for (auto v : f[u])
				if (v != i && v != u && tag[v][i]) {
					if (!G[u][i] && !G[i][u])
						printf(">>> %d %d %d\n", i, u, v);
					G[u][i] = 1;
					break;
				}
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (G[i][j] || G[j][i]) printf("%d %d\n", i, j);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			putc(G[i][j] ? 'x' : 'o');
		putc('\n');
	}
}

} int main() { return ringo::main(), 0; }
