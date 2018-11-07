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

const int maxn = 10010, maxm = 200010, inf = 1e9;
int n, m, u, v, w, s, e, ans, flow, flag;
int pre[maxn], dep[maxn], gap[maxn], cur[maxn];
int tot = 2, hed[maxn], nxt[maxm], to[maxm], val[maxm];

il void add_simple_edge(int u, int v, int w) { nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++; }
il void add_edge(int u, int v, int w) { /* printf("add edge %d %d %d\n", u, v, w); */ add_simple_edge(u, v, w), add_simple_edge(v, u, 0); }

void main() {
	read(n), read(m), read(s), read(e);
	rep(i, 1, m) read(u), read(v), read(w), add_edge(u, v, w);	
	u = s, gap[0] = n;
	while (dep[s] < n) {
		// printf(">>> %d\n", u);
		// printf("dep "); rep(i, 1, n) print(dep[i]), putc(' '); putc('\n');
		// printf("gap "); rep(i, 0, n) print(gap[i]), putc(' '); putc('\n');
		if (u == e) {
			flow = inf;
			for (int i = pre[e]; i; i = pre[to[i ^ 1]])
				flow = std::min(flow, val[i]);
			for (int i = pre[e]; i; i = pre[to[i ^ 1]])
				val[i] -= flow, val[i ^ 1] += flow;
			// printf("find ans %d\n", flow);
			ans += flow, u = s;
		}
		flag = 0;
		for (int &i = cur[u]; i; i = nxt[i])
			if (val[i] && dep[u] == dep[to[i]] + 1) {
				u = to[i], pre[to[i]] = i;
				flag = 1; break;
			}
		if (!flag) {
			// printf("refresh depth %d\n", u);
			if (!--gap[dep[u]]) break;
			dep[u] = n;
			for (int i = hed[u]; i; i = nxt[i])
				if (val[i] && dep[u] > dep[to[i]] + 1)
					dep[u] = dep[to[i]] + 1, cur[u] = i;
			++gap[dep[u]];
			if (u != s) u = to[pre[u] ^ 1];
		}
	}
	print(ans), putc('\n');
}

} int main() { return ringo::main(), 0; }