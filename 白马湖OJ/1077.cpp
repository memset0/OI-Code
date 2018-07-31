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
	long long a, b, c = 1, s = 0;
	scanf("%lld%lld", &a, &b);
	s = f(a, b);
	s = (a / s) * b;
	printf("%lld", s);
	return 0;
}
