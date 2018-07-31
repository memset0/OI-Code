#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int ans[100];
int n, b, d;
int f(int n) //十进制转二进制
{
	int k = 0;
	for (int i = 1; i <= b; i++)
	{
		if (n % 2 == 1) k++;
		n = n / 2;
	}
	return k;
}
int main()
{
	scanf("%d%d%d", &n, &b, &d);
	int m = 0, i = 2, MAX = , x;
	ans[1] = 0; ans[0] = 1;
	while ((m < n) && i <= ((1<<b) - 1))
	{
		if (f(ans[ans[0]] xor i) >= d) ans[++ans[0]] = i;
		i++;
	} 
	for (int i = 1; i <= ans[0]; i++)
		printf("%d ", ans[i]);
}
