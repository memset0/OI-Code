#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a = 2147483647, b = 2147483648, c = -2147483649;
	long long d = a / 2 * a;
	printf("%d\n%d\n%d\n%lld\n", a, b, c, d);
}
