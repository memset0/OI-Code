#include <bits/stdc++.h>
#define MAXN 1e9
using namespace std;
double x, y, s;
int n;
double solve(double a,double b,int c)
{
	if(c == 1)
		return max(a/b, b/a);
	double ans = MAXN, t1, t2;
	for (int i = 1; i <= c / 2; i++)
	{
		t1 = max(solve(a, b - i * s / a, c - i), solve(a, i * s / a, i)); //×ÝÇÐ 
		t2 = max(solve(a - i * s / b, b, c - i), solve(i * s / b, b, i)); //ºáÇÐ 
		ans = min(ans, min(t1, t2));
	}
	return ans;
}
int main()
{
    scanf("%lf%lf%d", &x, &y, &n);
    s = y * x / (double)n;
    printf("%.6lf", solve(x, y, n));
    return 0;
}
