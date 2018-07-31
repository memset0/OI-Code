#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double eps = 1e-7;
double cal(double x)
{
	return (8 * x*x*x*x + 7 * x*x*x + 2 * x*x + 3 * x + 6);
}
int main()
{
	int ix;
	double min = cal(0.0), max = cal(100.0);
	double x, y, ans;
	int n;
	scanf("%d", &n);
	int temp;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &y);
		double l = 0.0, r = 100.0, mid;
		if (y < min || y > max) {printf("No solution!\n"); break;}
		while ((r - l) > eps) 
		{
			mid = (l + r) / 2.0;
			ans = cal(mid);
			//printf("l = %.4lf; mid = %.4lf; r = %.4lf; ans = %.4lf\n", l, mid, r, ans);
			if (abs(ans - y) < eps)
			{
				break;
			}
			else if ((ans - y) > eps)
			{
				r = mid - eps;
			}
			else if ((y - ans) > eps)
			{
				l = mid + eps;
			}
		}
		printf("%.4lf\n", mid);
	}
	return 0;
}
//8*x4 + 7*x3 + 2*x2 + 3*x + 6 = Y
