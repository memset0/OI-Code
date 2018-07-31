#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int s = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= (n - i + 1); j++)
		{
			printf("%4d", ++s);
		}
		puts("");
	}
	return 0;
}
