#include <bits/stdc++.h>
#define read scanf
#define for(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int MAXN = 310;
int f[MAXN], a[MAXN][MAXN];
int main()
{
	int n, m;
	read("%d%d", &n, &m);
	for (i, 1, n)
		for (j, 1, m)
			read("%d", &a[i][j]);
	f[0] = 0;
	for (int i = 1; i <= n; i++)
		a[i][0] = 1; 
	//a[i][0]表示第i个公司准备取第几台机器 
	for (1, 1, m)
	return 0;
}
