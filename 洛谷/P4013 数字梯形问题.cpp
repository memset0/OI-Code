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

const int maxn = 50, inf = 1e9, maxm = 20000;
int n, m, u, s, e, l, r, cnt, flow, cost, max_flow, max_cost;
int pre[maxm], dis[maxm], q[maxm], inq[maxm];
int a[maxn][maxn], id[maxn][maxn], id2[maxn][maxn];
int tot = 2, hed[maxm], nxt[maxm], to[maxm], val[maxm], cst[maxm], col[maxm];

il void add_edge(int u, int v, int w, int c, int f) {
	// printf("add edge %d %d %d %d %d\n", u, v, w, c, f);
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
	cst[tot] = c, col[tot] = f, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, val[tot] = 0;
	cst[tot] = -c, col[tot] = f, hed[v] = tot++;
}

il void clear_edge() {
	for (int i = 2; i < tot; i += 2)
		val[i] += val[i ^ 1], val[i ^ 1] = 0;
}

il bool spfa() {
	memset(inq, 0, sizeof(inq));
	memset(pre, 0, sizeof(pre));
	memset(dis, -63, sizeof(dis));
	l = r = 0, q[0] = s, dis[s] = 0, inq[s] = 1;
	while (l <= r) {
		u = q[(l++) % cnt], inq[u] = 0;
		// printf("%d : %d %d\n", u, l, r);
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (val[i] && dis[u] + cst[i] > dis[v]) {
				// printf("%d -> %d %d\n", u, v, inq[v]);
				dis[v] = dis[u] + cst[i], pre[v] = i;
				if (!inq[v]) inq[v] = 1, q[(++r) % cnt] = v;
			}
	}
	// for (int i = 1; i <= cnt; i++) print(dis[i]), putc(i == cnt ? '\n' : ' ');
	// for (int i = 1; i <= cnt; i++) print(pre[i]), putc(i == cnt ? '\n' : ' ');
	return pre[e];
}

il int solve() {
	max_flow = max_cost = 0;
	while (spfa()) {
		flow = inf, cost = 0;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			flow = std::min(flow, val[i]);
		for (int i = pre[e]; i; i = pre[to[i ^ 1]]) {
			val[i] -= flow, val[i ^ 1] += flow;
			cost += flow * cst[i];
		}
		// printf(">>> %d %d\n", flow, cost);
		max_flow += flow, max_cost += cost;
	}
	return max_cost;
}

void main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	read(m), read(n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < m + i; j++) {
			read(a[i][j]);
			id[i][j] = ++cnt;
			id2[i][j] = ++cnt;
		}
	s = ++cnt, e = ++cnt;
	for (int i = 1; i <= m; i++)
		add_edge(s, id[1][i], 1, 0, 0);
	for (int i = 1; i < m + n; i++)
		add_edge(id2[n][i], e, 1, 0, 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < m + i; j++)
			add_edge(id[i][j], id2[i][j], 1, a[i][j], 2);
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m + i; j++) {
			add_edge(id2[i][j], id[i + 1][j], 1, 0, 3);
			add_edge(id2[i][j], id[i + 1][j + 1], 1, 0, 3);
		}
	print(solve()), putc('\n');
	clear_edge();
	for (int i = 2; i < tot; i += 2)
		if (col[i] == 1 || col[i] == 2) val[i] = inf;
	print(solve()), putc('\n');
	clear_edge();
	for (int i = 2; i < tot; i += 2)
		if (col[i] == 3) val[i] = inf;
	print(solve()), putc('\n');
}

} int main() { return ringo::main(), 0; }