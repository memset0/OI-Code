#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
char n[100];
int m[100];
int k, x, y;
long long ans = 1;
int main()
{
	scanf("%s%d", n, &k);
	for (int i = 0; i < strlen(n); i++)
	{
		n[i] -= '0';
		m[i] = 1;
	}
	for (int _i = 1; _i <= k; _i++)
	{
		scanf("%d%d", &x, &y);
		for (int i = 0; i < strlen(n); i++)
		{
			if ((n[i]) == x)
			{
				n[i] = y;
				m[i] ++;
			}
		}
	}
	ans = 1;
	for (int i = 0; i < strlen(n); i++)
	{
		ans *= m[i];
		//printf("n[%d] := %d   m[%d] := %d\n", i, n[i], i, m[i]);
	}
	printf("%lld", ans);
	return 0;
}
