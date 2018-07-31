#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
long long f(long long a, long long b)
{
	return b==0?a:f(b,a%b);
}
int main()
{
	int n;
	scanf("%d", &n);
	int i = 1;
	while (i * i <= n)
	{
		i++;
	}
	i--;
	printf("%d", i);
	return 0;
}
