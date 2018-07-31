#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int n, m, a, f[500010];
int main()
{
	int sum = 0;
	scanf("%d", &n);
	f[0] = 1; 
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		sum += a;
		for (int j = sum; j >= a; j--)
			f[j] |= f[j - a];
	}
	for (int i = sum/2; i >= 0; i--)
		if (f[i])
		{
			printf("%d", (sum - i*2));
			return 0;
		}
	return 0;
} 
