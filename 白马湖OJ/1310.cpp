//衣带渐宽终不悔 为伊消得人憔悴 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a[5000015];
int b[200015][2];
int c[200015];
long long ans = 0;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[a[i]][0] = b[a[i]][1]; 
		b[a[i]][1] = i; 
	}
	int maxn;
	for (int i = 200015; i >= 0; i--)
		if (b[i][1] != 0) 
		{
			maxn = i;
			break;
		}
	printf("i=N#A maxn = %d;\n", maxn);
	int max;
	for (int i = 1; i <= n; i++)
	{
		printf("i=%d : a[i] = %d; b[a[i]] = %d; c[a[i]] = %d\n", i, a[i], b[a[i]][1], c[a[i]]);
		if (b[a[i]][1] == 0) continue;
		if (c[a[i]] != 0 && b[a[i]][1] != i)
		{
			ans += c[a[i]];
			continue;
		}
		if (b[a[i]][1] == i) max = b[a[i]][0];
		else max = b[a[i]][1];
		for (int j = 2; j <= (maxn / a[i]); j++)
		{
			printf("i=%d : j=%d : ;\n", i, j);
			if (b[a[i] * j][1] > max) max = b[a[i] * j][1];
		}
		printf("i=%d : max = %d\n", i, max);
		ans += max;
		if (b[a[i]][1] != i) c[a[i]] = max;
	}
	printf("%lld", ans);
	return 0;
}

