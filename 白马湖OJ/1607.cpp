#include <bits/stdc++.h>
using namespace std;
const int maxn = 510, maxk = 100010;
int f[maxk]; 
int main()
{
	int k, n, t, p, sum_p = 0;
	scanf("%d%d", &k, &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &t, &p);
		sum_p += p;
		for (int j = k; j >= t; j--)
			f[j] = max(f[j], f[j-t] + p);
	} 
	printf("%d", sum_p - f[k]);
	return 0;
}
 
