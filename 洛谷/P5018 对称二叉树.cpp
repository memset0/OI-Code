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

const int maxn = 1e6 + 10;
int n, u, v, ans = 1;
int siz[maxn], val[maxn], ch[maxn][2];

void prepare(int u) {
	siz[u] = 1;
	if (~ch[u][0]) prepare(ch[u][0]), siz[u] += siz[ch[u][0]];
	if (~ch[u][1]) prepare(ch[u][1]), siz[u] += siz[ch[u][1]];
	// printf("prepare %d %d %d : %d %d %d\n", u, ch[u][0], ch[u][1], siz[u], siz[ch[u][0]], siz[ch[u][1]]);
}

bool check(int u, int v) {
	if (val[u] != val[v]) return false;
	if ((ch[u][0] == -1) + (ch[v][1] == -1) == 1) return false;
	if ((ch[u][1] == -1) + (ch[v][0] == -1) == 1) return false;
	bool ret = true;
	if (~ch[u][0] && ~ch[v][1]) ret &= check(ch[u][0], ch[v][1]);
	if (~ch[u][1] && ~ch[v][0]) ret &= check(ch[u][1], ch[v][0]);
	return ret;
}

void dfs(int u) {
	if (~ch[u][0]) dfs(ch[u][0]);
	if (~ch[u][1]) dfs(ch[u][1]);
	if (ch[u][0] == -1 || ch[u][1] == -1) return;
	if (siz[ch[u][0]] != siz[ch[u][1]]) return;
	if (check(ch[u][0], ch[u][1])) ans = std::max(ans, siz[u]);
}

void main() {
	read(n);
	for (int i = 1; i <= n; i++) read(val[i]);
	for (int i = 1; i <= n; i++) read(ch[i][0]), read(ch[i][1]);
	prepare(1), dfs(1);
	print(ans), putc('\n');
}

} int main() { return ringo::main(), 0; }
