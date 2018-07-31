//二分 + 维护前缀和 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m, ans_l, ans_r, ans_len = -1, a[maxn];
long long sum, a_sum[maxn];
bool check(int k)
{
	for (int i = 1; i+k-1 <= n; i++)
	{
		sum = a_sum[i+k-1] - a_sum[i-1];
		if (sum <= m) 
		{
			if (k > ans_len) //这句其实可以删掉吧 
			{
				ans_len = k;
				ans_l = i;
				ans_r = i+k-1;
			}
			return true;
		}
	}
	return false;
}
int main()
{
//	freopen("eat.in", "r", stdin);
//	freopen("eat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) 
		scanf("%d", &a[i]), a_sum[i] = a_sum[i-1] + a[i];
	int left = 1, right = n, mid;
	while (left + 3 < right) 
	{
		mid = (left + right) / 2;
		if (check(mid)) left = mid + 1;
		else right = mid - 1;
	}
	for (int i = left; i <= right; i++)
		check(i);
	printf("%d %d\n", ans_l, ans_r);
	return 0;
}
