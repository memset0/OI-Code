#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 10000000 + 15; 
bool mark[N];
int shl[10000015];
int num[10000015];
int find_prime(int n)      
{
	mark[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (mark[i] == 1) continue;
		else for (int j = 2; j * i <= n; j++) mark[j * i] = 1;
	}
	/*int k = 0;
	for (int i = 2; i <= b; i++)
	{
		if (mark[i] == 1) continue;
		prime
	}*/
}
int main()
{
	int a, b, k, s, temp, p;
	long long ans = 0;
	scanf("%d%d", &a, &b);
	if (a > b) {temp = a; a = b; b = temp;}
	find_prime(b + 15);
	for (int i = a; i <= b; i++) 
	{
		shl[i] = 1;
		num[i] = i;
	}
	for (int i = 2; i <= b; i++)
	{
		if (mark[i] == 1) continue;
		for (int j = ((a / i) * i); j <= b; j += i)
		{
			temp = 0;
			while (num[j] % i == 0 && num[j] != 0)
			{
				num[j] /= i;
				temp++;
			}
			shl[j] = shl[j] * (temp + 1);
		}
	}
	ans = 0;
	for (int i = a; i <= b; i++)
	{
		ans += shl[i];
	}
	printf("%lld", ans);
	return 0;
}
