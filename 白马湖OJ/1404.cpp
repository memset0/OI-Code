#include <iostream>
#include <cstdio>
#include <cstring>
#define move sb001
#define wod sb002
#define key sb003
#define Point sb004
using namespace std;

int n, m, p, k, s, x1, x2, y1, y2, g, x, y, f, r, ans = -1;
int wod[15][15][15][15]; //wall_or_door
int key[15][15]; //key
int cst[15][15];
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct Point/*存储坐标+钥匙+时间*/ {
	int x, y, k, t;
}q[100000], u, v;
int get/*获得钥匙后压缩状态*/(int x, int y) {
	return (x | y);
}
int find/*查询是否具有钥匙*/(int x, int y) {
	return ((x & (1 << (y - 1))) != 0);
}
int main/*主程序*/() {
	memset(wod, -1, sizeof(wod));
	memset(cst, -1, sizeof(cst));
	memset(key, 0, sizeof(key));
	scanf("%d%d%d", &n, &m, &p);
	scanf("%d", &k);
	for(int i = 1; i <= k; i++)
	{
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &g);
		wod[x1][y1][x2][y2] = g;
		wod[x2][y2][x1][y1] = g;
	}
	scanf("%d", &s);
	for (int i = 1; i <= s; i++)
	{
		scanf("%d%d%d", &x, &y, &g);
		key[x][y] |= (1 << (g - 1));
	}
	/* BFS */
	f = 1; r = 1; q[1].x = 1; q[1].y = 1; q[1].k = 0; q[1].t = 0; cst[1][1] = 0;
	while (f <= r)
	{
		//printf("f=%d r=%d\n", f, r);
		u = q[f++];
		//printf("u : x=%d y=%d k=%d t=%d\n", u.x, u.y, u.k, u.t);
		if /*判断是否到终点*/(u.x == n && u.y == m) {ans = u.t; break;}
		u.k |= key[u.x][u.y]; //获得当前位置的钥匙
		for (int i = 0; i < 4; i++)
		{
			v.x = u.x + move[i][0];
			v.y = u.y + move[i][1];
			v.t = u.t + 1;
			v.k = u.k;
			if /*判断是否越界*/(v.x < 1 || v.y < 1 || v.x > n || v.y > m) continue;
			if /*说明可以通过*/(wod[u.x][u.y][v.x][v.y] == -1 || find(v.k, wod[u.x][u.y][v.x][v.y]))
			{
				if /*判重*/((v.k | cst[v.x][v.y]) != cst[v.x][v.y] || cst[v.x][v.y] == -1)
				{
					//printf("v : x=%d y=%d k=%d t=%d\n", v.x, v.y, v.k, v.t);
					cst[v.x][v.y] = v.k;
					q[++r] = v;
					//printf("f=%d r=%d\n", f, r);
				}
			}
			else /*说明不可以通过*/ continue; 
		}
	}
	printf("%d", ans);
	return 0;
}
