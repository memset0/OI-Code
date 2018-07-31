#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int a[maxn], f[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	f[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] > a[i-1])
			f[i] = f[i-1] + 1;
		else 
			f[i] = 1;
	int max = f[1];
	for (int i = 2; i <= n; i++)
		 if (f[i] > max) max = f[i];
	printf("%d", max);
	return 0;
} 
