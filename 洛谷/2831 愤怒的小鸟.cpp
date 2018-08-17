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

const int maxn = 20;
const long double eps = 1e-6;
int t, n, m, f[maxn * maxn], dp[1 << maxn];
long double fa, fb;

struct node {
	long double x, y;
} a[maxn];

bool equ(long double a, long double b) {
	return fabs(a - b) < eps;
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	t = read();
	while (t--) {
		memset(f, 0, sizeof(f));
		memset(dp, 63, sizeof(dp));
		
		n = read(), m = read();
		for (int i = 1; i <= n; i++)
			scanf("%Lf%Lf", &a[i].x, &a[i].y);
		
		for (int i = 1; i <= n; i++)
			f[++f[0]] = 1 << (i - 1);
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (a[i].x != a[j].x) {
					fa = (a[i].y * a[j].x - a[j].y * a[i].x) / (a[i].x * a[j].x * (a[i].x - a[j].x));
					fb = (a[i].y - fa * a[i].x * a[i].x) / a[i].x;
					f[0]++;
					if (fa < 0)
						for (int k = 1; k <= n; k++)
							if (equ(fa * a[k].x * a[k].x + fb * a[k].x, a[k].y))
								f[f[0]] += 1 << (k - 1);
//					printf(">>> %.2Lf %.2Lf : %d\n", fa, fb, f[f[0]]);
				}
				
		dp[0] = 0;
		for (int i = 0; i < (1 << n); i++)
			for (int j = 1; j <= f[0]; j++)
				dp[i | f[j]] = min(dp[i | f[j]], dp[i] + 1);
				
//		for (int i = 1; i <= f[0]; i++) {
//			printf("%5d ", f[i]);
//			for (int j = 0; j <= 5; j++)
//				if (f[i] & (1 << j))
//					putchar('1');
//				else
//					putchar('0');
//			puts("");
//		}
		
		printf("%d\n", dp[(1 << n) - 1]);
		
	}
	
	return 0;
}

