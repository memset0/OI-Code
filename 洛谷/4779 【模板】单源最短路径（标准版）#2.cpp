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

const int maxn = 100010, maxm = 200010;

struct status {
	int u, w;
	status () {}
	status (int a, int b) { u = a, w = b; }
};

bool operator < (status a, status b) {
	return a.w > b.w;
}

priority_queue < status > q;

int n, m, s, u, v, w;
int dis[maxn], vis[maxn];
int tot = 2, hed[maxn], nxt[maxm], to[maxm], val[maxm];

int main() {
	memset(dis, -1, sizeof(dis));
	
	n = read(), m = read(), s = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), w = read();
		nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
		hed[u] = tot++;
	}
	
	dis[s] = 0, q.push(status(s, 0));
	while (q.size()) {
		u = q.top().u, q.pop();
		if (vis[u]) continue; else vis[u] = 1;
		for (int i = hed[u]; i; i = nxt[i]) {
			v = to[i];
			if (dis[v] == -1 || dis[u] + val[i] < dis[v]) {
				dis[v] = dis[u] + val[i];
				q.push(status(v, dis[v]));
			}
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", dis[i]);
	puts("");
	
	return 0;
}

