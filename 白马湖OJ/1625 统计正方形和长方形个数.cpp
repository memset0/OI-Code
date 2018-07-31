#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	scanf("%d,%d", &n, &m);
	if (n > m) swap(n, m);
	long long zfx, cfx;
	if (n == 1) 
	{
		zfx = m;
		cfx = m * (m+1) / 2 - zfx;
	}
	else
	{
		zfx = 0;
		for (int i = 1; i <= n; i++) 
			zfx += (n - i + 1) * (m - i + 1);
		cfx = n * m; cfx /= 4; cfx *= (n+1) * (m+1); cfx -= zfx;
	}
	printf("%lld,%lld", zfx, cfx);
	return 0;
}
