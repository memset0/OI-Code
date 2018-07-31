#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int n, s;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		s = i;
		for (int j = 1; j <= (n + 1 - i); j++)
		{
			printf("%4d", s);
			s += n + 1 - j;
		}
		puts("");
	}
	return 0;
}
