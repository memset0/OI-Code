#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define move sb001
#define temp sb002
#define ans sb003
using namespace std;
int cst[101][101];
int x, y, z, f, r, ans = -1;
struct Water {
	int x, y, k;
} q[10000000], u, v;
void nxt(int a, int b)
{
	if (cst[a][b] == 1) return;
	v.x = a; v.y = b; v.k = u.k + 1;
	q[r++] = v;
	return;
}
int main()
{
	memset(cst, -1, sizeof(cst));
	scanf("%d%d%d", &x, &y, &z);
	f = 0; r = 1;
	q[0].x = 0; q[0].y = 0; q[0].k = 0;
	while (f < r)
	{
		u = q[f++];
		//printf("%d : x=%d y=%d k=%d\n", f, u.x, u.y, u.k);
		cst[u.x][u.y] = 1;
		if/*ÅÐ¶ÏÊÇ·ñÎª´ð°¸*/(u.x == z || u.y == z) {
			ans = u.k;
			break;
		}
		/* 1 */ nxt(x, u.y);
		/* 2 */ nxt(u.x, y);
		/* 3 */ nxt(0, u.y);
		/* 4 */ nxt(u.x, 0);
		/* 5 */ if/*µ¹µ½¿Õ*/(u.x + u.y <= y) nxt(0, u.x + u.y);
					else nxt((u.x + u.y - y), y);
		/* 6 */ if/*µ¹µ½¿Õ*/(u.x + u.y <= x) nxt(u.x + u.y, 0);
					else nxt(x, (u.x + u.y - x));
	}
	if (ans == -1) printf("No Solution!");
	else printf("%d", ans);
	return 0;
}
