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

const int N = 810, Nd = 1610, Ed = 64810, inf = 1e9;
int n, m, s, e, u, v, w, l, r, cnt, flow, cost, max_flow, min_cost;
int a[N], id[N], id2[N], pre[Nd], dis[Nd], inq[Nd], q[Nd];
int tot = 2, hed[Nd], to[Ed], val[Ed], cst[Ed], nxt[Ed];

il void addSimpleEdge(int u, int v, int w, int c) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
	cst[tot] = c, hed[u] = tot++;
}

il void addEdge(int u, int v, int w, int c) {
	// printf("add edge %d %d %d %d\n", u, v, w, c);
	addSimpleEdge(u, v, w, c);
	addSimpleEdge(v, u, 0, -c);
}

bool spfa() {
	memset(pre, 0, sizeof(pre));
	memset(dis, 63, sizeof(dis));
	l = r = 0, q[0] = s, dis[s] = 0;
	while (l <= r) {
		u = q[(l++) % cnt], inq[u] = 0;
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (val[i] && dis[u] + cst[i] < dis[v]) {
				dis[v] = dis[u] + cst[i], pre[v] = i;
				if (!inq[v]) inq[v] = 1, q[(++r) % cnt] = v;
			}
	}
	return pre[e];
}

void main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	read(n), read(m);
	s = ++cnt, e = ++cnt;
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		id[i] = ++cnt;
		id2[i] = ++cnt;
		addEdge(s, id[i], 1, 0);
		addEdge(s, id2[i], 1, a[i]);
		addEdge(id2[i], e, 1, 0);
	}
	for (int i = 1; i <= m; i++) {
		read(u), read(v), read(w);
		if (u > v) std::swap(u, v);
		// addEdge(id[u], id[v], 1, w);
		addEdge(id[u], id2[v], 1, w);
	}
	while (spfa()) {
		flow = inf, cost = 0;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			flow = std::min(flow, val[i]);
		for (int i = pre[e]; i; i = pre[to[i ^ 1]]) {
			val[i] -= flow, val[i ^ 1] += flow;
			cost += cst[i] * flow;
		}
		// printf(">>> %d %d\n", flow, cost);
		min_cost += cost, max_flow += flow;
	}
	print(min_cost), putc('\n');
}

} int main() { return ringo::main(), 0; }