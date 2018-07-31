#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int _r(int l) {
	return rand() % l + 1;
}
const int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int main() {
	srand(GetTickCount());
	int n = 2, m = 2, x1, x2, y1, y2, way, dis[n + 1][n + 1][n + 1][n + 1];
	memset(dis, 0, sizeof(dis));
	printf("%d\n%d\n", n, m);
	for (int i = 1; i <= m; i++) {
		x1 = _r(n), y1 = _r(n), way = rand() % 4;
		x2 = x1 + mov[way][0];
		y2 = y1 + mov[way][1];
		while (dis[x1][y1][x2][y2] || x1 < 1 || x2 < 1 || y1 < 1 || y2 < 1 || x1 > n || x2 > n || y1 > n || y2 > n) {
			x1 = _r(n), y1 = _r(n), way = rand() % 4;
			x2 = x1 + mov[way][0];
			y2 = y1 + mov[way][1];
		}
		dis[x1][y1][x2][y2] = dis[x2][y2][x1][y1] = 1;
		if (i == 1) printf("%d %d %d %d\n", x1, y1, x2, y2);
		else printf("%d %d %d %d %d %d %d %d\n", x1, y1, x2, y2, x1, y1, x2, y2);
	}
	return 0;
}
