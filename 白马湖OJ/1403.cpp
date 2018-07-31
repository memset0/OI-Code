#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define move sb001
#define temp sb002
#define ans sb003
using namespace std;
short int map[31][31][31];
short int move[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int n, m, h, f, r, ans = -1;
char ch;
struct Point {
	short int x, y, h;
	int k;
} q[10000000], u, v, s, e;
int main()
{
	scanf("%d%d%d%*c", &h, &n, &m);
	for (int k = 1; k <= h; k++) 
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%c", &ch);
				if (ch == 'S') {s.x = i; s.y = j; s.h = k;}
				if (ch == 'E') {e.x = i; e.y = j; e.h = k;}
				if (ch == '#') {map[i][j][k] = 1;}
			}
			scanf("%*c");
		}
		if (k != h) scanf("%*c");
	}
	/* BFS */
	f = 0; r = 1;
	q[0].x = s.x; q[0].y = s.y; q[0].h = s.h; q[0].k = 0;
	while (f < r)
	{
		u = q[f++];
		//printf("%d : x=%d y=%d h=%d k=%d\n", f, u.x, u.y, u.h, u.k);
		if /*µ½´ïÖÕµã*/(u.x == e.x && u.y == e.y && u.h == e.h) {
			ans = u.k;
			break;
		}
		map[u.x][u.y][u.h] = 1;
		for (int i = 0; i < 6; i++)
		{
			v.x = u.x + move[i][0];
			v.y = u.y + move[i][1];
			v.h = u.h + move[i][2];
			if (v.x < 1 || v.y < 1 || v.h < 1 || v.x > n || v.y > m || v.h > h) continue;
			if (map[v.x][v.y][v.h] == 1) {continue;}
			map[v.x][v.y][v.h] = 1;
			v.k = u.k + 1;
			q[r++] = v;
		}
	}
	if (ans == -1) printf("Trapped!");
	else printf("Escaped in %d minute(s).", ans);
	return 0;
}
