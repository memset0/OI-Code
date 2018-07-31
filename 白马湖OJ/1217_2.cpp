#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
double a[10015];
double b[10015];
int mark;
int n, m, k = 0;
int f(double, double);
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &a[i]);
	}
	double max = a[1];
	for (int i = 2; i <= n; i++)
	{
		if (a[i] > max) max = a[i];
	}
	if (max < m * 0.01) 
	{
		//cannot cut
		printf("0.00");
		return 0;
	}
	else
	{
		mark == 1;
		f(0.01, max);
	}
	max = -1;
	for (int i = 1; i <= k; i++)
	{
		if (b[i] > max) max = b[i];
	}
	printf("%.2lf", max);
	return 0;
}
int f(double l, double r)
{
	if (l > r) return false;
	double mid = (l + r) / 2;
	int n = 0;
	for (int i = 1; i <= n; i++)
	{
		n += floor(a[i] / mid);
	}
	if (l == r) 
	{
		if (n == m)
		{
			b[++k] = l;
			f(l + 0.01, r + 0.01);
			return false;
		}
	}
	if (n < m) return f(l, mid - 0.01);
	else if (n > m) return f(mid + 0.01, r);
	else if (n == m)
	{
		b[++k] = mid;
		f(mid + 0.01, r);
		return true;
	}
}
