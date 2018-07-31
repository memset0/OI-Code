#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 10000015;
bool mark[N];
int prime[100000];
int find_prime(int n)
{
	mark[1] = 1;
	mark[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (mark[i] == 1) continue;
		else for (int j = 2; j * i <= n; j++) mark[j * i] = 1;
	}
	//return make_prime(n);
}
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
int main()
{
	int k = find_prime(N);
	int left, right;
	scanf("%d%d", &left, &right);
	int temp = -1;
	for (int i = right; i >= left; i--)	
		if (mark[i] == 0) {temp = i; break;}
	if (temp == -1) return 0;
	for (int i = left; i <= right; i++)
	{
		if (mark[i] == 0) 
		{
			printf("%d", i);
			if (i != temp) printf(" ");
		}
	}
	//printf("*");
	return 0;
}
