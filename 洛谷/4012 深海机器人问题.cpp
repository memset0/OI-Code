// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 20, maxm = 300, maxe = 100010;
const int inf = 1e9;

#define at(x,y) (((x) - 1) * m + (y))

int n, m, u, v, x, y, s, e, l, r, c, tn, tm, ans, flow;
int pre[maxm], inq[maxm], dis[maxm], q[maxm * maxm];

int tot = 2, hed[maxm], nxt[maxe], to[maxe], val[maxe], cst[maxe];
inline void add_simple_edge(int u, int v, int w, int c)
	{ nxt[tot] = hed[u], to[tot] = v, val[tot] = w, cst[tot] = c; hed[u] = tot++; }
inline void add_edge(int u, int v, int w, int c)
	{ add_simple_edge(u, v, w, c); add_simple_edge(v, u, 0, -c); }

bool spfa() {
	memset(pre, 0, sizeof(pre)), memset(dis, -63, sizeof(dis));
	l = r = 1, q[1] = s, inq[s] = 1, dis[s] = 0;
	while (l <= r) {
		u = q[l++], inq[u] = 0;
//		printf("%d\n", u);
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
//			printf("%d -> %d : %d %d %d %d\n", u, v, dis[u], dis[v], val[i], cst[i]);
			if (val[i] && dis[u] + cst[i] > dis[v]) {
				dis[v] = dis[u] + cst[i], pre[v] = i;
				if (!inq[v]) inq[v] = 1, q[++r] = v;
			}
		}
	}
	return pre[e];
}

int main() {
	tn = read(), tm = read(), n = read() + 1 , m = read() + 1, s = n * m + 1, e = s + 1;
	rep(i, 1, n) rep(j, 1, m - 1) add_edge(at(i, j), at(i, j + 1), 1, read()), add_edge(at(i, j), at(i, j + 1), inf, 0);
	rep(j, 1, m) rep(i, 1, n - 1) add_edge(at(i, j), at(i + 1, j), 1, read()), add_edge(at(i, j), at(i + 1, j), inf, 0);
	rep(i, 1, tn) c = read(), x = read() + 1, y = read() + 1, add_edge(s, at(x, y), c, 0);
	rep(i, 1, tm) c = read(), x = read() + 1, y = read() + 1, add_edge(at(x, y), e, c, 0);
	while (spfa()) {
		flow = inf;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			flow = std::min(flow, val[i]);
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			val[i] -= flow, val[i ^ 1] += flow, ans += cst[i] * flow;
//		printf("> %d %d\n", flow, ans);
	}
	printf("%d\n", ans);
	return 0;
}

