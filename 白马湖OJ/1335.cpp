#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
int k[100009];
int main()
{
	int n;
	int sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &k[i]);
		sum += k[i];
	}
	int q = sum / n;
	for (int i = 1; i <= n; i++)
	{
		k[i] -= q;
	}
	int m = 0;
	for (int i = 1; i < n; i++)
	{
		if (k[i] == 0) continue;
		else 
		{
			m++;
			k[i + 1] += k[i];
			k[i] = 0;
		}
	}
	printf("%d", m);
	return 0;
} 
