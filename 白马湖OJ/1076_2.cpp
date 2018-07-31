#include <cstdio>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	long long a, b;
	scanf("%lld%lld", &a, &b);
	for (int i = b; i = 1; i--)
	{
		if (a % i == 0 && b % i == 0) 
		{
			printf("%d", i);
			return 0;
		}
	}
	return 0;
}
