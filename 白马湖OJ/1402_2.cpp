#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define move sb001

struct pp
{
	int x, y, k;
}q[10000], node, now;
int front, rear;
int n, m, k_top;
int mark[10][10], dis[10][10];
int move[4][2] = {{1, 0}, {-1, -0}, {0, 1}, {0, -1}};
int x1, x2, y1, y2, sx, sy, ex, ey;
int ans = 10000;

int BFS()
{
	front = 0; rear = 0;
	q[rear].x = sx;
	q[rear].y = sy;
	node.k = 0;
	rear += 1;
	for (int i = 1; i <= 10; i++) for (int j = 1; j <= 10; j++) dis[i][j] = -1;
	while (front != rear)
	{
		node = q[front++];
		if (node.k > k_top) continue;
		printf("x=%d y=%d k=%d\n", node.x, node.y, node.k);
		if (node.x == ex && node.y == ey) ans = node.k;
		for (int i = 0; i < 4; i++)
		{
			now.x = node.x + move[i][0];
			now.y = node.y + move[i][1];
			now.k = node.k + 1;
			if (now.x < 1 || now.y < 1 || now.x > n || now.y > m || mark[now.x][now.y] == 1) continue;
			q[rear++] = now;
			//if (dis[now.x][now.y] > (dis[node.x][node.y] + 1) || dis[now.x][now.y] == -1) 
			//dis[now.x][now.y] = dis[node.x][node.y] + 1;
		}
	}
} 
int main()
{
	char ch;
	scanf("%d%d%d%*c", &n, &m, &k_top);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%c", &ch);
			if (ch == 'S') {sx = i; sy = j;}
			else if (ch == 'X') {mark[i][j] = 1;}
			else if (ch == 'D') {ex = i; ey = j;}
		}
		scanf("%*c");
	}
	printf("ex=%d ey=%d\n", ex, ey);
	BFS();
	printf("ex=%d ey=%d\n", ex, ey);
	printf("%d", ans);
} 
