#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
const int maxn = 100000 + 1 << 3;
const int maxa = 10000;
int n, m, a[maxn];
bool cheak(int k)
{
	
}
int main()
{
	scanf("%d%d", &n, &m);
	int l = 0, r = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), r += a[i];
	int mid;
	while (l + 4 < r)
	{
		mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid;
	}
	return 0;
}
