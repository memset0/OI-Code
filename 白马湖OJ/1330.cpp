#include <bits/stdc++.h>
using namespace std;
int k[10000];
int main()
{
	long long n, m, max = -1, sum = 0;
	cin >> n>> m;
	for (int i = 1; i <= n; i++)
	{
		max = -1;
		for (int j = 1; j <= m ;j++)
		{
			scanf("%d", &k[j]);
			if (k[j] > max) max = k[j];
		}
		sum += max;
	}
	printf("%lld", sum);
	return 0;
}
