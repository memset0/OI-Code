#include <bits/stdc++.h>
using namespace std;
const int maxn = 15;
int n;
double l, r, k[maxn];
double f(double x) {
	double xs = 1, ans = 0;
	for (int i = 0; i <= n; i++) {
		ans += k[i] * xs;
		xs *= x;
	}
	return ans;
}
int main() {
	cin >> n >> l >> r;
	for (int i = n; i >= 1; i--)
		scanf("%lf", &k[i]);	
	while (r - l > 1e-9) {
		double l0 = (r - l) / 3 + l;
		double r0 = r - (r - l) / 3;
//		printf("%.6lf %.6lf %.6lf %.6lf\n", l, f(l0), f(r0), r);
		if (f(l0) > f(r0)) r = r0;
		else l = l0;
	}
	printf("%.5lf", l);
	return 0;
}
