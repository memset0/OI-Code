#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
long long x, y, s, ans = 0, i, j;
long long GCD(long long a, long long b)
{
	return b==0?a:GCD(b,a%b);
}
int main()
{
	scanf("%d%d", &x, &y);
	s = x * y;
	for (i = x; i <= y; i++)
	{
		if (s % i != 0) continue;
		j = s / i;
		if (GCD(i, j) == x) 
		{
			ans++;
			//printf("%lld %lld\n", i, j);
		}
	}
	printf("%lld", ans);
}
