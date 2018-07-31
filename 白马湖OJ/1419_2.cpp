#include <bits/stdc++.h>
#define map lalala
using namespace std;
bool bo;
int n, x, y, cnt = 0, map[15][15], had[15], ans[15];
void dfs(int u)
{
	if (u > n)
	{
		//ÕÒµ½´ð°¸
		for (int i = 1; i <= n; i++)
		{
			printf("%d ", ans[i]);
		}
		puts("");
	}
	for (int i = 1; i <= n; i++)
		if ((!had[i]) && (!map[u][i]))
		{
			x = u; y = i;
			while (x > 0 && y > 0) 
				map[x--][y--] += 1;
			x = u; y = i;
			while (x > 0 && y < n) 
				map[x--][y++] += 1;
			x = u; y = i;
			while (x < n && y > 0) 
				map[x++][y--] += 1;
			x = u; y = i;
			while (x < n && y < n) 
				map[x++][y++] += 1;
			ans[u] = i;
			had[i] = 1;
			
			dfs(u+1);
			
			x = u; y = i;
			while (x > 0 && y > 0) 
				map[x--][y--] -= 1;
			x = u; y = i;
			while (x > 0 && y < n) 
				map[x--][y++] -= 1;
			x = u; y = i;
			while (x < n && y > 0) 
				map[x++][y--] -= 1;
			x = u; y = i;
			while (x < n && y < n) 
				map[x++][y++] -= 1;
			had[i] = 0;
			ans[u] = -1;
		}
}
int main()
{
	scanf("%d", &n);
	dfs(1);
	return 0;
}
