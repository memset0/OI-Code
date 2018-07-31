#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n, prime[100], ans[20], num[20];
void DFS(int f)
{
	for (int i = 2; i <= n; i++)
	{
		if (num[i] == 0 && prime[i + ans[f-1]] == 1)
		{
			num[i] = 1;
			ans[f] = i;
			if (f < n) DFS(f + 1);
			else if(prime[ans[1] + ans[n]] == 1)
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
	prime[2] = 1; 
	prime[3] = 1;
	prime[5] = 1;
	prime[7] = 1; 
	prime[11] = 1;
	prime[13] = 1;
	prime[17] = 1;
	prime[19] = 1;
	prime[23] = 1;
	prime[29] = 1;
	prime[31] = 1;
	scanf("%d", &n);
	ans[1] = 1; num[1] = 1;
	DFS(2);
	return 0;
}
