#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define move sb001
#define test sb002
using namespace std;

int n, k, a, b, c, top, ans, front, rear;
int mark[150][150] = {0};
int in_q[150][150] = {0};
int w[w
int move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
struct car
{
	int s, m, x, y;
}test, node, now, q[1000000];
void ret_top(int &top)
{
	test.s = k;
	for (int i = 2; i <= n; i++)
	{
		//printf("%d %d %d %d\n", i, 1, test.s, top);
		test.s--;
		if (mark[i][1] == 1) {top += a; test.s = k;}
		else if (test.s <= 0) {top += c; test.s = k;}
	}
	for (int i = 2; i <= n; i++)
	{
		//printf("%d %d %d %d\n", n, i, test.s, top);
		test.s--;
		if (mark[n][i] == 1) {top += a; test.s = k;}
		else if (test.s <= 0) {top += c; test.s = k;}
	}
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d", test.mark[i][j]);
		}
		printf("\n");
	}
	printf("%d", top);*/
}
void BFS()
{
	front = 0; rear = 1;
	q[0].s = k;
	q[0].m = 0;
	q[0].x = 1;
	q[0].y = 1;
	while (front < rear)
	{
		node = q[front++];
		printf("i=%d s=%d m=%d x=%d y=%d\n", front, node.s, node.m, node.x, node.y);
		if (node.m > ans) continue;
		if (node.x < 1 || node.y < 1 || node.x > n || node.y > n)
			continue;
		if (node.x == n && node.y == n)
		{
			if (node.m < ans) ans = node.m;
			continue;
		}
		node.s--;
		if (mark[node.x][node.y] == 1) {node.m += a; node.s = k;}
		if (node.s == 0) {node.m += c; node.s = k;}
		for (int i = 0; i <= 1; i++)
		{
			node.x += move[i][0];
			node.y += move[i][1];
			q[rear++] = node;
			node.x -= move[i][0];
			node.y -= move[i][1];
		}
		for (int i = 2; i <= 3; i++)
		{
			node.m += b;
			node.x += move[i][0];
			node.y += move[i][1];
			q[rear++] = node;
			node.x -= move[i][0];
			node.y -= move[i][1];
			node.m -= b;0
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
			scanf("%d", &mark[i][j]);
		}
	}
	ret_top(top);
	ans = top;
	BFS();
	printf("%d", ans);
	return 0;
}

