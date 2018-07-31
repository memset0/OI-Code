#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
const int mov[9][2] = {{0, 0}, 
	{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, 
	{2, 1}, {-2, 1}, {2, -1}, {-2, -1}
};
long long a[maxn][maxn], f[maxn][maxn];
int x, y, n, m;
void build(int x, int y) {
	if (x >= 0 && y >= 0)
		a[x][y] = 1;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &x, &y);
	n++, m++, x++, y++;
	for (int i = 0; i < 9; i++)
		build(x + mov[i][0], y + mov[i][1]);
	f[1][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] != 1) 
				f[i][j] = f[i - 1][j] + f[i][j - 1];
	printf("%lld", f[n][m]);
	return 0;
}
