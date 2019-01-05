// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>	
#define ll long long
using namespace std;

const int maxn = 510;
const double eps = 1e-2;
int n, m, cnt, ans, t[maxn], p[maxn], w[maxn];
double a[maxn][maxn];

bool cmp(int x, int y) {
	return w[x] < w[y];
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%lf", &a[i][j]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++)
		t[i] = i;
	sort(t + 1, t + n + 1, cmp);

	for (int ti = 1, i = t[ti]; ti <= n; ti++, i = t[ti]) {
		for (int j = 1; j <= m; j++)
			if (fabs(a[i][j]) > eps) {
				if (p[j]) {
					double dta = -a[i][j] / a[p[j]][j];
					for (int k = 1; k <= m; k++)
						a[i][k] += a[p[j]][k] * dta;
				} else {
					p[j] = i, cnt++, ans += w[i];
					break;
				}
			}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++)
//				printf("%.2lf ", a[i][j]);
//			puts("");
//		}
//		puts("");
	}
	printf("%d %d\n", cnt, ans);
	
	return 0;
}
