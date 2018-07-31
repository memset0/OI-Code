#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define move sb001
#define temp sb002
#define ans sb003
#define cst_u cst[u.p[0][0]][u.p[0][1]][u.p[0][2]][u.p[1][0]][u.p[1][1]][u.p[1][2]][u.p[2][0]][u.p[2][1]]
#define cst_v cst[v.p[0][0]][v.p[0][1]][v.p[0][2]][v.p[1][0]][v.p[1][1]][v.p[1][2]][v.p[2][0]][v.p[2][1]]
using namespace std;
int i, j, temp, ans = -1;
short int move[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
short int cst[9][9][9][9][9][9][9][9];
bool bo;
struct Point/*坐标+步数*/{
 	short int x, y, k;
 	short int p[3][3];
}q[500000], u, v, a, b;
int main()
{
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &a.p[i][j]);
			if (a.p[i][j] == 0) {a.x = i; a.y = j;}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &b.p[i][j]);
			if (b.p[i][j] == 0) {b.x = i; b.y = j;}
		}
	}
	/* BFS */
	int f = 0, r = 1;
	q[0] = a;
	q[0].k = 0;
	while (f <= r)
	{
		u = q[f++];
		cst_u = 1;
		if /*验证是否为答案*/(u.x == b.x && u.y == b.y) {
			bo = true;
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (u.p[i][j] != b.p[i][j]) {bo = false;}
				}
			}
			if (bo == true)
			{
				ans = u.k;
				break; 
			}
		}
		if (u.k < 20) for (int i = 0; i < 4; i++)
		{
			v = u;
			v.x = u.x + move[i][0];
			v.y = u.y + move[i][1];
			if (v.x < 0 || v.y < 0 || v.y > 2 || v.x > 2) continue;
			v.k = u.k + 1;
			temp = v.p[v.x][v.y];
			v.p[v.x][v.y] = v.p[u.x][u.y];
			v.p[u.x][u.y] = temp;
			if (cst_v == 1) continue;
			q[r++] = v;
		}
	}
	if (ans == -1) printf("No solution!");
	else printf("%d", ans);
	return 0;
} 
