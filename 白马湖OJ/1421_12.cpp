#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MAXN 15
#define ans wafjk001
#define move wafjk002
#define step wafjk003
#define cnt wafjk004
#define ex wafjk005
#define ey wafjk006
#define sx wafjk007
#define sy wafjk008
#define got wafjk009
#define map wafjk010
#define DFS wafjk011
using namespace std;
int move[4][2] = {
	{0, -1},
	{-1, 0},
	{0, 1},
	{1, 0}
};
int n, m, sx, sy, ex, ey, step, cnt = 0;
short int ans[MAXN*MAXN+3][2];
int map[MAXN+3][MAXN+3], got[MAXN+3][MAXN+3];
int DFS(int ux, int uy)
{
	//抵达终点 
	if (ux == ex && uy == ey)
	{
		for (int i = 1; i <= step; i++)
		{
			printf("(%d,%d)", ans[i][0], ans[i][1]);
			if (i != step) printf("->");
		}
		puts("");
		cnt += 1;
		return 0;
	}
	//下一步操作 
	int vx, vy;
	for (int i = 0; i < 4; i++)
	{
		vx = ux + move[i][0];
		vy = uy + move[i][1];
		//判断下一步合法性 
		if (vx <= 0 || vy <= 0 || vx > n || vy > m || map[vx][vy] == 0 || got[vx][vy] == 1) continue;
		//在got与ans里记录下一步操作 
		got[vx][vy] = 1;
		step++;
		ans[step][0] = vx;
		ans[step][1] = vy; 
		//下一次DFS
		DFS(vx, vy);
		//在got与ans里删除下一步操作 
		got[vx][vy] = 0;
		step--; 
	}
}
int main()
{
	//输入 
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &map[i][j]);
	scanf("%d%d", &sx, &sy);
	scanf("%d%d", &ex, &ey);
	/*if (map[sx][sy] == 0 || map[ex][ey] == 0)
	{
		//此处好像有点问题啊 
		printf("-1");
		return 0;
	}*/
	got[sx][sy] = 1; 
	step = 1;
	ans[1][0] = sx; ans[1][1] = sy;
	
	//DFS
	DFS(sx, sy);
	
	//输出
	//在函数里 
	
	//无答案的情况的输出
	if (cnt == 0) printf("-1"); 
	
	//结束 
	return 0;
}

