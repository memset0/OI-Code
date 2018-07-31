#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int n;
	int a[110];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)	
		scanf("%d", &a[i]);
	int m;
	scanf("%d", &m);
	int x, y, t;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &x, &y);
		t = a[x];
		a[x] = a[y];
		a[y] = t;
	}
	printf("%d", a[1]);
	for (int i = 2; i <= n; i++)
		printf(" %d", a[i]);
	return 0; 
}
