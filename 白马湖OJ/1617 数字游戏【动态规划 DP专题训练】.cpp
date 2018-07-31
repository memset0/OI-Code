#include <bits/stdc++.h>
using namespace std;
const int maxn = 60;
const int maxm = 20;
int n, m, a[maxn], s[maxn];
int f[maxm][maxn][maxn];
int cal(int x) {
	while (x < 0) x += 10000;
	x = x % 10;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i + n] = a[i];
	n = n + n;
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int x;
	for (int i = 1; i <= n; i++) 
		for (int j = i; j <= n; j++)
			f[1][i][j] = cal(s[j] - s[i - 1]);
	for (int len = 1; len <= n; len++) {
		for (int i = 1, j = len; j <= n; i++, j++) {
			for (int k = i; k <= j; k++) {
				// i ~ (k - 1) 已完成
				// k ~ j 未完成 
				x = cal(s[j] - s[k - 1]);
				for (int t = 2; t <= m; t++)
					f[t][i][j] = max(f[t][i][j], 
						f[t - 1][i][k - 1] * x);
			}
		}
	}
	n /= 2;
	int ans1 = -1;
	for (int i = 1; i + n - 1 <= 2 * n; i++)
		ans1 = max(ans1, f[m][i][i + n - 1]);
	
	n *= 2;
	memset(f, -1, sizeof(f));
	for (int i = 1; i <= n; i++) 
		for (int j = i; j <= n; j++)
			f[1][i][j] = cal(s[j] - s[i - 1]);
	for (int len = 1; len <= n; len++) {
		for (int i = 1, j = len; j <= n; i++, j++) {
			for (int k = i; k <= j; k++) {
				// i ~ (k - 1) 已完成
				// k ~ j 未完成 
				x = cal(s[j] - s[k - 1]);
				for (int t = 2; t <= m; t++)
					if (f[t - 1][i][k - 1] != -1) {
						if (f[t][i][j] == -1) f[t][i][j] = f[t - 1][i][k - 1] * x;
						else f[t][i][j] = min(f[t][i][j], f[t - 1][i][k - 1] * x);
					}
			}
		}
	}
	n /= 2;
	int ans2 = f[m][1][n];
	for (int i = 1; i + n - 1 <= 2 * n; i++)
		ans2 = min(ans2, f[m][i][i + n - 1]);
		
	cout << ans2 << endl << ans1 << endl; 
	return 0;
}

////有问题 
//#include <bits/stdc++.h> 
//using namespace std;
//const int maxn = 51;
//const int maxm = 10;
//int n, m, a[maxn], sum[maxn], f[maxm][maxn][maxn];
//int getsum(int i, int j) {
//	return (sum[j] - sum[i-1])
//}
//int main() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &a[i]);
//		sum[i] = sum[i-1] + a[i];
//	}
//	memset(f, 63, sizeof(f));
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			f[1][i][j] = getsum(i, j) % 10;
//		}
//	}
//	for (int k = 1; k <= m; k++) {
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				for (int x = i; x <= j; x++) {
//					for (int y = 1; y <= m; y++)
//						f[k][i][j] = min(f[k][i][j], f[y][i][x] * f[m - y][x][j]);
//				}
//			}
//		}
//	}
//	return 0;
//}
