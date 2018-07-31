#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a[500], b, ans[500];
int c[1015];
int lena, lenb, len;
int max(int, int);
void times(); 
int main()
{
	int k = 0, n;
	scanf("%d", &n);
	int i = 2;
	int m = n; 
	while (m >= i)
	{
		c[++k] = i;
		m -= i;
		i++;
	}
	for (int i = k; i >= (k - m + 1); i--)
	{
		c[i] ++;
	}
	for (int i = 1; i <= k; i++)
	{
		if (i != k) printf("%d ", c[i]);
		else printf("%d", c[i]);
	}
	printf("\n");
	lena = 1;
	a[1] = 1;
	for (int i = 1; i <= k; i++)
	{
		b = c[i];
		times();
	}
	for (int i = len; i >= 1; i--)
	{
		if (i != len)
		{
			if (a[i] / 10000 == 0) printf("0");
			if (a[i] / 1000 == 0) printf("0");
			if (a[i] / 100 == 0) printf("0");
			if (a[i] / 10 == 0) printf("0");
		}
		printf("%d", a[i]);
	}
}
int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
void times()
{
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= lena; i++)
	{
		ans[i] += a[i] * b;
		ans[i + 1] += ans[i] / 100000;
		ans[i] %= 100000;
	}
	len = lena + 1;
	while (len > 1 && ans[len] == 0) len--; 
	for (int i = 1; i <= len; i++)
		a[i] = ans[i];
	lena = len;
}
