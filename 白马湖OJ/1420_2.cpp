#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int num[20];
int main()
{
	int n, sum;
	scanf("%d", &n);
	num[0] = 1;
	num[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		sum = 0;
		for (int j = 0; j <= i - 1; j++)
			sum += num[j] * num[i-j-1];
		num[i] = sum;
	}
	printf("%d", num[n]);
	return 0;
} 
