#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int a[maxn], b[maxn], f[maxn][maxn];
int n, m;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	
	//for (int i = 1; i <= n; i++)
		//f[1][i] = a[1] == b[i], f[i][1] = a[i] == b[1];
		//f[1][i] = 1, f[i][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i-1] == b[j-1]) f[i][j] = f[i-1][j-1] + 1;
			else f[i][j] = max(f[i][j-1], f[i-1][j]);
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d", f[i][j]);
		puts("");
	}*/
			
	printf("%d", f[n][m]);
	
	return 0;
} 
