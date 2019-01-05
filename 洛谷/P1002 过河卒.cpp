#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
const int mov[9][2] = {{0, 0}, {1, 2}, {2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1}};
int n, m, x, y, a, b;
long long f[maxn][maxn];
int main()
{
	cin >> n >> m >> x >> y;
	for (int i = 0; i < 9; i++) 
	{
		a = x + mov[i][0];
		b = y + mov[i][1];
		if (0 <= a && a <= n && 0 <= b && b <= m)
		{
			f[a][b] = -1;
		}
	}
	for (int i = 0; i <= m; i++) {
		if (f[0][i] == -1) break;
		f[0][i] = 1;
	}
	for (int i = 0; i <= n; i++) {
		if (f[i][0] == -1) break;
		f[i][0] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (f[i][j] != -1) {
				if (f[i-1][j] == -1 && f[i][j-1] == -1) f[i][j] = 0;
				else if (f[i-1][j] == -1) f[i][j] = f[i][j-1];
				else if (f[i][j-1] == -1) f[i][j] = f[i-1][j];
				else f[i][j] = f[i-1][j] + f[i][j-1];
			}
//	for (int i = 0; i <= n; i++)
//	{
//		for (int j = 0; j <= m; j++)
//			printf("%4d", f[i][j]);
//		cout << endl;
//	}
	cout << f[n][m] << endl;
	return 0;
}