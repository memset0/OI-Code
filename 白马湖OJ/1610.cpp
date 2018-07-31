#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int f[maxn];
int minn(int a, int b)
{
	int min_n = min(a, b);
	if (min_n == 0) return max(a, b);
	else return min_n;
}
int main()
{
	int n, v, a;
	scanf("%d%d", &v, &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		for (int j = a; j <= v; j++)
			f[j] = minn(f[j], f[j-a] + 1);		
	}
	printf("%d", f[v]);
	return 0;
}
