#include <bit/stdc++.h>
using namespace std;
const int maxn = 50010;
int n, m, a_max, a ?_min 
bool fire(int n)
{
	j = 1;
	for (int x = 1; x <= k; x++)
	{
		i = j;
		while (p[j] < (p[i] + 2 * mid) && j <= n) j++;
	}
	//printf("%d %d\n", mid, j);
	if (j > n)
	{
		if (mid < ans) ans = mid;
		r = mid - 1;
	}
	else l = mid + 1;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	
	sort(a+1, a+n+1);
	
	int l = 1, r = n, mid;
	for (int i = 1; i <= n; i++)
	{
		mid = (l + r) / 2
		if (fire(mid)) r = mid - 1, ans = min(ans, mid);
		else l = mid + 1;
	}
	
	return 0; 
}
