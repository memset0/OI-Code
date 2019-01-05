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

const int maxn = 11010, maxm = 45010, inf = 1e9;

int n, m, u, v, l, r, x, e, s;
int flow, cost, max_flow, min_cost;
int pre[maxn], dis[maxn], q[maxn * maxn], inq[maxn];
int tot = 2, hed[maxn], nxt[maxm], to[maxm], val[maxm], cst[maxm];

void add_simple_edge(int u, int v, int w, int c) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, cst[tot] = c;
	hed[u] = tot++;
}

void add_edge(int u, int v, int w, int c) {
	add_simple_edge(u, v, w, c);
	add_simple_edge(v, u, 0, -c);
}

bool spfa() {
	memset(dis, -1, sizeof(dis));
	memset(pre, 0, sizeof(pre));
	l = r = 1, q[1] = s, dis[s] = 0, inq[s] = 1;
	while (l <= r) {
		u = q[l++], inq[u] = 0;
		for (int i = hed[u]; i; i = nxt[i])
			if (val[i]) {
				v = to[i];
//				printf("%d -> %d\n", u, v);
				if (dis[v] == -1 || dis[u] + cst[i] < dis[v]) {
					dis[v] = dis[u] + cst[i];
					pre[v] = i;
					if (!inq[v]) {
						inq[v] = 1;
						q[++r] = v;
					}
				}
			}
	}
	return pre[e];
}

int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		 x = read();
		 add_edge(i, i + 1, inf - x, 0);
	}
	for (int i = 1; i <= m; i++) {
		l = read(), r = read(), x = read();
		add_edge(l, r + 1, inf, x);
	}
	s = n + 2, e = n + 3;
	add_edge(s, 1, inf, 0);
	add_edge(n + 1, e, inf, 0);
	
	while (spfa()) {
		flow = inf, cost = 0;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			flow = min(flow, val[i]);
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			val[i] -= flow, val[i ^ 1] += flow;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			cost += cst[i] * flow;
//		printf(">>> %d %d\n", flow, cost);
		max_flow += flow, min_cost += cost; 
	}
	printf("%d\n", min_cost);
	
	return 0;
}