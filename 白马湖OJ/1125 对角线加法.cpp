#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, a[maxn][maxn];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		a[i][i] += 10, a[i][n+1-i] += 10;
	if (n % 2 == 1) a[n/2+1][n/2+1] -= 10;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%5d", a[i][j]);
		puts(""); 
	}
	return 0;
}
