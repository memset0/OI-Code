#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 50010;
const int TEST = 1;
int a[N];
int main()
{
	int len, n, m, ans;
	scanf("%d%d%d", &len, &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	a[0] = 0;
	a[n + 1] = len;
	int l = 0, r = len, mid, k, i, j;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (TEST) printf("%d %d %d\n", l, mid, r);
		k = 0; i = 0, j;
		for (j = 1; j <= n + 1; j++)
		{
			if (j == i) continue;
			if ((a[j] - a[i]) < mid) continue;
			if ((a[j] - a[i]) >= mid)
			{
				k += j - i - 1;
				i = j + 1;
				if (TEST) printf("%d ", a[j]);
			}
		}
		k += j - i - 1;
		if (TEST) printf("\n%d\n", k);
		if (k <= m) {ans = mid; l = mid + 1;}
		else {r = mid - 1;}
	}
	printf("%d", ans);
	return 0;
} 
