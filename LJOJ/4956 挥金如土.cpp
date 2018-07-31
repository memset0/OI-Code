#include <bits/stdc++.h>
using namespace std;

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 10010, maxk = 110;
int n, k, mul, dta; 
double f[maxn][maxk], ans, p;

int main() {

	scanf("%d%d%lf", &n, &k, &p);

	if (k == 1) {
		printf("1.000\n");
		return 0;
	}
	
	if (n > 10000) n = 10000;

	for (int i = 0; i < k; i++)
		f[1][i] = 0;
	f[1][0 % k] += p;
	f[1][1 % k] += 1 - p;
	mul = 1, dta = mul % k;

	for (int i = 2; i <= n; i++) {
		mul = (mul << 1) % k;
		dta = (k + k - mul) % k;
		for (int j = 0; j < k; j++) {
			f[i][j] = f[i - 1][j] * p + f[i - 1][(j + dta) % k] * (1 - p);
		}
	}

//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j < k; j++)
//			printf("%7.3lf", f[i][j]);
//		puts("");
//	}

	ans = f[n][0];
	for (int i = 0; i < k; i++)
		ans = f[n][i] < ans ? f[n][i] : ans;
	printf("%.3lf\n", ans);

	return 0;
}
