#include <bits/stdc++.h>
#define paint Paintt
using namespace std;
const int maxn = 300;
const int mov[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, u, vx, vy, a[maxn][maxn], c[maxn * maxn][3];
int read() {
	char c = getchar();
	while (c != '.' && c != '#' && c != 'o' && c != 'v') c = getchar();	
	if (c == '.') return 0; if (c == '#') return -1;
	if (c == 'o') return 1; if (c == 'v') return 2; 
}
void paint(int x, int y) {
//	cout << x << " "  << y << endl;
	for (int i = 0; i < 4; i++) {
		vx = x + mov[i][0];
		vy = y + mov[i][1];
		if (a[vx][vy] == -1 || vx < 1 || vy < 1 || vx > n || vy > m) continue;
		c[u][a[vx][vy]]++;
		a[vx][vy] = -1;
		paint(vx, vy);
	}
}
void full(int x, int y) {
	if (a[x][y] != -1) {
		c[u][a[x][y]]++;
		a[x][y] = -1;
		paint(x, y);
		if (u > 0) u++;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = read();
	
	u = 0;
	for (int i = 1; i <= n; i++) full(i, 1), full(i, m);
	for (int i = 1; i <= m; i++) full(1, i), full(n, i);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			printf("%3d", a[i][j]);
//		puts("");
//	}
	u = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)	
			full(i, j);
	int ans[3] = {0, 0, 0};
	for (int i = 1; i <= u; i++) {
//		cout << c[i][1] << " " << c[i][2] << endl;
		if (c[i][1] > c[i][2]) ans[1] += c[i][1];
		else ans[2] += c[i][2];
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			printf("%3d", a[i][j]);
//		puts("");
//	}
	cout << ans[1] << " " << ans[2] << endl;
	return 0;
}

