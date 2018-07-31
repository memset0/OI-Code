#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
double a[10015];
int mark;
int n, m;
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
			if (f(l + 0.01, r + 0.01) == false && mark == 1)
			{
				printf("%.2lf", l);
				mark = 0;
				return true;
			}
			else return false;
		}
	}
	if (n < m) return f(l, mid - 0.01);
	else if (n > m) return f(mid + 0.01, r);
	else if (n == m)
	{
		f(mid + 0.01, r);
		return true;
	}
}
