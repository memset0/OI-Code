#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int mov_x[4] = {1, 0, -1, 0};
const int mov_y[4] = {0, 1, 0, -1};
int n, m, l, r, Cos, ans = -1, a[maxn][maxn], hsh[maxn][maxn];
void DFS(int x, int y, int stp, int col) {
	if (ans != -1 && stp > ans) return; //可行性剪枝
//	printf("%d %d %d %d\n", x, y, stp, col);
	if (x == n && y == n) {
		if (stp < ans || ans == -1) ans = stp;
		return ;
	}
	if (a[x][y]) {
		//没填色过 
		int col = 0;
		for (int t = 0; t < 4; t++) {
			int xx = x + mov_x[t], yy = y + mov_y[t];
			if (xx < 1 || yy < 1 || xx > n || yy > n) continue;
			if (!a[xx][yy]) Cos = 2, col = a[x][y];
			else if (a[xx][yy] == a[x][y]) Cos = 0;
			else Cos = 1;
//			if (x == 2 && y == 3) cout << xx << " " << yy << " " << stp << " " << Cos << " " << hsh[xx][yy] << endl;
			if (stp + Cos < hsh[xx][yy] || hsh[xx][yy] == -1) {
//				cout << xx << " " << yy << " " << stp + Cos << " " << hsh[xx][yy] << endl;
				hsh[xx][yy] = stp + Cos;
				DFS(xx, yy, stp + Cos, col);
			}
		}
	} else {
		//填色过 
		for (int t = 0; t < 4; t++) {
			int xx = x + mov_x[t], yy = y + mov_y[t];
			if (xx < 1 || yy < 1 || xx > n || yy > n) continue;
			if (!a[xx][yy]) continue;
			if (col == a[xx][yy]) Cos = 0;
			else Cos = 1;
//			if (x == 2 && y == 3) cout << xx << " " << yy << " " << stp << " " << Cos << " " << hsh[xx][yy] << " " << a[xx][yy] << " " << col << endl;
			if (stp + Cos < hsh[xx][yy] || hsh[xx][yy] == -1) {
//				cout << xx << " " << yy << " " << stp + Cos << " " << hsh[xx][yy] << endl;
				hsh[xx][yy] = stp + Cos;
				DFS(xx, yy, stp + Cos, 0);
			}
		}
	}
}
int main() {
	memset(hsh, -1, sizeof(hsh));
	scanf("%d%d", &n, &m);
	int x, y, z;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		a[x][y] = z + 1;
	}
	DFS(1, 1, 0, 0);
	cout << ans << endl;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			printf("%3d", hsh[i][j]);
//		puts("");
//	}
	return 0;
}