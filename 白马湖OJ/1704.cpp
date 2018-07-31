#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 1000000
using namespace std;
short int c[MAXN + 100];
int main()
{
	int n;
	scanf("%d", &n);
	int a, b;
	int min = (MAXN + 100), max = -1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a, &b);
		if (min > a) min = a;
		if (max < b) max = b;
		for (int j = a; j <= b; j++)
		{
			c[j] += 1;
		}
		for (int j = b; j >= a; j--)
		{
			c[j] += 1;
		}
	}
	int i = min;
	int max_1 = -1, max_2 = -1;
	int m;
	while (i <= max)
	{
		m = 0;
		while (c[i] != 0 && i <= max)
		{
			i++;
			m++;
		}
		if (m > max_1) max_1 = m;
		m = 0;
		while (c[i] == 0 && i <= max)
		{
			i++;
			m++;
		}
		if (m > max_2) max_2 = m;
	}
	printf("%d %d\n", max_1-1, max_2+1);
	return 0;
}
