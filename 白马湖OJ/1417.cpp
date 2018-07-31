#include <bits/stdc++.h>
#define N (25)
using namespace std;
int n, m, sum, arr[N], ans[N], num[N], cnt = 0;
bool b;
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
				sum = 0; b = true;
				for (int j = 1; j <= m; j++)
					sum += arr[ans[j]];
				//printf("!%d\n", sum);
				for (int j = 2; j*j <= sum; j++)
				{
					if (sum % j == 0) b = false;
				}
				if (b) cnt++;
			}
			num[i] = 0;
		}
	}	
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	DFS(1, 1);
	printf("%d", cnt);
	return 0;
} 
