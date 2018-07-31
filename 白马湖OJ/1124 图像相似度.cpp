#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, m, cnt, a[maxn][maxn], b[maxn][maxn];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++)	
			scanf("%d", &b[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] == b[i][j]) 
				cnt++;
	cout << cnt << endl;
	return 0;
}
