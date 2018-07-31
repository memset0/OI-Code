#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
long long f[10001];
int main()
{
	int n, m, k;
	scanf("%d%d", &n, &m);
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		for (int j = k; j <= m; j++)
			f[j] += f[j-k];
	}
	printf("%lld", f[m]);
	return 0;
}


