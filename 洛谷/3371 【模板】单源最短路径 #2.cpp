#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n, m, s, dis[maxn], in_q[maxn];
struct G {
	int e, v;
};
vector < G > g[maxn];
int q[maxn * 10 ];
int main() {
	scanf("%d%d%d", &n, &m, &s);
	int x, y, z;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		g[x].push_back({y, z});
	}
	for (int i = 1; i <= n; i++)
		dis[i] =2147483647;
	int l = 1, r = 0;
	q[++r] = s,in_q[s] = true;
	dis[s] = 0;
	int u, v;
	while (l <= r) {
		u = q[l++]; in_q[u] = false;
		for (int i = 0; i < g[u].size(); i++) {
			v = g[u][i].e;
			if (dis[v] > dis[u] + g[u][i].v) {
				dis[v] = dis[u] + g[u][i].v;
				in_q[v] = true;
				q[++r] = v;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", dis[i]);
	return 0;
}
