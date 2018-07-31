#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define move sb001
#define test sb002
using namespace std;

int n, k, a, b, c, ans, f, r, tmp;
int cst[115][115][15];
int map[115][115];
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct Point
{
	int x, y, h;
}q[1000000], u, v;
void getnxt(int cost, int step)
{
	for (int i = 0; i < 4; i++)
	{
		v.x = u.x + move[i][0];
		v.y = u.y + move[i][1];
		if (v.x < 1 || v.y < 1 || v.x > n || v.y > n) continue;
		tmp = cost;
		if (i == 1 || i == 3) tmp += b;
		v.h = step;
		if (cst[v.x][v.y][v.h] == -1 || (cst[u.x][u.y][u.h] + tmp) < cst[v.x][v.y][v.h])
		{
			cst[v.x][v.y][v.h] = cst[u.x][u.y][u.h] + tmp;
			q[++r] = v;
		}
	}
}

int main()
{
	scanf("%d%d%d%d%d", &n, &k, &a, &b, &c);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	memset(cst, -1, sizeof(cst));
	f = 1; r = 1;
	q[r].x = 1; q[r].y = 1; q[r].h = k;
	cst[1][1][k] = 0;
	while (f <= r)
	{
		u = q[f++];
		//printf("u : x=%d y=%d h=%d cst=%d\n", u.x, u.y, u.h, cst[u.x][u.y][u.h]);
		if (map[u.x][u.y] == 1)
		{
			getnxt(a, k - 1);
		}
		else
		{
			getnxt(a + c, k - 1);
			if (u.h != 0) getnxt(0, u.h - 1);
		}
	}
	int ans = (1 << 30);
	for (int i = 0; i <= 10; i++)
	{
		//printf("cst[n][n][%d] = %d\n", i, cst[n][n][i]);
		if (cst[n][n][i] != -1 && cst[n][n][i] < ans) ans = cst[n][n][i];
	}
	printf("%d", ans);
	return 0;
}

