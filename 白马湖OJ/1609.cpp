#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int  maxn = 400;
int f[maxn][maxn];
int main()
{
	int G, V, n, t, g, v;
	scanf("%d%d%d", &G, &V, &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &t, &g, &v);
		for (int j = G; j >= g; j--)
			for (int jj = V; jj >= v; jj--)
				f[j][jj] = max(f[j][jj], f[j-g][jj-v] + t);
	}
	printf("%d", f[G][V]);
	return 0;
}
