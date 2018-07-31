#include <bits/stdc++.h>
using namespace std;
int a[10000015];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int m, k;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &k);
		if (k < a[1])
		{
			printf("%d\n", a[1]);
			continue;
		}
		if (k >= a[n]) 
		{
			printf("no\n");
			continue;
		}
		int l = 1, r = n, mid;
		while (l <= r)
		{
			mid = (l + r) / 2;
			//printf("l=%d mid=%d r=%d k=%d\n", l, mid, r, k);
			if(a[mid] < k)
			{
				l = mid + 1;
			}
			else if (a[mid] > k)
			{
				r = mid - 1;
			}
			else if (a[mid] == k)
			{
				break;
			}
		}
		while (a[mid + 1] <= k) mid++;
		while (a[mid] > k) mid--;
		mid++;
		printf("%d\n", mid);
		//printf("===k = %d, i = %d, a[i] = %d\n", k, mid, a[mid]);
	}
	return 0;
}
