#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1000015;
bool mark[N];
int prime[100000];
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
	int k = find_prime(N);
	//printf("%d\n", k);
	int a;
	scanf("%d", &a);
	if (mark[a]) printf("Yes!");
	else printf("No!");
	return 0;
}
