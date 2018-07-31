#include <bits/stdc++.h>
#define map lalala001
#define move lalala002
using namespace std;
int n, m, ans, _N_;
bool map[110][110];
char str[110];
int move[4][2] = {
	{0, -1},
	{-1, 0},
	{0, 1},
	{1, 0}
};
void DFS(int x, int y)
{
	if ((x < 1) || (x > n) || (y < 1) || (y > m))
		return;
	map[x][y] = 0;
	for (int i = 0; i < 4; i++)
		if (map[x + move[i][0]][y + move[i][1]])
			DFS(x + move[i][0], y + move[i][1]);
}
int main()
{
	scanf("%d", &_N_);
	for (int _I_ = 1; _I_ <= _N_; _I_++)
	{
		//memset(map, 0, sizeof(map));
		ans = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str+1);
			for (int j = 1; j <= m; j++)
				map[i][j] = (bool)(str[j] == '#');
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (map[i][j]) DFS(i, j), ans++;
		printf("%d\n", ans);
	}
	return 0;
}

