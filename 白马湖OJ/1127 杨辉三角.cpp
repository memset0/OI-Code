#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int n, a[maxn][maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		a[i][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		a[i][i] = 1;
		for (int j = 2; j < i; j++)
			a[i][j] = a[i-1][j] + a[i-1][j-1];
		for (int j = 1; j <= i; j++)
			printf("%5d", a[i][j]);
		puts("");
	}
	return 0;
}
