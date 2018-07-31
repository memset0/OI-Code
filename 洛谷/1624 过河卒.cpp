#include <bits/stdc++.h> 
#define map guohezu
using namespace std;
const int maxn = 100;
const int mov[16] = {1, 2, 2, 1, -1, 2, 2, -1, 1, -2, -2, 1, -1, -2, -2, -1};
int n, m, x, y, a, b, ans;
int map[maxn][maxn];
int main() {
	cin >> n >> m >> x >> y;
	for (int i = 0; i < 8; i++)
		map[x + mov[2 * i]][y + mov[2 * i + 1]] = -1;
	if (n == 0 || m == 0) ans = 1;
	else if (n < 0 || m < 0) ans = 0;
	else {
		for (int i = 0; i <= max(n, m); i++)
			map[0][i] = 1, map[i][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i-1][j] == -1 && map[i][j-1] == -1)
					map[i][j] = -1;
				else if (map[i-1][j] == -1)
					map[i][j] = map[i][j-1];
				else if (map[i][j-1] == -1) 
					map[i][j] = map[i-1][j];
				else map[i][j] = map[i-1][j] + map[i][j-1];
			}
		}
		ans = map[n][m];
	}
	cout << ans << endl; 
	return 0;
} 
