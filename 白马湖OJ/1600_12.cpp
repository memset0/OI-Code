#include <bits/stdc++.h>
using namespace std;
long long a[2][1015];
int main()
{
	int n;
	scanf("%d", &n);
	bool flag = true;
	scanf("%d", &a[flag][1]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			scanf("%d", &a[flag][j]);
		for (int j = 1; j <= i; j++)
			a[flag][j] += max(a[!flag)
		flag = !flag;
	}
	int maxx = -1;
	for (int i = 1; i <= n; i++)
		if (maxx < a[!flag][j]) max = a[!flag][j];
	printf("%d", maxx);
	return 0;
}
