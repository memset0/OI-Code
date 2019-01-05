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

std::string reads()
	{ std::string s; std::cin >> s; return s; }

const int maxn = 210, maxm = 80010;
const int inf = 1e9;

int n, m, s, e, u, v, l, r, flow, ans, find_ans;
int q[maxn * maxn], inq[maxn], dis[maxn], pre[maxn], used[maxn];
std::map < std::string, int > map;
std::map < int, std::string > ret;

int tot = 2, hed[maxn], nxt[maxm], to[maxm], val[maxm], cst[maxm];
inline void add_simple_edge(int u, int v, int w, int c)
	{ nxt[tot] = hed[u], to[tot] = v, val[tot] = w, cst[tot] = c, hed[u] = tot++; }
inline void add_edge(int u, int v, int w, int c)
	{ add_simple_edge(u, v, w, c), add_simple_edge(v, u, 0, -c); }

bool spfa() {
	memset(pre, 0, sizeof(pre)), memset(dis, -63, sizeof(dis));
	l = r = 1, q[1] = s, inq[s] = 1, dis[s] = 0;
	while (l <= r) {
		u = q[l++], inq[u] = 0;
		for (int i = hed[u], v = to[	i]; i; i = nxt[i], v = to[i])
			if (val[i] && dis[u] + cst[i] > dis[v]) {
				dis[v] = dis[u] + cst[i], pre[v] = i;
				if (!inq[v]) inq[v] = 1, q[++r] = v;
			}
	}
	return pre[e];
}

void dfs(int u, int flag, int stp) {
//	printf("%d %d > ", u, flag); for (int i = 1; i <= n; i++) printf("%d ", used[i]); puts("");
	if (u == n && !flag) dfs(n, 1, stp + 1);
	if (u == 1 && flag) { if (stp == ans) find_ans = 1; return; }
	for (int i = hed[u + n], v = to[i]; i && !flag && !find_ans; i = nxt[i], v = to[i]) {
		if (used[v] && u ^ v) {
			used[v]--;
			dfs(v, flag, stp + 1);
			used[v]++;
			if (find_ans) std::cout << ret[v] << std::endl;
		}
	}
	for (int i = hed[u], v = to[i] - n; i && flag && !find_ans; i = nxt[i], v = to[i] - n)
		if (used[v] && u ^ v) {
			used[v]--;
			dfs(v, flag, stp + 1);
			used[v]++;
			if (find_ans) std::cout << ret[v] << std::endl;
		}
}

int main() {
	n = read(), m = read(), add_edge(s = 1, n + 1, 1, 0), add_edge(n, e = n << 1, 1, 0);
	rep(i, 1, n) map[ret[i] = reads()] = i, add_edge(i, i + n, 1, 1);
	rep(i, 1, m) u = map[reads()], v = map[reads()], add_edge(u + n, v, 1, 0);
	while (spfa()) { flow = inf;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]]) flow = std::min(flow, val[i]);
		for (int i = pre[e]; i; i = pre[to[i ^ 1]]) val[i] -= flow, val[i ^ 1] += flow;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]]) ans += cst[i] * flow;
	}
	if (!ans) { printf("No Solution!\n"); return 0; }
	for (int i = 2; i < tot; i++) if (to[i] - to[i ^ 1] == n) used[to[i ^ 1]] += val[i ^ 1];
//	for (int i = 1; i <= n; i++) printf("%d\n", used[i]);
	printf("%d\n", ans), dfs(1, 0, -1), std::cout << ret[1] << std::endl;
	return 0;
}