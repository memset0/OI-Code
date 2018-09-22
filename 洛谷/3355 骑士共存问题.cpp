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

const int maxn = 210, maxm = 40010, maxe = 800010, inf = 1e9;
const int mov[8][2] {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

#define at(x,y) (((x) - 1) * n + (y))

int n, m, x, y, u, v, s, e, ans, flow, flag;
int a[maxn][maxn], pre[maxm], dis[maxm], cur[maxm], gap[maxm], dep[maxm];

int tot = 2, hed[maxm], val[maxe], to[maxe], nxt[maxe];
inline void add_simple_edge(int u, int v, int w)
	{ nxt[tot] = hed[u], to[tot] = v, val[tot] = w; hed[u] = tot++; }
inline void add_edge(int u, int v, int w)
	{ add_simple_edge(u, v, w), add_simple_edge(v, u, 0); }

int isap() {
	u = s, gap[0] = e;
	while (dep[u] < e) {
//		printf("%d %d %d\n", u, cur[u], hed[u]);
		flag = 0;
		for (int &i = cur[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (val[i] && dep[u] == dep[v] + 1) {
				pre[v] = i, u = v, flag = 1;
				break;
			}
		if (!flag) {
			if (!--gap[dep[u]]) break;
			dep[u] = e;
			for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
				if (val[i] && dep[v] + 1 < dep[u])
					dep[u] = dep[v] + 1, cur[u] = i;
			++gap[dep[u]];
			if (u ^ s) u = to[pre[u] ^ 1];
		} else if (u == e) {
			flow = inf;
			for (int i = pre[e]; i; i = pre[to[i ^ 1]])
				flow = std::min(flow, val[i]);
			for (int i = pre[e]; i; i = pre[to[i ^ 1]])
				val[i] -= flow, val[i ^ 1] += flow;
			u = s, ans += flow;
		}
	}
//	printf("%d\n", ans);
	return ans;
}

int main() {
	n = read(), m = read(), s = n * n + 1, e = n * n + 2;
	rep(i, 1, m) x = read(), y = read(), a[x][y] = 1;
	rep(i, 1, n) rep(j, 1, n) if (!a[i][j]) {
		if ((i + j) & 1) {
			add_edge(s, at(i, j), 1);
			rep(t, 0, 7) {
				x = i + mov[t][0], y = j + mov[t][1];
				if (!a[x][y] && x > 0 && y > 0 && x <= n && y <= n) add_edge(at(i, j), at(x, y), inf);
			}
		} else add_edge(at(i, j), e, 1);
	}
	printf("%d\n", n * n - m - isap());
	return 0;
}
