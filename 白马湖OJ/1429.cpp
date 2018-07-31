#include <bits/stdc++.h>
#define max lala01
using namespace std;
int x, y, n;
double t, each, max, ans;
void DFS(double ua, double ub, int i_, int j_)
{
	int k = ua * ub / each;
	for (int i = 1; i <= i_; i++) printf("    ");
	if (j_) printf("ºá "); else printf("×Ý ");
	printf("ua = %.2lf; ub = %.2lf; k = %d max = %.2lf ans = %.2lf\n", ua, ub, k, max, ans);
	if (k == 1) 
	{
		//ÕÒµ½´ð°¸
		if ()
		if (max < ans) ans = max;
		return;
	}
	//ºáÇÐ
	for (int i = 1; 2 * i <= k; i++)
	{
		double max_back = max;
		double va = ua * i / k, vb = ub;
		if (va < vb) t = va, va = vb, vb = t;
		if (va / vb > max) max = va / vb;
		if (max <= ans) DFS(va, vb, i_+1, 1);
		va = ua - va;
		if (va <= vb) t = va, va = vb, vb = t;
		if (va / vb > max) max = va / vb;
		if (max <= ans) DFS(va, vb, i_+1, 1);
		max = max_back;
	}
	//×ÝÇÐ 
	for (int i = 1; 2 * i <= k; i++)
	{
		double max_back = max;
		double vb = ub * i / k, va = ua;
		if (va < vb) t = va, va = vb, vb = t;
		if (va / vb > max) max = va / vb;
		if (max <= ans) DFS(va, vb, i_+1, 0);
		vb = ub - vb;
		if (va < vb) t = va, va = vb, vb = t;
		if (va / vb > max) max = va / vb;
		if (max <= ans) DFS(va, vb, i_+1, 0);
		max = max_back;
	}
}
int main()
{
	scanf("%d%d%d", &x, &y, &n);
	if (x < y) t = x, x = y, y = t;
	each = x * y / (double)n;
	
	max = x / y;
	ans = x * y;
	
	DFS(x, y, 0, 1);
	
	printf("%.8lf", ans);
}
