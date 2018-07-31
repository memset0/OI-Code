#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
short int num[125010];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= m; i++)
	{
		for (int j = i; j <= m; j++)
		{
			num[i*i + j*j] = 1;
		}
	}
	int a, b, k;
	int ans = 0;
	int maxn = 2 * m * m;
	bool bo;
	for (b = 1; b <= (maxn / (n - 1)); b++)
	{
		for (a = 1; a <= (maxn - (n - 1) * b); a++)
		{
			bo = true;
			for (k = 0; k < n; k++)
				if (num[a + k * b] != 1) 
				{
					bo = false;
					//printf("=== a=%d b=%d k=%d === break! ===\n", a, b, k);
					break;
				}
			if (bo) 
			{
				printf("%d %d\n", a, b);
			}
		}
	}	
	return 0;
}
