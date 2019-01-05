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

int n, m;
ll ans, sum;
ll a[maxn][maxn], s[maxn][maxn];

int main() {

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			if (!a[i][j])
				a[i][j] = -1e9;
		}
			
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s[i][j] = s[i - 1][j] + a[i][j];
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			printf("%lld ", a[i][j]);
//		puts("");
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			printf("%lld ", s[i][j]);
//		puts("");
//	}
	
	for (int l = 1; l <= n; l++)
		for (int r = l; r <= n; r++) {
			sum = 0;
			for (int i = 1; i <= m; i++) {
				sum = max(0LL, sum) + s[r][i] - s[l - 1][i];
				ans = max(ans, sum);
			}
		}
	printf("%lld\n", ans);
	
	return 0;
}