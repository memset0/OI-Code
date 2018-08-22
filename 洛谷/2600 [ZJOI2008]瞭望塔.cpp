// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 310;
int n;
double mid, ans = 1e200, lbound, rbound, lmid, rmid;
double x[maxn], y[maxn], k[maxn], b[maxn];

double calc(double x, double y) {
	double ans = 0;
	for (int i = 1; i < n; i++)
		ans = max(ans, x * k[i] + b[i] - y);
	return ans;
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf", &x[i]);
	for (int i = 1; i <= n; i++)
		scanf("%lf", &y[i]);

	for (int i = 1; i < n; i++) {
		k[i] = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);
		b[i] = y[i] - x[i] * k[i];
	}

	for (int i = 1; i < n; i++) {
		lbound = x[i];
		rbound = x[i + 1];
		for (int t = 100; t; t--) {
			lmid = lbound + (rbound - lbound) / 3;
			rmid = rbound - (rbound - lbound) / 3;
			if (calc(lmid, lmid * k[i] + b[i]) < calc(rmid, rmid * k[i] + b[i]))
				rbound = rmid;
			else
				lbound = lmid;
		}
		mid = (lbound + rbound) / 2;
		ans = min(ans, calc(mid, mid * k[i] + b[i]));
	}
	printf("%.3lf\n", ans);

	return 0;
}