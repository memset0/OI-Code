#include <bits/stdc++.h>
using namespace std;
const int int_max = 10000000;
const int int_min = -10000000;
const int maxn = 110 * 2;
int n, l, r, a[maxn], sum[maxn];
struct DP {
	int min, max;
}f[maxn][maxn];
int main() {
//	freopen("data.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n * 2; i++)	
		for (int j = 1; j <= n * 2; j++)	
			f[i][j].min = int_max, f[i][j].max = int_min;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	for (int i = 1; i <= 2 * n; i++) {
		sum[i] = sum[i - 1] + a[i];
		f[i][i].min = f[i][i].max = 0;
	}
	for (int i = 1; i <= 2 * n; i++) {
		for (int j = 1; j <= 2 * n; j++) {
			l = j, r = i + j;
			if (r > 2 * n) break;
//			cout << l << " " << r << endl;
			for (int k = l + 1; k <= r; k++) {
				f[l][r].min = min(f[l][r].min, f[l][k - 1].min + f[k][r].min + sum[r] - sum[l - 1]);
				f[l][r].max = max(f[l][r].max, f[l][k - 1].max + f[k][r].max + sum[r] - sum[l - 1]);
			}
		}
		
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			printf("%d|%d ", f[i][j].min, f[i][j].max);
//		}
//		puts("");
//	}
	int minn = f[1][n].min, maxx = f[1][n].max;
	for (int i = 2; i <= n + 1; i++) {
		minn = min(minn, f[i][i + n - 1].min);
		maxx = max(maxx, f[i][i + n - 1].max);
	}
	cout << minn << endl << maxx << endl;
	return 0;
}
