#include <bits/stdc++.h> 
using namespace std;
const int maxn = 110;
const int maxm = 1010;
int n, m, x, y, z, a[maxn][maxn], f[maxn][maxn];
int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
struct point {
	int x, y;
} u, v;
queue < point > q; 
int main() {
	memset(f, -1, sizeof(f));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		a[x][y] = z + 1;
	}
	f[1][1] = 0;
	q.push({1, 1});
	while (q.size()) {
		u = q.front();
		q.pop();
//		cout << u.x << " " << u.y << endl;
		for (int i = 0; i < 4; i++) {
			v = {u.x + mov[i][0], u.y + mov[i][1]};
			if (v.x > 0 && v.y > 0 && v.x <= n && v.y <= n && a[v.x][v.y] != 0 && (f[v.x][v.y] == -1 || f[u.x][u.y] + (a[u.x][u.y] == a[v.x][v.y] ? 0 : 1) < f[v.x][v.y])) {
				f[v.x][v.y] = f[u.x][u.y] + (a[u.x][u.y] == a[v.x][v.y] ? 0 : 1);
				q.push(v);
			}
		}
	}
	cout << f[n][n];
	return 0;
}
