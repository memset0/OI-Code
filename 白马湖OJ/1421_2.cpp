#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MAXN 15
using namespace std;
struct POINTS{
	short int x, y, l;
	short int ways[MAXN*MAXN+3];
}u, v, end, f[1000000], ans[MAXN*MAXN+3];
int n, m, cnt = 0;
int move[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int map[MAXN+3][MAXN+3], got[MAXN+3][MAXN+3];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &map[i][j]);
	scanf("%d%d", &f[1].x, &f[1].y);
	scanf("%d%d", &end.x, &end.y);
	int i = 1, j = 0;
	f[1].l = 1;
	while (i > 0)
	{
		j++;
		u = f[i--];
		printf("%d : i=%d \n", j, i); 
		/*µΩ¥Ô÷’µ„*/if (u.x = end.x && u.y == end.y) {
			ans[++cnt] = u;
			continue;
		}
		v = u;
		v.ways[v.l] = v.x * n + v.y;
		v.l += 1;
		for (int count = 0; count < 4; count++)
		{
			v.x = u.x + move[count][0];
			v.y = u.y + move[count][1];
			printf("!");
			if (map[v.x][v.y] != 0 && 0 < v.x && v.x <= n && 0 < v.y && v.y <= m) 
			{
				f[++i] = v;
				printf("!");
			}
		}
	}
	printf("%d", cnt);
	return 0;
}

