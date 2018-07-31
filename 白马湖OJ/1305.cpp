#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 10000000 + 15; 
bool mark[N];
int prime[3000000];
int t[3000000];
int find_prime(int n)
{
	mark[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (mark[i] == 1) continue;
		else for (int j = 2; j * i <= n; j++) mark[j * i] = 1;
	}
	int k = 0;
	for (int i = 1; i <= n; i++)
	{
		if (mark[i] == 1) continue;
		prime[++k] = i;
	}
	prime[0] = k;
	return k;
}
int main()
{
	int a, b, k, s, ii;
	long long ans = 0;
	scanf("%d%d", &a, &b);
	find_prime(b + 15);
	for(int i = a; i <= b; i++)
	{
		k = 0; s = 1; ii = i;
		int j = 1;
		while (prime[j] <= ii)
		{
			if (ii % prime[j] == 0)
			{
				k++; t[k] = 0;
				while (ii % prime[j] == 0) 
				{
					ii /= prime[j]; t[k]++;
				}
			}
			j++;
		}
		for (int j = 1; j <= k; j++)
		{
			s *= (t[k] + 1);
		}
		ans += s;
	}
	printf("%lld", ans);
	return 0;
}
