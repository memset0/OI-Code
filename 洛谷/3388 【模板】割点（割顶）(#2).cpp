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

const int maxn = 20010, maxm = 200010;

int n, m, u, v, ans, tim, top;
int cut[maxn], dfn[maxn], low[maxn], stk[maxn], ins[maxn];
int tot = 2, hed[maxn], nxt[maxm], to[maxm];

il void add_edge(int u, int v) { nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++; }

void tarjan(int u, int rt) {
	// printf("tarjan %d %d\n", u, rt);
	dfn[u] = low[u] = ++tim, stk[++top] = u, ins[u] = 1; int cnt = 0;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
		if (!dfn[v]) {  tarjan(v, rt), low[u] = std::min(low[u], low[v]), ++cnt;
			if (u != rt && low[v] >= dfn[u]) cut[u] = 1;
		} else if (ins[v]) low[u] = std::min(low[u], dfn[v]);
	}
	if (u == rt && cnt > 1) cut[u] = 1;
}

void main() {
	read(n), read(m);
	rep(i, 1, m) read(u), read(v), add_edge(u, v), add_edge(v, u);
	rep(i, 1, n) if (!dfn[i]) tarjan(i, i);
	rep(i, 1, n) if (cut[i]) ++ans;
	print(ans), putc('\n');
	rep(i, 1, n) if (cut[i]) print(i), putc(' ');
	putc('\n');
}

} int main() { return ringo::main(), 0; }