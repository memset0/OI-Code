#include <bits/stdc++.h>
#define N (10)
using namespace std;
int n, ans[N], num[N];
void DFS(int f)
{
	for (int i = 1; i <= n; i++)
	{
		if (num[i] == 0)
		{
			num[i] = 1;
			ans[f] = i;
			if (f < n) DFS(f + 1);
			else 
			{
				for (int j = 1; j <= n; j++)
				{
					printf("%d", ans[j]);
					if (j != n) printf(" ");
				}
				puts("");
			}
			num[i] = 0;
		}
	}	
}
int main()
{
	scanf("%d", &n);
	DFS(1);
	return 0;
}
