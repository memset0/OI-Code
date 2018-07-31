#include <bits/stdc++.h>
#define read scanf
using namespace std;
const int MAXN = 310;
int f[MAXN], a[MAXN][MAXN];
int main()
{
	int n, m;
	read("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read("%d", &a[i][j]);
	f[0] = 0;
	for (int i = 1; i <= n; i++)
		a[i][0] = 1; 
	//a[i][0]表示第i个公司准备取第几台机器 
	for (int i = 1; i <= m; i++)
	{
		for (int i = 1; i <= n; i++)
		{
			
		}
	}
	return 0;
}
