#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, m, x, a[maxn], b[maxn];
int main()
{
//	freopen("div.in", "r", stdin);
//	freopen("div.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[a[i]] = 1;
	m = n;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (a[i] > a[j]) x = a[i] / a[j];
			else x = a[j] / a[i];
			if (!b[x])
			{
				b[x] = 1;
				a[++m] = x;
			}
		}
	}
	printf("%d", m);
	return 0;
} 
