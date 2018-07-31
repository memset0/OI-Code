#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define move sb001

struct pp
{
	int x, y;
}q[1000], node, now;
int front, rear;
int mark[10][10], dis[10][10];
int move[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
int x1, x2, y1, y2, sx, sy, ex, ey;

int BFS()
{
	front = 0; rear = 0;
	q[rear].x = sx;
	q[rear].y = sy;
	mark[sx][sy] = 1;
	rear += 1;
	while (front != rear)
	{
		node = q[front++];
		for (int i = 0; i < 8; i++)
		{
			now.x = node.x + move[i][0];
			now.y = node.y + move[i][1];
			if (now.x < 1 || now.y < 1 || now.x > 8 || now.y > 8 || mark[now.x][now.y] == 1) continue;
			q[rear++] = now;
			mark[now.x][now.y] = 1;
			dis[now.x][now.y] = dis[node.x][node.y] + 1;
		}
	}
}

int main()
{
	char c1, c2;
	int n1, n2;
	scanf("%c%d %c%d", &c1, &n1, &c2, &n2);
	sx = c1 - 'a' + 1;
	sy = n1;
	ex = c2 - 'a' + 1;
	ey = n2;
	BFS();
	printf("%d", dis[ex][ey]);
	return 0;
} 
