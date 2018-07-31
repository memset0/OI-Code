#include <bits/stdc++.h>
using namespace std;
bool my_sort(int a, int b) {return a > b;}
int main()
{
	int a[5][30];
	for (int i = 1; i <= 4; i++)
		scanf("%d", &a[i][0]);
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= a[i][0]; j++)
			scanf("%d", &a[i][j]);
	int sum[3], ans = 0;
	for (int flag = 1; flag <= 4; flag++)
	{
		memset(sum, 0, sizeof(sum));
		sort(a[flag]+1, a[flag]+a[flag][0]+1, my_sort);
		for (int i = 1; i <= a[flag][0]; i++)
			printf("%d ", a[flag][i]);
		puts("");
		for (int i = 1; i <= a[flag][0]; i++)
			if (sum[1] < sum[2]) sum[1] += a[flag][i];
			else sum[2] += a[flag][i];
		ans += max(sum[1], sum[2]);
	}
	printf("%d", ans);
	return 0;
} 
