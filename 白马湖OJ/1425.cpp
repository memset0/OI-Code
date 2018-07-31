#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int n, sum, ans, got[50], s[50][50];
void DFS(int u)
{
	if (sum >= ans) return;
	if (got[0] == n) 
	{
		//完成任务 
		//printf("%d ", ans);
		sum += s[u][1];
		if (sum < ans) ans = sum;
		sum -= s[u][1];
	}
	for (int i = 1; i <= n; i++)
		if (!got[i])
		{
			got[i] = 1;
			got[0] += 1;
			sum += s[u][i];
			DFS(i);
			got[i] = 0;
			got[0] -= 1;
			sum -= s[u][i];
		}
}
int main()
{
	//输入 
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &s[i][j]);
	//初始化 
	ans = n * 1000 + 1; 
	sum = 0;
	got[1] = 1;
	got[0] = 1;
	//DFS
	DFS(1);
	//输出
	printf("%d", ans); 
	//结束 
	return 0;
}
