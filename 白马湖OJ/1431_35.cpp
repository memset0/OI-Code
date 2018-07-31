#include <bits/stdc++.h>
#define map abc001
char a[110][110];
bool b[110][110];
int n, m, ans;
void DFS(int x, int y)
{
	if ((x < 0) || (x >= n) || (y < 0) || (y >= m) || b[x][y] || (a[x][y] != '#'))
		return;
	b[x][y] = 1;
	DFS(x-1, y);
	DFS(x+1, y);
	DFS(x, y-1);
	DFS(x, y+1);
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		memset(b, 0, sizeof(b));
		ans = 0;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%s", a[i]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				 if (!b[i][j] && a[i][j] == '#')
				 	DFS(i, j), ans++;
		printf("%d\n", ans);
	}
	return 0;
}
