// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 110, maxm = 1010, inf = 1e9;
int n, m, u, v, s, e, a[maxn];
int ans, max_flow, sum;
int l, r, q[maxn], inq[maxn], dis[maxn], pre[maxn];
int tot = 2, hed[maxn], nxt[maxm], to[maxm], val[maxm], cst[maxm];

void add_edge(int u, int v, int w, int c) {
	// printf("add edge %d -> %d : %d %d\n", u, v, w, c);
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, cst[tot] =  c, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, val[tot] = 0, cst[tot] = -c, hed[v] = tot++;
}

bool spfa() {
	memset(dis, -1, sizeof(dis));
	memset(pre, 0, sizeof(pre));
	memset(inq, 0, sizeof(inq));

	l = r = 0, q[0] = s, inq[s] = 1, dis[s] = 0;
	while (l <= r) {
		u = q[(l++) % n];
		// printf(">>> %d\n", u);
		for (int i = hed[u]; i; i = nxt[i]) 
			if (val[i] && (dis[to[i]] > dis[u] + cst[i] || dis[to[i]] == -1)) {
				// printf("%d -> %d : %d %d %d\n", u, to[i], dis[u], dis[to[i]], dis[u] + cst[i]);
				dis[to[i]] = dis[u] + cst[i];
				pre[to[i]] = i;
				if (!inq[to[i]]) {
					inq[to[i]] = 1;
					q[(++r) % n] = to[i];
				}
			}
	}

	return pre[e];
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();

	for (int i = 1; i <= n; i++)
		sum += a[i];
	// cout << sum << endl;
	sum /= n;

	s = n + 1, e = n + 2;
	for (int i = 1; i <= n; i++)
		if (a[i] > sum) add_edge(s, i, a[i] - sum, 0);
		else if (a[i] < sum) add_edge(i, e, sum - a[i], 0);
	for (int i = 1; i < n; i++) {
		add_edge(i, i + 1, inf, 1);
		add_edge(i + 1, i, inf, 1);
	}
	add_edge(1, n, inf, 1), add_edge(n, 1, inf, 1);

	while (spfa()) {
		// printf("find answer\n");
		max_flow = inf;
		// for (int i = pre[e]; i; i = pre[to[i ^ 1]])
		// 	cout << i << " " << to[i] << " " << to[i ^ 1] << endl;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			max_flow = min(max_flow, val[i]);
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			val[i] -= max_flow, val[i ^ 1] += max_flow;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			ans += max_flow * cst[i];
		// printf("%d %d\n", max_flow, ans);
	}

	printf("%d\n", ans);

	return 0;
}