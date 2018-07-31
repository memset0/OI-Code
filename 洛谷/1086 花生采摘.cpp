#include <bits/stdc++.h>
using namespace std;
int K; char C;
inline void read(int &x) {
	x = 0, K = 1, C = getchar();
	while (!isdigit(C) && C != '-') C = getchar();
	if (C == '-') C = getchar(), K = -1;
	while (isdigit(C)) x = x * 10 + C - '0', C = getchar();
	x *= K;
}
const int maxn = 21;
int n, lx, ly, t, tmp, ans, vis[maxn * maxn];
struct Node {
	int x, y, val;
} a[maxn * maxn];
struct Edge {
	int e, v;
};
vector < Edge > g[maxn * maxn];
inline int dis(int x, int y) {
	return abs(a[x].x - a[y].x) + abs(a[x].y - a[y].y);
}
void DFS(int i, int v, int h) {
	ans = max(ans, v);
	cout << i << " " << v << " " << h << " " << ans << endl;
	for (int j = 0; j < g[i].size(); j++)
		if (!vis[g[i][j].e]) {
			if (h + g[i][j].v < t) {
				vis[g[i][j].e] = 1;
			 	DFS(g[i][j].e, v + a[g[i][j].e].val, h + g[i][j].v);
			 	vis[g[i][j].e] = 0;
			}
		}
}
int main() {
	read(lx), read(ly), read(t);
	for (int i = 1; i <= lx; ++i)
		for (int j = 1; j <= ly; ++j) {
			read(tmp);
			if (tmp) {
				a[++n] = {i, j, tmp};
				g[0].push_back({n, a[n].x});
				for (int k = 1; k <= n; k++) {
					g[n].push_back({i, dis(n, k)});
					g[i].push_back({n, dis(n, k)});
				}
			}
		}
	DFS(0, 0, 0);
	return 0;
}
