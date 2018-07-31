#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int n, p, a, i, s;
	scanf("%d", &n);
	for (int _i = 1; _i <= n; i++)
	{
		scanf("%d", &p);
		s = 1; i = 1;
		while (s % p != 0)
		{
			s = (s * i) % p;
			i++;
		}
		a = i;
		printf("%d\n", a);
	}
	return 0;
}
