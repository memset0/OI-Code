//洛谷 1855 榨取kkksc03
//真是一道神奇的题目 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int maxm = 210;
int n, m, t, a[maxn], b[maxn], f[maxm][maxm];
int main()
{
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &b[i]);
	f[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j_1 = m; j_1 >= a[i]; j_1--)
			for (int j_2 = t; j_2 >= b[i]; j_2--)
				f[j_1][j_2] = max(f[j_1][j_2], f[j_1-a[i]][j_2-b[i]] + 1);
	}
	int maxx = -1;
	for 
	return 0;
}
