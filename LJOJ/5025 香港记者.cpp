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

const int maxn = 200010, maxm = 400010;

int n, m, u, v, w;
int a[maxn], frm[maxn];
bool vis[maxn];
ll dis[maxn];
int tot = 2, hed[maxn], val[maxm], to[maxm], nxt[maxm];

void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	hed[u] = tot++;
}

struct status {
	int u, frm;
	ll dis;
	status () {}
	status (int a, int b, int c) { u = a, dis = b, frm = c; }
};
bool operator < (status x, status y) {
	if (x.dis != y.dis) return x.dis > y.dis;
	return a[x.frm] > a[y.frm];
}
priority_queue < status > q;

int main() {
//	freopen("INPUT", "r", stdin);
	
	memset(dis, -1, sizeof(dis));
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), w = read();
		add_edge(v, u, w);
	}
	
	dis[n] = 0, frm[n] = -1;
	q.push(status(n, 0, n));
	while (q.size()) {
		u = q.top().u, q.pop();
		if (vis[u]) continue;
		else vis[u] = 1;
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (dis[v] == -1 || dis[u] + val[i] < dis[v] || (dis[u] + val[i] == dis[v] && a[u] < a[frm[v]])) {
				dis[v] = dis[u] + val[i];
				frm[v] = u;
				q.push(status(v, dis[v], v));
			}
	}
	
	printf("%lld\n", dis[1]);
	printf("%d", a[1]);
	for (int u = 1; ~frm[u]; u = frm[u])
		printf(" %d", a[frm[u]]);
	putchar('\n');
	
	return 0;
}
