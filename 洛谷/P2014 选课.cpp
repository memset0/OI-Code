// luogu-judger-enable-o2
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

const int maxn = 310;
int n, m, ans;
int fa[maxn], val[maxn];
int g[maxn], f[maxn][maxn];
std::vector < int > son[maxn];

void dfs(int u) {
	// printf("dfs %d\n", u);
	f[u][u ? 1 : 0] = val[u];
	for (auto v : son[u]) {
		dfs(v);
		// printf("%d -> %d\n", u, v);
		// for (int i = 0; i <= m; i++)
		// 	print(f[u][i]), putc(i == m ? '\n' : ' ');
		for (int i = 0; i <= m; i++)
			g[i] = f[u][i];
		for (int i = (u ? 1 : 0); i <= m; i++)
			for (int j = 1; i + j <= m; j++)
				g[i + j] = std::max(g[i + j], f[u][i] + f[v][j]);
		// for (int i = 0; i <= m; i++)
		// 	print(g[i]), putc(i == m ? '\n' : ' ');
		for (int i = 0; i <= m; i++)
			f[u][i] = g[i];
	}
}

void main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(fa[i]), read(val[i]);
		son[fa[i]].push_back(i);
	}
	dfs(0);
	for (int i = 0; i <= m; i++)
		ans = std::max(ans, f[0][i]);
	// for (int i = 0; i <= n; i++) {
	// 	for (int j = 0; j <= m; j++)
	// 		print(f[i][j]), putc(' ');
	// 	puts("");
	// }
	print(ans), putc('\n');
}

} int main() { return ringo::main(), 0; }