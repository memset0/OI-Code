#include <bits/stdc++.h>
using namespace std;
const int maxn = 5010;
const int maxm = 200010;
int n, m, fa[maxn];
struct G_link {
	int x, y, z;
} G[maxm];
bool cmp(G_link a, G_link b) {
	return a.z < b.z;
}
int find(int x) {
	if (fa[x] == x) return fa[x];
	else return fa[x] = find(fa[x]);
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &G[i].x, &G[i].y, &G[i].z);
	sort(G + 1, G + m + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= m; i++)
		if (find(G[i].x) != find(G[i].y)) {
			fa[find(G[i].x)] = find(G[i].y);
			ans += G[i].z;
		}
	cout << ans << endl;
	return 0;
}
