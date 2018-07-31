#include <bits/stdc++.h>
#define each lalala001
#define sum lalala002
#define ans lalala003
using namespace std;
int n, each, a[25], b[10000], sum[10];
bool ans = false;
void DFS(int u)
{
	//判断
	printf("!");
	if ((sum[1] == each) && (sum[2] == each) && (sum[3] == each) && (sum[4] == each) == 3)
	{
		
		ans = true;
	}
	//DFS 
	for (int i = 1; i <= 4; i++)
		if (sum[i] + a[u] <= each)
		{
			int sum_back = sum[0];
			sum[i] += a[u];
			if (sum[i] == each) sum[0]++;
			DFS(u + 1);
			sum[0] = sum_back;
			sum[i] -= a[u];
		}
}
int main()
{
	//初始化 
	memset(sum, 0, sizeof(sum));
	memset(a, 0, sizeof(a));
	//输入 
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		sum[0] += a[i];
		b[a[i]]++;
	}
	for (int i = 10000; i >= 1; i--)
		while (b[i]) a[++a[0]] = i, b[i] -= 1;
	if ((sum[0] % 4) != 0) 
	{
		//肯定不能拼成正方形
		printf("no\n");
		return 0;
	}
	else each = sum[0] / 4;
	//DFS
	DFS(1);
	//输出
	if (ans) printf("yes\n");
	else printf("no\n");
	return 0;
}
