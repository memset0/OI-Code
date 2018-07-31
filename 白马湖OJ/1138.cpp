#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
struct Stu {
	int i;
	double n;
}a[maxn];
int n;
double x, y, z;
bool my_sort(Stu a, Stu b) {
	if (a.n == b.n) return a.i < b.i;
	return a.n > b.n;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d%lf%lf%lf", &a[i].i, &x, &y, &z);
		a[i].n = (0.700 * x) + (0.300 * y) + z;
	}
	sort(a+1, a+n+1, my_sort);
	for (int i = 1; i <= n; i++) {
		printf("%d %.2lf\n", a[i].i, a[i].n);
	}
	return 0;
}
