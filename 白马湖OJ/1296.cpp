#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a[500], b, ans[500];
long long lena, lenb, len;
int max(int, int);
void times(); 
int main()
{
	long long n;
	scanf("%lld", &n);
	long long p = n * log(2) / log(10) + 1;
	printf("%lld", p);
	lena = 1;
	a[1] = 1;
	for (int i = 1; i <= (n / 12); i++)
	{
		b = 4096;
		times();
	}
	for (int i = 1; i <= (n % 12); i++)
	{
		b = 2;
		times();
	}
	int j = 0;
	a[1] -= 1;
	for (int i = 100; i >= 1; i--)
	{
		if (j % 10 == 0) {printf("\n"); j == 1;}
		if (a[i] / 10000 == 0) printf("0");
		if (a[i] / 1000 == 0) printf("0");
		if (a[i] / 100 == 0) printf("0");
		if (a[i] / 10 == 0) printf("0");
		printf("%d", a[i]);
		j += 1;
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
	if (lena > 301) {lena = 301;}
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
