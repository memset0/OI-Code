#include <bits/stdc++.h>
using namespace std;
const int maxn = 60;
int n, m, v[maxn][maxn], f[maxn][maxn][maxn][maxn];
inline int Max(int a, int b, int c, int d) { 
	return max(a, max(b, max(c, d)));
}
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> v[i][j];
	int a, b, c, d, ans = -1;
	for (a = 1; a <= n; a++)
		for (b = 1; b <= m; b++)
			for (c = n; c > 0; c--)
				for (d = m; d > 0; d--) {
					f[a][b][c][d] = Max(
						f[a][b - 1][c + 1][d],
						f[a - 1][b][c][d + 1],
						f[a - 1][b][c + 1][d],
						f[a][b - 1][c][d + 1]) + v[a][b] + v[c][d];
					cout << a << " " << b << " " << c << " " << d << "  " << f[a][b][c][d] << endl;
					if (a == c && b == d) ans = max(ans, f[a][b][c][d]);
				}
	cout << f[3][3][1][1] << endl;
	return 0;
}
