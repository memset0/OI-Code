#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
int n, m, x, y, z, u, t[maxn], dis[maxn][maxn];
int main() {
	memset(dis, 0x3f, sizeof(dis));
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> z;
		x++, y++;
		dis[x][y] = z;
		dis[y][x] = z;
	}
	cin >> m;
	u = 1;
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> z;
		x++, y++;
		for (int k = u; k <= n; k++)
			if (t[k] <= z) {
				for (int i = 1; i <= n; i++)
					for (int j = 1; j <= n; j++)
						dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
				u++;
			} else break;
		if (u <= x || u <= y) cout << -1 << endl;
		else if (dis[x][y] == 0x3f3f3f3f) cout << -1 << endl;
		else cout << dis[x][y] << endl;
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			cout << dis[i][j] << " ";
//		cout << endl;
//	}
	return 0;
}
