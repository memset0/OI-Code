#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const long N = 1000000000015;
bool mark[1000000000015];
long prime[100000000];
int make_prime(long n)
{
	long k = 0;
	for (long i = 1; i <= n; i++)
	{
		if (mark[i] == 1) continue;
		prime[++k] = i;
	}
	prime[0] = k;
	return k;
}
int find_prime(long n)
{
	mark[1] = 1;
	mark[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (mark[i] == 1) continue;
		else for (int j = 2; j * i <= n; j++) mark[j * i] = 1;
	}
	return make_prime(n);
}
int main()
{
	int k = find_prime(N);
	printf("%d", k);
	//int n;
	//scanf("%d", &n);
	
	return 0;
}
