#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
const int mov[4][2] = {
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}
};
struct Point {
	int x, y;
	
}u, v;
int n, cnt = 0, f = 0, a[maxn][maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		a[0][i] = -1;
		a[i][0] = -1;
		a[n+1][i] = -1;
		a[i][n+1] = -1;
	}
	u.x = 1, u.y = 1;
	while (cnt < n*n)
	{
		a[u.x][u.y] = ++cnt;
		v.x = u.x + mov[f][0];
		v.y = u.y + mov[f][1];
		if (a[v.x][v.y] == -1 || a[v.x][v.y] != 0)
		{
			v.x = u.x - mov[f][0];
			v.y = u.y - mov[f][1];
			f = (f + 1) % 4;
			v.x = u.x + mov[f][0];
			v.y = u.y + mov[f][1];
		}
		u = v;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d ", a[i][j]);
		puts("");
	}
	return 0; 
}
