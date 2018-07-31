#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, m, cnt;
char a[maxn][maxn];
int ans[maxn][maxn];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%c", &a[i][j]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			if (a[i][j] == '*') cout << '*';
			else 
			{
				
			}
		puts("");
	}
	return 0;
}
