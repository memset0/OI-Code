#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define move sb001
using namespace std;

int n, m, k, sx, sy, ex, ey;
char ch[10][10];
bool map[10][10];
int step[10][10];
int move[4][2] = {{1, 0}, {-1, -0}, {0, 1}, {0, -1}};
struct Point {
	int x, y, h;
} u, v, q[100000];

int main()
{
	memset(step, -1, sizeof(step));
	scanf("%d%d%d%*c", &n, &m, &k);
	/* 输入 */
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%c", &ch[i][j]);
			if (ch[i][j] == 'S') {sx = i; sy = j;}
			if (ch[i][j] == 'D') {ex = i; ey = j;}
			if (ch[i][j] == 'X') {map[i][j] = 1;}
		}
		getchar();
	}
	/* 测试输入数据 */
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			printf("%c", ch[i][j]);
		}
		printf("\n");
	}
	/* BFS */
	int f = 1, r = 1;
	q[1].x = 1; q[1].y = 1; q[1].h = 0;
	while (f <= r)
	{
		u = q[f++];
		if (u.h >= step[u.x][u.y] || step[u.x][u.y] == -1) continue;
		step[u.x][u.y] = u.h;
		for (int i = 0; i < 4; i++)
		{
			v.x = u.x + move[i][0];
			v.y = u.y + move[i][1];
			v.h = u.h + 1;
			if (v.x < 1 || v.y < 1 || v.x > n || v.y > m) continue;
			q[++r] = v;
		}
	}
	if (step[n][m] != -1 && step[n][m] <= k) printf("YES");
	else printf("NO");
	return 0;
} 
