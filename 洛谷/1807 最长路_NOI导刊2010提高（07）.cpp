#include <bits/stdc++.h>
using namespace std;
const int maxn = 1510;
int n, m, dis[maxn], used[maxn], q[maxn * 1000];
struct Node {
	int e, v;
};
vector < Node > g[maxn];
int main() {
	memset(dis, -1, sizeof(dis));
	scanf("%d%d", &n, &m);
	int x, y, z;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		g[x].push_back({y, z});
	}
	int l = 1, r = 1, u;
	q[1] = 1, used[1] = 1;
	dis[1] = 0;
	while (l <= r) {
		u = q[l++], used[u] = 0;
		for (int i = 0; i < g[u].size(); i++)
			if (dis[g[u][i].e] == -1 || dis[g[u][i].e] < dis[u] + g[u][i].v) {
				dis[g[u][i].e] = dis[u] + g[u][i].v;
				if (!used[g[u][i].e]) {
					used[g[u][i].e] = 1;
					q[++r] = g[u][i].e;
				}
			}
	}
	printf("%d\n", dis[n]);
	return 0;
}
