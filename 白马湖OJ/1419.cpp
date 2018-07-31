#include <bits/stdc++.h>
using namespace std;
bool bo;
int n, x, y, cnt = 0, map[15][15], had[15], ans[15];
void dfs(int u)
{
	if (u > n)
	{
		//ÕÒµ½´ğ°¸
		cnt++;
		if (cnt <= 3)
		{
			printf("%d", ans[1]);
			for (int i = 2; i <= n; i++)
			{
				printf(" %d", ans[i]);
			}
			puts("");
		}
	}
	for (int i = 1; i <= n; i++)
		if (!had[i])
		{
			bo = true;
			x = u; y = i;
			while (x > 0 && y > 0) 
				if (ans[x--] == y--)
					bo = false;
			x = u; y = i;
			while (x > 0 && y <= n) 
				if (ans[x--] == y++)
					bo = false;
			if (!bo) continue;
			ans[u] = i;
			had[i] = 1;
			dfs(u+1);
			had[i] = 0;
			ans[u] = -1;
		}
}
int main()
{
	scanf("%d", &n);
	dfs(1);
	printf("%d", cnt);
	return 0;
}
