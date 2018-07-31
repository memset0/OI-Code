#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
const int maxm = 1010;
int n = 20, a[maxn];
long long sum = 0, ans = 0;
int f[maxm];
int main()
{
	cin >> a[1] >> a[2] >> a[3] >> a[5] >> a[10] >> a[20];
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int k = 1; k <= a[i]; k++)	
			for (int j = maxm; j >= i; j--)
				f[j] |= f[j-i];
	for (int i = 1; i <= maxm; i++)
		ans += f[i];
	printf("Total=%d", ans);
	return 0;
}
