
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

const int maxn = 5010, maxm = 100010, inf = 1e9;
int n, m, l, r, u, v, s, e, w, c, flow, cost, min_cost, max_flow;
int q[maxn], inq[maxn], dis[maxn], pre[maxn];
int tot = 2, hed[maxn], to[maxm], val[maxm], nxt[maxm], cst[maxm];

il void add_edge(int u, int v, int w, int c) {
	nxt[tot] = hed[u], to[tot] = v;
	val[tot] = w, cst[tot] = c, hed[u] = tot++;
}

bool spfa() {
	memset(inq, 0, sizeof(inq));
	memset(pre, 0, sizeof(pre));
	memset(dis, 63, sizeof(dis));
	l = r = 0, q[0] = s, dis[s] = 0, inq[s] = 1;
	while (l <= r) {
		u = q[(l++) % n], inq[u] = 0;
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
			if (val[i] && dis[u] + cst[i] < dis[v]) {
				dis[v] = dis[u] + cst[i], pre[v] = i;
				if (!inq[v]) q[(++r) % n] = v, inq[v] = 1;
			}
		}
	}
	return pre[e];
}

void main() {
	read(n), read(m), read(s), read(e);
	for (int i = 1; i <= m; i++) {
		read(u), read(v), read(w), read(c);
		add_edge(u, v, w, c);
		add_edge(v, u, 0, -c);
	}
	while (spfa()) {
		flow = inf, cost = 0;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			flow = std::min(flow, val[i]);
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			val[i] -= flow, val[i ^ 1] += flow;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			cost += flow * cst[i];
		min_cost += cost, max_flow += flow;
		// printf("find answer %d %d\n", flow, cost);
	}
	print(max_flow), putc(' ');
	print(min_cost), putc('\n');
}

} int main() { return ringo::main(), 0; }