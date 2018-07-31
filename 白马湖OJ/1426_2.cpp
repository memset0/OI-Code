#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int n, m, a, f[30010];
int main()
{
	scanf("%d%d", &n, &m);
	f[0] = 1; 
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		for (int j = 11000; j >= a; j--)
			f[j] |= f[j - a];
	}
	int i = 0;
	while (1)
	{
		i *= -1;
		if (f[m + i])
		{
			printf("%d", m + i);
			return 0;
		}
		i *= -1;
		if (f[m + i])
		{
			printf("%d", m + i);
			return 0;
		}
		i++;
	}
	return 0;
} 
