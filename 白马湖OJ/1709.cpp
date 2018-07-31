#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
long long milk[1010];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int p, a;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &p, &a);
		milk[p] += a;
	}
	long long ans = 0;
	for (int i = 0; i <= 1000; i++)
	{
		if (n < milk[i])
		{
			ans += i * n;
			break;
		}
		else
		{
			ans += i * milk[i];
			n -= milk[i];
		}
	}
	printf("%lld", ans);
	return 0; 
} 
 
