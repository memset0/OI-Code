#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1000015;
bool mark[N];
int prime[100000];
int make_prime(int n)
{
	int k = 0;
	for (int i = 1; i <= n; i++)
	{
		if (mark[i] == 1) continue;
		prime[++k] = i;
	}
	prime[0] = k;
	return k;
}
int find_prime(int n)
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
	int n;
	long long num;
	bool bo;
	scanf("%d", &n);
	//for (int i = 1; i <= k; i++) printf("%d ", prime[i]);
	for (int _i = 1; _i <= n; _i++)
	{
		scanf("%lld", &num);
		bo = true;
		if (num == 0 || num == 1)
		{
			printf("NO\n");
			continue;
		}
		for (int i = 1; i <= k; i++) 
		{
			if (num % prime[i] == 0 && num != prime[i]) 
			{
				 bo = false;
				 break;
			} 
		}
		if (bo == true) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
