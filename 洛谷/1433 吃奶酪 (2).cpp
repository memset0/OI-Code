#include <bits/stdc++.h>
using namespace std;
int n, dis[20];
double x[20], y[20], ans = 100000000;
void DFS(int k, double ux, double uy, double v) {
	if (k > n) {
		if (v < ans) ans = v;
		return ;
	}
	if (v > ans) return ;
	for (int i = 1; i <= n; i++)
		if (!dis[i]) {
			dis[i] = 1;
			DFS(k + 1, x[i], y[i], v + sqrt( (x[i]-ux)*(x[i]-ux) + (y[i]-uy)*(y[i]-uy) ));
			dis[i] = 0;
		}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf", &x[i], &y[i]);
	DFS(1, 0, 0, 0);
	printf("%.2lf", ans);
	return 0;
}
