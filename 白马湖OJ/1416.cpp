#include <bits/stdc++.h>
#define N (25)
using namespace std;
int n, m, ans[N], num[N];
void DFS(int f, int low)
{
	for (int i = low; i <= n; i++)
	{
		if (num[i] == 0)
		{
			num[i] = 1;
			ans[f] = i;
			if (f < m) DFS(f + 1, i + 1);
			else 
			{
				for (int j = 1; j <= m; j++)
				{
					printf("%d", ans[j]);
					if (j != m) printf(" ");
				}
				puts("");
			}
			num[i] = 0;
		}
	}	
}
int main()
{
	scanf("%d%d", &n, &m);
	DFS(1, 1);
	return 0;
} 
