#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1000015;
bool mark[N];
int prime[1000000];
int find_prime(int n)
{
	mark[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (mark[i] == 1) continue;
		else for (int j = 2; j * i <= n; j++) mark[j * i] = 1;
	}
	return 0;
}
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	find_prime(m);
	int ans = 0;
	for (int i = 2; i <= (m - n); i++)
	{
		if (mark[i] == 0 && mark[i + n] == 0)
		{
			ans++;
			printf("%d %d\n", i, (i + n));
		}
	}
	printf("Total Is:%d", ans);
	return 0;
}
