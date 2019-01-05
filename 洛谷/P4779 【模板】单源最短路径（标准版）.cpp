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

const int maxn = 100010, maxm = 500010;
int n, m, s, u, v, w, d, dis[maxn];
int tot, hed[maxn], nxt[maxm], val[maxm], to[maxm];

void add_edge(int u, int v, int w) {
	tot++;
	nxt[tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	hed[u] = tot;
}

struct status {
	int u, dis;
	bool operator < (const status &b) const {
		return dis > b.dis;
	}
} t;

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read(), m = read(), s = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), w = read();
		add_edge(u, v, w);
	}
	
	for (int i = 1; i <= n; i++)
		dis[i] = 2147483647;
	dis[s] = 0;
	
	priority_queue < status > q;
	q.push((status){s, 0});
	
	while (!q.empty()) {
		t = q.top(), q.pop();
		if (t.dis != dis[t.u]) continue;
		u = t.u;
		for (int i = hed[u]; i; i = nxt[i])
			if (dis[u] + val[i] < dis[to[i]]) {
				dis[to[i]] = dis[u] + val[i];
				q.push((status){to[i], dis[to[i]]});
			}
	}
	
	for (int i = 1; i <= n; i++)
		printf("%d ", dis[i]);
	puts("");
	
	return 0;
}