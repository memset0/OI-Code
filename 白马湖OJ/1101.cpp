#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a[1000];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	i = 1;
	while (i <= n)
	{
		printf("%d ",  a[i]);
		i += 2;
	}
	printf("\n");
	i = 2;
	while (i <= n)
	{
		printf("%d ",  a[i]);
		i += 2;
	}
	return 0;
}
