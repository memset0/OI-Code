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

const int maxn = 410, maxm = 80010;

int n, m, u, v, w, e, s, l, r;
int min_cost, max_flow;
int pre[maxn], dis[maxn], inq[maxn], q[maxn * maxn];
int tot = 2, hed[maxn], to[maxm], nxt[maxm], val[maxm], cst[maxm];

void add_edge(int u, int v, int w, int c) {
	nxt[tot] = hed[u], to[tot] = v;
	val[tot] = w, cst[tot] = c;
	hed[u] = tot++; 
} 

bool spfa() {
	memset(dis, -1, sizeof(dis));
	memset(pre, 0, sizeof(pre));
	l = r = 1, q[1] = s, dis[s] = 0, inq[s] = 1;
	while (l <= r) {
		u = q[l++], inq[u] = 0;
//		printf("%d\n", u);
		for (int i = hed[u]; i; i = nxt[i])
			if (val[i]) {
				v = to[i];
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
	s = 2 * n + 1, e = 2 * n + 2; 
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), w = read();
		add_edge(u + n, v, 1, w);
		add_edge(v, u + n, 0, -w);
	}
	add_edge(n * 2 + 1, 1, n, 0);
	add_edge(1, n * 2 + 1, 0, 0);
	add_edge(n * 2, n * 2 + 2, n, 0);
	add_edge(n * 2 + 2, n * 2, 0, 0);
	for (int i = 2; i < n; i++) {
		add_edge(i, n + i, 1, 0);
		add_edge(n + i, i, 0, 0);
	}
	add_edge(1, n + 1, n, 0);
	add_edge(n + 1, 1, 0, 0);
	add_edge(n, n * 2, n, 0);
	add_edge(n * 2, n, 0, 0);
	while (spfa()) {
		for (int i = pre[e]; i; i = pre[to[i ^ 1]]) {
			val[i] -= 1, val[i ^ 1] += 1;
			min_cost += cst[i];
		}
		max_flow += 1;
//		printf(">>> %d\n", min_cost);
	}
	printf("%d %d\n", max_flow, min_cost);
	return 0;
}
