//DP算法 80分 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
const int maxm = 1010;
int n, m, a[maxn];
int f[maxn][maxm]; //f可能需要开longlong 
int cal(int x, int y) 
{
	return (a[y] - a[x]) * (a[y] - a[x]);
}
int main()
{
	//初始化
	memset(f, -1, sizeof(f));
	//输入 
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	//排序 
	sort(a+1, a+n+1); 
	//DP
	int tmp;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j > i) break;
			if (j == 1) 
			{
				f[i][j] = cal(1, i);
				continue;
			}
			for (int k = j-1; k < i; k++)
			{
				tmp = f[k][j-1] + cal(k+1, i);
				if (f[i][j] == -1 || tmp < f[i][j])
					f[i][j] = tmp;
			}
		}
	}
	/*
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++)
			printf("cal(%d, %d) = %d\n", i, j, cal(i, j));
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= m; j++)
			printf("%d ", f[i][j]);
		puts("");
	}*/
	//输出
	printf("%d", f[n][m]) ;
	return 0;
}





//DFS 算法 30分 
/*#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
const int maxm = 1010;
int n, m, a[maxn];
long long ans = 1e10, sum = 0;
void DFS(int u, int k)
{
	if (sum > ans) return;
	if (u > n && k == m) ans = sum;
	if (u > n || k == m) return;
	for (int i = u; i <= n; i++)
	{
		sum += (a[i] - a[u]) * (a[i] - a[u]);
		DFS(i+1, k+1);
		sum -= (a[i] - a[u]) * (a[i] - a[u]);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	DFS(1, 0);
	printf("%d", ans);
	return 0;
}*/
