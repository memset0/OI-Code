#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
	int n, t;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	printf("%d", a[1]);
	for (int i = 2; i <= n; i++)
		printf(" %d", a[i]);
	return 0;
} 
